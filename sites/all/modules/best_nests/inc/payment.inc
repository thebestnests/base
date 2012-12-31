<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

function best_nests_checkout($type){
    return theme('best-nests-checkout', $type);
}

function best_nests_subscription_pay(){
    return theme('best_nests_checkout', 'subscription');
}

function best_nests_order_complete(){
	return '
<!-- Google Code for Pay for Listing Conversion Page -->
<script type="text/javascript">
var google_conversion_id = 1019880095;
var google_conversion_language = "en";
var google_conversion_format = "1";
var google_conversion_color = "ffffff";
var google_conversion_label = "DeUPCIGQugIQn8Wo5gM";
var google_conversion_value = 15;
</script>

<script type="text/javascript" src="http://www.googleadservices.com/pagead/conversion.js"></script>

<noscript>
<div style="display:inline;">
<img height="1" width="1" style="border-style:none;" alt="" src="http://www.googleadservices.com/pagead/conversion/1019880095/?value=15&amp;label=DeUPCIGQugIQn8Wo5gM&amp;guid=ON&amp;script=0"/>
</div>
</noscript>

<!-- Google Code for Purchased a Listing -->
<!-- Remarketing tags may not be associated with personally identifiable information or placed on pages related to sensitive categories. For instructions on adding this tag and more information on the above requirements, read the setup guide: google.com/ads/remarketingsetup -->
<script type="text/javascript">
var google_conversion_id = 1019880095;
var google_conversion_label = "reBeCOGiugIQn8Wo5gM";
var google_custom_params = window.google_tag_params;
var google_remarketing_only = true;
</script>

<script type="text/javascript" src="//www.googleadservices.com/pagead/conversion.js"></script>

<noscript>
<div style="display:inline;">
<img height="1" width="1" style="border-style:none;" alt="" src="//googleads.g.doubleclick.net/pagead/viewthroughconversion/1019880095/?value=0&amp;label=reBeCOGiugIQn8Wo5gM&amp;guid=ON&amp;script=0"/>
</div>
</noscript>

<p>Order Complete</p>';
}

function best_nests_order_cancel(){
	return "your order has been canceled";
}


?>
