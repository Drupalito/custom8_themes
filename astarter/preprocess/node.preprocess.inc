<?php

/**
 * @file
 * Contains a pre-process hook for 'node'.
 */

/**
 * Implements hook_preprocess_node().
 *
 * Override or insert variables into the node templates.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_node(&$variables, $hook) {

  // Add display_submitted.
  $variables['submitted'] = array();

  if ($variables['display_submitted'] && $css_view_mode != 'teaser' && $variables['type'] == 'article') {

    $variables['content_attributes_array']['itemprop'] = 'articleBody';

    if (!empty($variables['uid'])) {
      $node_meta[] = '<span id="author-' . check_plain(strip_tags($variables['name'])) . '" itemprop="author" itemscope itemtype="http://schema.org/Person">' . l($variables['name'], 'user/' . $variables['uid'], array('html' => TRUE, 'attributes' => array('itemprop' => array('url')))) . '</span>';
    }

    if ($variables['nid'] && $variables['comment'] != COMMENT_NODE_CLOSED) {

      $node_meta[] = l(format_plural($variables['comment_count'], t('@count comment'), t('@count comments')), 'node/' . $variables['nid'], array('fragment' => 'comments', 'attributes' => array('class' => array('scroll')))) . '<meta itemprop="commentCount" content="' . $variables['comment_count'] . '" />';
    }

    $node_meta[] = '<time datetime="' . format_date($variables['created'], 'custom', 'c') . '" itemprop="datePublished dateCreated">' . format_date($variables['created']) . '</time>';

    if ($variables['created'] != $variables['changed']) {

      $node_meta[] = '<time datetime="' . format_date($variables['changed'], 'custom', 'c') . '" itemprop="dateModified">' . format_date($variables['changed']) . '</time>';
    }
  }

  elseif ($variables['display_submitted']) {

    if (!empty($variables['uid'])) {

      $node_meta[] = '<span id="author-' . check_plain(strip_tags($variables['name'])) . '">' . l($variables['name'], 'user/' . $variables['uid'], array('html' => TRUE)) . '</span>';
    }

    $node_meta[] = '<time datetime="' . format_date($variables['created'], 'custom', 'c') . '">' . format_date($variables['created']) . '</time>';

    if ($variables['created'] != $variables['changed']) {

      $node_meta[] = '<time datetime="' . format_date($variables['changed'], 'custom', 'c') . '">' . format_date($variables['changed']) . '</time>';
    }
  }

  if ($variables['display_submitted'] && !empty($node_meta)) {
    $variables['submitted']['meta_list'] = array(
      '#theme' => 'item_list',
      '#type' => 'ul',
      '#items' => $node_meta,
      '#attributes' => array('class' => array('meta')),
    );
  }

  if ($css_view_mode == 'teaser') {

    // Teaser : clean link 'number comments'.
    if (isset($variables['content']['links']['comment']['#links']['comment-comments'])) {
      $variables['content']['links']['comment']['#links']['comment-comments']['attributes']['title'] = $variables['content']['links']['comment']['#links']['comment-comments']['title'] . ' ' . t('on') . ' ' . $variables['title'];
    }

    // Teaser : remove add comment link.
    if (isset($variables['content']['links']['comment']['#links']['comment-add'])) {
      unset($variables['content']['links']['comment']['#links']['comment-add']);
    }

    // Teaser : remove new comment link.
    if (isset($variables['content']['links']['comment']['#links']['comment-new-comments'])) {
      unset($variables['content']['links']['comment']['#links']['comment-new-comments']);
    }

    // Teaser : clean link 'readmore'.
    $variables['content']['links']['node']['#links']['node-readmore']['title'] = '<span class="i i-arrow-right2" aria-hidden="true"></span> ' . t('Read more');
    $variables['content']['links']['node']['#links']['node-readmore']['attributes']['title'] = $variables['title'] . ' (' . t('Read more') . ')';
  }
}
