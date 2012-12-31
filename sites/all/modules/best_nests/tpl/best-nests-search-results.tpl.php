<pre><?php //var_dump($listings); ?></pre>

<?php $states = best_nests_get_state_options(); ?>

<div id="listings-list">
	<!-- admin -->
	<h1 class="title"><?php echo $states[$listings[0]->state]; ?></h1>

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
                </td>
                <td><input id="listing-filter-min-price" class="listing-filter-text" 
                   type="text" value="max price" onfocus="$(this).val('')" 
                   name="filter_max_price"  onchange="tbn.search.shortListingFilter('maxPrice', $(this).val())">
                </td>
                </tr>
                <tr>
                <td>
                    <select id="listing-filter-beds" class="form-select" name="filter_beds" 
                            onchange="tbn.search.shortListingFilter('beds', $(this).val())">
                        <option selected value="">Bedrooms</option>
                        <option value="">&lt;Any&gt;</option>
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
                        <option value="">&lt;Any&gt;</option>
                        <option value="1">1</option>
                        <option value="2">2</option>
                        <option value="3">3</option>
                        <option value="4">4</option>
                        <option value="5+">5+</option>
                    </select>
                </td>
                </tr>
                <tr>
                <td>
                    <select id="listing-filter-city" class="form-select" name="filter_city"
                            onchange="tbn.search.shortListingFilter('city', $(this).val())">
                        <option selected value="%">City</option>
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
                        <option selected value="%">Region</option>
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
                <td>
                    <select id="listing-filter-state" class="form-select" name="filter_state"
                            onchange="tbn.search.shortListingFilter('state', $(this).val())">
                        <option selected value="%">State</option>
                        <?php
                        foreach($listings as $listing): 
                            $states[] = $listing->state;
                        endforeach;
                        $states = array_unique($states);
                        ?>
                        
                        <?php foreach ($states as $states):?>
                        <option><?php echo $states; ?></option>
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
            <td colspan="3"><a class="short-listing-header" href="/view-listing/<?php echo $listing->nid; ?>">
				<?php echo $listing->title; ?>
                </a>
            </td>
            
            <td colspan="1" class="short-listing-data-label red match-percent"><?php echo round($listing->match_count / $num_fields, 2) * 100 ?>% Match</td>
                
        </tr>
        
        <tr class="short-listing-image-container">
            <td rowspan="10">
                <a href="/view-listing/<?php echo $listing->nid; ?>">	
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
         	<td class="short-listing-data-label">Bedrooms/Baths:</td>
            <td class="short-listing-data"><?php echo "$listing->beds/$listing->baths"; ?></td>
        </tr>
        <tr>
			<td class="short-listing-data-label">City/State:</td>
			<td class="short-listing-data"><?php echo "$listing->city/$listing->state"; ?></td>
  		</tr>
        <tr>
			<td class="short-listing-data-label">Region:</td>
			<td class="short-listing-data"><?php echo $listing->region; ?></td>
  		</tr>
        
        
        
        
        <?php if (array_key_exists($listing->nid, $radius)): ?>
        <tr>
			<td class="short-listing-data-label">Distance:</td>
			<td class="short-listing-data"><?php echo $radius[$listing->nid]; ?> miles</td>
  		</tr>
        <?php endif; ?>
        
        <?php if (array_key_exists($listing->nid, $dates['discount'])) : ?>
        <tr>
			<td colspan="2" class="short-listing-data-label">Discounts exists for days searched!</td>
  		</tr>
        <?php endif; ?>
        
        <?php if (array_key_exists($listing->nid, $dates['availability'])) : ?>
        <tr>
			<td colspan="2" class="short-listing-data-label">Property is available during for days searched!</td>
  		</tr>
        <?php endif; ?>
        
        


        <tr>
			<td colspan="2" class="short-listing-details"><?php echo $listing->body; ?></td>
        </tr>
		
	</table>
	<?php endforeach; ?>
</div>
<?php endif; ?>
