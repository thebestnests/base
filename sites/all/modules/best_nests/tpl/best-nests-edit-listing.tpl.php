<div id="long-listing-container">
	<input type="hidden" id="listing-nid" value="<?php echo $listing->nid ?>" />
	<input type="hidden" id="listing-status-change-to" value="0">
	<input type="hidden" id="is-listing-owner" value="<?php echo $listing->is_owner; ?>"> 
	<h3><?php echo $listing->title; ?></h3>
	<fieldset id="long-listing-details">
	  <legend>Details</legend>
	  <table id="long-listing-table">
          <tr>
              <td>Title</td>
              <td colspan="8"><input type="text" id="listing-title" value="<?php echo $listing->title; ?>" /></td>
          </tr>
		<tr>
		  <td>Base Price:</td>
		  <td>$<input type="text" id="listing-base-price" value="<?php echo $listing->base_price; ?>" /></td>
	  	
	  	  <td>Bedrooms:</td>
		  <td><input type="text" id="listing-beds" value="<?php echo $listing->beds; ?>" /></td>  
	  
		  <td>City/State/Zip:</td>
		  <td>
		  	<input type="text" id="listing-city" class="longer" value="<?php echo $listing->city; ?>" />
          </td>
          <td colspan="2">
		  	<select class="tripState" id="listing-state" name="dstate" stateval="<?php echo $listing->state; ?>">
                    <option value="AL">Alabama</option> 
                    <option value="AK">Alaska</option> 
                    <option value="AZ">Arizona</option> 
                    <option value="AR">Arkansas</option> 
                    <option value="CA">California</option> 
                    <option value="CO">Colorado</option> 
                    <option value="CT">Connecticut</option> 
                    <option value="DE">Delaware</option> 
                    <option value="DC">D.C.</option> 
                    <option value="FL">Florida</option> 
                    <option value="GA">Georgia</option> 
                    <option value="HI">Hawaii</option> 
                    <option value="ID">Idaho</option> 
                    <option value="IL">Illinois</option> 
                    <option value="IN">Indiana</option> 
                    <option value="IA">Iowa</option> 
                    <option value="KS">Kansas</option> 
                    <option value="KY">Kentucky</option> 
                    <option value="LA">Louisiana</option> 
                    <option value="ME">Maine</option> 
                    <option value="MD">Maryland</option> 
                    <option value="MA">Massachusetts</option> 
                    <option value="MI">Michigan</option> 
                    <option value="MN">Minnesota</option> 
                    <option value="MS">Mississippi</option> 
                    <option value="MO">Missouri</option> 
                    <option value="MT">Montana</option> 
                    <option value="NE">Nebraska</option> 
                    <option value="NV">Nevada</option> 
                    <option value="NH">New Hampshire</option> 
                    <option value="NJ">New Jersey</option> 
                    <option value="NM">New Mexico</option> 
                    <option value="NY">New York</option> 
                    <option value="NC">North Carolina</option> 
                    <option value="ND">North Dakota</option> 
                    <option value="OH">Ohio</option> 
                    <option value="OK">Oklahoma</option> 
                    <option value="OR">Oregon</option> 
                    <option value="PA">Pennsylvania</option> 
                    <option value="RI">Rhode Island</option> 
                    <option value="SC">South Carolina</option> 
                    <option value="SD">South Dakota</option> 
                    <option value="TN">Tennessee</option> 
                    <option value="TX">Texas</option> 
                    <option value="UT">Utah</option> 
                    <option value="VT">Vermont</option> 
                    <option value="VA">Virginia</option> 
                    <option value="WA">Washington</option> 
                    <option value="WV">West Virginia</option> 
                    <option value="WI">Wisconsin</option> 
                    <option value="WY">Wyoming</option>
                </select>
                <input type="text" id="listing-zip" value="<?php echo $listing->zip; ?>" /> 
		  </td>		  
         

			
		</tr>
		<tr>
		  <td>Cleaning Fee:</td>
		  <td>$<input type="text" id="listing-cleaning-fee" value="<?php echo $listing->cleaning_fee; ?>" /></td>	
		
		  <td>Bathrooms:</td>
		  <td><input type="text" id="listing-baths" value="<?php echo $listing->baths; ?>" /></td>
          
		  <td>Minimum Stay:</td>
		  <td><input type="text" id="listing-minimum-stay" value="<?php echo $listing->minimum_stay; ?>" /></td>
          
           <td>Region:</td>
		  <td><input type="text" id="listing-region" class="longer" value="<?php echo $listing->region; ?>" /></td>
        </tr>
        <tr>
		  <td>Website:</td>
		  <td colspan="3"><input type="text" id="listing-website" class="longer" value="<?php echo $listing->website; ?>" /></td>
          
          <td>Youtube Video:</td>
		  <td colspan="3">
		  	<textarea cols="50" id="listing-youtube-link" class="longer"><?php echo $listing->youtube_link; ?></textarea>
		  	<img onclick="$('#youtube-help').dialog('open')" style="cursor: pointer" src="/sites/default/files/help.jpg">
		  </td>
          
          
	    </tr>
	    
	  </table>
	  
	  <p class="short-listing-data-description">
	    <span id="edit-listing-details" class="short-listing-data-label">Details:</span>
		<textarea name="details" id="listing-details-ta"><?php echo $listing->body; ?></textarea>
	  </p>
	  
