<?php

function best_nests_search(){
    return drupal_get_form('best_nests_listing_search_form');
}

function best_nests_listing_search_form(){
    $form['row1'] = array(
        '#type'     => 'markup',
        '#value'    => '<div class="row">'
    );
    
    $form['min_price'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Min Price',
      '#attributes' => array('class' => "med left"),  
    );
    
    $form['max_price'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Max Price',
      '#attributes' => array('class' => "med left"),
    );
    
    $form['beds'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Beds',
      '#attributes' => array('class' => "short left"),
    );
    
    $form['baths'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Baths',
      '#attributes' => array('class' => "short"),  
    );
    
    
    
    $form['row1b'] = array(
        '#type'     => 'markup',
        '#value'    => '</div>'
    );
    
    $form['row2'] = array(
        '#type'     => 'markup',
        '#value'    => '<div class="row">'
    );
       
    
    $form['city'] = array(
      '#type'     => 'textfield',
      '#title'    => 'City',
      '#attributes' => array('class' => "med left"),  
    );
    
    $form['state'] = array(
      '#type'     => 'select',
      '#title'    => 'State',
      '#options'  => best_nests_get_state_options(),    
      '#attributes' => array('class' => "med left"),  
    );

    $form['zip'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Zip Code',
      '#attributes' => array('class' => "short left"), 
    );

    $form['radius'] = array(
        '#type'     => 'select',
        '#title'    => 'Radius (miles)',
        '#options'  => array("0" => "0", "5" => "5", "10" => "10", "25" => "25", "50" => "50", "100" => "100", "200" => "200"),
    );
    
    $form['row2b'] = array(
        '#type'     => 'markup',
        '#value'    => '</div>'
    );
    
    
    $form['row3'] = array(
        '#type'     => 'markup',
        '#value'    => '<div class="row">'
    );
    
    $form['from_availability'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Availability From',
      '#attributes' => array('class' => "med"),  
    );
    
    $form['to_availability'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Availability To',
      '#attributes' => array('class' => "med"),  
    );
    
    $form['from_discount'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Discount From',
      '#attributes' => array('class' => "med"),  
    );
    
    $form['to_discount'] = array(
      '#type'     => 'textfield',
      '#title'    => 'Discount To',
      '#attributes' => array('class' => "med"),  
    );

    $form['row3b'] = array(
        '#type'     => 'markup',
        '#value'    => '</div>'
    );
    
    $form['submit'] = array(
      '#type'   => 'submit',
      '#value'  => t("Search"),
    );
    
    $form['reset'] = array(
      '#type'   => 'reset',
      '#value'  => t("Reset"),
    );
    
    return $form;
}

function best_nests_listing_search_form_validate($form, &$form_state){
	//form_set_error
	if ( !is_int($form_state['values']['beds']) ){
		form_set_error("Number of Bedrooms must only be a number");
	} 
	
	if ( !is_int($form_state['values']['baths']) ){
		form_set_error("Number of Bathrooms must only be a number");
	} 
	
	if ( !is_int($form_state['values']['min_price']) ){
		form_set_error("Minimum Price must only be a number");
	} 
	
	if ( !is_int($form_state['values']['max_price']) ){
		form_set_error("Maximum Price must only be a number");
	} 
	
	if ( !is_string($form_state['values']['city'])){
		form_set_error("City must be letters only");
	}
	
	if ( !is_string($form_state['values']['state'])){
		form_set_error("City must be letters only");
	}
	
	if ( !preg_match('/^dddd-dd-dd$/', $form_state['values']['from_availability']) ){
		form_set_error("Zip Code must only be a number");
	}
	
	if ( !preg_match('/^dddd-dd-dd$/', $form_state['values']['to_availability']) ){
		form_set_error("Zip Code must only be a number");
	} 
	
	if ( !preg_match('/^dddd-dd-dd$/', $form_state['values']['from_discount']) ){
		form_set_error("Zip Code must only be a number");
	}
	
	if ( !preg_match('/^dddd-dd-dd$/', $form_state['values']['to_discount']) ){
		form_set_error("Zip Code must only be a number");
	} 
	
	
}


