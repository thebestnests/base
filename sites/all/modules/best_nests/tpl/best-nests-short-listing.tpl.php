<?php $states = best_nests_get_state_options(); ?>
<?php 

$uri = split("/", $_SERVER['REQUEST_URI']); 
if (count($uri) == 4){
	$date = explode("-", $uri[3]);
	$ts = mktime(0,0,0, (int)$date[1], (int)$date[2], (int)$date[0]);
	$date = date("F jS, Y", $ts);
}else{
	$date = date("F jS, Y");
}

?>
<div id="listings-list">
	<!-- admin -->
	<h1 class="title"><?php echo $states[$listings[0]->state]; ?> listings and discounts for <?php echo $date; ?></h1>
<?php if (is_null($listings)) :?>
	<p>There are no listings for this state</p>
</div>
<?php else: ?>
	 
    <div class="listings-list-filter">
        <form method="post" id="filter-form">
            <table><tr>
                <td><input id="listing-filter-min-price" class="listing-filter-text" 
                   type="text" value="min price" onfocus="$(this).val('')" 
                   name="filter_min_price" onchange="tbn.search.shortListingFilter('minPrice', $(this).val())">
                   <a id="min-x" onclick="tbn.search.shortListingFilter('minPrice', 0)">x</a>
                </td>
                <td><input id="listing-filter-max-price" class="listing-filter-text" 
                   type="text" value="max price" onfocus="$(this).val('')" 
                   name="filter_max_price"  onchange="tbn.search.shortListingFilter('maxPrice', $(this).val())">
                   <a id="max-x" onclick="tbn.search.shortListingFilter('maxPrice', 1000000)">x</a>
                </td>
                <td>
                    <select id="listing-filter-beds" class="form-select" name="filter_beds" 
                            onchange="tbn.search.shortListingFilter('beds', $(this).val())">
                        <option selected value="">Bedrooms</option>
                        <!-- <option value="">&lt;Any&gt;</option> -->
                        <option value="1">1</option>
                        <option value="2">2</option>
                        <option value="3">3</option>
                        <option value="4">4</option>
                        <option value="5">5+</option>
                    </select>
                </td>
                <td>
                    <select id="listing-filter-baths" class="form-select" name="filter_baths"
                            onchange="tbn.search.shortListingFilter('baths', $(this).val())">
                        <option selected value="">Baths</option>
                        <!-- <option value="">&lt;Any&gt;</option> -->
                        <option value="1">1</option>
                        <option value="2">2</option>
                        <option value="3">3</option>
                        <option value="4">4</option>
                        <option value="5+">5+</option>
                    </select>
                </td>
                <td>
                    <select id="listing-filter-city" class="form-select" name="filter_city"
                            onchange="tbn.search.shortListingFilter('city', $(this).val())">
                        <option selected value="">City</option>
                        <?php
                        $cities = array();
                        foreach($listings as $listing): 
                            $cities[] = $listing->city;
                        endforeach;
                        $cities = array_unique($cities);
                        ?>
                        
                        <?php foreach ($cities as $city):?>
                        <option><?php echo $city; ?></option>
                        <?php endforeach; ?>
                    </select>
                </td>
                <td>
                    <select id="listing-filter-region" class="form-select" name="filter_region"
                            onchange="tbn.search.shortListingFilter('region', $(this).val())">
                        <option selected value="">Region</option>
                        <?php
                        $regions = array();
                        foreach($listings as $listing): 
                            $regions[] = $listing->region;
                        endforeach;
                        $regions = array_unique($regions);
                        ?>
                        
                        <?php foreach ($regions as $region):?>
                        <option><?php echo $region; ?></option>
                        <?php endforeach; ?>
                    </select>
                </td>

            </tr></table>
            <!--<span class="button-wrapper">
                <span class="button">
                    <span><input type="submit" name="submit" class="form-submit" value="Apply Filter" id="edit-submit-state-listings"></span>
                </span>
            </span>-->
        </form>
	</div>
	



	<!-- Loop through each listing -->
	<?php foreach ($listings as $listing): ?>

    <table class="short-listing-container" beds="<?php echo $listing->beds; ?>"
            baths="<?php echo $listing->baths; ?>"  city="<?php echo $listing->city; ?>"
            price="<?php echo $listing->base_price; ?>" region="<?php echo $listing->region; ?>">
        <tr>
            <td colspan="3"><a class="short-listing-header" href="/view-listing/<?php echo $listing->listing_nid; ?>">
				<?php echo $listing->title; ?>
                </a>
            </td>
        </tr>
        
        <tr class="short-listing-image-container">
            <td rowspan="8">
            	<a href="/view-listing/<?php echo $listing->listing_nid; ?>">	
        			<img class="short-listing-image" 
                     title="<?php echo $listing->title; ?>" 
        			 alt="Image of <?php echo $listing->title; ?>" 
                     src="/sites/default/files/listing_pics/tn/<?php echo $listing->default_image; ?>" />
                </a>
            </td>
  		</tr>
        
        <tr>
			<td class="short-listing-data-label">Base Price:</td>
		    <td class="short-listing-data">$<?php echo $listing->base_price; ?></td>
        </tr>
        <tr>
         	<td class="short-listing-data-label">Bedrooms:</td>
            <td class="short-listing-data"><?php echo $listing->beds; ?></td>
        </tr>
        <tr>
		    <td class="short-listing-data-label">Bathrooms:</td>
		    <td class="short-listing-data"><?php echo $listing->baths; ?></td>
        </tr>
        <tr>
			<td class="short-listing-data-label">City:</td>
			<td class="short-listing-data"><?php echo $listing->city; ?></td>
  		</tr>
        <tr>
			<td class="short-listing-data-label">Region:</td>
			<td class="short-listing-data"><?php echo $listing->region; ?></td>
  		</tr>
        <tr>
			<td class="short-listing-data-label">Today's Discount:</td>
			<td class="short-listing-data red"><strong><?php echo $listing->discount; ?>%<?php echo $listing->discounted_price; ?></strong></td>
  		</tr>


        <tr>
			<td colspan="2" class="short-listing-details"><?php echo $listing->body; ?></td>
        </tr>
		
	</table>
	<?php endforeach; ?>
</div>
<?php endif; ?>
