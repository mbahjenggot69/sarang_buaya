<?php
require '../../function.php';
require '../../cek.php';

if (!isset($_SESSION['log']) || $_SESSION['role'] !== 'admin') {
    // Pengguna tidak memiliki izin, arahkan mereka ke halaman lain (misalnya, ke halaman login)
    header('location: ../../index.php');
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
        <title>Peralatan Praktikum Termofluida - Sistem Informasi Manajemen Ruangan</title>
        <link rel="icon" href="../../assets/img/logo-simera-icon.png" type="image/png">
        <link href="https://cdn.jsdelivr.net/npm/simple-datatables@7.1.2/dist/style.min.css" rel="stylesheet" />
        <link href="../../css/styles.css" rel="stylesheet" />
        <script src="https://use.fontawesome.com/releases/v6.3.0/js/all.js" crossorigin="anonymous"></script>
    </head>

    <body class="sb-nav-fixed">
        <?php include '../../nav_main_adm.php'; ?>
        <div id="layoutSidenav">
            <div id="layoutSidenav_nav">
                <nav class="sb-sidenav accordion sb-sidenav-dark" id="sidenavAccordion">
                    <div class="sb-sidenav-menu">
                        <div class="nav">
                            <div class="sb-sidenav-menu-heading">Core</div>
                            <a class="nav-link" href="../main.php">
                                <div class="sb-nav-link-icon"><i class="fas fa-tachometer-alt"></i></div>
                                Menu Utama
                            </a>
                            <div class="sb-sidenav-menu-heading">Interface</div>
                            <a class="nav-link collapsed" href="#" data-bs-toggle="collapse" data-bs-target="#collapseLayouts" aria-expanded="false" aria-controls="collapseLayouts">
                                <div class="sb-nav-link-icon"><i class="fas fa-microscope"></i></div>
                                Praktikum
                                <div class="sb-sidenav-collapse-arrow"><i class="fas fa-angle-down"></i></div>
                            </a>
                            <div class="collapse" id="collapseLayouts" aria-labelledby="headingOne" data-bs-parent="#sidenavAccordion">
                                <nav class="sb-sidenav-menu-nested nav">
                                    <a class="nav-link" href="plt_termofluida.php">Pinjam</a>
                                    <a class="nav-link" href="pjm_pra_ter.php">Peralatan Dipinjam</a>
                                </nav>
                            </div>
                            <a class="nav-link collapsed" href="#" data-bs-toggle="collapse" data-bs-target="#collapsePages" aria-expanded="false" aria-controls="collapsePages">
                                <div class="sb-nav-link-icon"><i class="fas fa-list"></i></div>
                                Eksperimen
                                <div class="sb-sidenav-collapse-arrow"><i class="fas fa-angle-down"></i></div>
                            </a>
                            <div class="collapse" id="collapsePages" aria-labelledby="headingTwo" data-bs-parent="#sidenavAccordion">
                                <nav class="sb-sidenav-menu-nested nav">
                                    <a class="nav-link" href="mdl_termofluida.php">Modul</a>
                                    <a class="nav-link" href="jdw_termofluida.php">Jadwal & Modul</a>
                                    <a class="nav-link" href="pjm_eks_ter.php">Peralatan Dipinjam</a>
                                </nav>
                            </div>
                            <a class="nav-link collapsed" href="#" data-bs-toggle="collapse" data-bs-target="#collapseMenus" aria-expanded="false" aria-controls="collapseMenus">
                                <div class="sb-nav-link-icon"><i class="fas fa-history"></i></div>
                                Riwayat
                                <div class="sb-sidenav-collapse-arrow"><i class="fas fa-angle-down"></i></div>
                            </a>
                            <div class="collapse" id="collapseMenus" aria-labelledby="headingThree" data-bs-parent="#sidenavAccordion">
                                <nav class="sb-sidenav-menu-nested nav">
                                    <a class="nav-link" href="rwt_eks_ter.php">Jadwal & Modul</a>
                                    <a class="nav-link" href="rwt_pra_ter.php">Peralatan Praktikum</a>
                                </nav>
                            </div>
                            <div class="sb-sidenav-menu-heading">Addons</div>
                            <a class="nav-link" href="charts.html">
                                <div class="sb-nav-link-icon"><i class="fas fa-chart-area"></i></div>
                                Charts
                            </a>
                            <a class="nav-link" href="tables.html">
                                <div class="sb-nav-link-icon"><i class="fas fa-table"></i></div>
                                Tables
                            </a>
                        </div>
                    </div>
                    <div class="sb-sidenav-footer">
                        <div class="small">Login sebagai:</div>
                        admin
                    </div>
                </nav>
            </div>
            <div id="layoutSidenav_content">
                <main>
                    <div class="container-fluid px-4">
                        <h1 class="mt-4">Peralatan Praktikum Termofluida Dipinjam</h1>
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
                                            <th>Nama Alat</th>
                                            <th>Tanggal Mulai</th>
                                            <th>Tanggal Selesai</th>
                                            <th>Nama Peminjam</th>
                                            <th>Aksi</th>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        <?php
                                        $ambilsemuadatastok = mysqli_query($conn, "select * from plt_termofluida where status = 1");
                                        $no = 1;
                                        while ($data = mysqli_fetch_array($ambilsemuadatastok)) {
                                            $kode = $data['kode'];
                                            $nama = $data['nama'];
                                            $kondisi = $data['kondisi'];
                                            $tanggal = $data['tanggal'];
                                            $tgl_mulai = $data['tgl_mulai'];
                                            $tgl_selesai = $data['tgl_selesai'];
                                            $id = $data['id'];
                                            $status = $data['status'];
                                            $peminjam = $data['peminjam'];
                                        ?>
                                            <tr>
                                                <td><?= $no++; ?></td>
                                                <td><?= $kode; ?></td>
                                                <td><?= $nama; ?></td>
                                                <td><?= $tgl_mulai; ?></td>
                                                <td><?= $tgl_selesai; ?></td>
                                                <td><?= $peminjam; ?></td>
                                                <td>
                                                    <button type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#selesai<?= $id; ?>">
                                                        Selesai
                                                    </button>
                                                </td>
                                            </tr>

                                            </tr>
                                            <!-- The Modal Selesai -->
                                            <div class="modal fade" id="selesai<?= $id; ?>">
                                                <div class="modal-dialog">
                                                    <div class="modal-content">
                                                        <!-- Modal Header -->
                                                        <div class="modal-header">
                                                            <h4 class="modal-title">Selesai Pinjam ?</h4>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"></button>
                                                        </div>
                                                        <!-- Modal body -->
                                                        <form method="post">
                                                            <div class="modal-body">
                                                                Apakah Anda yakin ingin selesai pinjam <?= $nama; ?>?
                                                                <br>
                                                                <input type="hidden" name="id" value="<?= $id; ?>">
                                                                <br>
                                                                <select name="kondisi" class="form-control" required>
                                                                    <option value="Baik">Baik</option>
                                                                    <option value="Reparasi">Reparasi</option>
                                                                    <option value="Rusak">Rusak</option>
                                                                </select>
                                                                <br>
                                                                <button type="submit" class="btn btn-danger" name="selesaipinjam_ter">Selesai</button>
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
                <?php include '../../footer.php'; ?>
            </div>
        </div>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.3/dist/js/bootstrap.bundle.min.js" crossorigin="anonymous"></script>
        <script src="../../js/scripts.js"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.8.0/Chart.min.js" crossorigin="anonymous"></script>
        <script src="../../assets/demo/chart-area-demo.js"></script>
        <script src="../../assets/demo/chart-bar-demo.js"></script>
        <script src="https://cdn.jsdelivr.net/npm/simple-datatables@7.1.2/dist/umd/simple-datatables.min.js" crossorigin="anonymous"></script>
        <script src="../../js/datatables-simple-demo.js"></script>
    </body>

    </html>

<?php
}
?>