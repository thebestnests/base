<table>
    <thead>
        <tr>
            <th id="abuse-user">User</th>
            <th id="abuse-title">Title</th>
            <th id="abuse-location">Location</th>
            <th id="abuse-discount">Discount</th>
            <th id="abuse-avg">Avg</th>
            <th id="abuse-actions"></th>
        </tr>
    </thead>
    <tbody>
        <?php foreach($abuse_list as $listing): ?>
        <tr>
            <td><?php echo $listing->name; ?></td>
            <td><?php echo $listing->title; ?></td>
            <td><?php echo $listing->location; ?></td>
            <td><?php echo $listing->discount; ?></td>
            <td><?php echo $listing->avg; ?></td>
            <td>
                <a href="/approve-discount/<?php echo $listing->listing_nid . "/" . $listing->discount; ?>">approve</a>
                <a href="/deny-discount/<?php echo $listing->listing_nid . "/" . $listing->discount; ?>">deny</a>
                <a onclick="tbn.getAbuseHistory(<?php echo $listing->uid; ?>)">view abuse history</a>
            </td>
        </tr>
        <?php endforeach; ?>
    </tbody>
</table>

<div id="view-abuse-history-dialog"></div>