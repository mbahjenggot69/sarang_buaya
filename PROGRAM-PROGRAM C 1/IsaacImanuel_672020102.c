#include <stdio.h>
#include <stdlib.h>

struct databarang {
	char perusahaan[100], nama[50];
	int kg,harga,stok;
} data;

void menu_1(){
	system("cls");
	printf("===== Menu 1 : Isi Data =====\n");
	printf("Perusahaan		= "); scanf("%s", &data.perusahaan);
	printf("Nama Barang		= "); scanf("%s", &data.nama);
	printf("Berat Barang (kg)	= "); scanf("%d", &data.kg);
	printf("Harga			= "); scanf("%d", &data.harga);
	printf("Stok Barang		= "); scanf("%d", &data.stok);
}
void menu_2(){
	system("cls");
	printf("===== Menu 2 : Lihat Data =====\n");
	printf("Perusahaan		= %s\n", &data.perusahaan);
	printf("Nama Barang		= %s\n", &data.nama);
	printf("Berat Barang (kg)	= %d Kg\n",data.kg);
	printf("Harga			= Rp.%d\n",data.harga);
	printf("Stok Barang		= %d\n",data.stok);
}
void main () {
	int menu;
	do {

 	printf("===== Data Barang =====\n");
 	printf("1. Isi Data \n");
 	printf("2. Lihat data \n");
 	printf("3. Selesai \n");
 	printf("Pilihan Menu : ");
 	scanf( "%d", &menu); 	
 	
 	
 	switch(menu) {

 	case 1 :
 		menu_1();
		break; 
		
 	case 2 :
 		menu_2();
 		break;
 		
 	case 3 :
 		exit(0);
 		default :
 	
 		system("cls");
		break;
 		}
 	}
 	while(menu != 3);
 }
