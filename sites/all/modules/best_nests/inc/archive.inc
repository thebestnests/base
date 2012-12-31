<?php


/* orginally created listing with the forms api but the logical flow turned
 * out better using ajax
 
function best_nests_create_listing_form(){
	$form['#attributes'] = array(
      'enctype' => "multipart/form-data"
	);
	
	
	$form['basics'] = array(
		'#type'		=> 'fieldset',
		'#title' 	=> 'Basics',
	);
	
	$form['basics']['title']  = array(
		'#type' 	=> 'textfield',
		'#title' 	=> 'Property Title',
		//'#required' => TRUE,
	);
	
	$form['basics']['website'] = array(
		'#type' 	=> 'textfield',
		'#title' 	=> 'Property Website',
		//'#required' => TRUE,
	);
	
	$form['basics']['beds'] = array(
		'#type' 	=> 'textfield',
		'#title' 	=> 'Bedrooms',
		//'#required' => TRUE,
		'#size'		=> "3"
	);

	$form['basics']['baths'] = array(
		'#type' 	=> 'textfield',
		'#title' 	=> 'Bathrooms',
		//'#required' => TRUE,
		'#size'		=> "3",
	);

	$form['basics']['body'] = array(
		'#type' 	=> 'textarea',
		'#title' 	=> 'Property Description',
		//'#required' => TRUE,
	);
	
	$form['basics']['listing_image'] = array(
     	'#type'   => 'file',
      	'#title'  => 'Picture',
    );
	
	$form['location'] = array(
		'#type'		=> 'fieldset',
		'#title'	=> 'Location',
	);
	
	$form['location']['city'] = array(
		'#type' 	=> 'textfield',
		'#title' 	=> 'City',
		//'#required' => TRUE,
	);
	
	$form['location']['state'] = array(
		'#type' 	=> 'select',
		'#title' 	=> 'State',
		'#options'	=> best_nests_get_state_options(),
		//'#required' => TRUE,
	);
	
	$form['terms'] = array(
		'#type' 	=> 'fieldset',
		'#title'	=> 'Terms',
	);
	
	$form['terms']['cleaning_fee'] = array(
		'#type' 	=> 'textfield',
		'#title' 	=> 'Cleaning Fee',
		//'#required' => TRUE,
		'#default_value' => '0.00',
		'#attributes' => array("onclick" => "this.select()"),
	);
	
	$form['terms']['minimum_stay'] = array(
		'#type' 	=> 'textfield',
		'#title' 	=> 'Minimum Stay',
		//'#required' => TRUE,
	);

	$form['rental_periods'] = array(
		'#type'		=> 'fieldset',
		'#title'	=> 'Rental Periods and Discounts',
		'#attributes' => array('id' => 'rental-period'),
	);
	
	
	
	/** Section to add multiple rental periods via JS **
	$page = '<table id="rental-periods-table"><tr><th>From</th><th>To</th><th>Discount</th></tr></table>';
	$page .= '<label for="from-date">From Date: </label><input style="border: 1px solid black" type="text" id="from-date" /><br />';
	$page .= '<label for="to-date">To Date: </label><input style="border: 1px solid black"  type="text" id="to-date" /><br />';
	$page .= '<label for="discount">Discount: </label><input style="border: 1px solid black"  type="text" id="discount" /><br />';
	$page .= '<input type="button" onclick="bnAddRentalPeriod()" value="Add Rental Period" id="add-rental-period-button" />';
	
	$form['rental_periods']['add_code'] = array(
		'#type'		=> 'markup',
		'#value'	=> $page 
	);
	
	
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t("Add Listing"),
	);
	
	return $form;
}


function best_nests_create_listing_form_submit($form, &$form_state){
	global $user;

	$node = new stdClass();
	$node->title = $form_state['values']['title'];
	$node->body	= $form_state['values']['body'];
	$node->type = 'best_nests_listing';
	$node->uid = $user->uid;
	$node->format = 1;
	$node->name = $user->name;
	
	
	$node->beds = $form_state['values']['beds'];
	$node->baths = $form_state['values']['baths'];
	$node->city = $form_state['values']['city'];
	$node->state = $form_state['values']['state'];
	$node->cleaning_fee = $form_state['values']['cleaning_fee'];
	$node->minimum_stay = $form_state['values']['minimum_stay'];
	$node->website = $form_state['values']['website'];

	$node = node_submit($node);
	if ($node){
		node_save($node);
	}else{
		error_log("Error creating question");
	}
	
	if (!is_null($_POST['rental_periods'])){
		foreach ($_POST['rental_periods'] as $val){
			best_nests_save_rental_period($node->nid, $val);
		}
	}

	best_nests_process_image('listing_image', $node->nid);
}
*/





















