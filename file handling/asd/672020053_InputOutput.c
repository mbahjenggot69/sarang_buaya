#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <dirent.h>


FILE *fp;
struct dirent *de;
int buffer[200];
char ch, fileName[200];

bool addToFile();
void manageData();
void addData();
void login();
void menu();
int main();

bool addToFile(char inputan[]) {
    FILE *fp = fopen(fileName,"a+");
    if (fp == NULL) {
    	return false;
    } else {
        fputs(inputan, fp);
    }
    fclose(fp);
    return true;
}

void manageData(){
	
	int s,x,pilih,i=1,ada=1;
	char teks[100], hasil[200];
	system("cls");
	printf("===============================================\n");
	printf("||                 KELOLA FILE               ||\n");
	printf("===============================================\n");
	printf("|| 1. PILIH FILE                             ||\n");
	printf("|| 2. BACK                                   ||\n");
	printf("===============================================\n");
	printf("MASUKKAN PILIHAN : ");
	scanf(" %d", &s);
	if (s == 1){
		system("cls");
		printf("===============================================\n");
		printf("||                 DAFTAR FILE               ||\n");
		printf("===============================================\n");
		DIR *dr = opendir(".");
		while((de = readdir(dr)) != NULL){
			if(strstr(de->d_name,".txt")){
				buffer[i] = telldir(dr);
				ada = 1; 
				printf("%i. %s \n",i, de->d_name);
				i++;
			}
		}
		printf("\nPILIH FILE : ");
		scanf("%d", &pilih);
		closedir(dr);
		dr = opendir(".");
		while((de = readdir(dr)) != NULL){
			if(strstr(de->d_name,".txt")){
				if(buffer[pilih] == telldir(dr)){
					strcpy(fileName,de->d_name);
				}
			}	
		}
		closedir(dr);
		system("cls");
		printf("===============================================\n");
		printf("||                 KELOLA FILE               ||\n");
		printf("===============================================\n");
		printf("|| 1. LIHAT FILE                             ||\n");
		printf("|| 2. UPDATE FILE                            ||\n"); 
		printf("|| 3. DELETE FILE                            ||\n");
		printf("|| 4. CANCEL                                 ||\n");
		printf("===============================================\n");
		printf("PILIH MENU : ");
		scanf("%d", &x);
		if (x == 1){
			fp = fopen(fileName, "r");
	 		if (fp == "null"){
				printf("GAGAL BUKA FILE!");
				exit(1);
			}
			while ((ch = fgetc(fp)) != EOF){
				printf("%c", ch);
			} 
			printf("\n");
			system("pause");
			fclose(fp);
			
		} else if (x == 2){
			fp = fopen(fileName,"a+");
			printf("MASUKAN KONTEN : ");
			scanf (" %[^\n]%*c", &teks);
			printf ("%c", teks);
			snprintf(hasil, sizeof hasil, "%s",teks);
			if (addToFile(hasil)) { 
        		printf("SUKSES EDIT TEKS!\n");
    		} else {
        		printf("GAGAL EDIT TEKS!\n");
   			}
   			system("pause");
   			
		} else if (x == 3){
			fp = fopen(fileName, "w");
			fclose(fp);
			remove(fileName);
			printf("SUKSES HAPUS FILE!\n\n");
			system("pause");
			
		} else if (x == 4){
			menu();
		} else {
			exit(1);
		}
	} else if (s == 2){
		menu();
	} else {
		exit(1);
	}
}

void addData(){
	printf("===============================================\n");
	printf("||               BUAT FILE BARU              ||\n");
	printf("===============================================\n");
	printf("MASUKKAN NAMA FILE BARU : ");
	scanf("%s", &fileName);
	strcat(fileName,".txt");
	fp = fopen(fileName, "w");
	fclose(fp);
	printf("\nFile %s berhasil dibuat!", fileName);
	getch();
}

void login(){
    system("cls");
    char nim[10];
    char nama[40];      
    system("cls");
    printf("================================================\n");
    printf("||                    LOGIN                   ||\n");
    printf("================================================\n");
    printf("USERNAME  : ");
    scanf(" %s", nama);
    printf("PASSWORD  : ");
    scanf("%s", nim);
    system("cls");
    printf("SELAMAT DATANG %s (%s)", nama,nim);
    getch();
}

void menu(){
	system("cls");
	printf("===============================================\n");
    printf("||                INPUT/OUTPUT               ||\n");
    printf("===============================================\n");
    printf("|| 1. KELOLA FILE                            ||\n");
	printf("|| 2. BUAT FILE                              ||\n"); 
	printf("|| 3. LOG OUT                                ||\n");
	printf("|| 4. EXIT                                   ||\n");
	printf("===============================================\n");
    printf("PILIH MENU : ");
}

int main(){
	system("color 9F");
	int pilih;
	login();
	do {
		menu();
		scanf("%d",&pilih);
		if (pilih == 1){
			manageData();
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
	while (pilih != 4);
	return 0;
}

