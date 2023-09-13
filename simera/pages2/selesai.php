<?php
$conn = mysqli_connect("localhost", "root", "", "simera");

$kode = $_POST['kode']; // Sesuaikan dengan nama field yang sesuai pada tombol "Selesai"
$query = "SELECT * FROM pesan WHERE kode = ?";
$stmt = mysqli_prepare($conn, $query);
mysqli_stmt_bind_param($stmt, 's', $kode);
mysqli_stmt_execute($stmt);
$result = mysqli_stmt_get_result($stmt);

if ($row = mysqli_fetch_assoc($result)) {
    // Ambil data pemesanan
    $namaalat = $row['namaalat'];
    $tanggalpesan = $row['tanggalpesan'];
    $bataswaktu = $row['bataswaktu'];

    // Kemudian, masukkan data ini ke dalam tabel "historypesan"
    $queryInsert = "INSERT INTO historypesan (kode, namaalat, tanggalpesan, bataswaktu) VALUES (?, ?, ?, ?)";
    $stmtInsert = mysqli_prepare($conn, $queryInsert);
    mysqli_stmt_bind_param($stmtInsert, 'ssss', $kode, $namaalat, $tanggalpesan, $bataswaktu);
    mysqli_stmt_execute($stmtInsert);

    // Setelah data pindah ke "historypesan," Anda dapat menghapusnya dari "pesan"
    $queryDelete = "DELETE FROM pesan WHERE kode = ?";
    $stmtDelete = mysqli_prepare($conn, $queryDelete);
    mysqli_stmt_bind_param($stmtDelete, 's', $kode);
    mysqli_stmt_execute($stmtDelete);

    // Berikan respons OK
    http_response_code(200);
} else {
    // Data tidak ditemukan, berikan respons kesalahan
    http_response_code(404);
}
