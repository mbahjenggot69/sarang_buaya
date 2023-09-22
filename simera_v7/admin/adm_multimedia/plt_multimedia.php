<?php
require '../../function.php';
require '../../cek.php';

if (!isset($_SESSION['log']) || $_SESSION['role'] !== 'admin') {
    header('location: ../../index.php');
    exit();
} else {
    $username = $_SESSION['username'];

    // Periksa apakah pengguna adalah admin_lab1
    $isAdminLab4 = ($username === 'admin_lab4');
?>

    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge" />
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
        <meta name="description" content="" />
        <meta name="author" content="" />
        <title>Peralatan Laboratorium Multimedia - Sistem Informasi Manajemen Ruangan</title>
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
                                    <a class="nav-link" href="plt_multimedia.php">Manajemen & Pinjam</a>
                                    <a class="nav-link" href="pjm_pra_mul.php">Peralatan Dipinjam</a>
                                </nav>
                            </div>
                            <a class="nav-link collapsed" href="#" data-bs-toggle="collapse" data-bs-target="#collapsePages" aria-expanded="false" aria-controls="collapsePages">
                                <div class="sb-nav-link-icon"><i class="fas fa-list"></i></div>
                                Eksperimen
                                <div class="sb-sidenav-collapse-arrow"><i class="fas fa-angle-down"></i></div>
                            </a>
                            <div class="collapse" id="collapsePages" aria-labelledby="headingTwo" data-bs-parent="#sidenavAccordion">
                                <nav class="sb-sidenav-menu-nested nav">
                                    <a class="nav-link" href="mdl_multimedia.php">Modul</a>
                                    <a class="nav-link" href="jdw_multimedia.php">Jadwal & Modul</a>
                                    <a class="nav-link" href="pjm_eks_mul.php">Peralatan Dipinjam</a>
                                </nav>
                            </div>
                            <a class="nav-link collapsed" href="#" data-bs-toggle="collapse" data-bs-target="#collapseMenus" aria-expanded="false" aria-controls="collapseMenus">
                                <div class="sb-nav-link-icon"><i class="fas fa-history"></i></div>
                                Riwayat
                                <div class="sb-sidenav-collapse-arrow"><i class="fas fa-angle-down"></i></div>
                            </a>
                            <div class="collapse" id="collapseMenus" aria-labelledby="headingThree" data-bs-parent="#sidenavAccordion">
                                <nav class="sb-sidenav-menu-nested nav">
                                    <a class="nav-link" href="rwt_eks_mul.php">Jadwal & Modul</a>
                                    <a class="nav-link" href="rwt_pra_mul.php">Peralatan Praktikum</a>
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
                        <h1 class="mt-4">Peralatan Laboratorium Multimedia</h1>
                        <ol class="breadcrumb mb-4">
                            <li class="breadcrumb-item active">Sistem Informasi Manajemen Ruangan</li>
                        </ol>
                        <div class="card mb-4">
                            <?php if ($isAdminLab4) : ?>
                                <div class="card-header">
                                    <!-- Button to Open the Modal -->
                                    <button type="button" class="btn btn-primary" data-bs-toggle="modal" data-bs-target="#myModal">
                                        Tambah Alat
                                    </button>
                                </div>
                            <?php endif; ?>
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
                                            <?php if ($isAdminLab4) : ?>
                                                <th>Aksi</th>
                                            <?php endif; ?>
                                        </tr>
                                    </thead>
                                    <tbody>
                                        <?php
                                        $ambilsemuadatastok = mysqli_query($conn, "select * from plt_multimedia");
                                        $no = 1;
                                        while ($data = mysqli_fetch_array($ambilsemuadatastok)) {
                                            $kode = $data['kode'];
                                            $nama = $data['nama'];
                                            $harga = $data['harga'];
                                            $kondisi = $data['kondisi'];
                                            $tanggal = $data['tanggal'];
                                            $id = $data['id'];
                                        ?>
                                            <tr>
                                                <td><?= $no++; ?></td>
                                                <td><?= $kode; ?></td>
                                                <td><?= $nama; ?></td>
                                                <td><?= $harga; ?></td>
                                                <td><?= $kondisi; ?></td>
                                                <td><?= $tanggal; ?></td>
                                                <?php if ($isAdminLab4) : ?>
                                                    <td>
                                                        <button type="button" class="btn btn-warning" data-bs-toggle="modal" data-bs-target="#edit<?= $id; ?>">
                                                            Edit
                                                        </button>
                                                        <button type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#hapus<?= $id; ?>">
                                                            Hapus
                                                        </button>
                                                    </td>
                                                <?php endif; ?>
                                            </tr>
                                            <!-- The Modal Edit -->
                                            <div class="modal fade" id="edit<?= $id; ?>">
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
                                                                <input type="text" name="nama" value="<?= $nama; ?>" placeholder="Nama alat..." class="form-control" required>
                                                                <br>
                                                                <input type="text" name="kode" value="<?= $kode; ?>" placeholder="Kode..." class="form-control" required>
                                                                <br>
                                                                <input type="text" name="harga" value="<?= $harga; ?>" placeholder="Harga..." class="form-control" required>
                                                                <br>
                                                                <select name="kondisi" class="form-control" required>
                                                                    <option value="Baik">Baik</option>
                                                                    <option value="Reparasi">Reparasi</option>
                                                                    <option value="Rusak">Rusak</option>
                                                                </select>
                                                                <br>
                                                                <input type="hidden" name="id" value="<?= $id; ?>">
                                                                <button type="submit" class="btn btn-warning" name="editstok_mul">Edit</button>
                                                            </div>
                                                        </form>
                                                    </div>
                                                </div>
                                            </div>
                                            <!-- The Modal Hapus -->
                                            <div class="modal fade" id="hapus<?= $id; ?>">
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
                                                                Apakah Anda yakin ingin menghapus <?= $nama; ?> dengan kode <?= $kode; ?>?
                                                                <input type="hidden" name="id" value="<?= $id; ?>">
                                                                <br>
                                                                <br>
                                                                <button type="submit" class="btn btn-danger" name="hapusstok_mul">Hapus</button>
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
                        <select name="kondisi" class="form-control" required>
                            <option value="Baik">Baik</option>
                            <option value="Reparasi">Reparasi</option>
                            <option value="Rusak">Rusak</option>
                        </select>
                        <br>
                        <button type="submit" class="btn btn-primary" name="tambahstok_mul">Tambah</button>
                    </div>
                </form>
            </div>
        </div>
    </div>

    </html>

<?php
}
?>