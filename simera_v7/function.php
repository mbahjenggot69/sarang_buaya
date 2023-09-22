<?php
session_start();

// KONEKSI KE DATABASE
$conn = mysqli_connect("localhost","root","","simera");

// TAMBAH LAB
if(isset($_POST['tambahlab'])){
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $fakultas = $_POST['fakultas'];
    $kapasitas = $_POST['kapasitas'];
    $laboran = $_POST['laboran'];

    $tambahketabel = mysqli_query($conn,"insert into laboratorium (kode,nama,fakultas,kapasitas,laboran) values('$kode','$nama','$fakultas','$kapasitas','$laboran')");

    if($tambahketabel){
        header('location:main.php');
    } else {
        echo 'Gagal';
        header('location:main.php');
    }
}

// EDIT LAB
if(isset($_POST['editlab'])){
    $id = $_POST['id'];
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $fakultas = $_POST['fakultas'];
    $kapasitas = $_POST['kapasitas'];
    $laboran = $_POST['laboran'];

    $editdaritabel = mysqli_query($conn,"update laboratorium set kode='$kode',nama='$nama',fakultas='$fakultas',kapasitas='$kapasitas',laboran='$laboran' where id='$id'");
    
    if($editdaritabel){
        header('location:main.php');
    } else {
        echo 'Gagal';
        header('location:main.php');
    }
}

// HAPUS LAB
if(isset($_POST['hapuslab'])){
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn,"delete from laboratorium where id='$id'");
    
    if($hapusdaritabel){
        header('location:main.php');
    } else {
        echo 'Gagal';
        header('location:main.php');
    }
}

// TAMBAH ALAT ANATOMI
if(isset($_POST['tambahstok_ana'])){
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $tambahketabel = mysqli_query($conn,"insert into plt_anatomi (nama,kode,harga,kondisi) values('$nama','$kode','$harga','$kondisi')");

    if($tambahketabel){
        header('location:plt_anatomi.php');
    } else {
        echo 'Gagal';
        header('location:plt_anatomi.php');
    }
}

// TAMBAH ALAT HIDRODINAMIKA
if (isset($_POST['tambahstok_hid'])) {
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $tambahketabel = mysqli_query($conn, "insert into plt_hidrodinamika(nama,kode,harga,kondisi) values('$nama','$kode','$harga','$kondisi')");

    if ($tambahketabel) {
        header('location:plt_hidrodinamika.php');
    } else {
        echo 'Gagal';
        header('location:plt_hidrodinamika.php');
    }
}

// TAMBAH ALAT KOMPUTASI
if (isset($_POST['tambahstok_kom'])) {
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $tambahketabel = mysqli_query($conn, "insert into plt_komputasi(nama,kode,harga,kondisi) values('$nama','$kode','$harga','$kondisi')");

    if ($tambahketabel) {
        header('location:plt_komputasi.php');
    } else {
        echo 'Gagal';
        header('location:plt_komputasi.php');
    }
}

// TAMBAH ALAT MULTIMEDIA
if (isset($_POST['tambahstok_mul'])) {
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $tambahketabel = mysqli_query($conn, "insert into plt_multimedia(nama,kode,harga,kondisi) values('$nama','$kode','$harga','$kondisi')");

    if ($tambahketabel) {
        header('location:plt_multimedia.php');
    } else {
        echo 'Gagal';
        header('location:plt_multimedia.php');
    }
}

// TAMBAH ALAT TERMOFLUIDA
if (isset($_POST['tambahstok_ter'])) {
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $tambahketabel = mysqli_query($conn, "insert into plt_termofluida(nama,kode,harga,kondisi) values('$nama','$kode','$harga','$kondisi')");

    if ($tambahketabel) {
        header('location:plt_termofluida.php');
    } else {
        echo 'Gagal';
        header('location:plt_termofluida.php');
    }
}

