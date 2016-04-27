<?php

/**
 * @file
 * Contains a pre-process hook for 'comment'.
 */

/**
 * Implements hook_preprocess_comment().
 *
 * Override or insert variables into the comment templates.
 *
 * @see hook_preprocess()
 */
function astarter_preprocess_comment(&$variables) {

  // Comment is reply to pid.
  if (!empty($variables['comment']->pid)) {
    $variables['attributes_array']['itemref'][] = 'comment-' . $variables['comment']->pid;
  }

  $variables['picture'] = !empty($variables['picture']) ? '<span class="mrm">' . theme('user_picture', array('account' => $variables['elements']['#comment'])) . '</span>' : '';

  if ($variables['node']->type == 'article') {

    $variables['attributes_array']['itemprop'][] = 'comment';
    $variables['attributes_array']['itemscope'][] = 'itemscope';
    $variables['attributes_array']['itemtype'][] = 'http://schema.org/Comment';
    $variables['content_attributes_array']['itemprop'] = 'description';
    $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['itemprop'] = 'discussionUrl';

    $variables['meta_author']['#markup'] = '<cite itemprop="publisher author" class="bold">' . $variables['author'] . '</cite>';

    $variables['meta_comment_created']['#markup'] = '<time class="small" datetime="' . format_date($variables['comment']->created, 'custom', 'c') . '" itemprop="datePublished dateCreated">' . $variables['created'] . '</time>';

    if ($variables['comment']->created != $variables['comment']->changed) {
      $variables['meta_comment_changed']['#markup'] = '<time class="small" datetime="' . format_date($variables['comment']->changed, 'custom', 'c') . '" itemprop="dateModified">' . $variables['changed'] . '</time>';
    }

  }
  else {

    $variables['meta_author']['#markup'] = '<cite class="bold">' . $variables['author'] . '</cite>';

    $variables['meta_comment_created']['#markup'] = '<time class="small" datetime="' . format_date($variables['comment']->created, 'custom', 'c') . '">' . $variables['created'] . '</time>';

    if ($variables['comment']->created != $variables['comment']->changed) {
      $variables['meta_comment_changed']['#markup'] = '<time class="small" datetime="' . format_date($variables['comment']->changed, 'custom', 'c') . '">' . $variables['changed'] . '</time>';
    }
  }

  // Clean reply link.
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['id'] = 'comment-' . $variables['comment']->cid . '-reply';
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['rel'] = 'nofollow';
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['class'][] = 'comment__link';

  // Add Title to reply link.
  $variables['content']['links']['comment']['#links']['comment-reply']['attributes']['title'] = t('Reply to comment !username of !date at !time', array(
    '!username' => $variables['author'],
    '!date' => format_date($variables['comment']->created, 'custom', 'd/m/Y'),
    '!time' => format_date($variables['comment']->created, 'custom', 'H:i'),
    )
  );
}
