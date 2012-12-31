var tbn = {};

jQuery(document).ready( function(){
	$('body').append('<div id="add-image-dlg"></div>');
	$('body').append('<div id="update-success">Your data has been saved.</div>');
	
	
	$('#from-date').datepicker({minDate : 0, dateFormat: 'yy-mm-dd'});
	$('#to-date').datepicker({minDate : 0, dateFormat: 'yy-mm-dd'});
    $('#edit-from-availability').datepicker({minDate : 0, dateFormat: 'yy-mm-dd'});
    $('#edit-to-availability').datepicker({minDate : 0, dateFormat: 'yy-mm-dd'});
    $('#edit-from-discount').datepicker({minDate : 0, dateFormat: 'yy-mm-dd'});
    $('#edit-to-discount').datepicker({minDate : 0, dateFormat: 'yy-mm-dd'});
    //$('#filter-form')[0].reset();
    
    
    $('#block-discount-search').datepicker({minDate :0, dateFormat: 'yy-mm-dd'});
    

    if (location.pathname.substr(1).split('/')[0] == "edit-listing" || location.pathname.substr(1).split('/')[0] == "create-listing"){
    	tbn.getListingImageForm($('#listing-nid').val());
        
        $("div#add-image-dlg").dialog({
		autoOpen : false,
		title: 'Add Image',
		width: 420,
		height: 300,
		modal : true,
		show: 'fade',
		hide: 'fade',
		buttons: {
			"Add Image" : function() { $('#p-loading-image').show(); $('#edit-submit').click();},
			"Cancel": function() {$(this).dialog("close");}}
	});
    }
    
	
	
	
	$('#update-success').dialog({
		autoOpen : false,
		title: 'Update Success',
		modal: true,
		buttons: {"Ok": function() {$(this).dialog("close");}}
	});
	
	$('#view-abuse-history-dialog').dialog({
		autoOpen : false,
		title: 'Abuse History',
		width: 600,
		height: 300,
		buttons: {"Ok": function() {$(this).dialog("close");}}
	});
	
	$('#cancel-dialog').dialog({
		autoOpen : false,
		title: 'Cancel Listings',
		buttons: {"Ok": function() {$(this).dialog("close");}},
		show: "fade",
		hide: "fade"
	});
	
	$('#contact-dialog').dialog({
		autoOpen : false,
		title: 'Contact Lister',
		width: 500,
		modal: true,
		show: "fade",
		hide: "fade"
	});
    
	$('#youtube-help').dialog({
		autoOpen : false,
		title: 'YouTube Help',
		width: 700,
		modal: true,
		show: "fade",
		hide: "fade"
	});
	
    $('#long-listing-image-container a').lightBox({
		imageLoading: '/sites/default/files/lightbox/loading.gif',
		imageBtnClose: '/sites/default/files/lightbox/close.gif',
		imageBtnPrev: '/sites/default/files/lightbox/prev.gif',
		imageBtnNext: '/sites/default/files/lightbox/next.gif'
    });
    
    try{ 
        $('#listing-state').val($('#listing-state')[0].getAttribute("stateval"));
    }catch(e){} 
    
    
    
    $('#block-menu-menu-listing-menu ul').append('<li class="leaf"><a href="#" onclick="$(\'#contact-dialog\').dialog(\'open\')">Contact Lister</a></li>');
    if ($('#youtube-dialog').length > 0){
    	$('#block-menu-menu-listing-menu ul').append('<li class="leaf"><a href="#" onclick="$(\'#youtube-dialog\').dialog(\'open\')">Watch Video</a></li>');
    	$('#youtube-dialog').dialog({
    		autoOpen : false,
    		title: 'Listing Video',
    		width: 350,
    		modal: true,
    		show: "fade",
    		hide: "fade"
    	});
    }
    
    if ($('#website').length > 0){
    	var website = $('#website')[0].href;
    	$('#block-menu-menu-listing-menu ul').append('<li class="leaf"><a target="_blank" href="' + website + '">Visit Website</a></li>');
    }
    
    
    isListingOwner = $('#is-listing-owner').val();
    page = location.pathname.substr(1).split('/')[0]; 
    if (isListingOwner == 'true'){
    	if (page == 'edit-listing'){
    		$('#block-menu-tbn-lister ul').append('<li class="leaf"><a href="/view-listing/' + $('#listing-nid').val() + '">View Listing</a></li>');
    	}else if(page == 'view-listing'){
    		$('#block-menu-tbn-lister ul').append('<li class="leaf"><a href="/edit-listing/' + $('#listing-nid').val() + '">Edit Listing</a></li>');
    	}else{
    		
    	}
    }
    
    //$('#block-menu-menu-listing-menu ul').append('<li><a href="#" onlick="$(\'#contact-dialog\').dialog(\'open\')">Contact Lister</a></li>;');
    
    
    $('#calendar-periods select').val(0);
    
    /* Google Code for Visited Home Page Remarketing List */
    if (location.pathname == "/"){
    	
    	
    	    	
    	var google_conversion_id = 1019880095;
    	var google_conversion_language = "en";
    	var google_conversion_format = "3";
    	var google_conversion_color = "666666";
    	var google_conversion_label = "EtP6CPmQugIQn8Wo5gM";
    	var google_conversion_value = 0;
    	
    	
    	var fileref=document.createElement('script');
    	fileref.setAttribute("type","text/javascript");
    	fileref.setAttribute("src", "http://www.googleadservices.com/pagead/conversion.js");
    	
    	//<script type="text/javascript" src="http://www.googleadservices.com/pagead/conversion.js">
    	//</script>
    	
    	/*
    	<noscript>
    	<div style="display:inline;">
    	<img height="1" width="1" style="border-style:none;" alt="" src="http://www.googleadservices.com/pagead/conversion/1019880095/?label=EtP6CPmQugIQn8Wo5gM&amp;guid=ON&amp;script=0"/>
    	</div>
    	</noscript>
    	*/
    }
    
    
    
    
});


