<?php
session_start();
$conn = mysqli_connect("localhost", "root", "root", "stockbarang");

if (isset($_POST['addbrg'])) {
    $namabarang = $_POST['namabarang'];
    $deskripsi = $_POST['deskripsi'];
    $stock = $_POST['stock'];

    $addto = mysqli_query($conn, "INSERT INTO stock (namabarang, deskripsi, stock) VALUES ('$namabarang', '$deskripsi', '$stock')");

    if ($addto) {
        header('location:index.php');
    } else {
        echo '<script> alert ("PERHATIAN | Inputan Anda Salah!"); </script>';
    }
}
if (isset($_POST['barangmasuk'])) {
    $barangnya = $_POST['barangnya'];
    $penerima = $_POST['penerima'];
    $qty = $_POST['qty'];

    $addtomasuk = mysqli_query($conn, "INSERT INTO masuk (idbarang, keterangan, qty) VALUES ('$barangnya', '$penerima', '$qty')");
    $updatestok = mysqli_query($conn, "UPDATE stock");
    if ($addtomasuk) {
        header('location:masuk.php');
    } else {
        echo '<script> alert ("PERHATIAN | Inputan Anda Salah!"); </script>';
    }
}