/*


 // gather boolean fields such as beds, baths, etc
    $boolean_fields = array();
    if (!empty( $form_state['values']['beds'] )){
        $boolean_fields['beds'] = $form_state['values']['beds'];
    }
    
    if (!empty( $form_state['values']['baths'] )){
        $boolean_fields['baths'] = $form_state['values']['baths'];
    }
    
    if (!empty( $form_state['values']['region'] )){
        $boolean_fields['region'] = $form_state['values']['region'];
    }
    
    // test for supplied location fields and store in a temporary array()
    $location_fields = array();
    if (!empty( $form_state['values']['city'] )){
        $location_fields['city'] = $form_state['values']['city'];
    }

    if (!empty( $form_state['values']['state'] )){
        $location_fields['state'] = $form_state['values']['state'];
    }

    if (!empty( $form_state['values']['zip'] )){
        $location_fields['zip'] = $form_state['values']['zip'];
    }    
    
    // if a radius was not selected then the city, state and zip fields will be
    // searched as a boolean if supplied
    if ($form_state['values']['radius'] == 0){
        $boolean_fields = array_merge($boolean_fields, $location_fields);
    }else{
        // rename for readability
        $radius_fields = $location_fields;
        $radius_fields['radius'] = $form_state['values']['radius']; 
    }
        
    //cleanup
    unset($location_fields);
    
    
    
    // note that for the purpose of searching, price searches are added to the
    // range array as they are <= and >= not just ==
    $range_fields = array();
    // test for numerical ranges (availability dates, discounted dates, price ranges)
    if (!empty($form_state['values']['min_price'])){
        $range_fields['base_price']['lower'] = $form_state['values']['min_price'];
    }
    
    if (!empty($form_state['values']['max_price'])){
        $range_fields['base_price']['upper'] = $form_state['values']['max_price'];  
    }
    
    
    
    $date_fields = array();
    if (!empty($form_state['values']['from_availability'])){
        $date_fields['availability']['lower'] = $form_state['values']['from_availability'];  
    }
    
    if (!empty($form_state['values']['to_availability'])){
        $date_fields['availability']['upper'] = $form_state['values']['to_availability'];  
    }
    
    
    if (!empty($form_state['values']['from_discount'])){
        $date_fields['discount']['lower'] = $form_state['values']['from_discount'];  
    }
    
    if (!empty($form_state['values']['to_discount'])){
        $date_fields['discount']['upper'] = $form_state['values']['to_discount'];  
    }
    
    
    // Start searching
    
    // array to store search result info
    $search_results = array();
    
    if (!empty($boolean_fields)){
        foreach ($boolean_fields as $key => $val){
            $search_results['boolean'][$key] = best_nests_boolean_search($key, $val);
        }
    }
    
    // 
    if (!empty($range_fields)){
        foreach ($range_fields as $key => $val){
            $search_results['range'][$key]['min'] = (isset($val['lower'])) ? $val['lower'] : NULL;
            $search_results['range'][$key]['max'] = (isset($val['upper'])) ? $val['upper'] : NULL;
            
            $search_results['range'][$key]['results'] = 
                best_nests_range_search($key, $search_results['range'][$key]['min'], $search_results['range'][$key]['max']);
            
        }
    }

    if (!empty($date_fields)){
        foreach ($date_fields as $key => $val){
            $search_results['date'][$key]['min'] = (isset($val['lower'])) ? $val['lower'] : NULL;
            $search_results['date'][$key]['max'] = (isset($val['upper'])) ? $val['upper'] : NULL;
            
            $search_results['date'][$key]['results'] = 
                best_nests_date_search($key, $search_results['date'][$key]['min'], $search_results['date'][$key]['max']);
            
        }
    }
    
    
    if (!empty($radius_fields)){
        $search_results['radius'] = best_nests_radius_search($radius_fields['radius'], $radius_fields['zip'], $radius_fields['state'], $radius_fields['city']);
    }
    
    
    
    // Tally the results
    
    // price search results are moved to the boolean array as they either match or don't
    // date ranges are stored as one date per row and therefore can have several matching 
    // rows which is not a simple boolean answer and will be processed differently
    
    if (!empty($search_results['range']['price'])){
        $search_results['boolean']['price'] = $search_results['range']['price']['results'];
        $search_results['boolean']['number_of_fields_searched']++;
        unset($search_results['range']['price']);
    }
    
    
    if (!empty($search_results['boolean'])){
        $search_results['boolean'] = best_nests_tally_boolean_search_results($search_results['boolean']);
    }
    
    if (!empty($search_results['range'])){
       $search_results['range'] = best_nests_tally_range_search_results($search_results['range']);
    }
    
    if (!empty($search_results['date'])){
       $search_results['date'] = best_nests_tally_date_search_results($search_results['date']);
    }
    
    if (!empty($search_results['radius'])){
       // $search_results['radius'] = best_nests_tally_radius_search_results($search_results['radius']);
    }
    
    
    //$search_results = best_nests_tally_search_results($search_results);
    
    
       // store result info in session
    $_SESSION['search_results'] = $search_results;
   
    
    // forward to processing function
   $form_state['redirect'] =  "search-results/";
    
}


function best_nests_tally_boolean_search_results($boolean_results){
    // array to hold the tally counts indexed by nid
    $tallies = array();

    // count the number of searched fields to calculate percentage later
    $tallies['number_of_fields_searched'] = 0;

    // search results are stored as a csv string and indexed by the search 
    // field (beds, price, etc)
    foreach($boolean_results as $results_list){
        $tallies['number_of_fields_searched']++;

        $results = array();
        if (! empty($results_list)){
        	$results = explode(",", $results_list);
        }
        // tally each nid
        foreach($results as $nid){
            if (array_key_exists($nid, $tallies)){
                $tallies[$nid]++;
            }else{
                $tallies[$nid] = 1;
            }
        }
    }
    return $tallies;
}



function best_nests_tally_range_search_results($range_results){
    // array to hold the tally counts indexed by nid
    $tallies = array();

    // count the number of searched fields to calculate percentage later
    $tallies['number_of_fields_searched'] = 1;

    // search results are stored as a csv string and indexed by the search 
    // field (beds, price, etc)
    foreach($range_results as $result){
        // tally each nid
        $results = explode(",", $result['results']);
        foreach($results as $nid){
            if (array_key_exists($nid, $tallies)){
                $tallies[$nid]++;
            }else{
                $tallies[$nid] = 1;
            }
        }
    }

    return $tallies;
}


function best_nests_boolean_search_percentages($results, $number_of_fields_searched){
    foreach($results as &$val){
        $val = $val / $number_of_fields_searched;
    }
    
    error_log($number_of_fields_searched);
    
    return $results;
}




function best_nests_tally_date_search_results($date_results){
    // array to hold the tally counts indexed by nid
    $tallies = array();

    // search results are stored as a csv string and indexed by the search field
    foreach($date_results as $field => $results_list){
        // get the number of searched days to display in search results
        if ( is_null($field['min']) || is_null($field['max']) ){
            $tallies[$field]['number_of_days_searched'] = 1;
        }else{
            //error_log( $results_list['min'] );
            $tallies[$field]['number_of_days_searched'] = 
                db_result(db_query("SELECT DATEDIFF('{$results_list['max']}', '{$results_list['min']}')"));
        }        

        // tally each nid
        $results = explode(",", $results_list['results']);
        foreach($results as $nid){
            if (array_key_exists($nid, $tallies)){
                $tallies[$field][$nid]++;
            }else{
                $tallies[$field][$nid] = 1;
            }
        }
    }

    return $tallies;
}










function best_nests_radius_search_percentages($search_results, $radius){
    $results = explode($search_results);
    $percentages = array();
    
    foreach ($results as $val){
        list($nid, $distance) = explode("|", $val);
        $percentages[$nid] = 1 - ($distance / $radius);
    }
    
    return $percentages;
}



function best_nests_boolean_search($search_field, $search_value){
    if ((int)$search_value == 0){
        $search_value = "'$search_value'";
    }
    
    $result = db_query("SELECT GROUP_CONCAT(listing_nid) FROM best_nests_listings WHERE $search_field = $search_value");
    return db_result($result);
}

function best_nests_range_search($search_field, $min = NULL, $max = NULL){
    $vals = array();
    if (!is_null($min)){
        $vals[] = "$search_field >= $min";
    }
    
    if (!is_null($max)){
        $vals[] = "$search_field <= $max";
    }
    
    $result = db_query("SELECT GROUP_CONCAT(listing_nid) FROM best_nests_listings WHERE " . join(" AND ", $vals));
    return db_result($result);    
    
}

function best_nests_date_search($type, $min = NULL, $max = NULL){   
    $vals = array();
    $vals[] = "type = '$type'";
    
    if (!is_null($min)){
        $vals[] = "date >= '$min'";
    }
    
    if (!is_null($max)){
        $vals[] = "date <= '$max'";
    }
    
    $q = "SELECT listing_nid FROM best_nests_calendar WHERE " . join(" AND ", $vals) . " GROUP BY listing_nid";
    
    $r = db_query($q);
    $results = array();
    while ($row = db_fetch_object($r)){
        $results[] = $row->listing_nid;
    }
    
    return join(",",$results);    
    
}

function best_nests_radius_search($radius, $zip = NULL, $state = NULL, $city = NULL){

    
    list($lng, $lat) = best_nests_geoencode("$city $state $zip");
    //error_log($lng . ":" . $lat);
    
    $results = db_query("SELECT 
        listing_nid,  
        ( 3959 * 
          acos( cos( radians($lng) ) * 
          cos( radians( lat ) ) * 
          cos( radians( lng ) - radians($lat) ) + 
          sin( radians($lng) ) * sin( radians( lat ) ) )
        ) AS distance 
     FROM 
         best_nests_geocodes 
     HAVING 
         distance < $radius 
     ORDER BY 
         distance 
     LIMIT 
         0 , 20;
     ");
    
    $search_results = array("radius" => $radius);
    
    while ($row = db_fetch_object($results)){
        $search_results[$row->listing_nid] = round($row->distance, 1);
    }
    
    return $search_results;
}





function best_nests_calculate_match_percentages($results){
    // each row of $results will have an associative array with keys of availability,
    // discount, basic (beds, baths, etc), and location
    // values are nids each having
    
    $new_results = array();
    $num_fields = 0;
    $dates = array("discount" => array(), "availability" => array());
    $radius = array();
    
    foreach ($results as $key => &$matches){
    	
        switch ($key){
            case 'boolean':
            case 'range':
                $num_fields += $matches['number_of_fields_searched'];
                unset($matches['number_of_fields_searched']);
                foreach ($matches as $listing_nid => &$count){
                    if (array_key_exists($listing_nid, $new_results)){
                        $new_results[$listing_nid] += $count;
                    }else{
                        $new_results[$listing_nid] = $count;
                    }
                    
                }
                
                
                break;
            case 'date':
                $dates = $matches;
                foreach ($matches as $type => $counts){
                    $num_fields += $counts['number_of_days_searched'];
                    unset($counts['number_of_days_searched']);

                    foreach ($counts as $listing_nid => &$count){
                        if (array_key_exists($listing_nid, $new_results)){

                            $new_results[$listing_nid] += $count;
                        }else{
                            $new_results[$listing_nid] = $count;
                        }

                    }
                }
                
                break;
            case 'radius':
                $num_fields++;
                $radius = $matches;
                unset($radius['radius']);
                foreach ($matches as $listing_nid => &$count){
                    if (array_key_exists($listing_nid, $new_results)){

                        $new_results[$listing_nid]++;
                    }else{
                        $new_results[$listing_nid] = 1;
                    }
                }
                
                break;
        }
    }
    
    
    
    return array($new_results, $dates, $radius, $num_fields);
}



function best_nests_search_results(){
    list($results, $dates, $radius, $num_fields) = best_nests_calculate_match_percentages($_SESSION['search_results']);
    
    // sort by number of criteria matched
    function best_nests_search_cmp($a,$b){
        if ($a == $b){
            return 0;
        }

        return ($a > $b) ? -1 : 1;
    }    
    
    uasort($results, "best_nests_search_cmp");
    
    // radius matches have a higher weight so we move those matches to the top
    // note 2 things: 1. they were sorted based on distance in the query
    //                2. the $radius array contains the distances which is why
    //                     we don't just use that array
    
    // loop through the radius matches and add the nid and match count to a new array
    $radius_matches = array();
    foreach ($radius as $key => $value){
        $radius_matches[$key] = $results[$key];
        //error_log($results[$key]);
        // remove the radius matches from the overall search results
        unset($results[$key]);
    }
    
    // using array merge we append the radius matches to the top of the overall
    // search results
    
    $results = $radius_matches + $results;
    $listings = array();
    
    foreach ($results as $listing_nid => $count){
        $listing = node_load($listing_nid);
        $listing->match_count = $count;
        $listings[] = $listing;
    }
    
    
   
    
    return theme('best-nests-search-results', $listings, $dates, $radius, $num_fields);
}


*/
?>
