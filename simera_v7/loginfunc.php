<?php
// VALIDASI AKUN DI DATABASE
if (isset($_POST['login'])) {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $cekdatabase = mysqli_query($conn, "select * from login where username='$username' and password='$password'");
    $hitung = mysqli_num_rows($cekdatabase);

    if ($hitung > 0) {
        $ambildatarole = mysqli_fetch_array($cekdatabase);
        $role = $ambildatarole['role'];
        $_SESSION['username'] = $username;

        if ($role == 'superadmin') {
            $_SESSION['log'] = 'Logged';
            $_SESSION['role'] = 'superadmin';
            header('location:superadmin/main.php');
        } elseif ($role == 'admin') {
            $_SESSION['log'] = 'Logged';
            $_SESSION['role'] = 'admin';
            header('location:admin/main.php');
        } else {
            $_SESSION['log'] = 'Logged';
            $_SESSION['role'] = 'user';
            header('location:user/main.php');
        }
    } else {
        header('location:index.php');
    }
}

if (isset($_SESSION['log'])) {
    if ($_SESSION['role'] === 'superadmin') {
        header('location:superadmin/main.php');
    } elseif ($_SESSION['role'] === 'admin') {
        header('location:admin/main.php');
    } else {
        header('location:user/main.php');
    }
}
?>