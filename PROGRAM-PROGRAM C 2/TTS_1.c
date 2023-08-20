#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void menu1(){
	printf("====================================\n");
	printf("||        SEGITIGA ANGKA          ||\n");
	printf("====================================\n");
	
	int n;
	printf("Masukkan Angka : ");
	scanf("%d",&n);

	int i,j;
	int angka = 1;
	
	for(i=1;i<=n;i++){
		for(j=0;j<=(n-i);j++){
			printf("  ");
		} for(j=0;j<(2*i-1);j++){
			printf("%d ", angka);
			if(angka == 9){
				angka = 0;  
			} else {
				angka++; 
			}
		}
		printf("\n");  
	}	
	printf("\n\n>>> Klik terserah untuk lanjut <<<");	
	getch();
}

void menu2(){
	int order;
	while (order != 4){
		printf("====================================\n");
		printf("||         SMART DRIVING          ||\n");
		printf("====================================\n");
		printf("|| 1. Lurus                       ||\n");
		printf("|| 2. Belok Kiri                  ||\n");
		printf("|| 3. Belok Kanan                 ||\n");
		printf("|| 4. Stop                        ||\n");
		printf("====================================\n");
		printf("Masukkan Perintah [1 - 3] : ");
		scanf("%d",&order);
	
		int i,j;
	
		if (order == 1) {
			printf("\nMobil lurus\n\n");
			for(i=1;i<=6;i++){
				for(j=6;j>=i;j--){
					printf(" ");
				} for(j=1;j<=i;j++){
					printf("*");
				} for(j=1;j<i;j++){
					printf("*");
				} printf("\n");
			}
			
			for(i=1;i<=5;i++){
				for(j=1;j<=5;j++){
					printf(" ");
				} for(j=1;j<=3;j++){
					printf("*");
				} for(j=1;j<=3;j++){
					printf(" ");
				} printf("\n");
			}	

		} else if (order == 2) {
			printf("\nMobil belok kiri\n\n");
			for(i=1;i<=4;i++){
				for(j=5;j>=i;j--){
					printf(" ");
				} for(j=1;j<=i;j++){
					printf("*");
				} for(j=1;j<i;j++){
					printf(" ");
				} printf("\n");
			}
			printf(" **********\n");
			printf("***********\n");
			printf(" **********\n");
			for (i=0;i<4;i++){
        		for (j=0;j<6;j++){
            		if (j<i+2){
                		printf(" ");
        			} else{
               			printf("*");
            		}
        		}
        		printf("\n");
	   		}	
		} else if (order == 3) {
			printf("\nMobil belok kanan\n\n");
			for(i=1;i<=5;i++){
				for(j=4;j>=i;j--){
					printf(" ");
				} for(j=1;j<=i;j++){
					printf(" ");
				} for(j=1;j<i;j++){
					printf("*");
				} printf("\n");
			}
			printf("**********\n");
			printf("***********\n");
			printf("**********\n");
			for(i=1;i<=5;i++) {
				for(j=1;j<=5;j++){
					printf(" ");
				} for(j=0;j<5-i;j++) {
         	  		printf("*");
       	 		} printf("\n");
   			 }
   			 
		} else if (order == 4) {
			printf("\nTerima kasih");
			printf("\n\n>>> Klik terserah untuk lanjut <<<");
			getch();
				
		} else {
			printf("\nAnda error\n\n");
		}	
	}
}

void keluar() {
	exit(0);
}

void invalid() {
	printf("Inputan salah");
	getch();
}

void main() {
	char nim[10];
	char nama[40];
	system("cls");
	printf("Masukan nama lengkap	: ");
	scanf("%[^\n]%*c", nama);
	printf("Masukan NIM		: ");
	scanf("%s", nim);
	
	char pilih;
	while (pilih != '3') {
		
		system("cls");
		printf("Selamat Datang %s (%s)", nama,nim);
		printf("\n====================================\n");
		printf("||             MENU               ||\n");
		printf("====================================\n");
		printf("|| 1. Segitiga Angka              ||\n");
		printf("|| 2. Smart Driving               ||\n");
		printf("|| 3. Keluar                      ||\n");
		printf("====================================\n");
		printf("Masukkan Pilihan : ");
		scanf(" %c", &pilih);
		
		if (pilih == '1'){
			menu1();
		} else if (pilih == '2'){
			menu2();
		} else if (pilih == '3'){
			keluar();
		} else {
			invalid();
		}
	}
}
