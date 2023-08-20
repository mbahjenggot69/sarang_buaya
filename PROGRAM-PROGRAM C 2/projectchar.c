#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define max_size 10 //max kalimat

char kalimat[max_size][255]; 
//sebuah variable array global dengan nama kalimat dan type data char[]/string 


void menu() {
	system("cls");
	printf("====================================\n");
	printf("Menu Utama\n");
	printf("====================================\n");
	printf("1. Lihat List Kalimat\n");
	printf("2. Tambah Kalimat\n");
	printf("3. Hapus Kalimat\n");
	printf("4. Exit\n");
	printf("====================================\n");
	printf("Masukkan Pilihan Menu : ");
}

void list_kalimat() {
	system("cls");
	printf("====================================\n");
	printf("Menu List Kalimat\n");
	printf("====================================\n");
	bool ada = false;
	int i;
	
	for (i = 0; i<max_size; i++) {
		if (strlen(kalimat[i]) == 0) { //ketika kosong, maka stop dan ulang fornya
			continue;
		} else {
			ada = true;
			printf("[%d] %s\n",i,kalimat[i]);
		}
	}
	
	if (!ada) {
		printf("Belum ada list kalimat!\n");
	}
	printf("====================================\n");
	system("pause");		
}

void tambah_kalimat() {
	system("cls");
	printf("====================================\n");
	printf("Menu Tambah Kalimat\n");
	printf("====================================\n");
	int total = 0, i;
	
	printf("Indeks yang tersedia : ");
	for (i = 0; i<max_size; i++) {
		if (strlen(kalimat[i]) == 0) { //ketika kosong, maka stop dan ulang fornya
			printf("%d, ",i);
			total++;
		}
	}
	
	printf("\n");
	
	if (total > 0) {
		int indeks = -1;
		char simpan[255];
		
		printf("Pilih indeks : ");
		scanf("%d", &indeks);
		if (indeks > max_size-1 || indeks < 0) {
			printf("Indeks tidak tersedia!\n");
		} else {
			if (strlen(kalimat[indeks]) == 0) {
				printf("Masukkan kalimat untuk disimpan pada indeks-%d : ",indeks);
				scanf(" %[^\n]%*c", &simpan); //untuk input string
				
				strcpy(kalimat[indeks], simpan); //masukin kalimat (dari variable simpan) ke array (kalimat) sesuai dengan indeks
				printf("\nSukses menyimpan kalimat pada indeks ke %d!\n",indeks);
			} else {
				printf("Indeks tidak tersedia!\n");
			}
		}
	} else {
		printf("Tidak ada!\n");
	}
	
	printf("====================================\n");
	system("pause");	
}

void hapus_kalimat() {
	system("cls");
	printf("====================================\n");
	printf("Menu Hapus Kalimat\n");
	printf("====================================\n");
	bool ada = false;
	int i;
	
	for (i = 0; i<max_size; i++) {
		if (strlen(kalimat[i]) == 0) { //ketika kosong, maka stop dan ulang fornya
			continue;
		} else {
			ada = true;
			printf("[%d] %s\n",i,kalimat[i]);
		}
	}
	
	if (!ada) {
		printf("Belum ada list kalimat!\n");
	} else {
		printf("====================================\n");
		int indeks = -1;
		
		printf("\nPilih indeks untuk dihapus : ");
		scanf("%d", &indeks);
		if (indeks > max_size-1 || indeks < 0) {
			printf("Gagal hapus!\n");
		} else {
			if (strlen(kalimat[indeks]) > 0) {
				strcpy(kalimat[indeks], ""); //kosongin nilainya
				printf("\nSukses hapus kalimat pada indeks ke-%d!\n",indeks);
			} else {
				printf("Gagal hapus!\n");
			}
		}
		
	}
	
	printf("====================================\n");
	system("pause");	
}


void main() {
	int i, pilihan;
	
	for (i = 0; i < max_size; i++) {
		strcpy(kalimat[i], ""); //inisialisasi nilai kosong
	}
	
	do {
		menu();
		scanf("%d", &pilihan);
		
		if (pilihan == 1) {
			list_kalimat();
		} else if (pilihan == 2) {
			tambah_kalimat();
		} else if (pilihan == 3) {
			hapus_kalimat();
		} else if (pilihan == 4) {
			printf("Goodbye!");
		}
	} while (pilihan != 4);
}
