<?php 

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