// EDIT ALAT ANATOMI
if(isset($_POST['editstok_ana'])){
    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $editdaritabel = mysqli_query($conn,"update plt_anatomi set nama='$nama',kode='$kode',harga='$harga',kondisi='$kondisi' where id='$id'");
    
    if($editdaritabel){
        header('location:plt_anatomi.php');
    } else {
        echo 'Gagal';
        header('location:plt_anatomi.php');
    }
}

// EDIT ALAT HIDRODINAMIKA
if (isset($_POST['editstok_hid'])) {
    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $editdaritabel = mysqli_query($conn, "update plt_hidrodinamika set nama='$nama',kode='$kode',harga='$harga',kondisi='$kondisi' where id='$id'");

    if ($editdaritabel) {
        header('location:plt_hidrodinamika.php');
    } else {
        echo 'Gagal';
        header('location:plt_hidrodinamika.php');
    }
}

// EDIT ALAT KOMPUTASI
if (isset($_POST['editstok_kom'])) {
    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $editdaritabel = mysqli_query($conn, "update plt_komputasi set nama='$nama',kode='$kode',harga='$harga',kondisi='$kondisi' where id='$id'");

    if ($editdaritabel) {
        header('location:plt_komputasi.php');
    } else {
        echo 'Gagal';
        header('location:plt_komputasi.php');
    }
}

// EDIT ALAT MULTIMEDIA
if (isset($_POST['editstok_mul'])) {
    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $editdaritabel = mysqli_query($conn, "update plt_multimedia set nama='$nama',kode='$kode',harga='$harga',kondisi='$kondisi' where id='$id'");

    if ($editdaritabel) {
        header('location:plt_multimedia.php');
    } else {
        echo 'Gagal';
        header('location:plt_multimedia.php');
    }
}

// EDIT ALAT TERMOFLUIDA
if (isset($_POST['editstok_ter'])) {
    $id = $_POST['id'];
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $editdaritabel = mysqli_query($conn, "update plt_termofluida set nama='$nama',kode='$kode',harga='$harga',kondisi='$kondisi' where id='$id'");

    if ($editdaritabel) {
        header('location:plt_termofluida.php');
    } else {
        echo 'Gagal';
        header('location:plt_termofluida.php');
    }
}

// HAPUS ALAT ANATOMI
if (isset($_POST['hapusstok_ana'])) {
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn, "delete from plt_anatomi where id='$id'");

    if ($hapusdaritabel) {
        header('location:plt_anatomi.php');
    } else {
        echo 'Gagal';
        header('location:plt_anatomi.php');
    }
}

// HAPUS ALAT HIDRODINAMIKA
if (isset($_POST['hapusstok_hid'])) {
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn, "delete from plt_hidrodinamika where id='$id'");

    if ($hapusdaritabel) {
        header('location:plt_hidrodinamika.php');
    } else {
        echo 'Gagal';
        header('location:plt_hidrodinamika.php');
    }
}

// HAPUS ALAT KOMPUTASI
if (isset($_POST['hapusstok_kom'])) {
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn, "delete from plt_komputasi where id='$id'");

    if ($hapusdaritabel) {
        header('location:plt_komputasi.php');
    } else {
        echo 'Gagal';
        header('location:plt_komputasi.php');
    }
}

// HAPUS ALAT MULTIMEDIA
if (isset($_POST['hapusstok_mul'])) {
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn, "delete from plt_multimedia where id='$id'");

    if ($hapusdaritabel) {
        header('location:plt_multimedia.php');
    } else {
        echo 'Gagal';
        header('location:plt_multimedia.php');
    }
}

// HAPUS ALAT TERMOFLUIDA
if (isset($_POST['hapusstok_ter'])) {
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn, "delete from plt_termofluida where id='$id'");

    if ($hapusdaritabel) {
        header('location:plt_termofluida.php');
    } else {
        echo 'Gagal';
        header('location:plt_termofluida.php');
    }
}

