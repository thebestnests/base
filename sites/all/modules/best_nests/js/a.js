jQuery(document).ready( function(){
	var path = location.pathname.split('/');
	
	if (path[1] == 'user' && path[2] == 'reset'){
		var date = new Date();
		date.setTime(date.getTime() + 15552000000);
		document.cookie = 'ii-tracker-reset-redirect=true; expires=' + date + '; path=/';
	}
	
	var theCookies = document.cookie;
	if (theCookies.search(';') >= 0){
		theCookies = theCookies.split(';');
	}else{
		theCookies = new Array(theCookies);
	}
	
	jQuery.each(theCookies, function(){
		var separator = this.search('=');
		if (this.substring(0, separator) == 'ii-tracker-reset-redirect'){
			if ($)
			//console.debug(this)
			window.location = "/member-home";
			today = new Date();
			today.setDate(today.getDate() - 1);
			document.cookie = 'ii-tracker-reset-redirect=true; expires=' + today + '; path=/';
		}
	});
	
	
	
	
	
	
	try{
		var val = $('#edit-project option[selected]').val();
		$('#edit-project').val(val);
	}catch(err){}
	
	try{
		$('#edit-title').change( function(){
			if ($('#edit-title').val() == 'ticket status change'){
				$('#edit-ticket-status-wrapper').show();
			}
		});
	}catch(err){}
	

	
	$('#edit-requested-due-date').datepicker({ minDate : 0 });
	$('#est-due-date').datepicker({ minDate : 0 });
	
	
	
	
	
	
	
	
});


function iiTrackerSaveNotify(uid, nid){
	if ($('#notify')[0].checked == true){
		var notify = 1
	}else{
		var notify = 0;
	}
	
	$.ajax({
		'url'		: '/save-notify/',
		'type'		: 'POST',
		'data'		: { 'uid' : uid, 'nid' : nid, 'notify' : notify },
		'success'	: iiTrackerMarkSaved
	});
}

function iiTrackerMarkSaved(){
	$('#notifySaveBtn').hide();
}




