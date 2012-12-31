<?php


function best_nests_menu() { 
	// Primary Links
	
	$items['contact-us'] = array(
		'title' 	=> 'Contact Us',
        'page callback' 	=> 'best_nests_contact_form',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_NORMAL_ITEM,
    	'menu_name'			=> 'primary-links',
	);
	
    $items['search'] = array(
		'title' 	=> 'Advanced Search',
        'page callback' 	=> 'best_nests_search',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_NORMAL_ITEM,
    	'menu_name'			=> 'primary-links',
	); 
    
	$items['my-account'] = array(
		'title' 	=> 'My Account',
        'page callback' 	=> 'best_nests_my_account',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_NORMAL_ITEM,
    	'menu_name'			=> 'primary-links',
	);
	
	// Listing Menu

	
	$items['create-listing'] = array(
		'title' 			=> 'Create Listing',
		'page callback' 	=> 'best_nests_create_listing',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_NORMAL_ITEM,
		'menu_name'			=> 'tbn-lister',
	);
	
	// Lister Menu
	$items['create-listing'] = array(
		'title' 			=> 'Create Listing',
		'page callback' 	=> 'best_nests_create_listing',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_NORMAL_ITEM,
		'menu_name'			=> 'tbn-lister',
	);

	$items['my-listings'] = array(
	    'title' 			=> 'My Listings',
	    'page callback' 	=> 'best_nests_my_listings',
	    'access arguments' 	=> array('best_nests_listing'),
	    'type'				=> MENU_NORMAL_ITEM,
		'menu_name'			=> 'tbn-lister',
	);
	
 
	
	
    $items['search-results'] = array(
		'page callback' 	=> 'Search Results',
        'page callback' 	=> 'best_nests_search_results',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
    
	
	$items['state'] = array(
	    'page callback' 	=> 'best_nests_state_listings',
	    'access arguments' 	=> array('access content'),
	    'type'				=> MENU_CALLBACK,
	);
	
	
	$items['view-listing'] = array(
		'page callback' 	=> 'best_nests_view_listing',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK,
	);
	
    $items['get-listing-image-form'] = array(
		'title' 			=> '',
		'page callback' 	=> 'best_nests_get_listing_image_form',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);

	$items['add-calendar-period'] = array(
		'title' 			=> '',
		'page callback' 	=> 'best_nests_add_calendar_period',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
	
	$items['update-listing'] = array(
		'title' 			=> '',
		'page callback' 	=> 'best_nests_update_listing',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);

    $items['edit-listing'] = array(
		'title' 			=> 'Edit Listing',
		'page callback' 	=> 'best_nests_edit_listing',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
	
	$items['delete-images'] = array(
		'page callback' 	=> 'best_nests_delete_images',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);  
    
    $items['set-default-image'] = array(
		'page callback' 	=> 'best_nests_set_default_image',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
    
	$items['check-calendar-period'] = array(
		'page callback' => 'best_nests_check_calendar_period',
		'access arguments' => array('access content'),
		'type'	=> MENU_CALLBACK,
	);
	
    $items['delete-calendar-period'] = array(
		'page callback' 	=> 'best_nests_delete_calendar_period',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);  
    
    $items['change-availability-status'] = array(
		'page callback' 	=> 'best_nests_change_availability_status',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
    
    $items['listing-contact'] = array(
		'page callback' 	=> 'best_nests_listing_contact',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
    
    $items['checkout'] = array(
		'page callback' 	=> 'best_nests_checkout',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
    
    $items['geoencode'] = array(
		'page callback' 	=> 'best_nests_geoencode',
		'access arguments' 	=> array('access content'),
		'type'				=> MENU_CALLBACK
	);
        
    $items['pplistener'] = array(
        'title' => 'Utility',
        'page callback' => 'best_nests_paypal_ipn_listener',
        'access arguments' => array('access content'),
        'type' => MENU_CALLBACK
    );



    $items['admin/import'] = array(
        'title' => 'Import/Utility',
        'page callback'     => 'import_listings',
        'access arguments'  => array('access admin'),
        'type'              => MENU_NORMAL_ITEM
    );

    $items['admin/import/delete-imported'] = array(
        'title' => 'Delete Imported',
        'page callback'     => 'delete_imported_listings',
        'access arguments'  => array('access admin'),
        'type'              => MENU_NORMAL_ITEM
    );

    $items['admin/import/import-images'] = array(
        'title' => 'Import Images',
        'page callback'     => 'import_images',
        'access arguments'  => array('access admin'),
        'type'              => MENU_NORMAL_ITEM
    );

    $items['admin/import/import-discounts'] = array(
        'title' => 'Import Discounts',
        'page callback'     => 'import_discounts',
        'access arguments'  => array('access admin'),
        'type'              => MENU_NORMAL_ITEM
    ); 

    $items['admin/import/admin/utility'] = array(
        'title' => 'Utility',
        'title'             => 'Utility',
        'page callback'     => 'best_nests_utility',
        'access arguments'  => array('access admin'),
        'type'              => MENU_NORMAL_ITEM
    );


    $items['approve-discount'] = array(
        'page callback' => 'best_nests_approve_discount',
        'access arguments' => array('best_nests_admin'),
        'type' => MENU_CALLBACK
    );

    $items['deny-discount'] = array(
        'page callback' => 'best_nests_deny_discount',
        'access arguments' => array('best_nests_admin'),
        'type' => MENU_CALLBACK
    );
    
    $items['abuse-list'] = array(
        'page callback' => 'best_nests_abuse_list',
        'access arguments' => array('best_nests_admin'),
        'type' => MENU_NORMAL_ITEM,
    	'menu_name' => 'tbn-admin',
    	'title' => 'Abuse List',
    );
    
    $items['admin/abuse-history'] = array(
        'page callback' => 'best_nests_get_abuse_history',
        'access arguments' => array('best_nests_admin'),
        'type' => MENU_CALLBACK
    );
    
    $items['order-complete'] = array(
        'page callback' => 'best_nests_order_complete',
        'access arguments' => array('access content'),
        'type' => MENU_CALLBACK
    );
    
    $items['order-cancel'] = array(
        'page callback' => 'best_nests_order_cancel',
        'access arguments' => array('access content'),
        'type' => MENU_CALLBACK
    );
    
    $items['toggle-listing'] = array(
    	'page callback' => "best_nests_toggle_listing",
    	'access arguments' => array('access content'),
    	'type' => MENU_CALLBACK,
    );
    
    return $items;
}
