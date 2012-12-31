<?php

function best_nests_check_discount_abuse($discount, $listing_nid, $cal_id){
    //get average discount
    $average_discount = db_result(db_query("SELECT AVG(discount) FROM best_nests_calendar"));

    //when adding a discount period, if the discount being added is greater than 65% or 1.5% of the average
    if ($discount > 65 || $discount > 20 && $discount > ($average_discount * 1.5)){
        //flag the discount and send to administrator for approval.
        
        db_query("UPDATE best_nests_calendar SET abuse_flag=1 WHERE id=$cal_id");

        // notify admin
        best_nests_notify('admin', 'abuse', $listing_nid);
    }

}

function best_nests_notify($to, $subject, $listing_nid){
    $listing = node_load($listing_nid);
    //$to = 'macstruthers@gmail.com';
    $to = 'jpyle@information-interactive.com';
    mail($to, $subject, "suspected abuse. discount period flagged");

}


function best_nests_abuse_list(){
    $abuse_list = best_nests_get_abuse_list();
    return theme('best-nests-abuse-list', $abuse_list);
}

function best_nests_get_abuse_list(){
    $abuse_list_query = db_query("
        SELECT
            l.listing_nid, GROUP_CONCAT(l.city, ', ', l.state) location,
            c.discount, 
            n.title, n.uid,
            u.name
        FROM
            best_nests_listings l,
            best_nests_calendar c,
            node n,
            users u
        WHERE
            c.abuse_flag=1 AND
            c.listing_nid = l.listing_nid AND
            n.nid = c.listing_nid AND
            u.uid = n.uid
        GROUP BY
            c.listing_nid, c.discount
        ORDER BY
            c.listing_nid
        ");

    $abuse_list = array();

    while ($row = db_fetch_object($abuse_list_query)){
        $row->avg = db_result(db_query("SELECT ROUND(AVG(discount)) FROM best_nests_calendar WHERE listing_nid IN
                (SELECT nid FROM node WHERE uid=$row->uid)"));
        
        $abuse_list[] = $row;
    }

    return $abuse_list;
}



function best_nests_approve_discount($listing_nid, $discount){
	db_query("INSERT INTO best_nests_abuse_tracking (uid, listing_nid, discount, date)
        VALUES ($uid, $listing_nid, $discount, $date)");
    db_query("UPDATE best_nests_calendar SET abuse_flag=0 WHERE listing_nid=$listing_nid AND discount=$discount");
    header("Location: /abuse-list");
}

function best_nests_deny_discount($listing_nid, $discount){
    db_query("DELETE FROM best_nests_calendar WHERE listing_nid=$listing_nid AND discount=$discount");

    $uid = db_result(db_query("SELECT uid FROM node WHERE nid=$listing_nid"));
    $date = Date("Ymd");
    db_query("INSERT INTO best_nests_abuse_tracking (uid, listing_nid, discount, date)
        VALUES ($uid, $listing_nid, $discount, $date)");
    
    header("Location: /abuse-list");
}


function best_nests_get_abuse_history($uid){
	$result = db_query("
		SELECT 
			t.listing_nid, t.discount, DATE_FORMAT(t.date, '%m-%%d-%Y') date, n.title 
		FROM 
			best_nests_abuse_tracking t, node n 
		WHERE 
			n.nid=t.listing_nid AND
			t.uid = $uid
	");
	$history = array();
	while ($row = db_fetch_object($result)){
		$history[] = $row;
	}

	echo theme('best-nests-abuse-history', $history);
}







?>