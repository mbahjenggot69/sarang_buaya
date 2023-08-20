#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

int plus(){
	system("cls");
	printf("============================================\n");
    printf("||             TAMBAH MATRIKS             ||\n");
    printf("============================================\n");
	
	printf("INPUT MATRIKS A :\n");
	int arrayA[2][2], arrayB[2][2];
	int i,j,n,baris,kolom;
	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("Masukan matriks A [%d][%d] = ", baris,kolom);
			scanf(" %d", &arrayA[baris][kolom]);
		}
	}
	
	printf("\n============================================\n");
	printf("\nINPUT MATRIKS B : \n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("Masukan matriks B [%d][%d] = ", baris,kolom);
			scanf(" %d", &arrayB[baris][kolom]);
		}
	}
	
	printf("\n============================================\n");
	printf("\nHASIL PENJUMLAHAN KEDUA MATRIKS :\n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("%d\t", (arrayA[baris][kolom]+arrayB[baris][kolom]));
		}
	printf("\n");	
	}

	printf("\n============================================\n");
	system("pause");
	return 0;
}

int times(){
	system("cls");
	printf("============================================\n");
    printf("||              KALI MATRIKS              ||\n");
    printf("============================================\n");
	
	printf("INPUT MATRIKS A :\n");
	int arrayA[2][2], arrayB[2][2];
	int i,j,n,baris,kolom;
	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("Masukan matriks A [%d][%d] = ", baris,kolom);
			scanf(" %d", &arrayA[baris][kolom]);
		}
	}
	
	printf("\n============================================\n");
	printf("\nINPUT MATRIKS B : \n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("Masukan matriks B [%d][%d] = ", baris,kolom);
			scanf(" %d", &arrayB[baris][kolom]);
		}
	}
	
	printf("\n============================================\n");
	printf("\nHASIL PERKALIAN KEDUA MATRIKS :\n");
	printf("%d\t", ((arrayA[0][0]*arrayB[0][0])+(arrayA[0][1]*arrayB[1][0])));
	printf("%d", ((arrayA[0][0]*arrayB[0][1])+(arrayA[0][1]*arrayB[1][1])));
	printf("\n%d\t", ((arrayA[1][0]*arrayB[0][0])+(arrayA[1][1]*arrayB[1][0])));
	printf("%d", ((arrayA[1][0]*arrayB[0][1])+(arrayA[1][1]*arrayB[1][1])));


	printf("\n\n============================================\n");
	system("pause");
	return 0;
}

int menu(){
	system("cls");
	printf("============================================\n");
    printf("||             OPERASI MATRIKS            ||\n");
    printf("============================================\n");
    printf("|| 1. TAMBAH MATRIKS                      ||\n");
	printf("|| 2. KALI MATRIKS                        ||\n"); 
	printf("|| 3. KELUAR                              ||\n");
	printf("============================================\n");
    printf("PILIH MENU : ");
	return 0;
}

int main(){
	system("color 9F");
	int pilih;
	do {
		menu();
		scanf("%d",&pilih);
		if (pilih == 1){
			plus();
		} else if (pilih == 2){
			times();
		} else if (pilih == 3){
			exit(0);
		} else {
			printf ("\nINPUTAN ANDA SALAH!");
			exit(1);
		}
	}
	while (pilih != 3);
	return 0;
}

