<?php

/**
 * @file
 * Integration with Views.
 */

/**
 * Implementation of hook_views_plugins().
 */
function drudesk_vs_views_plugins() {
  $module_path = drupal_get_path('module', 'drudesk_vs');
  return array(
    'module' => 'drudesk_vs', // This just tells our themes are elsewhere.
    'style' => array(
      'drudesk_viesws_style' => array(
        'title' => t('Drudesk column'),
        'help' => t('Displays items in a column.'),
        'handler' => 'drudesk_vs_plugin_style',
        'path' => $module_path .'/views',
        'theme path' => $module_path .'/theme',
        'theme file' => 'theme.inc',
        'theme' => 'drudesk_vs_plugin_style',
        'uses row plugin' => TRUE,
        'uses options' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => false,

        'type' => 'normal'

      ),
    ),
  );
}
