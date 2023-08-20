//SEBUAH CONTOH SEDERHANA CRUD
//AUTHOR: YANUARC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


FILE *fp;
int buffer[200];
char ch, fileName[200] = "p.txt";

//UNTUK PENGENAL, DITULIS TERAKHIR
void manageData();
void addData();
void menu();
int main();


void addData(){
	system("cls");
	printf("BUAT FILE BARU\n");
	printf("MASUKKAN NAMA FILE BARU : ");
	scanf("%s", &fileName);
	strcat(fileName,".txt");
	fp = fopen(fileName, "w");
	fclose(fp);
	printf("\nFile %s berhasil dibuat!", fileName);
	getch();
}


void manageData(){
	int x,pilih,i=1,ada=1;
	char teks[100], hasil[200];

		system("cls");
		printf("KELOLA FILE\n");
		printf("1. LIHAT FILE\n");
		printf("2. UPDATE FILE\n"); 
		printf("3. DELETE FILE\n");
		printf("4. CANCEL\n");
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
			getch();
			fclose(fp);
			
		} else if (x == 2){
			fp = fopen(fileName,"a+");
			printf("MASUKAN KONTEN : ");
			scanf (" %[^\n]%*c", &teks);
			printf ("%c", teks);
			snprintf(hasil, sizeof hasil, "%s",teks);
			fputs(hasil, fp);
   			getch();
   			fclose(fp);

   			
		} else if (x == 3){
			fp = fopen(fileName, "w");
			fclose(fp);
			remove(fileName);
			printf("SUKSES HAPUS FILE!\n\n");
			getch();
			fclose(fp);
			
		} else if (x == 4){
			menu();
		} else {
			exit(1);
		}
	
}

void menu(){
	system("cls");
    printf("INPUT/OUTPUT\n");
    printf("1. BUAT FILE\n");
	printf("2. KELOLA FILE\n"); 
	printf("3. EXIT\n");
    printf("PILIH MENU : ");
}

int main(){
	int pilih;
	do {
		menu();
		scanf("%d",&pilih);
		if (pilih == 1){
			addData();
		} else if (pilih == 2){
			manageData();
		} else if (pilih == 3){
			exit(0);
		} else {
			printf ("\nINPUTAN ANDA SALAH!");
			main();
		}
	}
	while (pilih != 3);
	return 0;
}