// PINJAM ALAT ANATOMI
if (isset($_POST['pinjamtastok_ana'])) {
    $nama = $_POST['nama'];
    $kode = $_POST['kode'];
    $harga = $_POST['harga'];
    $kondisi = $_POST['kondisi'];

    $tambahketabel = mysqli_query($conn, "insert into plt_anatomi(nama,kode,harga,kondisi) values('$nama','$kode','$harga','$kondisi')");

    if ($tambahketabel) {
        header('location:plt_termofluida.php');
    } else {
        echo 'Gagal';
        header('location:plt_termofluida.php');
    }
}

// TAMBAH ADMIN
if(isset($_POST['tambahadmin'])){
    $nama = $_POST['nama'];
    $email = $_POST['email'];
    $username = $_POST['username'];
    $password = $_POST['password'];

    $tambahketabel = mysqli_query($conn,"insert into login (nama,email,username,password,role) values('$nama','$email','$username','$password','admin')");

    if($tambahketabel){
        header('location:kel_admin.php');
    } else {
        echo 'Gagal';
        header('location:kel_admin.php');
    }
}

// EDIT ADMIN
if(isset($_POST['editadmin'])){
    $id = $_POST['id'];
    $username = $_POST['username'];
    $password = $_POST['password'];

    $editdaritabel = mysqli_query($conn,"update login set username='$username',password='$password' where id='$id'");
    
    if($editdaritabel){
        header('location:kel_admin.php');
    } else {
        echo 'Gagal';
        header('location:kel_admin.php');
    }
}

// HAPUS ADMIN
if(isset($_POST['hapusadmin'])){
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn,"delete from login where id='$id'");
    
    if($hapusdaritabel){
        header('location:kel_admin.php');
    } else {
        echo 'Gagal';
        header('location:kel_admin.php');
    }
}

// TAMBAH USER
if(isset($_POST['tambahuser'])){
    $nama = $_POST['nama'];
    $email = $_POST['email'];
    $username = $_POST['username'];
    $password = $_POST['password'];

    $tambahketabel = mysqli_query($conn,"insert into login (nama,email,username,password,role) values('$nama','$email','$username','$password','user')");

    if($tambahketabel){
        header('location:kel_user.php');
    } else {
        echo 'Gagal';
        header('location:kel_user.php');
    }
}

// EDIT USER
if(isset($_POST['edituser'])){
    $id = $_POST['id'];
    $username = $_POST['username'];
    $password = $_POST['password'];

    $editdaritabel = mysqli_query($conn,"update login set username='$username',password='$password' where id='$id'");
    
    if($editdaritabel){
        header('location:kel_user.php');
    } else {
        echo 'Gagal';
        header('location:kel_user.php');
    }
}

// HAPUS USER
if(isset($_POST['hapususer'])){
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn,"delete from login where id='$id'");
    
    if($hapusdaritabel){
        header('location:kel_user.php');
    } else {
        echo 'Gagal';
        header('location:kel_user.php');
    }
}

// TAMBAH JADWAL ANATOMI
if(isset($_POST['tambahjadwal_ana'])){
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $modul = $_POST['modul'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];

    $tambahketabel = mysqli_query($conn, "insert into jdw_anatomi (kode,nama,modul,tgl_mulai,tgl_selesai) values('Anatomi','$nama','$modul','$tgl_mulai','$tgl_selesai')");

    if($tambahketabel){
        header('location:jdw_anatomi.php');
    } 
    else {
        echo 'Gagal';
        header('location:jdw_anatomi.php');
    }
}

// TAMBAH JADWAL HIDRODINAMIKA
if (isset($_POST['tambahjadwal_hid'])) {
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];

    $tambahketabel = mysqli_query($conn, "insert into jdw_hidrodinamika (kode,nama,tgl_mulai,tgl_selesai) values('Hidrodinamika','$nama','$tgl_mulai','$tgl_selesai')");

    if ($tambahketabel) {
        header('location:jdw_hidrodinamika.php');
    } else {
        echo 'Gagal';
        header('location:jdw_hidrodinamika.php');
    }
}

