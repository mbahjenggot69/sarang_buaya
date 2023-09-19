<?php
function checkAdminAccess()
{
    // Pastikan pengguna sudah masuk dan memiliki peran 'admin'
    if (isset($_SESSION['log']) && $_SESSION['role'] === 'superadmin') {
        // Izinkan akses halaman
        return true;
    }
}


//JIKA BELUM LOGIN
if (isset($_SESSION['log'])) {
} else {
    header('location:index.php');
}
