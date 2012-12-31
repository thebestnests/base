<?php 
// $Id: page-front.tpl.php,v 1.1.4.1 2009/05/26 06:21:30 jwolf Exp $ 
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">

  <head>
    <title>The Best Nests :: Vacation Rentals, Rental Property Owners, Cheap vacations, vacation rentals by owners</title>
<meta name="description" content="Find discounted vacation rentals. List your vacation property anywhere in the United States. The site features the best valued cabins, condos, and beach homes. To rent your home list your vacation rental on thebestnests.com." />
<meta name="keywords" content="discounted vacation rental, cheap vacations, beach vacation homes, skiing vacation rental, rent your Bed and Breakfast, how to market your rental home, how to rent your vacation home, last minute vacation rentals" />
<meta name="google-site-verification" content="NnIkdFBW5OPcGxZxgtHytb2fuFCbZNvTw_TGeyyQfFc" />
    <?php print $styles; ?>
    <!--[if IE 7]>
      <?php print $ie7_styles; ?>
    <![endif]-->
    <!--[if lte IE 6]>
      <?php print $ie6_styles; ?>
    <![endif]-->
    <?php if ($local_styles): ?>
    <?php print $local_styles; ?>
    <?php endif; ?>
    <?php print $scripts; ?>
  </head>

  <body class="<?php print $body_classes; ?>">
    <div id="page">
      <?php if ($content): ?>
      <div id="skip">
        <a href="#main-content"><?php print t('Skip to Main Content'); ?></a>
      </div>
      <?php endif; ?>
      <?php if ($banner): ?>
      <div id="banner" class="clearfix">
        <?php print $banner; ?>
      </div><!-- /banner -->
      <?php endif; ?> 
      <?php if ($header_top): ?>
      <div id="header-top" class="clearfix">
        <?php print $header_top; ?>
      </div><!-- /header-top -->
      <?php endif; ?>
      <div id="header-wrapper" class="clearfix">
        <div id="header-first">
          <?php if ($logo): ?> 
          <div id="logo">
            <a href="<?php print check_url($front_page) ?>" title="<?php print t('Home') ?>"><img src="<?php print $logo ?>" alt="<?php print t('Home') ?>" /></a>
          </div>
          <?php endif; ?>
          <?php if ($site_name): ?>
          <h1><a href="<?php print check_url($front_page) ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a></h1>
          <?php endif; ?>
        </div><!-- /header-first -->
        <div id="header-middle">
          <?php if ($site_slogan): ?>
          <div id="slogan">
            <?php print $site_slogan; ?>
          </div>
          <?php endif; ?>
          <?php if ($header_middle): ?>
          <?php print $header_middle; ?>
          <?php endif; ?>
        </div><!-- /header-middle -->
        <div id="search-box">
          <?php print $search_box; ?>
        </div><!-- /search-box -->
      </div><!-- /header-wrapper -->
            <?php if ($primary_links): ?>
        <div id="primary-menu">
          <?php print theme('links', $primary_links); ?>
        </div><!-- /primary_menu -->
      <?php endif; ?>
      <?php if ($preface_sidebar || $mission) : ?>
      <div id="preface-wrapper" class="clearfix" <?php print $banner_image; ?>>
        <?php if ($preface_sidebar): ?>
          <div id="preface-sidebar">
            <?php print $preface_sidebar; ?>
          </div>
        <?php endif; ?>
        <?php if ($mission): ?>
          <div id="mission"> 
            <?php print $mission; ?>
          </div>
        <?php endif; ?>
      </div><!-- /preface-wrapper -->
      <?php endif; ?>
      <div id="main-wrapper" class="clearfix">  
        <?php if ($sidebar_first): ?>
        <div id="sidebar-first">
          <?php print $sidebar_first; ?>
        </div><!-- /sidebar-first -->
        <?php endif; ?>
          <div id="content-wrapper">
          <?php if ($messages): ?>
          <?php print $messages; ?>
          <?php endif; ?>
          <?php if ($help): ?>
          <?php print $help; ?>
          <?php endif; ?>
          <div id="content">
            <a name="main-content" id="main-content"></a>
            <?php if ($tabs): ?>
            <div id="content-tabs" class="clear">
              <?php print $tabs; ?>
            </div>
            <?php endif; ?>
            <?php if ($content || $title): ?>
            <div id="content-inner" class="clear">
              <?php //if ($content): ?>
              <?php //print $content; ?>
              <?php //endif; ?>
              <h2>Welcome to TheBestNests.com, the #1 value-based meeting place for owners of rental properties and people who want to rent terrific locations at the best possible prices.</h2>
