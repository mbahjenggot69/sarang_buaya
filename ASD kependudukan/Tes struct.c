/*	Contoh Penggunaan Struct dengan File Handling Sederhana 
	Author: Yanuarchr
	23, February 2023 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

char buffer[200];
FILE *fp; // pointer untuk file
char ch, fileName[] = "Kependudukan.txt"; //buatlah sebuah file dengan ext .txt dengan syarat satu folder dengan file .C ini
int i=1;

struct penduduk{ // penggunaan struct 
	char nik[20], nama[20], lahir[20], hp[20], email[20];
};


void menu(){
	system("cls");
    printf("KEPENDUDUKAN DESA KONOHA \n");
    printf("1. TAMBAH DATA PENDUDUK \n");
	printf("2. LIHAT DATA PENDUDUK \n"); 
	printf("3. EXIT \n");
    printf("PILIH MENU : ");
}

void menu1(){
	system("cls");
    printf("TAMBAH DATA PENDUDUK\n");
	struct penduduk pdd; //panggil struct yang sudah dibuat
	printf("NIK: ");
	scanf(" %s", &pdd.nik);
	printf("\nNama: ");
	scanf (" %[^\n]%*c", &pdd.nama);
	printf("\nTanggal Lahir: ");
	scanf (" %[^\n]%*c", &pdd.lahir);
	printf("\nNomor HP: ");
	scanf (" %s", &pdd.hp);
	printf("\nEmail: ");
	scanf (" %[^\n]%*c", &pdd.email);
	
	// dalam code ini saya menggunakan perintah snprintf untuk meng "concate" inputan menjadi 1 string yang ditampung dalam array buffer
	snprintf(buffer, sizeof buffer, "%d. NIK: %s | Nama: %s | Tanggal Lahir: %s | Nomor HP: %s | Email: %s\n",i,pdd.nik,pdd.nama,pdd.email,pdd.hp,pdd.lahir); 
	i++;
	
	fp = fopen(fileName,"a+"); // buka file kalian dan gunakan method "a+" untuk append
	fputs(buffer, fp); // masukkan string ke dalam file .txt
	fclose(fp); // tutup
   	system("pause");	
}

void menu2(){
	system("cls");
    printf("LIHAT DATA PENDUDUK\n");
	fp = fopen(fileName, "r"); // buka file kalian dan gunakan method "r" untuk read
	if (fp == "null"){
		printf("GAGAL BUKA FILE!");
		exit(1);
	}
	while ((ch = fgetc(fp)) != EOF){ // mendapatkan record dari file sampai EOF (end of file)
		printf("%c", ch); // cetak
	} 
	printf("\n\n");
	system("pause");
	fclose(fp); // tutup
}

int main(){
	system("color 9F");
	int pilih;
	do {
		menu();
		scanf("%d",&pilih);
		if (pilih == 1){
			menu1();
		} else if (pilih == 2){
			menu2();
		} else if (pilih == 3){
			exit(0);
		} else {
			printf ("\nINPUTAN ANDA SALAH!\n\n");
			printf("Tekan Enter untuk kembali ke menu utama!");
			getch();
			main();
		}
	}
	while (pilih != 3);
	return 0;
}

