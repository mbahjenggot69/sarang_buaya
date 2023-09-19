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

    $addtotable = mysqli_query($conn, "INSERT INTO stok (namaalat,kode,harga,kondisi) VALUES('$namaalat','$kode','$harga','$kondisi')");

    if ($addtotable) {
        echo '<script> alert ("SUCCESS | Berhasil menambah alat!"); </script>';
    } else {
        echo '<script> alert ("FAILED | Gagal menambah alat!"); </script>';
    }
}

// PESAN
if (isset($_POST['pesan'])) {
    $kode = $_POST['kode'];
    $namaalat = $_POST['namaalat'];
    $tanggalpesan = $_POST['tanggalpesan'];
    $bataswaktu = $_POST['bataswaktu'];

    $addtotable = mysqli_query($conn, "INSERT INTO pesan (kode,namaalat,tanggalpesan,bataswaktu) VALUES('$kode','$namaalat','$tanggalpesan','$bataswaktu')");

    if ($addtotable) {
        echo '<script> alert ("SUCCESS | Berhasil memesan alat!"); </script>';
    } else {
        echo '<script> alert ("FAILED | Gagal memesan alat!"); </script>';
    }
}

// UPDATE 
if (isset($_POST['updatealat'])) {
    $idalat = $_POST['idalat'];
    $namaalat = $_POST['namaalat'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $update = mysqli_query($conn, "UPDATE stok SET namaalat='$namaalat',kode='$kode',harga='$harga',kondisi='$kondisi' where idalat='$idalat'");

    if ($update) {
        echo '<script> alert ("SUCCESS | Berhasil mengubah alat!"); </script>';
    } else {
        echo '<script> alert ("FAILED | Gagal mengubah alat!"); </script>';
    }
}

// HAPUS 
if (isset($_POST['hapusalat'])) {
    $idalat = $_POST['idalat'];

    $hapus = mysqli_query($conn, "DELETE FROM stok WHERE idalat='$idalat' ");

    if ($hapus) {
        echo '<script> alert ("SUCCESS | Berhasil menghapus alat!"); </script>';
    } else {
        echo '<script> alert ("FAILED | Gagal menghapus alat!"); </script>';
    }
}

// SELESAI 
if (isset($_POST['selesai'])) {
    $idalat = $_POST['idalat'];

    // Salin data dari tabel pesan ke tabel historypesan
    $pindah = mysqli_query($conn, "INSERT INTO historypesan (kode, namaalat, tanggalpesan, bataswaktu) 
                                   SELECT kode, namaalat, tanggalpesan, bataswaktu FROM pesan WHERE idalat = '$idalat'");

    // Hapus data dari tabel pesan berdasarkan idalat
    $hapus = mysqli_query($conn, "DELETE FROM pesan WHERE idalat = '$idalat' ");

    if ($hapus) {
        echo '<script> alert ("SUCCESS | Berhasil menyelesaikan pesanan!"); </script>';
    } else {
        echo '<script> alert ("FAILED | Gagal menyelesaikan pesanan!"); </script>';
    }
}


//REGISTER
if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["regis"])) {
    // Ambil data dari form
    $namaawal = $_POST['namaawal'];
    $namaakhir = $_POST['namaakhir'];
    $username = $_POST['username'];
    $email = $_POST['email'];
    $password = $_POST['password'];
    $passconf = $_POST['passconf'];

    // Validasi data
    if (empty($namaawal) || empty($namaakhir) || empty($username) || empty($email) || empty($password) || empty($passconf)) {
        echo '<script> alert("Semua field harus diisi"); </script>';
    } elseif ($password !== $passconf) {
        echo '<script> alert("Konfirmasi kata sandi tidak cocok"); </script>';
    } else {
        // Hash kata sandi
        $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

        // Query untuk memeriksa apakah email atau username sudah ada dalam database
        $checkQuery = "SELECT * FROM login WHERE email = ? OR username = ?";
        $stmt = mysqli_prepare($conn, $checkQuery);
        mysqli_stmt_bind_param($stmt, 'ss', $email, $username);
        mysqli_stmt_execute($stmt);
        $result = mysqli_stmt_get_result($stmt);

        if (mysqli_num_rows($result) > 0) {
            echo '<script> alert("Email atau username sudah digunakan"); </script>';
        } else {
            // Query untuk menyimpan data ke database
            $insertQuery = "INSERT INTO login (namaawal, namaakhir, username, email, password, role) VALUES (?, ?, ?, ?, ?, 'user')";
            $stmt = mysqli_prepare($conn, $insertQuery);
            mysqli_stmt_bind_param($stmt, 'sssss', $namaawal, $namaakhir, $username, $email, $hashedPassword);

            if (mysqli_stmt_execute($stmt)) {
                echo '<script> alert("Pendaftaran berhasil"); </script>';
                header('Location:index.php');
                exit;
            } else {
                echo '<script> alert("Terjadi kesalahan saat mendaftar"); </script>';
            }
        }
    }
}