<!-- 	  
      <form action="https://www.paypal.com/cgi-bin/webscr" method="post">
<input type="hidden" name="cmd" value="_s-xclick">
<input type="hidden" name="hosted_button_id" value="FJJE7ZFU9YM78">
<input type="hidden" name="item_name" value="Best Nests Listing # <?php echo $listing->nid; ?>">
<input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_subscribeCC_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
<img alt="" border="0" src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1" height="1">
</form>

-->
      
      
      
      
      
      
    <span class="button-wrapper">
		<span class="button">
			<span><input type="button" value="Save Changes" onclick="tbn.editListingDetails()"></span>
		</span>
	</span>  
      
      <form action="https://www.paypal.com/cgi-bin/webscr" method="post" style="display: inline">
<input type="hidden" name="cmd" value="_s-xclick">
<input type="hidden" name="hosted_button_id" value="FW5UWSZPUEUQ6">
<input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_subscribeCC_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
<img alt="" border="0" src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1" height="1">
</form>

    <span class="button-wrapper">
		<span class="button">
			<span><input type="button" value="Cancel Subscription" onclick="$('#cancel-dialog').dialog('open')"></span>
		</span>
	</span>
	

	<!-- 
	 <span class="button-wrapper">
		<span class="button">
			<span><input type="button" value="Disable" onclick="tbn.disableListing(<?php echo $listing->nid?>)"></span>
		</span>
	</span>  
      -->
	  
  	   <!--
	  
        <form action="https://www.paypal.com/cgi-bin/webscr" method="post">
             <span class="button-wrapper" id="save-listing-details-btn">
                    <span class="button">
                        <span>
                          <input type="button" id="edit-details-btn" onclick="tbn.editListingDetails()" value="Save Changes" />
                        </span>
                    </span>
                </span>
            <?php if ($listing->paid == 0): ?>
            <input type="hidden" name="cmd" value="_s-xclick">
            <input type="hidden" name="hosted_button_id" value="FW5UWSZPUEUQ6">
            <input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_subscribeCC_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
            <img alt="" border="0" src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1" height="1">
            <?php endif; ?>
        </form>

      -->

   
	</fieldset>
	
	<fieldset id="long-listing-pictures">
		<legend>Images</legend>	
  		<div id="long-listing-image-container">
            <p><span id="default-image-key"></span> = default image</p>
  			<?php foreach ($listing->images as $image): ?>
        	<img class="long-listing-image <?php if ($image->is_default) echo "default-image"; ?>"
                 title="<?php echo $listings->title; ?>" onclick="tbn.selectImage(this)" id="<?php echo $image->fid; ?>" 
        		 alt="Image of <?php echo $listings->title; ?>" src="/sites/default/files/listing_pics/tn/<?php echo $image->filename; ?>" />
        	
        	<?php endforeach; ?>
  		</div>
  		
  		<p>
  	      <span class="button-wrapper">
			<span class="button">
				<span>
	  			  <input id="add-image-btn" type="button" onclick="$('div#add-image-dlg').dialog('open')" value="Add Image" />
		  		</span>
			</span>
		  </span>
          <span class="button-wrapper">
			<span class="button">
				<span>
	  			  <input id="delete-image-btn" type="button" onclick="tbn.deleteImages()" value="Delete Selected Images" />
		  		</span>
			</span>
		  </span>  
          <span class="button-wrapper">
			<span class="button">
				<span>
	  			  <input id="set-default-image-btn" type="button" onclick="tbn.setDefaultImage()" value="Set as Default Image" />
		  		</span>
			</span>
		  </span>  
                 
	    </p>
	</fieldset>
	
  	<fieldset id="calendar-periods">
  		<legend>Availability and Discount Periods</legend>	
            <h4 class="periods-header">Discounts <span class="pending-approval">(pending approval in red)</span></h4>
	  		<table id="discounts-table" class="calendar-table">
				<tr>
					<th>From</th>
					<th>To</th>
					<th>Discount</th>
					<th>Discounted Price</th>
					<th></th>
				</tr>
			
				<?php foreach ($listing->discount as $discount_period): ?>
				<tr <?php if ($discount_period->abuse_flag == 1) echo 'class="red"';?>>
					<td class="period-col2"><?php echo $discount_period->from_date; ?></td>
					<td class="period-col2"><?php echo $discount_period->to_date; ?></td>
                    <td class="period-col3"><?php echo $discount_period->discount; ?>%</td>
                    <td class="period-col4">$<?php echo $listing->base_price * (1 - ($discount_period->discount * .01)); ?></td>
                    <td class="period-col5">
                    	<a onclick="tbn.deleteCalendarPeriod(<?php echo $discount_period->id; ?>)">remove</a>
                    </td>
                </tr>   
				<?php endforeach; ?>
			</table>
            
            
            <h4 class="periods-header">Availability <span class="pending-approval">(pending approval in red)</span></h4>
            <table id="availability-table" class="calendar-table">
				<tr>
					<th>From</th>
					<th>To</th>
                    <th>Status</th>
                    <th></th>
				</tr>
			<?php foreach ($listing->bookings as $booking): ?>
				<tr>
					<td class="period-col2"><?php echo $booking->from_date; ?></td>
					<td class="period-col2"><?php echo $booking->to_date; ?></td>
                    <td class="period-col3"><?php echo $booking->type; ?></td>
                    <td class="period-col4">
                    	<select onchange="tbn.changeCalendarPeriodType(<?php echo $booking->id; ?>, $(this).val())">
                    		<option>Update Status</option>
                    		<option>Available</option>
                    		<option>Fully Booked</option>
                    		<option>Provisionally Booked</option>
                    	</select>
                </tr>   
				<?php endforeach; ?>
			</table>
			
			<p id="add-period-container">
                 <h4 class="periods-header">Add Period</h4>
				<label for="from-date">From Date: <span class="red">*</span> </label><input style="border: 1px solid black" type="text" id="from-date" name="from-date" /><br />
				<label for="to-date">To Date: </label><input style="border: 1px solid black"  type="text" id="to-date" name="to-date" /><br />
				<label for="discount">Discount: </label><input style="border: 1px solid black"  type="text" id="discount" name="discount" /> (% as a whole number)<br />
                <label>Type: </label>
                <input style="border: 1px solid black"  onchange="tbn.periodTypeChecks()" type="radio" name="type" checked value="discount" /> <label for="type">Discount </label>
                <input style="border: 1px solid black"  onchange="tbn.periodTypeChecks()" type="radio" name="type" value="fully-booked" /> <label class="type-label" for="type">Fully Booked </label>
                <input style="border: 1px solid black"  onchange="tbn.periodTypeChecks()" type="radio" name="type" value="provisionally-booked" /> <label class="type-label" for="type">Provisionally Booked </label>                
				<p>
		  	      <span class="button-wrapper">
					<span class="button">
						<span>
							<input type="button" onclick="tbn.addCalendarPeriod()" value="Add Period" id="add-rental-period-button" />
						</span>
					</span>
		  		  </span>
                  
                  <span class="button-wrapper">
					<span class="button">
						<span>
							<input type="button" onclick="tbn.deleteCalendarPeriod()" value="Delete Selected Periods" id="delete-rental-period-button" />
						</span>
					</span>
		  		  </span>
	    		</p>
		 	</p>
			
  	</fieldset>
  	

</div>


<div id="cancel-dialog">
To cancel this listing:
<ul>
    <li>Log in to your PayPal account.</li>
    <li>Click Profile near the top of the page.</li>
    <li>Click My money under My Profile.</li>
    <li>Click the agreements you want to view in the My preapproved payments section.</li> 
</ul>
</div>

<div id="youtube-help" style="display: none">
<p>First, on the page viewing your video, click "Share" at the top of the video player. A window will open showing image below. 
Copy the text in the large circle and paste into the youtube field on the listing form. 
Optionally make sure to uncheck the box in the smaller circle.</p>
<img src="/sites/default/files/youtube.png">

</div>