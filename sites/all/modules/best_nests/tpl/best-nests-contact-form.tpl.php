<form id="contact-mail-page" method="post" accept-charset="UTF-8">
	<div>You can leave a message using the contact form below.
		<div id="edit-name-wrapper" class="form-item">
			<label for="edit-name">Your name: <span title="This field is required." class="form-required">*</span></label>
			<input type="text" class="form-text required" value="" size="60" id="edit-name" name="name" maxlength="255">
		</div>
		
		<div id="edit-mail-wrapper" class="form-item">
			<label for="edit-mail">Your e-mail address: <span title="This field is required." class="form-required">*</span></label>
			<input type="text" class="form-text required" value="" size="60" id="edit-mail" name="email" maxlength="255">
		</div>
		
		<div id="edit-subject-wrapper" class="form-item">
			<label for="edit-subject">Subject: <span title="This field is required." class="form-required">*</span></label>
			<input type="text" class="form-text required" value="" size="60" id="edit-subject" name="subject" maxlength="255">
		</div>
		
		<div id="edit-cid-wrapper" class="form-item">
			<label for="edit-cid">Category: <span title="This field is required." class="form-required">*</span></label>
			<select id="edit-cid" class="form-select required" name="cid">
				<option value="General Information">General Information</option>
				<option selected="selected" value="Support">Support</option>
			</select>
		</div>
		
		<div id="edit-message-wrapper" class="form-item">
			<label for="edit-message">Message: <span title="This field is required." class="form-required">*</span></label>
			<div class="resizable-textarea">
				<span>
					<textarea class="form-textarea resizable required  textarea-processed" id="edit-message" name="message" rows="5" cols="60"></textarea>
					<div class="grippie" style="margin-right: -6px;"></div>
				</span>
			</div>
		</div>

		<label for="edit-copy" class="option">
			<input type="checkbox" class="form-checkbox" value="1" id="edit-copy" name="copy"> 
			Send yourself a copy.
		</label>
	</div>
	<p>
		<span class="button-wrapper">
			<span class="button">
				<span>
					<input type="submit" class="form-submit" value="Send e-mail" id="edit-submit" name="submit">
				</span>
			</span>
		</span>
	</p>
</form>
