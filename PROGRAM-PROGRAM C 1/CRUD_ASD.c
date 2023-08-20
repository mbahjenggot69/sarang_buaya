#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

FILE *fp;
int buffer[200];
char ch, fileName[100] = "tes.txt";

void addData();

void addData(){
	printf("masukkan file baru..\n");
	scanf("%s", &fileName);
	strcat(fileName, ".txt");
	fp = fopen(fileName, "w");
	fclose(fp);
	printf("file sudah berhasil dibuat!");
	getch();
}

void readData(){
	system("cls");
	printf("Lihat data\n");
	fp = fopen(fileName, "r");
	while ((ch = fgetc(fp)) != EOF){
		printf("%c", ch);
	}
	getch();
	fclose(fp);
}

void updateData(){
	
}

void deleteData(){
	
}


int main(){
//	addData();
	readData();
	return 0;
}
