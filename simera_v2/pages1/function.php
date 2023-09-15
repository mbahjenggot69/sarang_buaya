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
        header('location:../pages1/manajemen.php');
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
        header('location:../pages1/pemesanan.php');
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
        header('location:../pages1/manajemen.php');
    } else {
        echo '<script> alert ("PERHATIAN | Email atau Password Anda salah!"); </script>';
    }
}

// HAPUS 
if (isset($_POST['hapusalat'])) {
    $idalat = $_POST['idalat'];

    $hapus = mysqli_query($conn, "delete from stok where idalat='$idalat' ");

    if ($hapus) {
        header('location:../pages1/manajemen.php');
    } else {
        echo '<script> alert ("PERHATIAN | Email atau Password Anda salah!"); </script>';
    }
}

// SELESAI 
if (isset($_POST['selesai'])) {
    $idalat = $_POST['idalat'];

    // Salin data dari tabel pesan ke tabel historypesan
    $pindah = mysqli_query($conn, "INSERT INTO historypesan (kode, namaalat, tanggalpesan, bataswaktu) 
                                   SELECT kode, namaalat, tanggalpesan, bataswaktu 
                                   FROM pesan 
                                   WHERE idalat = '$idalat'");

    // Hapus data dari tabel pesan berdasarkan idalat
    $hapus = mysqli_query($conn, "DELETE FROM pesan WHERE idalat = '$idalat' ");

    if ($hapus) {
        header('location:../pages1/pemesanan.php');
    } else {
        echo '<script> alert ("PERHATIAN | Terjadi kesalahan saat menghapus data!"); </script>';
    }
}

function checkAdminAccess()
{
    // Pastikan pengguna sudah masuk dan memiliki peran 'admin'
    if (isset($_SESSION['log']) && $_SESSION['role'] === 'superadmin') {
        // Izinkan akses halaman
        return true;
    }
}
