<?php
require '../function.php';
require '../cek.php';

if (!isset($_SESSION['log']) || $_SESSION['role'] !== 'user') {
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
        <title>Sistem Informasi Manajemen Ruangan</title>
        <link rel="icon" href="../assets/img/logo-simera-icon.png" type="image/png">
        <link href="https://cdn.jsdelivr.net/npm/simple-datatables@7.1.2/dist/style.min.css" rel="stylesheet" />
        <link href="../css/styles.css" rel="stylesheet" />
        <script src="https://use.fontawesome.com/releases/v6.3.0/js/all.js" crossorigin="anonymous"></script>
    </head>
    <body class="sb-nav-fixed">
        <?php include '../nav_main.php';?>
        <div id="layoutSidenav_content" style="padding-top: 80px;">
            <main>
                <div class="container-fluid px-4">
                    <h1 class="mt-1">Ruangan Laboratorium</h1>
                    <ol class="breadcrumb mb-4">
                        <li class="breadcrumb-item active">Sistem Informasi Manajemen Ruangan</li>
                    </ol>
                    <div class="card mb-4">
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
                                            <button class="btn btn-info" onclick="location.href='<?= $peralatan[$id - 1]; ?>'">
                                                Peralatan
                                            </button>
                                            <button class="btn btn-info" onclick="location.href='<?= $jadwal[$id - 1]; ?>'">
                                                Jadwal
                                            </button>
                                        </td>
                                    </tr>
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
</html>

<?php    
}
?>