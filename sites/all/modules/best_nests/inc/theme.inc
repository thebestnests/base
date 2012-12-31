<?php


function best_nests_theme($existing, $type, $theme, $path) {
	return array(
	    'best-nests-short-listing' => array(
			'template'	=> 'best-nests-short-listing',
	    	'arguments' => array('listings' => NULL),
			'path'		=> drupal_get_path('module', 'best_nests') . '/tpl',
		),
		
		'best-nests-edit-listing' => array(
			'template'	=> 'best-nests-edit-listing',
	    	'arguments' => array('listing' => NULL),
			'path'		=> drupal_get_path('module', 'best_nests') . '/tpl',
		),
        
        'best-nests-long-listing' => array(
			'template'	=> 'best-nests-long-listing',
	    	'arguments' => array('listing' => NULL, 'calendars' => NULL),
			'path'		=> drupal_get_path('module', 'best_nests') . '/tpl',
		),
        
        'best-nests-my-listings' => array(
			'template'	=> 'best-nests-my-listings',
	    	'arguments' => array('listings' => NULL),
			'path'		=> drupal_get_path('module', 'best_nests') . '/tpl',
		),
        'best-nests-checkout' => array(
			'template'	=> 'best-nests-checkout',
	    	'arguments' => array('type' => NULL),
			'path'		=> drupal_get_path('module', 'best_nests') . '/tpl',
		),
        
        'best-nests-search-results' => array(
			'template'	=> 'best-nests-search-results',
	    	'arguments' => array('listings' => NULL, 'dates' => NULL, 'radius' => NULL, 'num_fields' => NULL),
			'path'		=> drupal_get_path('module', 'best_nests') . '/tpl',
		),

        'best-nests-abuse-list' => array(
            'template'  => 'best-nests-abuse-list',
            'arguments' => array('abuse_list' => NULL),
            'path'      => drupal_get_path('module', 'best_nests') . '/tpl',
        ),
        'best-nests-abuse-history' => array(
            'template'  => 'best-nests-abuse-history',
            'arguments' => array('history' => NULL),
            'path'      => drupal_get_path('module', 'best_nests') . '/tpl',
        ),
        'best-nests-success' => array(
            'template'  => 'best-nests-success',
            'path'      => drupal_get_path('module', 'best_nests') . '/tpl',
        ),
        'best-nests-contact-form' => array(
            'template'  => 'best-nests-contact-form',
            'path'      => drupal_get_path('module', 'best_nests') . '/tpl',
        ),
	);
}