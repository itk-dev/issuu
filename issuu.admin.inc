<?php

/**
 * Builds the administation menu for this module.
 *
 *
 * @return array
 */
function issuu_admin_settings() {

  $form['issuu'] = array(
    '#type' => 'fieldset',
    '#access' => user_access('administer site configuration'),
    '#title' => t('Issuu basic configuration'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  $form['issuu']['issuu_domain'] = array(
    '#type' => 'textfield',
      '#title' => t('Domain'),
      '#required' => TRUE,
      '#size' => 40,
      '#default_value' => variable_get('issuu_domain', ''),
  );

  $form['issuu']['issuu_guid'] = array(
    '#type' => 'textfield',
      '#title' => t('Guid'),
      '#required' => TRUE,
      '#size' => 40,
      '#default_value' => variable_get('issuu_guid', ''),
  );

  $form['issuu_types'] = array(
    '#type' => 'fieldset',
    '#access' => user_access('administer site configuration'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE
  );

  // Load all node types
  $options = array();
  $types = node_get_types();
  foreach ($types as $key => $obj) {
    if ($obj->has_body) {
      $options[$key] = $obj->name. ' (' .t($obj->description). ')';
    }
  }

  $form['issuu_types']['issuu_selected_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content type to activate issuu on'),
    '#required' => TRUE,
    '#options' => $options,
    '#default_value' => variable_get('issuu_selected_types', array()),
  );

  return system_settings_form($form);
}