// TAMBAH JADWAL KOMPUTASI
if (isset($_POST['tambahjadwal_kom'])) {
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];

    $tambahketabel = mysqli_query($conn, "insert into jdw_komputasi (kode,nama,tgl_mulai,tgl_selesai) values('Hidrodinamika','$nama','$tgl_mulai','$tgl_selesai')");

    if ($tambahketabel) {
        header('location:jdw_komputasi.php');
    } else {
        echo 'Gagal';
        header('location:jdw_komputasi.php');
    }
}

// TAMBAH JADWAL MULTIMEDIA
if (isset($_POST['tambahjadwal_mul'])) {
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];

    $tambahketabel = mysqli_query($conn, "insert into jdw_multimedia (kode,nama,tgl_mulai,tgl_selesai) values('Hidrodinamika','$nama','$tgl_mulai','$tgl_selesai')");

    if ($tambahketabel) {
        header('location:jdw_multimedia.php');
    } else {
        echo 'Gagal';
        header('location:jdw_multimedia.php');
    }
}

// TAMBAH JADWAL TERMOFLUIDA
if (isset($_POST['tambahjadwal_ter'])) {
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];

    $tambahketabel = mysqli_query($conn, "insert into jdw_termofluida (kode,nama,tgl_mulai,tgl_selesai) values('Hidrodinamika','$nama','$tgl_mulai','$tgl_selesai')");

    if ($tambahketabel) {
        header('location:jdw_termofluida.php');
    } else {
        echo 'Gagal';
        header('location:jdw_termofluida.php');
    }
}

// TAMBAH MODUL ANATOMI
if(isset($_POST['tambahmodul_ana'])){
    $kode = $_POST['kode'];
    $nama = $_POST['nama'];

    $tambahketabel = mysqli_query($conn, "insert into mdl_anatomi (kode,nama) values('$kode','$nama')");

    if($tambahketabel){
        header('location:mdl_anatomi.php');
    } 
    else {
        echo 'Gagal';
        header('location:mdl_anatomi.php');
    }
}

// HAPUS MODUL ANATOMI
if (isset($_POST['hapusmodul_ana'])) {
    $id = $_POST['id'];

    $hapusdaritabel = mysqli_query($conn, "delete from mdl_anatomi where id='$id'");

    if ($hapusdaritabel) {
        header('location:mdl_anatomi.php');
    } else {
        echo 'Gagal';
        header('location:mdl_anatomi.php');
    }
}

