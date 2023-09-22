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
        <title>Sistem Informasi Manajemen Ruangan </title>
        <link rel="icon" href="../assets/img/logo-simera-icon.png" type="image/png">
        <link href="https://cdn.jsdelivr.net/npm/simple-datatables@7.1.2/dist/style.min.css" rel="stylesheet" />
        <link href="../css/styles.css" rel="stylesheet" />
        <script src="https://use.fontawesome.com/releases/v6.3.0/js/all.js" crossorigin="anonymous"></script>
    </head>
    <body class="sb-nav-fixed">
        <?php include '../nav_main.php';?>
        <div id="layoutSidenav_content" style="padding-top: 56px;">
            <main>
                <div class="container-fluid px-4">
                    <h1 class="mt-1">Ruangan Laboratorium</h1>
                    <ol class="breadcrumb mb-4">
                        <li class="breadcrumb-item active">Sistem Informasi Manajemen Ruangan</li>
                    </ol>
                    <div class="card mb-4">
                        <div class="card-header">
                            <!-- Button to Open the Modal -->
                            <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#myModal">
                                Tambah Lab
                            </button>
                        </div>
                        <div class="card-body">
                            <table id="datatablesSimple">
                                <thead>
                                    <tr>
                                        <th>No</th>
                                        <th>Kode</th>
                                        <th>Laboratorium</th>
                                        <th>Fakultas</th>
                                        <th>Nama Laboran</th>
                                        <th>Kapasitas</th>
                                        <th>Aksi</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php
                                    $peralatan = [
                                        "plt_anatomi.php",
                                        "plt_hidrodinamika.php",
                                        "plt_komputasi.php",
                                        "plt_multimedia.php",
                                        "plt_termofluida.php"
                                    ];

                                    $jadwal = [
                                        "jdw_anatomi.php",
                                        "jdw_hidrodinamika.php",
                                        "jdw_komputasi.php",
                                        "jdw_multimedia.php",
                                        "jdw_termofluida.php"
                                    ];
                                    
                                    $ambilsemuadatastok = mysqli_query($conn,"select * from laboratorium");
                                    $no = 1;
                                    while($data = mysqli_fetch_array($ambilsemuadatastok)){
                                        $kode = $data['kode'];
                                        $nama = $data['nama'];
                                        $fakultas = $data['fakultas'];
                                        $laboran = $data['laboran'];
                                        $kapasitas = $data['kapasitas'];
                                        $id = $data['id'];
                                    ?>
                                    <tr>
                                        <td><?=$no++;?></td>
                                        <td><?=$kode;?></td>
                                        <td><?=$nama;?></td>
                                        <td><?=$fakultas;?></td>
                                        <td><?=$laboran;?></td>
                                        <td><?=$kapasitas;?></td>
                                        <td>
                                            <button type="button" class="btn btn-info" data-bs-toggle="modal" data-bs-target="#lihat<?=$id;?>">
                                                Lihat
                                            </button>
                                            <button type="button" class="btn btn-warning" data-bs-toggle="modal" data-bs-target="#edit<?=$id;?>">
                                                Edit
                                            </button>
                                            <button type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#hapus<?=$id;?>">
                                                Hapus
                                            </button>       
                                        </td>
                                    </tr>
                                    <!-- The Modal Lihat -->
                                    <div class="modal fade" id="lihat<?=$id;?>">
                                        <div class="modal-dialog">
                                            <div class="modal-content">
                                                <!-- Modal Header -->
                                                <div class="modal-header">
                                                    <h4 class="modal-title">Lihat Laboratorium</h4>
                                                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                </div>
                                                <!-- Modal body -->
                                                <div class="modal-body">
                                                    <button class="btn btn-info" onclick="location.href='<?= $peralatan[$id - 1]; ?>'">
                                                        Peralatan
                                                    </button>
                                                    <button class="btn btn-info" onclick="location.href='<?= $jadwal[$id - 1]; ?>'">
                                                        Jadwal
                                                    </button>
                                                    <button class="btn btn-info" onclick="location.href='kel_admin.php'">
                                                        Kelola Admin
                                                    </button>
                                                    <button class="btn btn-info" onclick="location.href='kel_user.php'">
                                                        Kelola User
                                                    </button>
                                                </div>
                                            </div>
                                        </div>
                                    </div>
                                    <!-- The Modal Edit -->
                                    <div class="modal fade" id="edit<?=$id;?>">
                                        <div class="modal-dialog">
                                            <div class="modal-content">
                                                <!-- Modal Header -->
                                                <div class="modal-header">
                                                    <h4 class="modal-title">Edit Lab</h4>
                                                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                </div>
                                                <!-- Modal body -->
                                                <form method="post">
                                                    <div class="modal-body">
                                                        <input type="text" name="kode" value="<?=$kode;?>" placeholder="Kode..." class="form-control" required>
                                                        <br>
                                                        <input type="text" name="nama" value="<?=$nama;?>" placeholder="Nama lab..." class="form-control" required>
                                                        <br>
                                                        <input type="text" name="fakultas" value="<?=$fakultas;?>" placeholder="Fakultas..." class="form-control" required>
                                                        <br>
                                                        <input type="text" name="laboran" value="<?=$laboran;?>" placeholder="Nama laboran..." class="form-control" required>
                                                        <br>
                                                        <input type="text" name="kapasitas" value="<?=$kapasitas;?>" placeholder="Kapasitas..." class="form-control" required>
                                                        <br>
                                                        <input type="hidden" name="id" value="<?=$id;?>">                                                            
                                                        <button type="submit" class="btn btn-warning" name="editlab">Edit</button>
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
                                                    <h4 class="modal-title">Hapus Lab?</h4>
                                                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                </div>
                                                <!-- Modal body -->
                                                <form method="post">
                                                    <div class="modal-body">
                                                        Apakah Anda yakin ingin menghapus <?=$nama;?> dengan kode <?=$kode;?>?
                                                        <input type="hidden" name="id" value="<?=$id;?>">   
                                                        <br>
                                                        <br>
                                                        <button type="submit" class="btn btn-danger" name="hapuslab">Hapus</button>
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
                    <h4 class="modal-title">Tambah Lab</h4>
                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                </div>
                <!-- Modal body -->
                <form method="post">
                    <div class="modal-body">
                        <input type="text" name="kode" placeholder="Kode..." class="form-control" required>
                        <br>
                        <input type="text" name="nama" placeholder="Nama lab..." class="form-control" required>
                        <br>
                        <input type="text" name="fakultas" placeholder="Fakultas..." class="form-control" required>
                        <br>
                        <input type="text" name="laboran" placeholder="Nama laboran..." class="form-control" required>
                        <br>
                        <input type="number" name="kapasitas" placeholder="Kapasitas..." class="form-control" required>
                        <br>
                        <button type="submit" class="btn btn-primary" name="tambahlab">Tambah</button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</html>

<?php    
}
?>