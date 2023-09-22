<?php
require '../function.php';
require '../cek.php';

if (!isset($_SESSION['log']) || $_SESSION['role'] !== 'superadmin') {
    // Pengguna tidak memiliki izin, arahkan mereka ke halaman lain (misalnya, ke halaman login)
    header('location: ../index.php');
    exit();
} else {
?>

<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge" />
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
        <meta name="description" content="" />
        <meta name="author" content="" />
        <title>Kelola Admin - Sistem Informasi Manajemen Ruangan</title>
        <link rel="icon" href="../assets/img/logo-simera-icon.png" type="image/png">
        <link href="https://cdn.jsdelivr.net/npm/simple-datatables@7.1.2/dist/style.min.css" rel="stylesheet" />
        <link href="../css/styles.css" rel="stylesheet" />
        <script src="https://use.fontawesome.com/releases/v6.3.0/js/all.js" crossorigin="anonymous"></script>
    </head>
    <body class="sb-nav-fixed">
        <?php include '../nav_main.php';?>
        <div id="layoutSidenav">
            <?php include '../nav_superadmin.php';?>
            <div id="layoutSidenav_content">
                <main>
                    <div class="container-fluid px-4">
                        <h1 class="mt-4">Kelola Admin</h1>
                        <ol class="breadcrumb mb-4">
                            <li class="breadcrumb-item active">Sistem Informasi Manajemen Ruangan</li>
                        </ol>
                        <div class="card mb-4">
                            <div class="card-header">
                                <!-- Button to Open the Modal -->
                                <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#myModal">
                                    Tambah Admin
                                </button>
                            </div>
                            <div class="card-body">
                                <table id="datatablesSimple">
                                    <thead>
                                        <tr>
                                            <th>No</th>
                                            <th>Nama Admin</th>
                                            <th>Email</th>
                                            <th>Username</th>
                                            <th>Password</th>
                                            <th>Role</th>
                                            <th>Aksi</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        <?php
                                        $ambilsemuadatalogin = mysqli_query($conn,"select * from login where role='admin'");
                                        $no = 1;
                                        while($data = mysqli_fetch_array($ambilsemuadatalogin)){
                                            $id = $data['id'];
                                            $nama = $data['nama'];
                                            $email = $data['email'];
                                            $username = $data['username'];
                                            $password = $data['password'];
                                            $role = $data['role'];
                                        ?>
                                        <tr>
                                            <td><?=$no++;?></td>
                                            <td><?=$nama;?></td>
                                            <td><?=$email;?></td>
                                            <td><?=$username;?></td>
                                            <td><?=$password;?></td>
                                            <td><?=$role;?></td>
                                            <td>
                                                <button type="button" class="btn btn-warning" data-bs-toggle="modal" data-bs-target="#edit<?=$id;?>">
                                                    Edit
                                                </button>
                                                <button type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#hapus<?=$id;?>">
                                                    Hapus
                                                </button>       
                                            </td>
                                        </tr>
                                        <!-- The Modal Edit -->
                                        <div class="modal fade" id="edit<?=$id;?>">
                                            <div class="modal-dialog">
                                                <div class="modal-content">
                                                    <!-- Modal Header -->
                                                    <div class="modal-header">
                                                        <h4 class="modal-title">Edit Admin</h4>
                                                        <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                    </div>
                                                    <!-- Modal body -->
                                                    <form method="post">
                                                        <div class="modal-body">
                                                            <input type="text" name="username" value="<?=$username;?>" placeholder="Username..." class="form-control" required>
                                                            <br>
                                                            <input type="text" name="password" value="<?=$password;?>" placeholder="Password..." class="form-control" required>
                                                            <br>
                                                            <input type="hidden" name="id" value="<?=$id;?>">                                                            
                                                            <button type="submit" class="btn btn-warning" name="editadmin">Edit</button>
                                                        </div>
                                                    </form>
                                                </div>
                                            </div>
                                        </div>
                                        <!-- The Modal Hapus -->
                                        <div class="modal fade" id="hapus<?=$id;?>">
                                            <div class="modal-dialog">
                                                <div class="modal-content">
                                                    <!-- Modal Header -->
                                                    <div class="modal-header">
                                                        <h4 class="modal-title">Hapus Admin?</h4>
                                                        <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                    </div>
                                                    <!-- Modal body -->
                                                    <form method="post">
                                                        <div class="modal-body">
                                                            Apakah Anda yakin ingin menghapus <?=$username;?> dengan password <?=$password;?>?
                                                            <input type="hidden" name="id" value="<?=$id;?>">   
                                                            <br>
                                                            <br>
                                                            <button type="submit" class="btn btn-danger" name="hapusadmin">Hapus</button>
                                                        </div>
                                                    </form>
                                                </div>
                                            </div>
                                        </div>
                                        <?php
                                        }
                                        ?>
                                    </tbody>
                                </table>
                            </div>
                        </div>
                    </div>
                </main>
                <?php include '../footer.php';?>
            </div>
        </div>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" crossorigin="anonymous"></script>
        <script src="../js/scripts.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.8.0/Chart.min.js" crossorigin="anonymous"></script>
        <script src="../assets/demo/chart-area-demo.js"></script>
        <script src="../assets/demo/chart-bar-demo.js"></script>
        <script src="https://cdn.jsdelivr.net/npm/simple-datatables@7.1.2/dist/umd/simple-datatables.min.js" crossorigin="anonymous"></script>
        <script src="../js/datatables-simple-demo.js"></script>
    </body>
    <!-- The Modal -->
    <div class="modal fade" id="myModal">
        <div class="modal-dialog">
            <div class="modal-content">
                <!-- Modal Header -->
                <div class="modal-header">
                    <h4 class="modal-title">Tambah Akun</h4>
                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                </div>
                <!-- Modal body -->
                <form method="post">
                    <div class="modal-body">
                        <input type="text" name="nama" placeholder="Nama..." class="form-control" required>
                        <br>
                        <input type="text" name="email" placeholder="Email..." class="form-control" required>
                        <br>
                        <input type="text" name="username" placeholder="Username..." class="form-control" required>
                        <br>
                        <input type="text" name="password" placeholder="Password..." class="form-control" required>
                        <br>
                        <button type="submit" class="btn btn-primary" name="tambahadmin">Tambah</button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</html>

<?php    
}
?>