<!-- ImageReady Slices (Untitled-1) -->
<img src="/sites/default/files/usa_map.jpg" width="468" height="344" border="0" alt="" usemap="#imagemap_Map">
<map name="imagemap_Map">
<area shape="poly" alt="Rhode Island" coords="445,83, 459,83, 458,94, 446,93" href="/state/rhode island">
<area shape="poly" alt="New Jersey" coords="400,104, 400,111, 402,115, 396,121, 401,126, 405,127, 406,129, 409,120, 408,112, 407,111, 407,108" href="/state/NJ">
<area shape="poly" alt="Hawaii" coords="148,289, 188,301, 180,327, 132,325, 146,290" href="/state/HI">
<area shape="poly" alt="Alaska" coords="60,244, 109,249, 107,272, 131,290, 126,301, 90,295, 77,304, 62,313, 18,320, 12,302, 62,299, 37,287, 35,260, 46,250" href="/state/AK">
<area shape="poly" alt="California" coords="34,89, 64,97, 56,126, 59,131, 90,177, 92,182, 86,192, 86,197, 69,197, 62,196, 46,189, 27,155, 24,108, 24,89" href="/state/CA">
<area shape="poly" alt="Nevada" coords="65,97, 64,98, 57,123, 58,127, 90,174, 91,163, 96,163, 100,152, 107,106, 85,103" href="/state/NV">
<area shape="poly" alt="Oregon" coords="48,47, 54,56, 62,58, 73,61, 81,60, 94,63, 96,67, 88,77, 90,80, 86,102, 34,88, 33,81, 39,71" href="/state/OR">
<area shape="poly" alt="Washington" coords="50,22, 76,21, 100,29, 93,62, 75,59, 66,59, 61,56, 55,56, 52,50, 47,45, 47,22" href="/state/WA">
<area shape="poly" alt="Idaho" coords="133,84, 130,108, 86,102, 91,80, 88,77, 98,68, 94,61, 99,31, 106,32, 105,43, 113,60, 108,70, 116,71, 121,84" href="/state/ID">            
<area shape="poly" alt="Utah" coords="100,156, 137,161, 142,122, 128,121, 127,120, 129,109, 108,106" href="/state/UT">                                                           
<area shape="poly" alt="Arizona" coords="99,156, 138,162, 130,218, 113,217, 85,200, 87,196, 87,191, 91,185, 93,181, 91,175, 92,163, 96,165" href="/state/AR">                 
<area shape="poly" alt="New Mexico" coords="138,163, 185,166, 182,216, 152,213, 151,215, 153,216, 138,216, 140,220, 130,219" href="/state/NM">                             
<area shape="poly" alt="Colorado" coords="138,162, 194,166, 195,127, 193,125, 183,125, 174,126, 143,122" href="/state/CO">                                                   
<area shape="poly" alt="Wyoming" coords="135,81, 128,120, 181,125, 183,85" href="/state/WY">                                                                                  
<area shape="poly" alt="Montana" coords="187,45, 186,33, 107,29, 105,43, 114,60, 109,69, 117,70, 121,82, 134,83, 135,80, 184,85, 186,45" href="/state/MT">                    
<area shape="poly" alt="Texas" coords="185,173, 183,217, 152,214, 155,221, 164,235, 175,254, 190,247, 208,276, 232,286, 243,277, 242,259, 256,251, 261,247, 261,239, 263,230, 257,218, 258,207, 258,204, 255,203, 252,201, 240,201, 229,200, 210,193, 210,174" href="/state/TX">                                                                                    
<area shape="poly" alt="Oklahoma" coords="185,167, 185,172, 211,173, 210,192, 221,196, 235,200, 248,199, 253,199, 253,169, 208,168, 195,169, 194,167" href="/state/OK">      
<area shape="poly" alt="Kansas" coords="195,137, 195,168, 253,167, 252,147, 249,142, 250,139, 247,138" href="/state/KS">                                                       
<area shape="poly" alt="Nebraska" coords="183,106, 181,124, 197,125, 197,136, 247,137, 245,132, 242,130, 241,120, 237,113, 233,108, 226,111, 224,107" href="/state/NE">      
<area shape="poly" alt="South Dakota" coords="185,77, 183,105, 225,106, 226,110, 233,107, 236,111, 238,102, 236,101, 238,83, 235,81, 235,80, 237,78" href="/state/SD">   
<area shape="poly" alt="North Dakota" coords="187,45, 185,76, 237,77, 237,71, 236,69, 233,46, 230,43, 187,43" href="/state/ND">                                          
<area shape="poly" alt="Minnesota" coords="275,101, 237,101, 238,83, 235,80, 238,77, 238,72, 236,67, 234,46, 246,46, 247,41, 259,47, 282,50, 286,53, 282,60, 269,67, 265,71, 266,75, 263,78, 265,89, 275,98" href="/state/MN">
<area shape="poly" alt="Iowa" coords="244,131, 243,124, 238,112, 238,102, 275,102, 281,112, 284,115, 283,119, 280,121, 279,123, 279,127, 277,130" href="/state/IA">
<area shape="poly" alt="Missouri" coords="289,175, 290,175, 293,174, 294,170, 296,170, 296,166, 295,165, 291,159, 287,157, 285,151, 286,149, 282,147, 280,145, 278,142, 275,131, 245,131, 251,138, 250,141, 254,147, 254,171, 289,170, 291,173" href="/state/MO">
<area shape="poly" alt="Arkansas" coords="293,175, 288,175, 290,172, 289,170, 254,172, 254,202, 259,203, 259,207, 282,207, 282,202, 289,184" href="/state/AR">
<area shape="poly" alt="Louisiana" coords="296,227, 296,233, 302,237, 311,244, 296,249, 278,245, 263,244, 262,238, 264,229, 263,226, 260,219, 258,217, 259,208, 281,207, 282,209, 283,217, 280,227" href="/state/LA">
<area shape="poly" alt="Mississippi" coords="308,231, 306,185, 290,186, 282,203, 284,216, 281,226, 297,226, 297,231, 298,234, 302,237, 309,235, 308,230" href="/state/MS">
<area shape="poly" alt="Alabama" coords="316,231, 312,234, 309,232, 307,185, 326,184, 332,204, 334,207, 335,220, 333,222, 326,222, 321,221, 314,224" href="/state/AL">
<area shape="poly" alt="Florida" coords="368,221, 389,253, 389,269, 386,281, 374,286, 368,282, 372,276, 373,269, 362,261, 356,242, 357,240, 348,232, 337,239, 330,233, 318,232, 317,230, 315,224, 324,222, 338,223, 363,225" href="/state/FL">
<area shape="poly" alt="Georgia" coords="328,182, 348,181, 346,184, 370,207, 366,221, 363,224, 338,222, 334,221, 336,220, 335,213, 335,208, 332,204, 332,201, 327,184" href="/state/GA">
<area shape="poly" alt="South Carolina" coords="348,182, 352,179, 365,177, 365,180, 370,179, 379,180, 386,185, 386,189, 382,201, 372,206, 347,183" href="/state/SC">
<area shape="poly" alt="North Carolina" coords="338,181, 358,162, 405,154, 413,164, 402,180, 391,185, 386,184, 377,179, 367,178, 365,179, 365,177, 350,178, 349,180" href="/state/NC">
<area shape="poly" alt="Tennessee" coords="295,171, 289,186, 337,181, 357,162, 342,165, 335,165, 294,171" href="/state/TN">
<area shape="poly" alt="Kentucky" coords="330,143, 346,145, 350,154, 341,164, 296,170, 297,165, 300,164, 301,165, 306,155, 321,152, 329,142, 331,142" href="/state/KY">
<area shape="poly" alt="Ilinois" coords="302,111, 304,116, 307,147, 304,151, 305,156, 302,161, 301,164, 298,163, 296,165, 295,163, 294,163, 293,160, 292,158, 288,157, 286,152, 287,148, 283,147, 282,147, 281,144, 279,143, 276,131, 280,127, 279,123, 283,119, 285,114, 283,113, 282,112" href="/state/IN">
<area shape="poly" alt="Wisconsin" coords="281,70, 277,68, 281,64, 279,63, 272,66, 267,69, 267,75, 263,79, 265,89, 274,97, 276,97, 276,104, 281,111, 301,110, 303,109, 301,102, 302,91, 304,84, 300,84, 299,80, 295,74, 284,72, 282,71" href="/state/WI">
<area shape="poly" alt="Indiana" coords="325,115, 328,143, 320,152, 305,155, 305,151, 307,146, 305,116, 312,115, 324,114" href="/state/IN">
<area shape="poly" alt="Michigan" coords="312,114, 336,112, 342,99, 341,85, 336,81, 330,74, 326,66, 316,62, 309,62, 305,62, 303,57, 295,56, 281,67, 282,69, 282,71, 291,73, 296,74, 300,81, 300,83, 301,83, 304,84, 310,93, 310,98, 313,103, 311,114" href="/state/MI">
<area shape="poly" alt="Ohio" coords="325,114, 329,141, 338,144, 347,144, 358,129, 358,121, 355,107, 347,112, 340,113, 337,112" href="/state/OH">
<area shape="poly" alt="West Virginia" coords="381,129, 377,130, 366,145, 365,151, 356,154, 350,152, 347,147, 351,140, 358,130, 359,126, 362,130, 368,128, 369,133, 380,128" href="/state/WV">
<area shape="poly" alt="Virginia" coords="342,164, 403,154, 397,141, 390,141, 389,140, 388,136, 382,130, 378,130, 369,141, 365,152, 356,155, 352,153" href="/state/VA">
<area shape="rect" alt="Delaware" coords="424, 113, 443, 125" href="/state/DE">
<area shape="poly" alt="Massachusetts" coords="444,72, 463,72, 462,81, 444,81" href="/state/MA">
<area shape="poly" alt="Connecticut" coords="441,97, 444,93, 455,95, 455,104, 440,104" href="/state/CT">
<area shape="poly" alt="New Jersey" coords="434,115, 447,117, 449,105, 434,105" href="/state/NJ">
<area shape="poly" alt="Maryland" coords="417,135, 431,137, 434,131, 434,127, 417,127" href="/state/MD">
<area shape="poly" alt="District of Columbia" coords="409,137, 424,138, 425,147, 414,150, 406,149" href="/state/DC">
<area shape="poly" alt="Maryland" coords="369,132, 381,127, 389,136, 390,140, 396,140, 403,139, 403,135, 401,132, 399,134, 396,132, 396,127, 396,123, 392,123, 369,127" href="/state/MD">
<area shape="poly" alt="Rhode Island" coords="421,93, 424,93, 424,97, 423,98, 422,98" href="/state/RI">
<area shape="poly" alt="Connecticut" coords="407,95, 407,105, 415,101, 421,99, 420,94, 420,93, 417,93" href="/state/CT">
<area shape="poly" alt="Pennsylvania" coords="397,99, 401,115, 396,121, 365,127, 360,127, 355,104, 360,104, 360,109" href="/state/PA">
<area shape="poly" alt="Massachusetts" coords="406,94, 425,92, 425,97, 434,97, 434,88, 425,81, 411,88, 406,87" href="/state/MA">
<area shape="poly" alt="New York" coords="401,68, 388,69, 383,74, 383,81, 379,87, 365,87, 360,100, 362,105, 397,98, 401,104, 411,109, 425,104, 418,100, 411,103, 406,106, 406,81" href="/state/NY">
<area shape="poly" alt="Vermont" coords="407,87, 401,68, 411,61, 411,87" href="/state/VT">
<area shape="poly" alt="New Hampshire" coords="411,87, 413,61, 417,63, 425,81" href="/state/NH">
<area shape="poly" alt="Maine" coords="426,81, 417,60, 422,31, 438,34, 452,56" href="/state/MA">
</map>
<!-- End ImageReady Slices -->
              
