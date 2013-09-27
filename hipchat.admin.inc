<?php

/*
 * @file
 * Admin settings form for the module
 */


/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function hipchat_admin_settings($form, &$form_state) {
  $form = array();

  $form['hipchat_token'] = array(
    '#type' => 'textfield',
    '#title' => 'HipChat token',
    '#required' => TRUE,
    '#default_value' => variable_get('hipchat_token'),
    '#description' => t('Get an Admin API token from !hipchat_link', array('!hipchat_link' => l(t('your HipChat admin page'), 'https://www.hipchat.com/group_admin/api'))),
    
  );

  $form['hipchat_default_room'] = array(
    '#type' => 'textfield',
    '#title' => t('HipChat default room'),
    '#description' => t('Enter the default room to send notices. Enter the human name, not the room id'),
    '#default_value' => variable_get('hipchat_default_room'),
  );
  
  $form['hipchat_message_color'] = array(
    '#type' => 'select',
    '#title' => t('Select color'),
    '#options' => array(
      'yellow' => t('Yellow'),
      'red' => t('Red'),
      'green' => t('Green'),
      'purple' => t('Purple'),
      'gray' => t('Gray'),
    ),
   '#description' => t('Select color on message sent to room'),
   '#default_value' => variable_get('hipchat_message_color'),
  );


  /* 
   * Fetch all node types, 
   * 
  */

  $nodetypes = node_type_get_names();

  foreach ($nodetypes as $key => $value) {
    $form[$key] = array(
      '#type' => 'fieldset', 
      '#title' => t('Choose how ' . $value . ' should behave'), 
      '#weight' => 5, 
      '#collapsible' => TRUE, 
      '#collapsed' => TRUE,
    );

    $form[$key]['hipchat_' . $key . '_insert'] = array(
      '#type' => 'checkbox',
      '#title' => 'Act on ' . t($key) . ' insert',
      '#return_value' => 1,
      '#default_value' => variable_get('hipchat_' . $key . '_insert'),
    );

    $form[$key]['hipchat_' . $key . '_update'] = array(
      '#type' => 'checkbox',
      '#title' => 'Act on ' . t($key) . ' update',
      '#return_value' => 1,
      '#default_value' => variable_get('hipchat_' . $key . '_update'),
    );

    $form[$key]['hipchat_' . $key . '_delete'] = array(
      '#type' => 'checkbox',
      '#title' => 'Act on ' . t($key) . ' delete',
      '#return_value' => 1,
      '#default_value' => variable_get('hipchat_' . $key . '_delete'),
    );

    $form[$key]['hipchat_' . $key . '_comment_insert'] = array(
      '#type' => 'checkbox',
      '#title' => 'Act on ' . t($key) . ' comment insert',
      '#return_value' => 1,
      '#default_value' => variable_get('hipchat_' . $key . '_comment_insert'),
    );

    $form[$key]['hipchat_' . $key . '_comment_update'] = array(
      '#type' => 'checkbox',
      '#title' => 'Act on ' . t($key) . ' comment update',
      '#return_value' => 1,
      '#default_value' => variable_get('hipchat_' . $key . '_comment_update'),
    );

    $form[$key]['hipchat_' . $key . '_comment_delete'] = array(
      '#type' => 'checkbox',
      '#title' => 'Act on ' . t($key) . ' comment delete',
      '#return_value' => 1,
      '#default_value' => variable_get('hipchat_' . $key . '_comment_delete'),
    );    
  }

  $form['hipchat_message_markup'] = array(
    '#markup' => '<div id="message_div"></div>',
    '#weight' => 18,
  );

  // Find token and room and if set enable button and allow user to send test message.
  $token = variable_get('hipchat_token');
  $room = variable_get('hipchat_default_room');
  $form['hipchat_send_test_message'] = array(
    '#type' => 'button',
    '#value' => t('Send test message'),
    '#disabled' => (!empty($token) && !empty($room) ? FALSE : TRUE),
    '#ajax' => array(
      'callback' => 'hipchat_send_test_message',
    ),
    '#weight' => 19,
  );

  return system_settings_form($form);
}

// Ajax callback to send testmessage, might be usefull to actually return error code
function hipchat_send_test_message(&$form, $form_state) {

  $send = hipchat_send('Testmessage');
  
  if ($send == TRUE ) {
    return array(
      '#type' => 'ajax',
      '#commands' => array(
        ajax_command_replace("#message_div", '<em>Test message success</em><br />'),
      )
    );

  } 
  else {  
    return array(
      '#type' => 'ajax',
      '#commands' => array(
        ajax_command_replace("#message_div", '<em>Test message failed</em><br />'),
      )
    );

  }
  
}
