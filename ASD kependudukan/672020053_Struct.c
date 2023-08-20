#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

char buffer[200];
FILE *fp;
char ch, fileName[] = "Kependudukan.txt";
int i=1;

struct penduduk{
	char nik[20], nama[20], lahir[20], hp[20], email[20];
};

bool addToFile(char inputan[]) {
    fp = fopen(fileName,"a+");
    if (fp == NULL) {
    	return false;
    } else {
        fputs(inputan, fp);
    }
    fclose(fp);
    return true;
}

void menu(){
	system("cls");
	printf("===============================================\n");
    printf("|| SISTEM INFORMASI KEPENDUDUKAN DESA KONOHA ||\n");
    printf("===============================================\n");
    printf("|| 1. TAMBAH DATA PENDUDUK                   ||\n");
	printf("|| 2. LIHAT DATA PENDUDUK                    ||\n"); 
	printf("|| 3. EXIT                                   ||\n");
	printf("===============================================\n");
    printf("PILIH MENU : ");
}

void menu1(){
	system("cls");
	printf("===============================================\n");
    printf("||           TAMBAH DATA PENDUDUK            ||\n");
    printf("===============================================\n");
	struct penduduk pdd; 
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
	snprintf(buffer, sizeof buffer, "%d\t|%s\t|%s\t|%s\t|%s\t|%s\n",i,pdd.nik,pdd.nama,pdd.email,pdd.hp,pdd.lahir);
	i++;
	
	if (addToFile(buffer)) { 
       	printf("\nSUKSES MENAMBAH DATA!\n");
   	} else {
       	printf("GAGAL MENAMBAH DATA!\n");
   	}
   	system("pause");	
}

void menu2(){
	system("cls");
	printf("===============================================================================================\n");
    printf("||                                   LIHAT DATA PENDUDUK                                     ||\n");
    printf("===============================================================================================\n");
    printf("Nomor\t|NIK\t\t|Nama Warga\t|Email\t\t|No. Handphone\t|Tanggal Lahir");
    printf("\n===============================================================================================\n");
	fp = fopen(fileName, "r");
	if (fp == "null"){
		printf("GAGAL BUKA FILE!");
		exit(1);
	}
	while ((ch = fgetc(fp)) != EOF){
		printf("%c", ch);
	} 
	printf("\n\n");
	system("pause");
	fclose(fp);
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

