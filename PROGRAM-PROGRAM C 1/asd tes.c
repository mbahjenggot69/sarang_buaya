#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

//void addvalue (int *value){
//	
//	*value += 3;
//}

int main(){
	//pointer	
//	int value=3;
//	addvalue(&value);
//	printf("%d ", value);

	//tambah file
	char ch, fileName[100] = "asd tes.txt";
	FILE*fp;
	
//	fp = fopen(fileName,"a+");
//	
//	printf("masukan konten : ");
//	while (1){
//		ch = getchar();
//		if (ch == -1)
//		break;
//		fputc(ch,fp);
//	}
//	fclose(fp);
//	printf("sukses menambah konten ke file %s", fileName);

	//buka file
	
//	if (fp == "null"){
//		printf("gagal");
//		exit(1);
//	}
//	
//	printf("isi file %s : \n", fileName);
//	while ((ch = fgetc(fp)) != EOF){
//		printf("%c", ch);
//	}
//	fclose(fp);
	
	//edit, lalu baca
//	printf("isi file %s : \n", fileName);
//	while (1){
//		ch = getchar();
//		if (ch == -1)
//		break;
//		fputc(ch,fp);
//		}
//	fclose(fp);
//	if (fp == "null"){
//		printf("gagal");
//		exit(1);
//	}
//	
//	printf("isi file %s : \n", fileName);
//	while ((ch = fgetc(fp)) != EOF){
//		printf("%c", ch);
//	}
//	fclose(fp);
	
	
	//print isi file sendiri
	
	FILE *fp;
	int c;
	fp = fopen(__FILE__,"r");
	
	do {
		c = getc(fp);
		putchar(c);
	} while (c != EOF);
	
	fclose(fp);
return 0;
	
}
