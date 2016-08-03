<?php

/**
 * @file
 * Contains the fluid grid style plugin.
 */

/**
 * Style plugin to render items in a fluid grid.
 *
 * @ingroup views_style_plugins
 */
class drudesk_vs_plugin_style extends views_plugin_style {
  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['items_width'] = array('default' => 100);
    $options['items_height'] = array('default' => 100);
    $options['column_count'] = array('default' => 4);
    $options['row_count'] = array('default' => 4);
    return $options;
  }

  /**
   * Provide a form to edit options for this plugin.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $items_width_options = array('' => t('Auto'))
      + drupal_map_assoc(variable_get('views_fluid_grid_plugin_style_widths',
        array(100, 150, 180, 200, 250, 300, 350, 400, 450, 500)));
    $items_height_options = array('' => t('Auto'))
      + drupal_map_assoc(variable_get('views_fluid_grid_plugin_style_heights',
        array(100, 150, 200, 250, 300, 350, 400, 450, 500)));
    $items_column_row_count_options = drupal_map_assoc(array(
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9,
    ));
    $form['size'] = array(
      '#type' => 'fieldset',
      '#title' => t('Items size'),
    );
    $form['size']['items_width'] = array(
      '#type' => 'select',
      '#title' => t('Width'),
      '#options' => $items_width_options,
      '#default_value' => $this->options['items_width'],
    );
    $form['size']['items_height'] = array(
      '#type' => 'select',
      '#title' => t('Height'),
      '#options' => $items_height_options,
      '#default_value' => $this->options['items_height'],
    );
    $form['column_count'] = array(
      '#type' => 'select',
      '#title' => t('Height'),
      '#options' => $items_column_row_count_options,
      '#default_value' => $this->options['column_count'],
    );
    $form['row_count'] = array(
      '#type' => 'select',
      '#title' => t('Height'),
      '#options' => $items_column_row_count_options,
      '#default_value' => $this->options['row_count'],
    );

  }
  /**
   * Process the options form.
   */
  function options_submit(&$form, &$form_state) {
    foreach ($form_state['values']['style_options']['size'] as $key => $value) {
      $form_state['values']['style_options'][$key] = $value;
    }

    parent::options_submit($form, $form_state);
  }
}
