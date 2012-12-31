<?php
// $Id: block.tpl.php,v 1.1.4.1 2009/06/13 10:51:09 jwolf Exp $
?>
<!-- start block.tpl.php -->
<div class="block-wrapper <?php print $block_zebra; ?>">

      
        <div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="block block-<?php print $block->module ?>">
          <?php if ($block->subject): ?>
          <?php $firstword = acquia_slate_wordlimit($block->subject, 1, "");
          $block->subject = str_replace($firstword, "<span class=\"first-word\">" . $firstword . "</span>", $block->subject); ?>
          <h2 class="title block-title"><?php print $block->subject ?></h2>
          <?php endif;?>
          <div class="content">
            <?php print $block->content ?>
          </div>
        </div>
  
  
</div>
<!-- /end block.tpl.php -->