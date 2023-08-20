#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

FILE * fp;
struct dirent *de;
char ch, fileName[100] = "database.txt";
int fileTampung[100];

void thirdMenu(){
	system("cls");
	int j = 1, pilihan, isFound = 0;
	DIR *dr = opendir(".");
	while((de = readdir(dr)) != NULL){
		if(strstr(de->d_name,".txt")){
			fileTampung[j] = telldir(dr); // Nampung File
			isFound = 1; // Ngecek ada atau file
			printf("%i. %s \n",j, de->d_name);
			j++;
		}
	}
	closedir(dr);
	printf("Pilih File : ");
	scanf("%d", &pilihan);
	
	dr = opendir(".");
		while((de = readdir(dr)) != NULL){
			if(strstr(de->d_name,".txt")){
				if(fileTampung[pilihan] == telldir(dr)){
					strcpy(fileName,de->d_name); // Copy Nama File String
				}
			}	
		}
		printf("Kamu memilih file %s", fileName);
	closedir(dr);
	getch();
}

void renameFile(){
	char namaBaru[100];
	printf("Masukkan nama baru : ");
	scanf("%s", &namaBaru);
	strcat(namaBaru, ".txt");
	
	if(rename(fileName, namaBaru) == 0){
		printf("File berganti nama\n");
		strcpy(fileName,namaBaru);
	} else {
		printf("file gagal ganti\n");
	} 
	
	getch();
}

void readFile(){
	fp = fopen(fileName, "r");
	//EOF => End Of File
	printf("Isi dari file %s adalah \n", fileName);
	while((ch = fgetc(fp)) != EOF){
		printf("%c", ch);
	}
	getch();
	fclose(fp);
}

void updateFile(){
	system("cls");
	fp = fopen(fileName,"a");
	printf("Masukkan isi file : \n");
	while(1){
		ch = getchar(); // scanf("%c",&ch);
		if(ch == -1){ // ctrl + z
			break;
		}
		fputc(ch,fp);
	}
	fclose(fp);
	printf("File berhasil dibuat \n");
	getch();
}

void deleteFile(){
	system("cls");
	//remove(fileName)
	char charChoice;
	
	printf("Apakah anda yakin? (y/t) :");
	scanf(" %c", &charChoice);
	switch(charChoice){
		case 'y':
			// Proses Remove
			if(remove(fileName) == 0){
				printf("File berhasil dihapus\n");
			} else {
				printf("File gagal dihapus\n");
			}
			
			getch();
			main();
		break;
		case 't':
			printf("File tidak jadi dihapus\n");
			getch();
			main();
		break;
		default: printf("Invalid Input\n");
		getch();
	}
}

void firstMenu(){
	int choice;
	fp = fopen(fileName, "r");
	
	if(fp == NULL){
		printf("File belum ada\n"); getch();
	} else {
		do {
			system("cls");
			printf("Menu 1: Manajemen File\n");
			printf("Current File : %s\n", fileName);
			printf("-------------------------\n");
			printf("1. Read File\n");
			printf("2. Update File\n");
			printf("3. Delete File\n");
			printf("4. Rename File\n");
			printf("5. Return to main menu\n");
			printf("Masukkan Pilihan : ");
			scanf("%d",&choice);
			
			switch(choice){
				case 1: fclose(fp); readFile(); break;
				case 2: fclose(fp); updateFile(); break;
				case 3: fclose(fp); deleteFile(); break;
				case 4: fclose(fp); renameFile(); break;
				case 5: fclose(fp); main(); break;
				default: printf("invalid input\n");
				getch();
			}
		} while(choice != 5);
	}
	
}

void secondMenu(){
	system("cls");
//	printf("Masukkan Nama File Baru : ");
//	scanf("%s", &fileName);
//	strcat(fileName,".txt");
	// "data" + ".txt" => data.txt
	
	fp = fopen(fileName, "w"); // Membuka File
	fclose(fp);
	
	printf("File %s berhasil dibuat", fileName);
	getch();
}

int main(){
	int choice;
	// File Handling - Read Write Update Delete File 
	do {
		system("cls");
		printf("Menu Manajemen File C ASD 2022\n");
		printf("1. Read / Update / Delete File\n");
		printf("2. Create New File\n");
		printf("3. Lihat Folder\n");
		printf("4. Exit\n");
		printf("Masukkan Pilihan : ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: firstMenu(); break;
			case 2: secondMenu(); break;
			case 3: thirdMenu(); break;
			case 4: exit(EXIT_SUCCESS); break;
			default: printf("invalid input\n");
		}
		getch();
		
	} while(choice != 4);
	
	return 0;
}
