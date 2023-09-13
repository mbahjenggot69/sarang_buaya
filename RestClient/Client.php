<?php 

    $sumber = 'http://localhost:8080/LatihanRestful/webresources/testController/getdata';
    $konten = file_get_contents($sumber);
    $data = json_decode($konten, true);
    for($i = 0; $i < count($data); $i++)
    {
        print $data[$i]['id']."|";
        print $data[$i]['nama']."<br>";
    }


?>