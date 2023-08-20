#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

void getData() {
	char ch, fileName[200] = "replica.txt";
    FILE *fp;
    fp = fopen(fileName, "r")
 	if (fp == "null"){
		printf("gagal");
		exit(1);
	}
	printf("isi file %s : \n", "replica.txt");
	while ((ch = fgetc(fp)) != EOF){
		printf("%c", ch);
	}
	fclose(fp);
}

void manageData(){
}

void addData(){
	
}


void login(){
    system("cls");
    char nim[10];
    char nama[40];
    printf("================================================\n");
    printf("||                SELAMAT DATANG              ||\n");
    printf("||  SILAKAN LOGIN DAHULU SEBELUM MELANJUTKAN  ||\n");
    printf("================================================\n");          
    printf("press enter to continue. . .");
    getch();
    system("cls");
    printf("================================================\n");
    printf("||                    LOGIN                   ||\n");
    printf("================================================\n");
    printf("\nMASUKAN NAMA ANDA : ");
    scanf(" %s", nama);
    printf("MASUKAN NIM ANDA  : ");
    scanf("%s", nim);
    system("cls");
    printf("Selamat Datang %s (%s)", nama,nim);
    getch();
}

int menu(){
	system("cls");
	printf("===============================================\n");
    printf("||                 CONTROL FLOW              ||\n");
    printf("===============================================\n");
    printf("|| 1. KELOLA FILE                            ||\n");
	printf("|| 2. BUAT FILE                              ||\n"); 
	printf("|| 3. LOG OUT                                ||\n");
	printf("|| 4. EXIT                                   ||\n");
	printf("===============================================\n");
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
			getData();
		} else if (pilih == 2){
			addData();
		} else if (pilih == 3){
			main();
		} else if (pilih == 4){
			exit(0);
		} else {
			printf ("\nINPUTAN ANDA SALAH!");
			exit(1);
		}
	}
	while (pilih != 3);
	return 0;
}
