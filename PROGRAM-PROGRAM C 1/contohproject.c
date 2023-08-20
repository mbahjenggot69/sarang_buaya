#include <stdio.h>

void menu_utama() {
	system("cls");
	printf("====================================\n");
	printf("Menu Utama\n");
	printf("====================================\n");
	printf("1. Segitiga Diamond\n");
	printf("2. Kuis 2\n");
	printf("3. Rekursif (Pangkat)\n");
	printf("4. Exit\n");
	printf("====================================\n");
	printf("Masukkan Pilihan Menu : ");
}

void menu1() {
	system("cls");
	printf("====================================\n");
	printf("Menu Segitiga Diamond\n");
	printf("====================================\n");
	int batas;
	
	printf("Masukkan Batas (1 - 10) : ");
	scanf("%d",&batas);
	
	if (batas < 1 || batas > 10) {
		printf("Batas hanya boleh 1 - 10!\n");
		menu1();
		system("pause");
	} else {
		int i, j;
		for (i = 0; i < batas; i++) {
			for (j = batas-i; j > 1; j--) {
				printf(" ");
			}
			
			for (j = 0; j <= i*2; j++) {
				printf("*");
			}
			printf("\n");
		}
		
		for (i = batas-2; i >= 0; i--) {
			for (j = batas-i; j > 1; j--) {
				printf(" ");
			}
			
			for (j = 0; j <= i*2; j++) {
				printf("*");
			}
			printf("\n");
		}
	}
	printf("====================================\n");
	system("pause");	
}

void menu2() {
	system("cls");
	printf("====================================\n");
	printf("Kuis 2\n");
	printf("====================================\n");
	int tinggi;
	
	printf("Masukkan Tinggi (1 - 10) : ");
	scanf("%d",&tinggi);
	
	if (tinggi < 1 || tinggi > 10) {
		printf("Tinggi hanya boleh 1 - 10!\n");
		system("pause");
		menu2();
	} else {
		int i,j,k;
		for (i = 0; i < tinggi; i++) {
			for (j = tinggi; j > 0; j--) {
				printf("%d",j);
			}
			
			printf("\n");
		}
		printf("\n");
		
		for (i = 0; i < tinggi; i++) {
			for (j = tinggi-i; j > 0; j--) {
				printf("%d",j);
			}
			
			for (k = i; k < i+1; k++) {
				printf("%d",k);
			}
			
			printf("\n");
		}
		printf("\n");
		
		for (i = tinggi; i > 0; i--) {
			for (j = tinggi-i; j > 0; j--) {
				printf("X");
			}
			
			for (k = 0; k < tinggi; k++) {
				printf("%d",k+i);
			}
			
			printf("\n");
		}
	}
	printf("====================================\n");
	system("pause");	
}

void menu3() {
	system("cls");
	printf("====================================\n");
	printf("Rekursif Pangkat\n");
	printf("====================================\n");
	int angka,pangkat;
	
	printf("Masukkan Angka : ");
	scanf("%d",&angka);
	printf("Masukkan Pangkat : ");
	scanf("%d",&pangkat);
	int hasil = hitungPangkat(angka,pangkat);
	printf("Hasil %d^%d : %d\n",angka,pangkat,hasil);	
	printf("====================================\n");
	system("pause");	
}

void keluar() {
	system("cls");
	printf("====================================\n");
	printf("Goodbye!!\n");
	printf("====================================\n");
}

void notfound() {
	system("cls");
	printf("====================================\n");
	printf("Menu Tidak ditemukan!!\n");
	printf("====================================\n");
	system("pause");
}

int hitungPangkat(int x, int y) { //dengan cara rekursif
	if (y == 0) {
		return 1;
	}
	y--;
	return x * hitungPangkat(x,y);
}

void main() {
	char pilihan;
	
	while (pilihan != '4') {
		menu_utama();
		scanf(" %c", &pilihan);
		
		if (pilihan == '1') {
			menu1();
		} else if (pilihan == '2') {
			menu2();
		} else if (pilihan == '3') {
			menu3();
		} else if (pilihan == '4') {
			keluar();
		} else {
			notfound();
		}
	}
}
