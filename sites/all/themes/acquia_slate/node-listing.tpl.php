<?php 
// $Id: node.tpl.php,v 1.1 2009/02/28 23:33:58 jwolf Exp $ 
?>

<!-- start node.tpl.php -->
<div id="node-<?php print $node->nid; ?>" class="node <?php print $node_classes; ?>">
  <?php print $picture ?>

  <?php if ($page == 0): ?>
  <h2 class="title"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
  <?php endif; ?>
  
  <?php if ($terms): ?>
  <div class="terms">
    <?php print $terms; ?>
  </div>
  <?php endif;?>
  
  <div class="content">
  	<div id="listing-top">
    	<div class="lt-left">
        	<?php print $node->field_main_image[0]['view'] ?>
            <hr />
        	<?php $viewName = 'listing_images'; print views_embed_view($viewName); ?>
        </div>
    	<div class="lt-mid">
        	<ul>
            	<li>Bedrooms: <strong><?php print $node->field_bedrooms[0]['view'] ?></strong></li>
                <li>Bathrooms: <strong><?php print $node->field_bathrooms[0]['view'] ?></strong></li>
                <li>City: <strong><?php print $node->field_city[0]['view'] ?></strong></li>
                <li>State: <strong><?php print $node->field_state[0]['view'] ?></strong></li>
                <li>Rental Price/night: <strong><?php print $node->field_base_price[0]['view'] ?></strong></li>
                <li>Cleaning Fee: <strong><?php print $node->field_cleaning_fee[0]['view'] ?></strong></li>
                <li>Minimum Night Stay: <strong><?php print $node->field_miminum_night_stay[0]['view'] ?></strong></li>
                <?php if ($node->field_website[0]['view']): ?><li>Website: <strong><?php print $node->field_website[0]['view'] ?></strong></li><?php endif; ?>
            </ul>
        </div>
    	<div class="lt-right">
        	<h2>Booking Form</h2>
            <?php print drupal_get_form('email_example_form'); ?>
        </div>
  	<div id="listing-mid">
    	<div class="lm-left">
        	<h3>Property Description</h3>
        	<?php print $node->field_property_description[0]['view'] ?>
            <?php if ($node->field_youtube_video[0]['view']): ?>
				<hr /><?php print $node->field_youtube_video[0]['view'] ?>
            <?php endif; ?>
        </div>
    	<div class="lm-right">
        	<p><a href="#availability"><strong>Click Here for Availability Calendar</strong></a></p>
            <br />
            <?php //$viewName = 'discount_calendar_block'; print views_embed_view($viewName); ?>
            <?php print $discount_calendar; ?>
        </div>
    </div>
  	<div id="listing-bottom">
    </div>
    <div id="availability">
        <h3>Availability Calendar</h3>
    	<?php print $node->content['availability_calendars']['#value'] ?>
    </div>
    </div>
    <?php //print $content ?>
  </div>
  
  <?php if ($links): ?>
  <div class="links">
    <div class="corner top-right"></div>
    <div class="corner top-left"></div>
    <div class="inner">
      <?php print $links; ?>
    </div>
    <div class="corner bottom-right"></div>
    <div class="corner bottom-left"></div>
  </div>
  <?php endif; ?>

  <?php if ($node_bottom && !$teaser): ?>
  <div id="node-bottom">
    <?php print $node_bottom; ?>
  </div>
  <?php endif; ?>
</div>
<!-- /#node-<?php print $node->nid; ?> -->
