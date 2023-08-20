#include <stdio.h>

void informasi_diri(char nim[], char nama[], char goldarah) {
	printf("NIM : %s\n",nim);
	printf("Nama : %s\n",nama);
	printf("Golongan Darah : %c\n",goldarah);
}

void header() {
	printf("=======================\n");
	printf("HALO GUYS!!!\n");
	printf("=======================\n");
}

void footer() {
	printf("=======================\n");
	printf("THANK YOU!!!\n");
	printf("=======================\n");
}

void body(char nim[], char nama[], char goldarah) {
	header();
	informasi_diri(nim, nama, goldarah);
	footer();
}

void main() {
	char nim[] = "672018001";
	char name[] = "NAMA SAYA";
	char golongan = 'A';
	body(nim,name,golongan);
}

