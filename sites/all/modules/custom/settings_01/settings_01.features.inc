<?php
/**
 * @file
 * settings_01.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function settings_01_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function settings_01_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function settings_01_image_default_styles() {
  $styles = array();

  // Exported image style: full_page_image.
  $styles['full_page_image'] = array(
    'label' => 'Full page image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1600,
          'height' => 1200,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function settings_01_node_info() {
  $items = array(
    'photo_item' => array(
      'name' => t('Фотография'),
      'base' => 'node_content',
      'description' => t('Фотография'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
