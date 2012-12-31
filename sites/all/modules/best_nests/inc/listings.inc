<?php


function best_nests_state_listings($state = '%', $date = null){
    if (is_null($date)){
        $date = date("Y-m-d");
    }
    
    $listing_nids = db_query("
        SELECT 
            l.listing_nid, l.base_price, l.beds, l.baths, l.city, l.state, l.region, l.zip,
            n.title,
            CONCAT(SUBSTRING(nr.body, 1, 200), ' ... ') as body
        FROM 
            best_nests_listings l,
            node n, 
            node_revisions nr
        WHERE 
            l.state like '$state' AND
            l.paid = 1 AND
            n.nid = l.listing_nid AND
            nr.nid = listing_nid
        ORDER BY state ASC
    ");

    $listings = array();
    while ($row = db_fetch_object($listing_nids)){
    	//short term workaround
    	//$row->body = $row->description;
    	
        $row->discount = db_result(db_query("
        	SELECT discount 
        	FROM best_nests_calendar 
        	WHERE 
        		listing_nid=$row->listing_nid AND 
        		type='d' AND 
        		'$date' BETWEEN from_date AND to_date AND
        		abuse_flag=0"
        ));
        
        if (empty($row->discount)){
    		$row->discount = 0;    	
	    }else{
	    	$discounted_price = $row->base_price - ($row->base_price * ($row->discount * .01));
        	$row->discounted_price = " ($" . $discounted_price . ")";
        	//error_log($row->discount);
        	
	    }
        
	    $row->default_image = best_nests_get_default_image($row->listing_nid);
        $listings[] = $row;
    }
    
    if (empty($listings)){
    	return "<h3>There are no active listings for this state</h3>";
    }else{
    	usort($listings, best_nests_cmp);
	    return theme('best-nests-short-listing', $listings);
    }
    
}



function best_nests_get_listings($state, $style = "full", $beds = '%', $baths = '%', $min_price = '0', $max_price = '100000'){
    $listing_nids = db_result(db_query("
        SELECT 
            GROUP_CONCAT(listing_nid)
        FROM 
            best_nests_listings
        WHERE
            state='$state' AND
            beds LIKE '$beds' AND
            baths LIKE '$baths' AND
            base_price >= $min_price AND
            base_price <= $max_price AND
    		l.paid = 1
    "));

    $listings = array();
    $listing_nids = split(",", $listing_nids);
    
    foreach ($listing_nids as $listing_nid){
        $listing = node_load($listing_nid);

        if ($style == "full"){
           $listing->discount = array(); 

            $rental_periods = db_query("
                SELECT 
                    id, from_date, to_date, discount * .01 discount, type 
                FROM 
                    best_nests_calendar
                WHERE 
                    listing_nid=$listing_nid AND
                    abuse_flag=0
                ORDER BY
                    from_date ASC");
            
            while ($row = db_fetch_object($rental_periods)){
                if ($row->type == "discount"){
                    $listing->discount[] = $row;
                }else{
                    $listing->available[] = $row;
                }
            }

        }else{
             $listing->discount = db_result(db_query(
                "SELECT 
                    discount
                FROM 
                    best_nests_calendar
                WHERE 
                    listing_nid = $listing_nid AND
                    abuse_flag=0 AND
                    date = CURDATE() AND
                    type != 'discount'
                LIMIT 1"
            ));

            if ($listing->discount < 1){
                $listing->discount = 0;
            }
        }

        $listings[] = $listing;
    }
    
    if ($style != "full"){
        usort($listings, "best_nests_cmp");
    }
    
    return $listings;
}

function best_nests_cmp($a,$b){
    if ($a->discount == $b->discount){
        return 0;
    }

    return ($a->discount > $b->discount) ? -1 : 1;
}  

/*
function best_nests_view_short_listing($state, $date = NULL){
    if ($_POST['submit']){
        $beds = $_POST['filter_beds'];
        $baths = $_POST['filter_baths'];
        $min_price = ($_POST['filter_min_price'] != "min price") ? $_POST['filter_min_price'] : "0";
        $max_price = ($_POST['filter_max_price'] != "max price") ? $_POST['filter_max_price'] : "100000";
        
        $listings = best_nests_get_listings($state, "short", $beds, $baths, $min_price, $max_price); // AND paid=1");
    }else{
    	$listings = best_nests_get_listings($state, "short"); // AND paid=1");
    }
    
	return theme('best-nests-short-listing', $listings);
}
*/


function best_nests_view_listing($nid){
	$listing = node_load($nid);
    $calendars = best_nests_listing_calendars(12, "listing", $nid);
    global $user;
    $listing->is_owner = 'false';
    
    if ($user->uid == $listing->uid){
    	$listing->is_owner = 'true';
    }
    
	$listing->discount = db_result(db_query("
		SELECT 
			discount 
		FROM 
			best_nests_calendar 
		WHERE 
			listing_nid = %d AND
			type = 'd' AND
			'%s' BETWEEN from_date AND to_date", 
		$listing->nid, date("Ymd")));

	if (empty($listing->discount)){
		$listing->discount = 0;
	}
	
	if (strpos($listing->website, "http://") === FALSE){
		$listing->website = "http://" . $listing->website;
	}
	
	$listing->youtube_link = str_replace("http://youtu.be/", "", $listing->youtube_link);
	$listing->youtube_link = str_replace("http://www.youtube.com/watch?v=", "", $listing->youtube_link);
	
	
    $listing->discounted_price = $listing->base_price - ($listing->base_price * ($listing->discount * .01));
    
	return theme('best-nests-long-listing', $listing, $calendars);
}





/** Create/Edit Listing **/
function best_nests_create_listing(){
    global $user;
    if ($user->uid == 0){
    	header("Location: /user/login");
    }else{
	    $node = new stdClass();
	    $node = node_submit($node);
	    
	    $node->type = 'best_nests_listing';
	    $node->uid = $user->uid;
	    $node->format = 1;
	    $node->name = $user->name;
	    $node->paid = 0;
	    
	    
	    if ($node){
	        node_save($node);
	    }else{
	        error_log("Error creating question");
	    }
	    
	    $node->images = array();
	    $node->availability = array();
	    $node->discounts = array();
	    
	    //return theme('best-nests-edit-listing', $node);
	    //header("Location: /edit-listing/" . $node->nid);
	    return best_nests_edit_listing($node->nid);
    }
}

function best_nests_edit_listing($listing_nid){
	
	$status = array('f' => 'Fully Booked', 'p' => 'Provisionally Booked');
    $listing = node_load($listing_nid);
    $discounts = db_query("
    	SELECT 
    		id, discount, DATE_FORMAT(from_date, '%m/%%d/%Y' ) from_date, 
    		DATE_FORMAT(to_date, '%m/%%d/%Y') to_date, abuse_flag
    	FROM 
    		best_nests_calendar 
    	WHERE 
    		listing_nid=$listing->nid AND 
    		type='d' 
    	ORDER BY from_date");
    
    while ($row = db_fetch_object($discounts)){
        $listing->discount[] = $row;
    }
    
    
    $bookings = db_query("
    	SELECT 
    		id, abuse_flag, DATE_FORMAT(from_date, '%m/%%d/%Y' ) from_date, 
    		DATE_FORMAT(to_date, '%m/%%d/%Y') to_date, type 
    	FROM 
    		best_nests_calendar 
    	WHERE 
    		listing_nid=$listing->nid AND 
    		type !='d' 
    	ORDER BY from_date");
	while ($row = db_fetch_object($bookings)){
		$row->type = $status[$row->type];
        $listing->bookings[] = $row;
    }
    
    
	global $user;
    $listing->is_owner = 'false';
    
    if ($user->uid == $listing->uid){
    	$listing->is_owner = 'true';
    }
    
    /*$availability = db_query("SELECT date FROM best_nests_calendar WHERE listing_nid=$listing->nid AND type='availability' ORDER BY date");
    while ($row = db_fetch_object($availability)){
        $listing->availability[] = $row;
    }
    */
    return theme('best-nests-edit-listing', $listing);
}


function best_nests_update_listing(){
	$node = node_load($_POST['listing_nid']);
	
    $node->title = $_POST['title'];
    $node->body = $_POST['body'];
    
	$node->beds = $_POST['beds'];
	$node->baths = $_POST['baths'];
	$node->base_price = $_POST['base_price'];
	$node->city = $_POST['city'];
	$node->state = $_POST['state'];
	$node->minimum_stay = $_POST['minimum_stay'];
    $node->cleaning_fee = $_POST['cleaning_fee'];
    $node->website = $_POST['website'];
    $node->youtube_link = $_POST['youtube_link'];
    $node->zip = $_POST['zip'];
    $node->region = $_POST['region'];
    
	
	$node = node_submit($node);
	if ($node){
		node_save($node);
	}else{
		error_log("Error updating listing");
	}
	
	var_dump($node);
	
}

function best_nests_toggle_listing($listing_nid, $status){
	db_query("UPDATE best_nests_listings SET active=$status WHERE listing_nid=$listing_nid");
	echo $status;
}

function best_nests_my_listings(){
    //error_log('test');
    global $user;
    $nids = db_query("SELECT nid FROM node WHERE type='best_nests_listing' AND uid=$user->uid");
    $listings = array();
    
    while ($row = db_fetch_object($nids)){
    	$listing = node_load($row->nid);
    	if (empty($listing->title)){
    		$listing->title = "listing #" . $listing->nid;
    	}
        $listings[] = $listing;
        
    }
	return theme('best-nests-my-listings', $listings);
}

function best_nests_get_state_options(){
	$selects = array();
	$selects["AL"] = "Alabama"; 
	$selects["AK"] = "Alaska"; 
	$selects["AZ"] = "Arizona"; 
	$selects["AR"] = "Arkansas"; 
	$selects["CA"] = "California"; 
	$selects["CO"] = "Colorado"; 
	$selects["CT"] = "Connecticut"; 
	$selects["DE"] = "Delaware"; 
	$selects["DC"] = "District Of Columbia"; 
	$selects["FL"] = "Florida"; 
	$selects["GA"] = "Georgia"; 
	$selects["HI"] = "Hawaii"; 
	$selects["ID"] = "Idaho"; 
	$selects["IL"] = "Illinois"; 
	$selects["IN"] = "Indiana"; 
	$selects["IA"] = "Iowa"; 
	$selects["KS"] = "Kansas"; 
	$selects["KY"] = "Kentucky"; 
	$selects["LA"] = "Louisiana"; 
	$selects["ME"] = "Maine"; 
	$selects["MD"] = "Maryland"; 
	$selects["MA"] = "Massachusetts"; 
	$selects["MI"] = "Michigan"; 
	$selects["MN"] = "Minnesota"; 
	$selects["MS"] = "Mississippi"; 
	$selects["MO"] = "Missouri"; 
	$selects["MT"] = "Montana"; 
	$selects["NE"] = "Nebraska"; 
	$selects["NV"] = "Nevada"; 
	$selects["NH"] = "New Hampshire"; 
	$selects["NJ"] = "New Jersey"; 
	$selects["NM"] = "New Mexico"; 
	$selects["NY"] = "New York"; 
	$selects["NC"] = "North Carolina"; 
	$selects["ND"] = "North Dakota"; 
	$selects["OH"] = "Ohio"; 
	$selects["OK"] = "Oklahoma"; 
	$selects["OR"] = "Oregon"; 
	$selects["PA"] = "Pennsylvania"; 
	$selects["RI"] = "Rhode Island"; 
	$selects["SC"] = "South Carolina"; 
	$selects["SD"] = "South Dakota"; 
	$selects["TN"] = "Tennessee"; 
	$selects["TX"] = "Texas"; 
	$selects["UT"] = "Utah"; 
	$selects["VT"] = "Vermont"; 
	$selects["VA"] = "Virginia"; 
	$selects["WA"] = "Washington"; 
	$selects["WV"] = "West Virginia"; 
	$selects["WI"] = "Wisconsin"; 
	$selects["WY"] = "Wyoming";

	return $selects;
}


function best_nests_listing_contact_form($p, $nid){

    $form['email'] = array(
        '#type'     => 'textfield',
        '#title'    => 'Email Address',
        '#required' => TRUE,
    );

    $form['arrival_date'] = array(
        '#type'   => "textfield",
        '#title'  => "Date of Arrival",
        '#required' => TRUE,
    );

    $form['num_nights'] = array(
        '#type'   => "textfield",
        '#title'  => "Number of Nights",
        '#required' => TRUE,
    );

    $form['phone'] = array(
        '#type'   => "textfield",
        '#title'  => "Phone",
        '#required' => TRUE,
    );

    $form['comments'] = array(
        '#type'   => "textarea",
        '#title'  => "Comments & Questions",
        '#required' => TRUE,
    );

    $form['listing_nid'] = array(
        '#type'   => "hidden",
        '#value' => "$nid",
    );


    $form['submit'] = array(
        '#type'   => 'submit',
        '#value'  => t("Submit"),
    );
    
    $form['cancel'] = array(
        '#type'   => 'markup',
        '#value'  => '<span class="button-wrapper"><span class="button"><span><input type="button" onclick="$(\'#contact-dialog\').dialog(\'close\')" value="Cancel">
        				</span></span></span>',
    	'#button_type' => "button",
    );

    return $form;


}

function best_nests_listing_contact_form_submit($form, &$form_state){
    $listing = node_load($form_state['values']['listing_nid']);
    $user = user_load($listing->uid);
    
    $to = $user->mail;
    $from = $form_state['values']['email'];
    
    //error_log($user->mail);
    
    $body = "Number of nights: " . $form_state['values']['num_nights'] . "<br />" .
            "Phone: " . $form_state['values']['phone'] . "<br />" .
            "Comments" . $form_state['values']['comments'];
    
    $subject = "Listing Contact from The Best Nests"; 
    
    $headers  = 'MIME-Version: 1.0' . "\r\n";
    $headers .= 'Content-type: text/html; charset=iso-8859-1' . "\r\n";
    
    
    //mail($to, $subject, $body, $headers);

    //error_log($body);
    $form_state['redirect'] = "view-listing/" . $form_state['values']['listing_nid'];
    
}


