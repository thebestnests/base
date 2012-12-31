<?php




function best_nests_get_listing_image_form($listing_nid){
    $count = best_nests_get_listing_image_count($listing_nid);
    if ($count < 8){
    	echo drupal_get_form('best_nests_listing_image_form', $listing_nid);
    }else{
        echo "You have uploaded the maximum number of pictures. Delete existing
            to upload different ones";
    }
}

function best_nests_listing_image_form($ph, $listing_nid){
	$form['#attributes'] = array(
      'enctype' => "multipart/form-data",
	  'onsubmit' => "return tbn.validateImageForm()",
	);
	
	$form['listing_image'] = array(
     	'#type'   => 'file',
      	'#title'  => 'Image',
    );
    
    
    $form['listing_nid'] = array(
    	'#type'		=> 'hidden',
    	'#value'	=> $listing_nid,
    );
    
    $form['loading'] = array(
        '#type'  => 'markup',
        '#value' => '<p id="p-loading-image" style="text-align:center;display:none"><img id="loading-image" src="/sites/default/files/loading.gif"></p>',
    );
    
    	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t("Add Image"),
		'#attributes' => array("style" => "display: none;"),
	);
		
	
	$form['warning'] = array(
    	'#type' => 'markup',
    	'#value' =>  '<p id="image-message" class="hidden red">*Please select an image</p>',
    );
    
    return $form;
}


