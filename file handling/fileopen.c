#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


char delim[] = ";";
char data_barang[200][3][200];
int jml_data_barang = 0;


int main(){
FILE *fp = fopen("list_data.txt","r"); //buka penyimpanan file
    char line[200];
	
	memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0;  
	   
	if (fp == NULL) { //Jika file tidak ditemukan/nama file tidak sama dg file_name
//		printf("Gagal membuka file %s", file_name);//maka cetak Gagal membuka file
		exit(EXIT_FAILURE);
	} else {
		int i = 0;
		while (fgets(line, sizeof(line), fp) != NULL) { //while -> baca string dari fp distore ke line dengan max panjang 200 
		//1. Silver Queen;20000;40;
		//2. Masker;10000;20;
			char *token = strtok(line, delim); 
    		printf("%d ",  jml_data_barang+1);
			int j = 0;
			while (token != NULL) {//looping perkata
				strcpy(data_barang[i][j], token);//copy string dari token ke data_barang perkata
    			printf(";%s", data_barang[i][j]);
//    			printf("%d", );
				token = strtok(NULL, delim);//kosongkan kata
				j++;//ganti kolom
				
			}
			
			i++;//ganti baris
			jml_data_barang++;
			//printf("%d", jml_data_barang);
		}
	}
	fclose(fp);
}
