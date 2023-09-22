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
        <title>Peralatan Laboratorium Komputasi - Sistem Informasi Manajemen Ruangan</title>
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
                        <h1 class="mt-4">Peralatan Laboratorium Komputasi</h1>
                        <ol class="breadcrumb mb-4">
                            <li class="breadcrumb-item active">Sistem Informasi Manajemen Ruangan</li>
                        </ol>
                        <div class="card mb-4">
                            <div class="card-header">
                                <!-- Button to Open the Modal -->
                                <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#myModal">
                                    Tambah Alat
                                </button>
                            </div>
                            <div class="card-body">
                                <table id="datatablesSimple">
                                    <thead>
                                        <tr>
                                            <th>No</th>
                                            <th>Kode</th>
                                            <th>Nama Alat</th>
                                            <th>Harga</th>
                                            <th>Kondisi</th>
                                            <th>Tanggal Masuk</th>
                                            <th>Aksi</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        <?php
                                        $ambilsemuadatastok = mysqli_query($conn,"select * from stok");
                                        $no = 1;
                                        while($data = mysqli_fetch_array($ambilsemuadatastok)){
                                            $kode = $data['kode'];
                                            $nama = $data['nama'];
                                            $harga = $data['harga'];
                                            $kondisi = $data['kondisi'];
                                            $tanggal = $data['tanggal'];
                                            $id = $data['id'];
                                        ?>
                                        <tr>
                                            <td><?=$no++;?></td>
                                            <td><?=$kode;?></td>
                                            <td><?=$nama;?></td>
                                            <td><?=$harga;?></td>
                                            <td><?=$kondisi;?></td>
                                            <td><?=$tanggal;?></td>
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
                                                        <h4 class="modal-title">Edit Alat</h4>
                                                        <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                    </div>
                                                    <!-- Modal body -->
                                                    <form method="post">
                                                        <div class="modal-body">
                                                            <input type="text" name="nama" value="<?=$nama;?>" placeholder="Nama alat..." class="form-control" required>
                                                            <br>
                                                            <input type="text" name="kode" value="<?=$kode;?>" placeholder="Kode..." class="form-control" required>
                                                            <br>
                                                            <input type="text" name="harga" value="<?=$harga;?>" placeholder="Harga..." class="form-control" required>
                                                            <br>
                                                            <input type="text" name="kondisi" value="<?=$kondisi;?>" placeholder="Kondisi..." class="form-control" required>
                                                            <br>
                                                            <input type="hidden" name="id" value="<?=$id;?>">                                                            
                                                            <button type="submit" class="btn btn-warning" name="editstok">Edit</button>
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
                                                        <h4 class="modal-title">Hapus Alat?</h4>
                                                        <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                    </div>
                                                    <!-- Modal body -->
                                                    <form method="post">
                                                        <div class="modal-body">
                                                            Apakah Anda yakin ingin menghapus <?=$nama;?> dengan kode <?=$kode;?>?
                                                            <input type="hidden" name="id" value="<?=$id;?>">   
                                                            <br>
                                                            <br>
                                                            <button type="submit" class="btn btn-danger" name="hapusstok">Hapus</button>
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
                    <h4 class="modal-title">Tambah Alat</h4>
                    <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                </div>
                <!-- Modal body -->
                <form method="post">
                    <div class="modal-body">
                        <input type="text" name="nama" placeholder="Nama alat..." class="form-control" required>
                        <br>
                        <input type="text" name="kode" placeholder="Kode..." class="form-control" required>
                        <br>
                        <input type="text" name="harga" placeholder="Harga..." class="form-control" required>
                        <br>
                        <input type="text" name="kondisi" placeholder="Kondisi..." class="form-control" required>
                        <br>
                        <button type="submit" class="btn btn-primary" name="tambahstok">Tambah</button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</html>

<?php    
}
?>