// PINJAM ALAT ANATOMI
if (isset($_POST['pinjamstok_ana'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $peminjam = $_POST['peminjam'];

    if ($tgl_selesai < $tgl_mulai) {
        $_SESSION['notification'] = [
            'type' => 'danger',
            'message' => 'Tanggal selesai tidak dapat lebih awal dari tanggal pinjam !'
        ];
        header('location:plt_anatomi.php');
        exit();
    }

    // SET STATUS PINJAM = 1
    $pinjamdaristok = mysqli_query($conn, "update plt_anatomi set status = 1, tgl_mulai = '$tgl_mulai',tgl_selesai = '$tgl_selesai', peminjam ='$peminjam'  WHERE id = $id");

    if ($pinjamdaristok) {
        $_SESSION['notification'] = [
            'type' => 'success',
            'message' => 'Berhasil pinjam alat mohon periksa halaman peralatan dipinjam !'
        ];
        header('location:plt_anatomi.php');
        exit();
    } else {
        header('location:plt_anatomi.php');
    }
}

// SELESAI PINJAM ANATOMI
if (isset($_POST['selesaipinjam_ana'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $kondisi = $_POST['kondisi'];

    // SET STATUS SELESAI = 0
    $selesaipinjam = mysqli_query($conn, "UPDATE plt_anatomi SET kondisi = '$kondisi', status = 0, tgl_selesai = now() WHERE id = '$id'");

    if ($selesaipinjam) {
        header('location:pjm_pra_ana.php');
    } else {
        header('location:pjm_pra_ana.php');
    }
}

// PINJAM ALAT HIDRODINAMIKA
if (isset($_POST['pinjamstok_hid'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $peminjam = $_POST['peminjam'];

    if ($tgl_selesai < $tgl_mulai) {
        $_SESSION['notification'] = [
            'type' => 'danger',
            'message' => 'Tanggal selesai tidak dapat lebih awal dari tanggal pinjam !'
        ];
        header('location:plt_hidrodinamika.php');
        exit();
    }

    // SET STATUS PINJAM = 1
    $pinjamdaristok = mysqli_query($conn, "update plt_hidrodinamika set status = 1, tgl_mulai = '$tgl_mulai',tgl_selesai = '$tgl_selesai', peminjam ='$peminjam'  WHERE id = $id");

    if ($pinjamdaristok) {
        $_SESSION['notification'] = [
            'type' => 'success',
            'message' => 'Berhasil pinjam alat mohon periksa halaman peralatan dipinjam !'
        ];
        header('location:plt_hidrodinamika.php');
        exit();
    } else {
        header('location:plt_hidrodinamika.php');
    }
}

// SELESAI PINJAM HIDRODINAMIKA
if (isset($_POST['selesaipinjam_hid'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $kondisi = $_POST['kondisi'];

    // SET STATUS SELESAI = 0
    $selesaipinjam = mysqli_query($conn, "UPDATE plt_hidrodinamika SET kondisi = '$kondisi', status = 0, tgl_selesai = now() WHERE id = '$id'");

    if ($selesaipinjam) {
        header('location:pjm_pra_hid.php');
    } else {
        header('location:pjm_pra_hid.php');
    }
}

// PINJAM ALAT KOMPUTASI
if (isset($_POST['pinjamstok_kom'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $peminjam = $_POST['peminjam'];

    if ($tgl_selesai < $tgl_mulai) {
        $_SESSION['notification'] = [
            'type' => 'danger',
            'message' => 'Tanggal selesai tidak dapat lebih awal dari tanggal pinjam !'
        ];
        header('location:plt_komputasi.php');
        exit();
    }

    // SET STATUS PINJAM = 1
    $pinjamdaristok = mysqli_query($conn, "update plt_komputasi set status = 1, tgl_mulai = '$tgl_mulai',tgl_selesai = '$tgl_selesai', peminjam ='$peminjam'  WHERE id = $id");

    if ($pinjamdaristok) {
        $_SESSION['notification'] = [
            'type' => 'success',
            'message' => 'Berhasil pinjam alat mohon periksa halaman peralatan dipinjam !'
        ];
        header('location:plt_komputasi.php');
        exit();
    } else {
        header('location:plt_komputasi.php');
    }
}

// SELESAI PINJAM KOMPUTASI
if (isset($_POST['selesaipinjam_kom'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $kondisi = $_POST['kondisi'];

    // SET STATUS SELESAI = 0
    $selesaipinjam = mysqli_query($conn, "UPDATE plt_komputasi SET kondisi = '$kondisi', status = 0, tgl_selesai = now() WHERE id = '$id'");

    if ($selesaipinjam) {
        header('location:pjm_pra_kom.php');
    } else {
        header('location:pjm_pra_kom.php');
    }
}

// PINJAM ALAT MULTIMEDIA
if (isset($_POST['pinjamstok_mul'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $peminjam = $_POST['peminjam'];

    if ($tgl_selesai < $tgl_mulai) {
        $_SESSION['notification'] = [
            'type' => 'danger',
            'message' => 'Tanggal selesai tidak dapat lebih awal dari tanggal pinjam !'
        ];
        header('location:plt_multimedia.php');
        exit();
    }

    // SET STATUS PINJAM = 1
    $pinjamdaristok = mysqli_query($conn, "update plt_multimedia set status = 1, tgl_mulai = '$tgl_mulai',tgl_selesai = '$tgl_selesai', peminjam ='$peminjam'  WHERE id = $id");

    if ($pinjamdaristok) {
        $_SESSION['notification'] = [
            'type' => 'success',
            'message' => 'Berhasil pinjam alat mohon periksa halaman peralatan dipinjam !'
        ];
        header('location:plt_multimedia.php');
        exit();
    } else {
        header('location:plt_multimedia.php');
    }
}

// SELESAI PINJAM MULTIMEDIA
if (isset($_POST['selesaipinjam_mul'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $kondisi = $_POST['kondisi'];

    // SET STATUS SELESAI = 0
    $selesaipinjam = mysqli_query($conn, "UPDATE plt_multimedia SET kondisi = '$kondisi', status = 0, tgl_selesai = now() WHERE id = '$id'");

    if ($selesaipinjam) {
        header('location:pjm_pra_mul.php');
    } else {
        header('location:pjm_pra_mul.php');
    }
}

// PINJAM ALAT TERMOFLUIDA
if (isset($_POST['pinjamstok_ter'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $peminjam = $_POST['peminjam'];

    if ($tgl_selesai < $tgl_mulai) {
        $_SESSION['notification'] = [
            'type' => 'danger',
            'message' => 'Tanggal selesai tidak dapat lebih awal dari tanggal pinjam !'
        ];
        header('location:plt_termofluida.php');
        exit();
    }

    // SET STATUS PINJAM = 1
    $pinjamdaristok = mysqli_query($conn, "update plt_termofluida set status = 1, tgl_mulai = '$tgl_mulai',tgl_selesai = '$tgl_selesai', peminjam ='$peminjam'  WHERE id = $id");

    if ($pinjamdaristok) {
        $_SESSION['notification'] = [
            'type' => 'success',
            'message' => 'Berhasil pinjam alat mohon periksa halaman peralatan dipinjam !'
        ];
        header('location:plt_termofluida.php');
        exit();
    } else {
        header('location:plt_termofluida.php');
    }
}

// SELESAI PINJAM TERMOFLUIDA
if (isset($_POST['selesaipinjam_ter'])) {
    $id = $_POST['id'];
    $tgl_mulai = $_POST['tgl_mulai'];
    $tgl_selesai = $_POST['tgl_selesai'];
    $kondisi = $_POST['kondisi'];

    // SET STATUS SELESAI = 0
    $selesaipinjam = mysqli_query($conn, "UPDATE plt_termofluida SET kondisi = '$kondisi', status = 0, tgl_selesai = now() WHERE id = '$id'");

    if ($selesaipinjam) {
        header('location:pjm_pra_ter.php');
    } else {
        header('location:pjm_pra_ter.php');
    }
}

// SALIN DATA ALAT ANATOMI
if (isset($_POST['selesaipinjam_ana'])) {
    $id = $_POST['id'];

    // Salin data dari tabel plt_anatomi ke tabel rwt_pra_ana
    $salindata = mysqli_query($conn, "INSERT INTO rwt_pra_ana (id, kode, nama, tgl_mulai, tgl_selesai, peminjam)
                    SELECT id, kode, nama, tgl_mulai, tgl_selesai, peminjam
                    FROM plt_anatomi
                    WHERE id = '$id'");

    if ($salindata) {
        header('location:pjm_pra_ana.php');
    } else {
        echo 'Gagal';
        header('location:pjm_pra_ana.php');
    }
}

// PINDAH DATA JADWAL ANATOMI
if (isset($_POST['selesaijadwal_ana'])) {
    $id = $_POST['id'];

    // Salin data dari tabel pesan ke tabel riwayat
    $pindahtabel = mysqli_query($conn, "INSERT INTO rwt_eks_ana (kode, nama, tgl_mulai, tgl_selesai) 
                                    SELECT kode, nama, tgl_mulai, tgl_selesai 
                                    FROM jdw_anatomi 
                                    WHERE id = '$id'");

    // Hapus data dari tabel pesan berdasarkan idalat
    $hapusdaritabel = mysqli_query($conn, "DELETE FROM jdw_anatomi WHERE id = '$id'");

    if ($hapusdaritabel) {
        header('location:jdw_anatomi.php');
    } else {
        echo 'Gagal';
        header('location:jdw_anatomi.php');
    }
}

// PINDAH DATA JADWAL HIDRODINAMIKA
if (isset($_POST['selesaijadwal_hid'])) {
    $id = $_POST['id'];

    // Salin data dari tabel pesan ke tabel riwayat
    $pindahtabel = mysqli_query($conn, "INSERT INTO rwt_eks_hid (kode, nama, tgl_mulai, tgl_selesai) 
                                    SELECT kode, nama, tgl_mulai, tgl_selesai 
                                    FROM jdw_hidrodinamika 
                                    WHERE id = '$id'");

    // Hapus data dari tabel pesan berdasarkan idalat
    $hapusdaritabel = mysqli_query($conn, "DELETE FROM jdw_hidrodinamika WHERE id = '$id'");

    if ($hapusdaritabel) {
        header('location:jdw_hidrodinamika.php');
    } else {
        echo 'Gagal';
        header('location:jdw_hidrodinamika.php');
    }
}

// PINDAH DATA JADWAL KOMPUTASI
if (isset($_POST['selesaijadwal_kom'])) {
    $id = $_POST['id'];

    // Salin data dari tabel pesan ke tabel riwayat
    $pindahtabel = mysqli_query($conn, "INSERT INTO rwt_eks_kom (kode, nama, tgl_mulai, tgl_selesai) 
                                    SELECT kode, nama, tgl_mulai, tgl_selesai 
                                    FROM jdw_komputasi 
                                    WHERE id = '$id'");

    // Hapus data dari tabel pesan berdasarkan idalat
    $hapusdaritabel = mysqli_query($conn, "DELETE FROM jdw_komputasi WHERE id = '$id'");

    if ($hapusdaritabel) {
        header('location:jdw_komputasi.php');
    } else {
        echo 'Gagal';
        header('location:jdw_komputasi.php');
    }
}

// PINDAH DATA JADWAL MULTIMEDIA
if (isset($_POST['selesaijadwal_mul'])) {
    $id = $_POST['id'];

    // Salin data dari tabel pesan ke tabel riwayat
    $pindahtabel = mysqli_query($conn, "INSERT INTO rwt_eks_mul (kode, nama, tgl_mulai, tgl_selesai) 
                                    SELECT kode, nama, tgl_mulai, tgl_selesai 
                                    FROM jdw_multimedia 
                                    WHERE id = '$id'");

    // Hapus data dari tabel pesan berdasarkan idalat
    $hapusdaritabel = mysqli_query($conn, "DELETE FROM jdw_multimedia WHERE id = '$id'");

    if ($hapusdaritabel) {
        header('location:jdw_multimedia.php');
    } else {
        echo 'Gagal';
        header('location:jdw_multimedia.php');
    }
}

// PINDAH DATA JADWAL TERMOFLUIDA
if (isset($_POST['selesaijadwal_ter'])) {
    $id = $_POST['id'];

    // Salin data dari tabel pesan ke tabel riwayat
    $pindahtabel = mysqli_query($conn, "INSERT INTO rwt_eks_ter (kode, nama, tgl_mulai, tgl_selesai) 
                                    SELECT kode, nama, tgl_mulai, tgl_selesai 
                                    FROM jdw_termofluida 
                                    WHERE id = '$id'");

    // Hapus data dari tabel pesan berdasarkan idalat
    $hapusdaritabel = mysqli_query($conn, "DELETE FROM jdw_termofluida WHERE id = '$id'");

    if ($hapusdaritabel) {
        header('location:jdw_termofluida.php');
    } else {
        echo 'Gagal';
        header('location:jdw_termofluida.php');
    }
}
