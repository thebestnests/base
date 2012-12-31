<table>
	<tr>
		<th>Listing Title</th>
		<th>Date</th>
		<th>Discount</th>
	</tr>
	<?php foreach ($history as $abuse): ?>
	<tr>
		<td><?php echo $abuse->title; ?></td>
		<td><?php echo $abuse->date; ?></td>
		<td><?php echo $abuse->discount; ?></td>
	</tr>
	<?php endforeach; ?>
</table>