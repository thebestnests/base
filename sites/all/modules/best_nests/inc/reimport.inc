<?php 


/*

1. need to verify the total number of exiting listings
2. import users
	- can they simply be added to the users db?

3. 







 */









function delete_imported_listings(){
	$nodes = db_query("SELECT nid FROM node WHERE type='best_nests_listing'");
	while ($row = db_fetch_object($nodes)){
		node_delete($row->nid);
	}
	
	db_query("TRUNCATE TABLE best_nests_nid_map");
	db_query("TRUNCATE TABLE best_nests_listings");
	db_query("TRUNCATE TABLE best_nests_geocodes");
	
	return "done";
}

function import_listings(){
	$dbh = mysql_connect('localhost', 'root', 'b@ck$lid3');
	mysql_select_db('bestnestsold', $dbh) ;

	
	/*
	$users = mysql_query("SELECT uid, name, pass, mail, status, timezone, init, data, timezone_name FROM users", $dbh);
	while ($row = mysql_fetch_object($users)){
		db_query("INSERT INTO users (name, pass, mail, status, timezone, init, data)
			VALUES ('$row->name', '$row->pass', '$row->mail', $row->status, '$row->timezone', 
					'$row->init', '$row->data')");
		
		$new_uid = db_last_insert_id('users', 'uid');
		
		db_query("INSERT INTO best_nests_uid_map (old, new) VALUES ($row->uid, $new_uid)");
	}
	*/
	
	/*
	
	$listings = mysql_query("
		 SELECT
			n.nid, u.uid, u.name, n.title title, 
			bp.field_base_price_value base_price,
			beds.field_bedrooms_value beds,
			baths.field_bathrooms_value baths,
			city.field_city_value city,
		    t.name state,
		    c.field_cleaning_fee_value cleaning_fee,
			stay.field_miminum_night_stay_value minimum_stay,
			d.field_property_description_value body,
			web.field_website_url website,
			yt.field_youtube_video_value youtube_link
		FROM
			node n, users u, node_revisions nr,
			content_field_base_price bp,
			content_field_bedrooms beds,
			content_field_bathrooms baths,
			content_field_city city,
			content_field_state state,
			content_field_cleaning_fee c,
			content_field_miminum_night_stay stay,
			content_field_property_description d,
			content_field_website web,
			content_field_youtube_video yt,
		    term_data t  
		WHERE
			n.type='listing_free' AND
		        u.uid = n.uid AND
			nr.nid = n.nid AND
			bp.nid = n.nid AND
			beds.nid = n.nid AND
			baths.nid = n.nid AND
			city.nid  = n.nid AND
			state.nid  = n.nid AND
			c.nid  = n.nid AND
			stay.nid  = n.nid AND
			d.nid  = n.nid AND
			web.nid  = n.nid AND
			yt.nid  = n.nid AND
		    t.tid = state.field_state_value
	", $dbh);
	
	
	//error_log(mysql_num_rows($listings));
	
	while ($row = mysql_fetch_object($listings)){
		//$exists = db_result(db_query("SELECT COUNT(*) FROM best_nests_nid_map WHERE old = $row->nid"));
		
		//$new_uid = db_result(db_query("SELECT new FROM best_nests_uid_map WHERE old = $row->uid"));
		//$r .= $row->uid . ":" . $new_uid . '<br>';
		if ($row->uid > 1){		
			$states = best_nests_get_state_options();
			
		    $node = new stdClass();
	        $node->type = "best_nests_listing";
	        $node->uid = $row->uid;
	        $node->title = $row->title;
	        $node->body = $row->body;
	        $node->base_price = $row->base_price;
	        $node->beds = $row->beds;
	        $node->baths = $row->baths;
	        $node->city = $row->city;
	        $node->state = array_search($row->state, $states);
	        $node->cleaning_fee = $row->cleaning_fee;
	        $node->minimum_stay = $row->minimum_stay;
	        $node->website = $row->website;
	        $node->youtube_link = $row->youtube_link;
	
	        
	        //$node = node_submit($node);
	          
	        //var_dump($node);
	            
	        if ($node){
	        	node_save($node);
	        	  $r .= $node->uid . ',';
	        }else{
	        	error_log("Error updating listing");
	        }
	           
	        
	        $address = array($node->city, $node->state);
	        list($lat, $lng) = best_nests_geoencode(join(' ', $address));
	        best_nests_save_geocode($node->nid, $lat, $lng);
	        
			db_query("INSERT into best_nests_nid_map (old,new) VALUES ($row->nid, $node->nid)");            
	        //die();
		}
	
	}
	*/
	
	
		
		$images = mysql_query("
			SELECT 
				i.nid, f.fid, f.filename, f.uid, f.filepath, f.filemime, f.filesize, f.status, f.timestamp 
			FROM 
				content_field_images i, files f 
			WHERE 
				i.field_images_fid != '' AND 
				f.fid = i.field_images_fid", $dbh);
		
		$orphans = array();
		while ($row = mysql_fetch_object($images)){ 
	
			//var_dump($row);
			$dir = "/home/www/bestnestsbackup/sites/default/files/"; 
			$mime = explode(".", $row->filename);
			$mime = $mime[1];
			//$uid = db_result(db_query("SELECT new FROM best_nests_uid_map WHERE old = $row->uid"));
			$nid = db_result(db_query("SELECT new FROM best_nests_nid_map WHERE old = $row->nid"));
			
			
			
			if (empty($nid)){
				$orphans[] = $row->nid;
			}else{
			
				db_query("INSERT INTO files (fid, uid, filename, filepath, filemime, filesize, status, timestamp)
					VALUES ($row->fid, $row->uid, '$row->filename', '$row->filename', '$row->filemime', $row->filesize, 
						    $row->status, $row->timestamp)");
						 
				
				
				best_nests_process_image($dir . $row->filename, $mime, 'tn');
			  	$new_filename = best_nests_process_image($dir . $row->filename, $mime, 'full', 500, 500);
			  	
			  	if ($new_filename !== FALSE){
				  	db_query("INSERT INTO best_nests_images (listing_nid, fid) 
				  		VALUES ($nid, $row->fid)");
				  	
				  	db_query("UPDATE files SET filename = '$new_filename' WHERE fid=$row->fid");
			  	}elseif ($new_filename == FALSE){
			  		$ext = explode(".", $file->filename);
			  		$ext = $ext[1];
			  		$md5_filename = md5_file($dir . $file->filename);
			  		$fid = db_result(db_query("SELECT fid FROM files WHERE filename = '$md5_filename." . $ext . "'"));
					$is_on_listing = db_result(db_query("
						SELECT count(*) 
						FROM best_nests_images 
						WHERE listing_nid = $nid AND fid = $row->fid"));
					if ($is_on_listing == 0){
						db_query("INSERT INTO best_nests_images (listing_nid, fid, is_default) VALUES ($nid, $row->fid, 0)");
					}
			  		//db_query("DELETE FROM files WHERE fid = $file->fid");
			  	}
			  	//unlink($dir . $row->filename);
				//$form_state['redirect'] = "edit-listing/" . $form_state['values']['listing_nid'];
			}
		  
		}
		
		
	
	
	return join(", ", array_unique($orphans));
	
	
	
	
	return "done";
}        







/*    
    
1. import base data into new nodes
   - save old nid in listings table temporarily

2. images
   - download all images from old site into temp directory on new site
   - alter image upload script to process all images in that directory
   - use old nid from listings table to associate
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
SELECT 
    a.nid, a.field_discount_price_value, 
    b.field_discount_percentage_value, c.field_base_price_value
FROM
 * 
    content_field_discount_price a, content_field_discount_percentage b, content_field_base_price c
WHERE
    b.nid=a.nid AND c.nid=a.nid
GROUP BY 
    a.nid
    
    
    
    
    
    
    
    
    
    
    
    
    
  
    
    
 SELECT
	n.nid,
        u.uid, u.name,
	n.title, nr.body,
	bp.field_base_price_value,
	beds.field_bedrooms_value,
	baths.field_bathrooms_value,
	city.field_city_value,
  
    t.name,
 
	state.field_state_value,
	
    c.field_cleaning_fee_value,
	stay.field_miminum_night_stay_value,
	d.field_property_description_value,
	web.field_website_url,
	yt.field_youtube_video_value


FROM
	node n, 
        users u,
	node_revisions nr,
	content_field_base_price bp,
	content_field_bedrooms beds,
	content_field_bathrooms baths,
	content_field_city city,
	content_field_state state,
	content_field_cleaning_fee c,
	content_field_miminum_night_stay stay,
	content_field_property_description d,
	content_field_website web,
	content_field_youtube_video yt,
    term_data t  

WHERE
	n.type='listing_free' AND
        u.uid = n.uid AND
	nr.nid = n.nid AND
	bp.nid = n.nid AND
	beds.nid = n.nid AND
	baths.nid = n.nid AND
	city.nid  = n.nid AND
	state.nid  = n.nid AND
	c.nid  = n.nid AND
	stay.nid  = n.nid AND
	d.nid  = n.nid AND
	web.nid  = n.nid AND
	yt.nid  = n.nid AND
    t.tid = state.field_state_value





SELECT
	f.filepath, c.nid
	
FROM
	content_field_images c,
	files f

WHERE
	f.fid = c.field_images_fid

GROUP BY
     c.nid   
   
  
 
}
*/
?>