tbn.getListingImageForm = function(listing_nid){
	$.ajax({
		url : '/get-listing-image-form/' + listing_nid,
		dataType : 'html',
		success : function(txt){
			$('div#add-image-dlg').append(txt);
		}
	});
};

tbn.addCalendarPeriod = function(){
	if ($('#from-date').val().length > 0){
		if ($("input[name=type]:checked").val() == 'discount' && $('#discount').val().length == 0){
			alert("Please enter a discount");
		}else{
			var data = {
					discount: $("#discount").val(),
					listing_nid: $("#listing-nid").val(),
			        type: $("input[name=type]:checked").val().substring(0,1)
				};
				
				data.from = $('#from-date').val();
				
				if ($('#to-date').val().length == 0){
					data.to = $('#from-date').val();
				}else{
					data.to = $('#to-date').val();
				}
			
			$.ajax({
				url : '/check-calendar-period/' + data.from + '/' + data.to + '/' + data.type + '/' + data.listing_nid,
				success : function(txt){
					if (txt == '0'){
						$.ajax({
							url : '/add-calendar-period',
							type : 'post',
							data : data,
							success : function(){
					            $('#from-date').val('');
					            $('#to-date').val('');
					            $("#discount").val('');
					            window.location.reload();
							}
						});
					}else{
						alert('Error: The selected day has already been added');
					}
					
				}
			});
		}
	}else{
		alert("Please Select a Start Date");
	}
};


tbn.editListingDetails = function(){
	data = {
        title		: $("#listing-title").val(),
        body		: $("#listing-details-ta").val(),
		base_price 	: $("#listing-base-price").val(),
		beds		: $("#listing-beds").val(),
		baths		: $("#listing-baths").val(),
		city		: $("#listing-city").val(),
		state		: $("#listing-state").val(),
		region		: $("#listing-region").val(),
		zip			: $("#listing-zip").val(),
		listing_nid : $("#listing-nid").val(),
        cleaning_fee: $("#listing-cleaning-fee").val(),
        minimum_stay: $("#listing-minimum-stay").val(),
        website     : $("#listing-website").val(),
        youtube_link: $("#listing-youtube-link").val()
        
	};
	
	$.ajax({
		url : '/update-listing',
		type : 'post',
		data : data,
		success : function(){
			$('#update-success').dialog("open");
		}
	});
	
};

tbn.disableListing = function(id){
	$.ajax({
		url : '/toggle-listing/' + id + "/" + $("#listing-status-change-to").val(),
		success : function(txt){
			if (txt == '0'){
				$("#listing-status-change-to").val('1');
				$("#disabled-span").html("Listing is disabled");
			}else{
				$("#listing-status-change-to").val('0');
				$("#disabled-span").html("");
			}
		}
	});
};


/*
function bnAddRntalPeriod(){
	// create the hidden field for form submittal
	var from = $('#from-date').val().split('/');
	from = Math.round((new Date(from[2], from[0], from[1])).getTime() / 1000);
	
	var to = $('#to-date').val().split('/');
	to = Math.round((new Date(to[2], to[0], to[1])).getTime() / 1000);
	
	var discount = $('#discount').val();
	var val = from + '|' + to + '|' + discount;
	var add = '<input type="hidden" name="rental_periods[]" value="' + val + '" />';
	
	$('#best-nests-create-listing-form').append(add);
	
	
	// now create the row in the table so they can see the rental period they just created
	var row = "<tr><td>" + $("#from-date").val() + "</td><td>" + $("#to-date").val() + "</td><td>" +
	"" + $("#discount").val() + "</td></tr>";
	$('#rental-periods-table').append(row);
}
*/

