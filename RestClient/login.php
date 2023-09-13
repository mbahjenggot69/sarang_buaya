<?php 
    $sumber = 'http://localhost:8080/LatihanRestful/webresources/testController/cekLogin';
    $ch = curl_init($sumber);
    $data_array = array("nama" => "paijo", "nim" => 672020053);
    $jsonDataEncoded = json_encode($data_array);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $jsonDataEncoded);
    curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: application/json'));
    $result = curl_exec($ch);


