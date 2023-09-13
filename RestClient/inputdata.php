    <?php
        $sumber = 'http://localhost:8080/LatihanRestful/webresources/testController/postData';
    
        $ch = curl_init($sumber);
        $data_array = array(
            "nama" => "Anggasta Naufal",
            "id" => "67"
        );
    
        $jsonDataEncode = json_encode($data_array);
    
        curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt($ch, CURLOPT_POSTFIELDS, $jsonDataEncode);
        curl_setopt($ch, CURLOPT_HTTPHEADER, array('Content-Type: application/json'));
    
        $result = curl_exec($ch);
    ?>