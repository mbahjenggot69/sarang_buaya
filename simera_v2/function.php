<?php

session_start();
$conn = mysqli_connect("localhost", "root", "", "simera");

//LOGIN
if (isset($_POST['login'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $cekdatabase = mysqli_query($conn, "SELECT * FROM login WHERE username='$username' AND password='$password'");
    $hitung = mysqli_num_rows($cekdatabase);

    if ($hitung > 0) {
        $ambildatarole = mysqli_fetch_array($cekdatabase);
        $role = $ambildatarole['role'];

        if ($role == 'superadmin') {
            $_SESSION['log'] = 'Logged';
            $_SESSION['role'] = 'superadmin';
            header('location:pages1/main.php');
            echo '<script> alert ("SU"); </script>';
        } elseif ($role == 'admin') {
            $_SESSION['log'] = 'Logged';
            $_SESSION['role'] = 'admin';
            header('location:pages2/main.php');
            echo '<script> alert ("Admin"); </script>';
        } else {
            $_SESSION['log'] = 'Logged';
            $_SESSION['role'] = 'user';
            header('location:pages3/main.php');
            echo '<script> alert ("User"); </script>';
        }
    } else {
        echo '<script> alert ("PERHATIAN | Email atau Password Anda salah!"); </script>';
    }
}


if (isset($_SESSION['log'])) {
    if ($_SESSION['role'] === 'superadmin') {
        header('location:pages1/main.php');
    } else if ($_SESSION['role'] === 'admin') {
        header('location:pages2/main.php');
    } else {
        header('location:pages3/main.php');
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
                header('Location: /index.php');
                exit;
            } else {
                echo '<script> alert("Terjadi kesalahan saat mendaftar"); </script>';
            }
        }
    }
}