function best_nests_listing_search_form_submit($form, &$form_state){
	// for readability
	$vals = (object) $form_state['values'];

	// count number of fields that have values to computer percentage.
	// start with -5 to account for the form_* fields and submit
	$number_of_searched_fields = -5;
	foreach ($vals as $val){
		if (!empty($val)){
			$number_of_searched_fields++;
		}
	}
	
	// prep availability and discount search into an OR separated list 
	$availability_dates = best_nests_get_date_list($vals->from_availability, $vals->to_availability);
 	$discount_dates = best_nests_get_date_list($vals->from_discount, $vals->to_discount);
	
	// prepare google radius search
	$lng = 0;
	$lat = 0;
	if ($vals->radius > 0){
		list($lng, $lat) = best_nests_geoencode("$vals->city $vals->state $vals->zip");
	}
	
	// and the query ...
	$sql = "SELECT *
	  		FROM (
	  			SELECT (
	  				CASE WHEN l.base_price BETWEEN '$min_price' AND '$max_price' THEN 1 ELSE 0 END +
					CASE WHEN l.beds = $beds THEN 1 ELSE 0 END + 
					CASE WHEN l.baths = $beds THEN 1 ELSE 0 END +
					CASE WHEN l.city = $city THEN 1 ELSE 0 END +
					CASE WHEN l.state = $state THEN 1 ELSE 0 END +
					CASE WHEN l.zip = THEN 1 ELSE 0 END +
					
					CASE WHEN $dates BETWEEN c.from_availability AND c.to_availability AND c.type != 'd' THEN 1 ELSE 0 END +
					CASE WHEN $dates BETWEEN c.from_discount AND c.to_discount AND c.type = 'd' THEN 1 ELSE 0 END +
					
					CASE WHEN  
				        ( 3959 * 
				          acos( cos( radians($lng) ) * 
				          cos( radians( g.lat ) ) * 
				          cos( radians( g.lng ) - radians($lat) ) + 
				          sin( radians($lng) ) * sin( radians( g.lat ) ) )
				        ) AS distance < $radius THEN 1 ELSE 0 END
					
					
					/ $number_of_searched_fields 
				) AS numMatches, listing_nid nid
	          	FROM best_nests_listings l, best_nests_calendar c, best_nests_geocode g
	        	) AS derived,
			WHERE derived.numMatches > 0
	 		ORDER BY derived.numMatches DESC
	";

	$result = db_query($sql);
	$listings = array();
	while ($row = db_fetch_object($result)){
		$listing = node_load($row->nid);
		$listing->match = $row->numMatches;
		$listings[] = $listing;
	}
	
	return $listings;
}



function best_nests_geoencode($address){    
    define("MAPS_HOST", "maps.google.com");
    define("KEY", "ABQIAAAA5t1O-9SFxnKddevSLuUVRRTAuf6n0o0kbfor7PkIJaLzCQ0GMRRqXdtSXICm43VS2FNTPWhPnzwhZQ");
    
    $base_url = "http://" . MAPS_HOST . "/maps/geo?output=xml&key=" . KEY;
    
    $request_url = $base_url . "&q=" . urlencode($address);
    $xml = simplexml_load_file($request_url) or die("url not loading");
    
    $status = $xml->Response->Status->code;
    if (strcmp($status, "200") == 0) {
        $coordinates = $xml->Response->Placemark->Point->coordinates;
        $coordinatesSplit = split(",", $coordinates);
        
        // Format: Longitude, Latitude, Altitude
        $lat = $coordinatesSplit[1];
        $lng = $coordinatesSplit[0];
        
        return array($lat, $lng);
    }else{
        // failure to geocode
        $message = "Address " . $address . " failed to geocoded. " .
                  "Received status " . $status;
        error_log($message);
        mail('support@information-interactive.com', "Geo-encode error", $message);
        return false;
    }
    

}


function best_nests_save_geocode($listing_nid, $lat, $lng){
	if (!is_null($lat) && !is_null($lng)){
    	db_query("INSERT INTO best_nests_geocodes (listing_nid, lat, lng) 
              VALUES ($listing_nid, $lat, $lng)");
	}
}





?>