tbn.deleteImages = function(){
    data = {
		listing_nid : $("#listing-nid").val(),
        filenames : Array()
	};
    
    var images = $('#long-listing-image-container img.image-selected');
    images.each( function(){
        src = this.src.split('/');
        data.filenames.push("'" + src[src.length-1] + "'");
    });
    
    data.filenames = data.filenames.join(',');
	$.ajax({
		url : '/delete-images',
		type : 'post',
		data : data,
		success : function(){
            //$('#long-listing-image-container img.image-selected').remove();
			window.location.reload();
        }
	});
};

tbn.setDefaultImage = function(){
    var id = $('#long-listing-image-container img.image-selected')[0].id;
    
	$.ajax({
		url : '/set-default-image/' + id + "/" + $("#listing-nid").val(),
		success : function(){
            $('#long-listing-image-container img.default-image').removeClass('default-image');
            var img = $('#long-listing-image-container img.image-selected');
            img.removeClass('image-selected');
            img.addClass('default-image');
            
            
        }
	});
};

tbn.selectImage = function(element){
    element = $(element);
    if (element.hasClass("image-selected")){
        element.removeClass("image-selected");
    }else{
        element.addClass("image-selected");
    };
};

tbn.selectRow = function(element){
    element = $(element);
    if (element.hasClass("row-selected")){
        element.removeClass("row-selected");
    }else{
        element.addClass("row-selected");
    }
};

tbn.deleteCalendarPeriod = function(id){
    data = {
		id : id
	};
    
    $.ajax({
		url : '/delete-calendar-period/' + id,
		success : function(){
            window.location.reload();
        }
	});
};

tbn.changeCalendarPeriodType= function(id, val){
    if (val != "Update Status"){
        if (val == "Available"){
        	tbn.deleteCalendarPeriod(id);
        }else{
	        $.ajax({
	            url : "/change-availability-status/" + id + "/" +  val,
	            success : function(){
	            	window.location.reload();
	            }
	        });
        }
    }
};

tbn.sendListingContact = function(){
    var data = {
        email:          $('#long-listing-email-address').val(),
        arrival_date :  $('#long-listing-arrival-date').val(),
        num_nights :    $('#long-listing-number-of-nights').val(),
        phone:          $('#long-listing-home-phone').val(),
        comments:       $('#long-listing-comments').val(),
        listing_nid:    $('#listing-nid').val()
    };
    
     $.ajax({
            url : '/listing-contact',
            type : 'post',
            data : data,
            success : function(){
                
            }
        });
};








tbn.search = {};
tbn.search.vals = { beds : "", baths : "", city : "", minPrice : "0", maxPrice : "1000000" };


tbn.search.shortListingFilter = function(type, val){
    // for ease, hide all the elements for a nanosecond
    $('table.short-listing-container').hide();
    
    // add the filter to the those entered
    tbn.search.vals[type] = val;
    
    // loop through the entered filter values and create the css attribute selector
    var attributes = "";
    jQuery.each(tbn.search.vals, function(index, value){   
        if (index != "minPrice" && index != "maxPrice" && value.length > 0){
            attributes += "[" + index + '="' + value + '"]';
        }
    });
    
    // select elements base on existing filters
    var listings = $('table.short-listing-container' + attributes);

    // loop through the elements(listing containers) and process
    listings.filter(function(){
       
       // get the base price of this particular listing and cast. not casting 
       // has unpredictable results
       var listingPrice =  parseInt( $(this)[0].getAttribute('price') ); 

       // kick out those that do not meet price criteria
       return listingPrice >= parseInt(tbn.search.vals.minPrice) && 
              listingPrice <= parseInt(tbn.search.vals.maxPrice);
       
       // finally, show what's left (those that meet the minimum price)
    }).show();
    
    if (tbn.search.vals.minPrice != 0){
    	$('#min-x').show();
    }else{
    	$('#listing-filter-min-price').val('min price');
    	$('#min-x').hide();
    }
    
    if (tbn.search.vals.maxPrice != 1000000){
    	$('#max-x').show();
    }else{
    	$('#listing-filter-max-price').val('max price');
    	$('#max-x').hide();
    }
    
};


tbn.blockDiscountSearch = function(){
    date = $('#block-discount-search').val();
    path = window.location.pathname.split("/");
    if (path[1] == 'state'){
        state = path[2];
    }
        
    console.debug(path);    
    window.location = "/state/" + state + "/" + date;
};


tbn.getAbuseHistory = function(id){
	 $.ajax({
         url : '/admin/abuse-history/' + id,
         success : function(txt){
        	 $('#view-abuse-history-dialog').html(txt);
        	 $('#view-abuse-history-dialog').dialog('open');
         }
     });
	
};

tbn.validateImageForm = function(){
	if ($('#edit-listing-image').val().length == 0){
		$('#image-message').show();
		return false;
	}else{
		return true;
	}
	return false;
};


tbn.periodTypeChecks = function(){
	if ($("input[name=type]:checked").val() == "discount"){
		$('#discount')[0].disabled = false;
	}else{
		$('#discount')[0].disabled = true;
	}
};