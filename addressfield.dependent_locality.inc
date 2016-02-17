<?php

/**
 * Returns the predefined suburbs.
 *
 * @param $country_code
 *   The country code for which administrative areas should be returned.
 *
 * @return
 *   An array of predefined administrative areas for the given country code, or
 *   NULL if not found.
 */
function addressfield_get_dependent_locality($country_code) {
  // Maintain a static cache to avoid passing the administrative areas through
  // t() more than once per request.
  $dependent_locality = &drupal_static(__FUNCTION__, array());
  if (empty($dependent_locality)) {
    // Get the default dependent locality (suburb).
    $dependent_locality = _addressfield_get_dependent_locality_defaults();

    // Allow other modules to alter the administrative areas.
    drupal_alter('addressfield_dependent_locality', $dependent_locality);
  }

  return isset($dependent_locality[$country_code]) ? $dependent_locality[$country_code] : NULL;
}

/**
 * Provides the default suburbs.
 */
function _addressfield_get_dependent_locality_defaults() {
  // To avoid needless pollution of the strings list we only pass to t()
  // those administrative areas that are in English (or a latin transcription),
  // and belong to a country that either has multiple official languages (CA)
  // or uses a non-latin script (AE, CN, JP, KR, UA, RU, etc).
  // No translation is expected in other cases.
  $dependent_locality = array();
  
  $dependent_locality['NZ'] = array(
    ''   => t('Outside Tauranga'),
	'Aongatete' => t('Aongatete'),
	'Arataki' => t('Arataki'),
	'Athenree' => t('Athenree'),
	'Avenues' => t('Avenues'),
	'Bayfair' => t('Bayfair'),
	'Bellevue' => t('Bellevue'),
	'Bethlehem' => t('Bethlehem'),
	'Brookfield' => t('Brookfield'),
	'Bureta' => t('Bureta'),
	'Cambridge Heights' => t('Cambridge Heights'),
	'City Centre' => t('City Centre'),
	'Gate Pa' => t('Gate Pa'),
	'Greerton' => t('Greerton'),
	'Hairini' => t('Hairini'),
	'Judea' => t('Judea'),
	'Kairua' => t('Kairua'),
	'Katikati' => t('Katikati'),
	'Lower Kaimai' => t('Lower Kaimai'),
	'Maketu' => t('Maketu'),
	'Matua' => t('Matua'),
	'Maungatapu' => t('Maungatapu'),
	'Mount Maunganui' => t('Mount Maunganui'),
	'Ohauiti' => t('Ohauiti'),
	'Omanu' => t('Omanu'),
	'Omokoroa' => t('Omokoroa'),
	'Oropi' => t('Oropi'),
	'Otumoetai' => t('Otumoetai'),
	'Paengaroa' => t('Paengaroa'),
	'Papamoa' => t('Papamoa'),
	'Papamoa Beach' => t('Papamoa Beach'),
	'Parkvale' => t('Parkvale'),
	'Poike' => t('Poike'),
	'Pukehina' => t('Pukehina'),
	'Pyes Pa' => t('Pyes Pa'),
	'Pyes Pa' => t('Pyes Pa'),
	'Rangiuru' => t('Rangiuru'),
	'Tauranga South' => t('Tauranga South'),
	'Tauriko' => t('Tauriko'),
	'Te Maunga' => t('Te Maunga'),
	'Te Puke' => t('Te Puke'),
	'Te Puna' => t('Te Puna'),
	'Waihi Beach' => t('Waihi Beach'),
	'Welcome Bay' => t('Welcome Bay'),
	'Whakamarama' => t('Whakamarama'),
	'Windermere' => t('Windermere'),
  );

  return $dependent_locality;
}
