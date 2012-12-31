<?php

function best_nests_paypal_ipn_listener(){
    $return = "fail";
    
    $email = $_GET['ipn_email'];
    $header = "";
    $emailtext = "";
    
    // Read the post from PayPal and add 'cmd'
    $req = 'cmd=_notify-validate';
    if(function_exists('get_magic_quotes_gpc')){
        $get_magic_quotes_exists = true;
    }
    
    foreach ($_POST as $key => $value){
        // Handle escape characters, which depends on setting of magic quotes

        if($get_magic_quotes_exists == true && get_magic_quotes_gpc() == 1){
            $value = urlencode(stripslashes($value));
        } else {
            $value = urlencode($value);
        }
        
        $req .= "&$key=$value";
    }
    
    // Post back to PayPal to validate
    $header .= "POST /cgi-bin/webscr HTTP/1.0\r\n";
    $header .= "Content-Type: application/x-www-form-urlencoded\r\n";
    $header .= "Content-Length: " . strlen($req) . "\r\n\r\n";
    $fp = fsockopen ('ssl://www.paypal.com', 443, $errno, $errstr, 30);

    // Process validation from PayPal
    // TODO: This sample does not test the HTTP response code. All
    // HTTP response codes must be handles or you should use an HTTP
    // library, such as cUrl
    if (!$fp) { 
        // HTTP ERROR
        mail('support@information-interactive.com', 'Best Nests Paypal Connection Error', $errstr);
    
    } else {
        // NO HTTP ERROR
        
    	
    	
    	
        //page 23
        
        fputs ($fp, $header . $req);
    
        while (!feof($fp)) {
            $res = fgets ($fp, 1024);
            if (strcmp ($res, "VERIFIED") == 0) {
            // TODO:
            // Check the payment_status is Completed
            // Check that txn_id has not been previously processed
            // Check that receiver_email is your Primary PayPal email
            // Check that payment_amount/payment_currency are correct
            // Process payment
            // If 'VERIFIED', send an email of IPN variables and values to the
            // specified email address
				db_query("INSERT into best_nests_ipn_messages (item, status, txn_type, post)
						VALUES ('%s', '%s', '%s')",
						$_POST['item_name'], $_POST['payment_status'], $_POST['txn_type'], serialize($_POST));
            	
            	
                $return = "<pre>" . print_r($_POST, 1) . "</pre>";
                
                error_log(print_r($_POST, 1));
                
                if ($_POST['payment_status']  == "Completed"){
                    $nid = split("# ", $_POST['item_name']);   
		    		db_query("UPDATE {best_nests_listings} SET paid = 1 WHERE listing_nid = {$nid[1]}");
                   // send email to the lister notifying them their listing is live 
                }elseif($_POST['txn_type'] == 'subscr_cancel'){
                	$nid = split("# ", $_POST['item_name']);  
                	db_query("UPDATE {best_nests_listings} SET paid = 0 WHERE listing_nid = {$nid[1]}");
                	
                }
                /*foreach ($_POST as $key => $value){
                    $emailtext .= $key . " = " .$value ."\n\n";
                    
                   //error_log($key . " : " . $value);
                }*/

                
            } else if (strcmp ($res, "INVALID") == 0) {
                // If 'INVALID', send an email. TODO: Log for manual investigation.
                foreach ($_POST as $key => $value){
                    $emailtext .= $key . " = " .$value ."\n\n";
                }

                mail($email, "Live-INVALID IPN", $emailtext . "\n\n" . $req);
            }
        }
    }
    
    fclose ($fp);
    
    return "test"; //$return;
}
?>
