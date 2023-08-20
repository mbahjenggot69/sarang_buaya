#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

int loops(){
	int i,n,total=0;
	system("cls");
	printf("============================================\n");
    printf("||                  LOOPS                 ||\n");
    printf("============================================\n");
	printf("MASUKAN BILANGAN : ");
	scanf("%d", &n);
	
	//operasi
//	for (i=0;i<=n;i++){
//		total = total + i;
//	}
//	while (i<=n){
//		total = total + i;
//		i++;
//	}
	do{
		total = total + i;
		i++;	
	} while(i<=n);
	
	printf("HASIL = %d\n", total);
	printf("============================================\n");
	system("pause");
	return 0;
}

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
	printf("|| 4. Back                                ||\n");
	printf("============================================\n");
	printf("MASUKAN PILIHAN : ");
	scanf("%d", &pilihan);
	if (pilihan == 1){
		printf("\n============================================\n");
    	printf("||          Konversi IDRT ke BTC          ||\n");
    	printf("============================================\n");
		printf("MASUKAN JUMLAH IDRT : ");
		scanf("%d", &n);
		total = n/547974483.0;
		printf("BTC = %.6f\n\n", total);
		system("pause");
	} else if (pilihan == 2){
		printf("\n============================================\n");
    	printf("||          Konversi IDRT ke ETH          ||\n");
    	printf("============================================\n");
		printf("MASUKAN JUMLAH IDRT : ");
		scanf("%d", &n);
		total = n/37897476.0;
		printf("ETH = %.6f\n\n", total);
		system("pause");
	} else if (pilihan == 3){
		printf("\n============================================\n");
    	printf("||         Konversi IDRT ke USDT          ||\n");
    	printf("============================================\n");
		printf("MASUKAN JUMLAH IDRT : ");
		scanf("%d", &n);
		total = n/14342.0;
		printf("USDT = %.6f\n\n", total);
		system("pause");
	}
	return 0;
}

int menu(){
	system("cls");
	printf("============================================\n");
    printf("||               CONTROL FLOW             ||\n");
    printf("============================================\n");
    printf("|| 1. LOOPS                               ||\n");
	printf("|| 2. CHOICE                              ||\n"); 
	printf("|| 3. EXIT                                ||\n");
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
			loops();
		} else if (pilih == 2){
			choice();
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
