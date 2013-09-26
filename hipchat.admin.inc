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

  return system_settings_form($form);
}
