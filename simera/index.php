<?php

session_start();
$conn = mysqli_connect("localhost", "root", "", "simera");

// VALIDASI AKUN DI DATABASE
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

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
    <meta name="description" content="" />
    <meta name="author" content="" />
    <title>SIMERA | Login Page</title>
    <link href="css/styles.css" rel="stylesheet" />
    <script src="https://use.fontawesome.com/releases/v6.3.0/js/all.js" crossorigin="anonymous"></script>
</head>

<body class="bg-primary">
    <div id="layoutAuthentication">
        <div id="layoutAuthentication_content">
            <main>
                <div class="container">
                    <div class="row justify-content-center">
                        <div class="col-lg-5">
                            <div class="card shadow-lg border-0 rounded-lg mt-5">
                                <div class="card-header text-center d-flex flex-column align-items-center">
                                    <img src="assets/img/Logo_SIMERA_2.png" style="padding-bottom: 10px;" width="300px" alt="Logo" />
                                </div>
                                <div class="card-body">
                                    <form method="post">
                                        <div class="form-floating mt-4 mb-3">
                                            <input class="form-control" name="username" id="inputUsername" type="username" placeholder="Username" />
                                            <label for="inputUsername">Username</label>
                                        </div>
                                        <div class="form-floating mb-3">
                                            <input class="form-control" name="password" id="inputPassword" type="password" placeholder="Password" />
                                            <label for="inputPassword">Password</label>
                                        </div>
                                        <div class="d-flex align-items-center justify-content-center mt-3">
                                            <button class="btn btn-primary" style="padding-left: 227px; padding-right: 227px; padding-top: 10px; padding-bottom: 10px; " name="login">Login</button>
                                        </div>
                                        <br>
                                    </form>
                                </div>
                                <div class="card-footer text-center pt-3 pb-1">
                                    <p class="fs-6 fw-light">Belum punya akun? <a href="register.php" style="text-decoration-line: none; font-weight:500">Register</a></p>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
            </main>
        </div>
        <div id="layoutAuthentication_footer">
            <footer class="py-3 bg-light mt-auto">
                <div class="container-fluid px-4">
                    <div class="d-flex align-items-center justify-content-between small">
                        <div class="text-muted">Universitas Kristen Satya Wacana</div>
                        <div>
                            <a href="#">Privacy Policy</a>
                            &middot;
                            <a href="#">Terms &amp; Conditions</a>
                        </div>
                    </div>
                </div>
            </footer>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" crossorigin="anonymous"></script>
    <script src="js/scripts.js"></script>
</body>

</html>