<div style="clear:both;"></div>
<div id="front-boxes">
	<div class="fb-left">
    	<h3>For Property Owners:</h3>
        <p>TheBestNests.com offers the best tools in the industry to get property rented quickly and easily. TheBestNests.com provides owners with more control and options on their property profiles than any other rental service. Photos, videos and descriptive copy can be uploaded and revised anytime, day or night…24/7/365. If faster rental or a last-minute rental is desired, an owner can revise their base rental pricing by offering a limited time discount. This discount is immediately noted on TheBestNests.com and that owner's property will move up on the listing page, higher than other properties that are not offering as great a discount. This opportunity for value pricing, when desired, gives total flexibility to the owner…the ability to easily and quickly adjust pricing for real-time market conditions. TheBestNests.com provides the highest quality and flexibility at a significant savings versus competitive rental sites. For information on how to list your properties with TheBestNests.com, please click on "<a href="<?php print $base_path; ?>how-get-started">How to Get Started"</a>.</p>
    </div>
    <div class-"fb-right">
    	<h3>For Renters:</h3>
        <p>TheBestNests.com offers people interested in renting property the ability to achieve the best possible value, whether planning far into the future or deciding on a rental at the last minute. From beautiful photos, informative video and descriptive copy, interested renters can find properties that perfectly fit their needs, and TheBestNests.com also, exclusively, offers renters the opportunity to view and judge properties by the extent of the deal being offered. Renters can easily see those properties that are being offered at potentially significant discounts vs. their base rental prices. Because of this exclusive flexible pricing mechanism, value-oriented renters will love the opportunity to take advantage of high quality rentals offered at deeply discounted rates. To sign up with TheBestNests.com and take the first step toward the rental of your dreams, please click on a state.</p>
    </div>
