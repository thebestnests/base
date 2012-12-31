<div id="long-listing-container">
<input type="hidden" id="listing-nid" value="<?php echo $listing->nid ?>" />
<input type="hidden" id="is-listing-owner" value="<?php echo $listing->is_owner; ?>">
    <div id="long-listing-top">
    
	    <div id="long-listing-details-new">
		    <h1 class="title"><?php echo $listing->title; ?></h1>
		    <p>
		    	<?php echo $listing->beds; ?> Bedrooms, <?php echo $listing->baths; ?> Baths Located in <?php echo $listing->city; ?>, <?php echo $listing->state; ?> <?php echo $listing->zip; ?>
		    </p>
		    
		     <div id="short-listing-data-description">
		        <!-- <span id="listing-details" class="short-listing-data-label">Property Description</span> -->
		        <h3>Property Description</h3>
		        <p name="details"><?php echo $listing->body; ?></p>
		    </div> 
	    
	    	<ul>
	    	    <li>
	                <span class="long-listing-data-label">Rental Price/night: </span>
	                $<?php echo $listing->discounted_price ?> (<?php echo $listing->discount?>%)
	            </li>
	            <li>
	                <span class="long-listing-data-label">Cleaning Fee:</span>
	                $<?php echo $listing->cleaning_fee; ?>
	            </li>
	            <li>
	                <span class="long-listing-data-label">Minimum Stay:</span>
	                <?php echo $listing->minimum_stay; ?>
	            </li>
	    
	    	</ul>
	    </div>
    
	   
      
	    <div id="long-listing-images">
	       <img class="long-listing-large-image" title="<?php echo $listings->title; ?>"
	            alt="Image of <?php echo $listings->title; ?>" src="/sites/default/files/listing_pics/full/<?php echo $listing->default_image; ?>" />
	        <hr />
	        <div id="long-listing-image-container">
	        <?php foreach ($listing->images as $image): 
	        	if (!$image->is_default): ?>
	        	<a href="/sites/default/files/listing_pics/full/<?php echo $image->filename; ?>">
	            	<img class="long-listing-image-tn" title="<?php echo $listings->title; ?>"
	                alt="Image of <?php echo $listings->title; ?>" src="/sites/default/files/listing_pics/tn/<?php echo $image->filename; ?>" />
	        	</a>
	        	<?php endif;
	        endforeach; ?>
	        </div>
	    </div>
    </div>
    
    <div id="long-listing-calendars-div">
	    <h3>Availability & Discounts</h3>
	    <div class="calmonth-wrapper">
	        <span class="key-color discount"></span><span class="key-label">Discount Available</span>
	        <!-- <span class="key-color available"></span><span class="key-label">Available</span> -->
	        <span class="key-color fully-booked"></span><span class="key-label">Fully Booked</span>
	        <span class="key-color provisionally-booked"></span><span class="key-label">Provisionally booked</span>
	    </div>
	    <div id="long-listing-calendars">
	        <?php echo $calendars; ?>
	        
	    </div>
    </div>
    
    
    
    <div id="contact-dialog">
    <?php echo drupal_get_form('best_nests_listing_contact_form', $listing->nid); ?>
    </div>
    
    <div id="youtube-dialog">
        <?php echo $listing->youtube_link; ?>
    </div>
    
    <?php if ($listing->website): ?>
    <a id="website" href="<?php echo $listing->website; ?>"></a>
    <?php endif; ?>
     
</div>
