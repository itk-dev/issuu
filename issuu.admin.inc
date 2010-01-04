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
      '#required' => FALSE,
      '#size' => 40,
      '#default_value' => variable_get('issuu_domain', ''),
  );

  $form['issuu']['issuu_guid'] = array(
    '#type' => 'textfield',
      '#title' => t('Guid'),
      '#required' => FALSE,
      '#size' => 40,
      '#default_value' => variable_get('issuu_guid', ''),
  );


  return system_settings_form($form);
}