</div>

              
              
            </div>
            <?php endif; ?>            
            <?php if ($content_bottom): ?>
            <div id="content-bottom">
              <div class="corner top-right"></div>
              <div class="corner top-left"></div>
              <div class="inner">
              <?php print $content_bottom; ?>
              </div>
              <div class="corner bottom-right"></div>
              <div class="corner bottom-left"></div>
            </div><!-- /content-bottom -->
            <?php endif; ?>
          </div><!-- /content -->
        </div><!-- /content-wrapper -->
        <?php if ($sidebar_last): ?>
        <div id="sidebar-last">
          <?php print $sidebar_last; ?>
        </div><!-- /sidebar_last -->
        <?php endif; ?>
      </div><!-- /main-wrapper -->
    </div><!-- /page -->
    <?php if ($postscript_first || $postscript_middle || $postscript_last): ?>
    <div id="postscripts">
      <div id="postscript-wrapper" class="<?php print $postscripts; ?> clearfix">
        <?php if ($postscript_first): ?>
        <div id="postscript-first" class="column">
          <?php print $postscript_first; ?>
        </div><!-- /postscript-first -->
        <?php endif; ?>
        <?php if ($postscript_middle): ?>
        <div id="postscript-middle" class="column">
          <?php print $postscript_middle; ?>
        </div><!-- /postscript-middle -->
        <?php endif; ?>
        <?php if ($postscript_last): ?>
        <div id="postscript-last" class="column">
          <?php print $postscript_last; ?>
        </div><!-- /postscript-last -->
        <?php endif; ?>
      </div><!-- /postscript-wrapper -->
    </div><!-- /postscripts -->
    <?php endif; ?>
    <?php if ($footer || $footer_message): ?>
    <div id="footer" class="clearfix">
      <div id="footer-wrapper">
        <?php if ($footer_message): ?>
        <div id="footer-message">
          <?php print $footer_message; ?>
        </div>
        <?php endif; ?>
        <?php if ($footer) : ?>
          <div id="footer-region">
            <?php print $footer; ?>
          </div>
        <?php endif; ?>
      </div><!-- /footer-wrapper -->
    </div><!-- /footer -->
    <?php endif; ?>
    <?php print $closure; ?>
  </body>
</html>
