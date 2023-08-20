#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

int choice(){
	int n=0,pilihan;
	float total = 0.0;
	system("cls");
	printf("============================================\n");
    printf("||                  CHOICE                ||\n");
    printf("============================================\n");
    printf("|| 1. Konversi IDRT ke BTC                ||\n");
	printf("|| 2. Konversi IDRT ke ETH                ||\n"); 
	printf("|| 3. Konversi IDRT ke USDT               ||\n");
	printf("|| 4. EXIT                                ||\n");
	printf("============================================\n");
	printf("MASUKAN PILIHAN : ");
	scanf("%d", &pilihan);
	if (pilihan == 1){
		system("cls");
		printf("============================================\n");
    	printf("||          Konversi IDRT ke BTC          ||\n");
    	printf("============================================\n");
		printf("MASUKAN JUMLAH IDRT : ");
		scanf("%d", &n);
		total = n/547974483.0;
		printf("BTC = %.6f\n\n", total);
		system("pause");
	} else if (pilihan == 2){
		system("cls");
		printf("============================================\n");
    	printf("||          Konversi IDRT ke ETH          ||\n");
    	printf("============================================\n");
		printf("MASUKAN JUMLAH IDRT : ");
		scanf("%d", &n);
		total = n/37897476.0;
		printf("ETH = %.6f\n\n", total);
		system("pause");
	} else if (pilihan == 3){
		system("cls");
		printf("============================================\n");
    	printf("||         Konversi IDRT ke USDT          ||\n");
    	printf("============================================\n");
		printf("MASUKAN JUMLAH IDRT : ");
		scanf("%d", &n);
		total = n/14342.0;
		printf("USDT = %.6f\n\n", total);
		system("pause");
	} else if (pilihan == 4){
		printf("\nTERIMA KASIH");
		exit(0);
	} else {
		printf("\nMAAF, INPUTAN ANDA SALAH");
		exit(1);
	}
	return 0;
}

int main(){
	system("color 9F");
	char ulangi;
	choice();
	printf("\n\nULANGI? y/n\n>> ");
	scanf(" %c", &ulangi);
	do {
		if (ulangi == 'y'){
			main();
		} else if (ulangi == 'n'){
			printf("\nTERIMA KASIH");
			exit(0);
		}
	} while (ulangi != 'n');
	return 0;
}
