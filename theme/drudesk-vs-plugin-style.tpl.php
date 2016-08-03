<?php
/**
 * @file
 *
 */
?>
<div class="views-fluid-grid">
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <ul>
    <?php
    $arr_row = array();
    $conter = 0;
    $row_count = $options['row_count'];
    $column_count = $options['column_count'];
    foreach ($rows as $id => $item) {
      $conter++;
      $number = $conter % $column_count;
      $arr_row[($number)][] = '<li class="drudeks-vs-grid-item" style=" width:' .
        $options['items_width'] . 'px; height:' . $options['items_height'] . 'px"  >' . $item . '</li>';
    }
    for ($i = 0; $i < count($arr_row); $i++) {
      print '<div class="drudesk-vs-columm-wraper">';
      $count_in_arr = count($arr_row[$i]);
      for ($ii = 0; $ii < $count_in_arr; $ii++) {
        if ($ii % $row_count == 0) {
          print '<div class="drudesk-vs-row-wraper">';
        }
        print $arr_row[$i][$ii];
        if (($ii % $row_count == $row_count - 1) || $ii == ($count_in_arr - 1)) {
          print '</div>';
        }
      }
      print "</div>";
    }
    ?>
  </ul>
</div>
