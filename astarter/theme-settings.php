<?php

/**
 * @file
 * Theme setting callbacks for the starter theme.
 */

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form. The arguments
 *   that drupal_get_form() was originally called with are available in the
 *   array $form_state['build_info']['args'].
 * @param $form_id
 *   String representing the name of the form itself. Typically this is the
 *   name of the function that generated the form.
 *
 * @see hook_form_FORM_ID_alter()
 * @see hook_form_alter()
 */
function astarter_form_system_theme_settings_alter(&$form, FormStateInterface $form_state) {

  // Create the form using Forms API.
  $form['themedev'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Theme development settings'),
    '#weight'        => -1,
  );
  $form['themedev']['astarter_debug_css_grid'] = array(
    '#group'         => 'verticalTabs',
    '#type'          => 'checkbox',
    '#title'         => t('Debug CSS rythm and grid'),
    '#default_value' => theme_get_setting('astarter_debug_css_grid'),
    '#description'   => t('Display rythm and grid overlay (Only admin).'),
  );
}
