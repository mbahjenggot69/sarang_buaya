#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

void main(){

	//inputan string
 	//= "halo! saya suka belajar bahasa c";
	//scanf("%c");
	char delim[] = " "; //delimiters (pemisah)
	char tampung[100][100]; //array untuk menampung hasil pecahan
	char kalimat[100];
	
    printf("Masukkan Nama Barang : ");

    gets(kalimat);
	//printf("%s", kalimat); 
	//scanf("%s ", &kalimat);

	//https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
	 //fungsi untuk memecah kalimat mjd kata disimpan dalam pointer
	char *token = strtok(kalimat, delim);
    
    int i = 0;
	while (token != NULL) {
		//simpan kata dari token ke array tampung
		strcpy(tampung[i], token);
		
		//hapus (kosongkan) token
		token = strtok(NULL, delim); 
		i++;
	}
	
	int k;
	for (k = 0; k < i; k++) {
	    printf("%d \n", atoi(tampung[k]));
	}
}
