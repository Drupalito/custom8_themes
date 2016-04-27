<?php

/**
 * @file
 * Contains a pre-process hook for 'page'.
 */

/**
 * Implements hook_preprocess_page().
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_page(&$variables) {

  $variables['main_prefix'] = array();
  $variables['main_suffix'] = array();

  // Enable logo module for display logo.
  $variables['site_logo'] = module_exists('logo') ? theme('logo') : NULL

  // If is page node article.
  if (isset($variables['node']->nid) && $variables['node']->type == 'article') {
    // Add div on first.
    $variables['title_attributes_array']['itemprop'] = 'name';
    array_unshift($variables['main_prefix'], array('#markup' => '<div itemscope itemtype="http://schema.org/BlogPosting">'));
    // Close div on end.
    array_push($variables['main_suffix'], array('#markup' => '</div>'));
  }

  // If page different to frontpage.
  if (!drupal_is_front_page()) {
    // Add div on first.
    array_unshift($variables['title_prefix'], array('#markup' => '<div class="main__header">'));
    // Close div on end.
    array_push($variables['title_suffix'], array('#markup' => '</div>'));
  }
}
