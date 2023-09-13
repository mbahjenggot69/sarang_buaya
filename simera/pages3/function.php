<?php
session_start();

// KONEKSI KE DATABASE
$conn = mysqli_connect("localhost", "root", "", "simera");

// TAMBAH
if (isset($_POST['addnewalat'])) {
    $namaalat = $_POST['namaalat'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $addtotable = mysqli_query($conn, "insert into stok (namaalat,kode,harga,kondisi) values('$namaalat','$kode','$harga','$kondisi')");

    if ($addtotable) {
        header('location:../pages3/manajemen.php');
    } else {
        echo '<script> alert ("PERHATIAN | Email atau Password Anda salah!"); </script>';
    }
}

// PESAN
if (isset($_POST['pesan'])) {
    $kode = $_POST['kode'];
    $namaalat = $_POST['namaalat'];
    $tanggalpesan = $_POST['tanggalpesan'];
    $bataswaktu = $_POST['bataswaktu'];

    $addtotable = mysqli_query($conn, "insert into pesan (kode,namaalat,tanggalpesan,bataswaktu) values('$kode','$namaalat','$tanggalpesan','$bataswaktu')");

    if ($addtotable) {
        header('location:../pages3/pemesanan.php');
    } else {
        echo '<script> alert ("PERHATIAN | Email atau Password Anda salah!"); </script>';
    }
}

// UPDATE 
if (isset($_POST['updatealat'])) {
    $idalat = $_POST['idalat'];
    $namaalat = $_POST['namaalat'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $update = mysqli_query($conn, "update stok set namaalat='$namaalat',kode='$kode',harga='$harga',kondisi='$kondisi' where idalat='$idalat'");

    if ($update) {
        header('location:../pages3/manajemen.php');
    } else {
        echo '<script> alert ("PERHATIAN | Email atau Password Anda salah!"); </script>';
    }
}

// HAPUS 
if (isset($_POST['hapusalat'])) {
    $idalat = $_POST['idalat'];

    $hapus = mysqli_query($conn, "delete from stok where idalat='$idalat' ");

    if ($hapus) {
        header('location:../pages3/manajemen.php');
    } else {
        echo '<script> alert ("PERHATIAN | Email atau Password Anda salah!"); </script>';
    }
}
