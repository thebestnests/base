<table id="my-listings-table">
    <tr>
        <th>Title</th>
        <th>Beds/Baths</th>
        <th>Location</th>
    </tr>
    
    <?php foreach ($listings as $listing): ?>
    <tr>
        <td><a href="/edit-listing/<?php echo $listing->nid; ?>"><?php echo $listing->title; ?></a></td>
        <td><?php echo "$listing->beds/$listing->baths"; ?></td>
        <td><?php echo "$listing->city, $listing->state"; ?></td>
    </tr>
    <?php endforeach; ?>
</table>
