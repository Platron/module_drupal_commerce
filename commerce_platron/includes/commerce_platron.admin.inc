<?php

/**
 * Payment method callback: settings form.
 */
function commerce_platron_settings_form($settings = NULL) {
	$form = array();

	$settings = (array) $settings + array(
		'merchant_id'		=> '',
		'secret_key'		=> '',
		'lifetime'			=> '0',
		'demo_mode'			=> '1',
		'logo_url'			=> 'http://platron.ru/images/logo.png',
		'description'		=> 'Description',
		'success_message'	=> 'Thank you for payment',
		'fail_message'		=> 'Payment failed',
		'create_ofd_check'	=> '0',
		'ofd_vat_type'		=> '',
	);

	$form['merchant_id'] = array(
		'#type' => 'textfield',
		'#title' => t('Merchant id'),
		'#description' => t('See at <a href="http://platron.ru/admin/merchants.php">platron admin path merchants</a>'),
		'#default_value' => $settings['merchant_id'],
	);

	$form['secret_key'] = array(
		'#type' => 'textfield',
		'#title' => t('Secret key'),
		'#description' => t('See at <a href="http://platron.ru/admin/merchants.php">platron admin path merchants</a>'),
		'#default_value' => $settings['secret_key'],
	);

	$form['lifetime'] = array(
		'#type' => 'textfield',
		'#title' => t('Life time'),
		'#description' => t('To payment systems which not use check request. Set in minute. 0 - not used. Max 7 days'),
		'#default_value' => $settings['lifetime'],
	);

	$form['demo_mode'] = array(
		'#type' => 'checkbox',
		'#title' => t('Demo mode'),
		'#default_value' => $settings['demo_mode'],
	);

	$form['logo_url'] = array(
		'#type' => 'textfield',
		'#title' => t('Url to logo'),
		'#description' => t('Set it to show user'),
		'#default_value' => $settings['logo_url'],
	);

	$form['description'] = array(
		'#type' => 'textfield',
		'#title' => t('Description to user'),
		'#description' => t('Set it to show user'),
		'#default_value' => $settings['description'],
	);

	$form['success_message'] = array(
		'#type' => 'textarea',
		'#rows' => 3,
		'#title' => t('Success message'),
		'#description' => t('Enter optional text that will be displayed when payment succesful'),
		'#default_value' => $settings['success_message'],
	);

	$form['fail_message'] = array(
		'#type' => 'textarea',
		'#rows' => 3,
		'#title' => t('Fail message'),
		'#description' => t('Enter optional text that will be displayed when payment fail'),
		'#default_value' => $settings['fail_message'],
	);

	$form['create_ofd_check'] = array(
		'#type' => 'checkbox',
		'#title' => t('Create check for OFD'),
		'#description' => t('Should system send check to OFD'),
		'#default_value' => $settings['create_ofd_check'],
	);

	$options = array(
                  '0' => '0%',
                  '10' => '10%',
                  '20' => '20%',
                  '110' => '10/110',
                  '120' => '20/120',
		  'none' => 'Не облагается',
	);

	$form['ofd_vat_type'] = array(
	    '#type' => 'select',
    	'#title' => t('VAT type for OFD'),
	    '#description' => t('Specify the VAT type for items.'),
	    '#options' => $options,
		'#default_value' => $settings['ofd_vat_type'],
	);

	$form['#submit'][] = variable_set('commerce_platron_settings', $form);

	return $form;
}