function best_nests_listing_image_form_submit($form, &$form_state){
	error_log('test');
	//best_nests_process_image('listing_image', $form_state['values']['listing_nid']);
	//$validators = array('file_validate_extensions' => 'gif jpg png');
	$dir = $_SERVER['DOCUMENT_ROOT'] . base_path() . file_directory_path() . "/listing_pics/temp/";
  	$file = file_save_upload('listing_image', NULL, $dir, FALSE);
	
  	
  	// FIXME: change this to send the file object
  	best_nests_process_image($dir . $file->filename, $file->filemime, 'tn');
  	$new_filename = best_nests_process_image($dir . $file->filename, $file->filemime, 'full', 500, 500);
  	
  	if ($new_filename !== FALSE){
	  	db_query("INSERT INTO best_nests_images (listing_nid, fid) 
	  		VALUES ({$form_state['values']['listing_nid']}, $file->fid)");
	  	
	  	db_query("UPDATE files SET filename = '$new_filename' WHERE fid=$file->fid");
  	}elseif ($new_filename == FALSE){
  		$ext = explode(".", $file->filename);
  		$ext = $ext[1];
  		$md5_filename = md5_file($dir . $file->filename);
  		$fid = db_result(db_query("SELECT fid FROM files WHERE filename = '$md5_filename." . $ext . "'"));
		$is_on_listing = db_result(db_query("
			SELECT count(*) 
			FROM best_nests_images 
			WHERE listing_nid = {$form_state['values']['listing_nid']} AND fid = $fid"));
		if ($is_on_listing == 0){
			db_query("INSERT INTO best_nests_images (listing_nid, fid, is_default) VALUES ({$form_state['values']['listing_nid']}, $fid, 0)");
		}
  		db_query("DELETE FROM files WHERE fid = $file->fid");
  	}
  	unlink($dir . $file->filename);
	$form_state['redirect'] = "edit-listing/" . $form_state['values']['listing_nid'];
	
}


function best_nests_process_image($filename, $mime, $type, $new_width = 125, $new_height = 125){
	switch ($mime){
        case "image/jpeg":
        case "jpg":
            $ext = ".jpg";
            $create_func = 'imagecreatefromjpeg';
            $image_func = 'imagejpeg';
            break;
        case "image/gif":
        case "gif":
            $ext = ".gif";
            $create_func = 'imagecreatefromgif';
            $image_func = 'imagegif';
            break;
        case "image/png":
        case "png":
            $ext = ".png";
            $create_func = 'imagecreatefrompng';
            $image_func = 'imagepng';
            break;
        default:
        	return "BAD EXTENTION";
    }
	

   
	$md5_filename = md5_file($filename) . $ext;
	if (!best_nests_is_file_duplicate($md5_filename)){
	
		list($width, $height) = getimagesize($filename);
	
		$resize_percentage = 0;
		if ($width > $new_width){
			$resize_percentage = $new_width / $width;
			$new_height = $height * $resize_percentage;
		}elseif ($height > $new_height){
			$resize_percentage = $new_height / $height;
			$new_width = $width * $resize_percentage;
		}

		    
		if ($resize_percentage > 0){
	        $src_image = $create_func($filename);
			$dest_image = imagecreatetruecolor($new_width, $new_height);
			imagecopyresampled($dest_image, $src_image, 0, 0, 0, 0, $new_width, $new_height, $width, $height);
			$filepath = file_directory_path();
			
			
			$image_func($dest_image, $_SERVER['DOCUMENT_ROOT'] . base_path() . file_directory_path() . "/listing_pics/$type/$md5_filename");
		}else{
			copy($filename, $_SERVER['DOCUMENT_ROOT'] . base_path() . file_directory_path() . "/listing_pics/$type/$md5_filename");
		}
	}else{
		$md5_filename = FALSE;
	}
		return $md5_filename;
}






function best_nests_delete_images(){
	$dir = $_SERVER['DOCUMENT_ROOT'] . base_path() . file_directory_path() . "/listing_pics/";
	$fids = db_result(db_query("SELECT GROUP_CONCAT(fid) FROM files WHERE filename IN ({$_POST['filenames']})"));
    db_query("DELETE from best_nests_images WHERE fid IN ($fids) AND listing_nid={$_POST['listing_nid']}");
	
    
    $fids = explode(",", $fids);
    foreach ($fids as $fid){
    	$count = db_result(db_query("SELECT COUNT(*) FROM best_nests_images WHERE fid = $fid"));
    	if ($count == 0){
    		$filename = db_result(db_query("SELECT filename FROM files WHERE fid=$fid"));
    		db_query("DELETE FROM files WHERE fid=$fid");
    		unlink($dir . "full/" . $filename);
    		unlink($dir . "tn/" . $filename);
    	}
    }
}


function best_nests_set_default_image($fid, $listing_nid){
	db_query("UPDATE best_nests_images SET is_default=0 WHERE listing_nid=$listing_nid");
    db_query("UPDATE best_nests_images SET is_default=1 WHERE fid=$fid AND listing_nid=$listing_nid");
}


function best_nests_is_file_duplicate($filename){
	$is_duplicate = FALSE;
	$q = db_result(db_query("SELECT COUNT(*) FROM files WHERE filename='$filename'"));
	
	if ($q > 0){
		$is_duplicate = TRUE;
	}
	
	return $is_duplicate;	
}




function best_nests_get_listing_image_count($listing_nid){
    $count = db_result(db_query("SELECT COUNT(listing_nid) FROM best_nests_images WHERE listing_nid=$listing_nid"));
    return $count;
}




function best_nests_get_default_image($listing_nid){
    $filename = db_result(db_query("SELECT filename FROM files where fid = (SELECT fid FROM best_nests_images WHERE listing_nid=$listing_nid LIMIT 1)"));
	if (empty($filename)){
        	$filename = "no-image.png";
        }    
        
    return $filename;
}



function import_images(){
    
    //error_log("\n". print_r($_FILES,1) . "\n\n");
    $error = array();
    $corrected_filenames = array();
    
    $nid_map = array();
    $nid_map_query = db_query("SELECT new FROM best_nests_nid_map WHERE old = ");
    while ($row = db_fetch_object($nid_map_query)){
        $nid_map[$row->old_nid] = $row->listing_nid;
    }
    
    //print_r($nid_map);
    
    if (($handle = fopen("/home/www/images.csv", "r")) !== FALSE) {
        while (($data = fgetcsv($handle, 1000, ",")) !== FALSE) {
            $filename = $data[0];
            $listing_nid = db_result(db_query("SELECT listing_nid FROM best_nests_listings WHERE old_nid = {$data[1]}"));
            $listing_nid = $nid_map[$data[1]];
            
            list($filename, $ext) = split('\.', $filename);
            $filename = split("/", $filename);
            $filename = $filename[count($filename) -1];
            
            $path = '/home/www/thebestnests/sites/default/files/tempfiles/'; 
            
            if (!file_exists($path . $filename . "." . $ext)){
                if (!file_exists( $path . $filename . "_0." . $ext)){
                    if (!file_exists( $path . $filename . "_1." . $ext)){
                        if (!file_exists( $path . $filename . "_2." . $ext)){
                            if (!file_exists( $path . $filename . "_3." . $ext)){
                                if (!file_exists( $path . $filename . "_4." . $ext)){
                                    $error[] = $filename . "." . $ext;
                                }else{
                                    $corrected_filenames[] = array("nid" => $listing_nid, "fn" => $filename . "_4." . $ext);
                                }
                            }else{
                                $corrected_filenames[] = array("nid" => $listing_nid, "fn" => $filename . "_3." . $ext);
                            }
                        }else{
                            $corrected_filenames[] = array("nid" => $listing_nid, "fn" => $filename . "_2." . $ext);
                        }
                    }else{
                        
                        $corrected_filenames[] = array("nid" => $listing_nid, "fn" => $filename . "_1." . $ext);
                    }
                }else{
                    $corrected_filenames[] = array("nid" => $listing_nid, "fn" => $filename . "_0." . $ext);
                }
            }else{
                $corrected_filenames[] = array("nid" => $listing_nid, "fn" => $filename . "." . $ext);
            }
        }
    }
     
    foreach ($corrected_filenames as $row){
        $ext = split("\.", $row['fn']);
        $ext = $ext[count($ext) -1];
        
        $fn = best_nests_save_image('/home/www/thebestnests/sites/default/files/tempfiles/' . $row['fn'], $ext, "tn");
        $fn = best_nests_save_image('/home/www/thebestnests/sites/default/files/tempfiles/' . $row['fn'], $ext, "full", 500, 500);

        if ($fn){
            db_query("INSERT INTO best_nests_images(listing_nid, filename) VALUES (%d, '%s')",
                $row['nid'], $fn);
        }else{
            error_log("error");
        }

        //die();
    }
    
    
    error_log(count($error));
    //error_log(print_r($error,1));
}