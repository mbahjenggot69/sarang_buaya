#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char file_name[] = "list_data.txt";
char delim[] = ";";
char data_barang[200][3][200];
int jml_data_barang = 0;

char *substring(char *string, int position, int length) {
   	char *pointer;
   	int c;
 
   	pointer = malloc(length+1);
   
   	if (pointer == NULL) {
      	printf("Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
   	}
 
   	for (c = 0 ; c < length ; c++) {
      	*(pointer+c) = *(string+position-1);      
      	string++;  
   	}
 
   	*(pointer+c) = '\0';
 
   	return pointer;
}

void getData() {
	FILE *fp = fopen(file_name, "r");
    char line[200];
	
	memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0;  
	   
	if (fp == NULL) {
		printf("Gagal membuka file %s", file_name);
		exit(EXIT_FAILURE);
	} else {
		int i = 0;
		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);
    		
    		int j = 0;
			while (token != NULL) {
				strcpy(data_barang[i][j], token);
				token = strtok(NULL, delim);
				j++;
			}
			
			i++;
			jml_data_barang++;
		}
	}
	fclose(fp);
}

void viewData() {
    getData();
    system("@cls||clear");
    printf("============================================\n");
   	printf("Menu Lihat Data Barang\n");
   	printf("============================================\n");
    if (jml_data_barang > 0) {
        printf("Nama Barang\tHarga\tStok\n");
   		printf("============================================\n");
        int i;
		for (i = 0; i < jml_data_barang; i++) {
			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][0]);
			if (strlen(nama_brg) > 15) {
		   		strcpy(nama_brg, substring(nama_brg, 1, 15));
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][0], "\t");
			}
            int harga_brg = atoi(data_barang[i][1]);
            int stok_brg = atoi(data_barang[i][2]);

            printf("%s\t%d\t%d \n",nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("Tidak ada data barang!\n");
    }
    printf("============================================\n");
    system("pause");
    menu_utama();
}

bool addToFile(char inputan[]) {
	FILE *fp = fopen(file_name,"a+");
	if (fp == NULL) {
		return false;
	} else {
		fputs(inputan, fp);
	}
	fclose(fp);
	return true;
}

void tambahData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf("Menu Tambah Data Barang\n");
   	printf("============================================\n");
   	
   	char nama[100], harga[50], stok[50], hasil[200];
   	
	printf("Masukkan Nama Barang : ");
   	gets(nama);
   	if (strlen(nama) > 15) {
   		strcpy(nama, substring(nama, 1, 15));
	}
	
   	printf("Masukkan Harga Barang : ");
   	gets(harga);
   	int hargaa = atoi(harga);
   	if (hargaa < 1000) hargaa = 1000;
   	else if (hargaa > 9999999) hargaa = 9999999;
   	
   	printf("Masukkan Stok Barang : ");
   	gets(stok);
   	int stokk = atoi(stok);
   	if (stokk < 1) stokk = 1;
   	else if (stokk > 10000) stokk = 10000;
   	
   	printf("============================================\n");
	snprintf(hasil, sizeof hasil, "%s;%d;%d;\n", nama, hargaa, stokk);
	if (addToFile(hasil)) {
		printf("Sukses tambah data barang!\n");
	} else {
		printf("Gagal tambah data barang!\n");
	}
	printf("============================================\n");
	system("pause");
    menu_utama();
}

void hapusData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf("Menu Hapus Data Barang\n");
   	printf("============================================\n");
   	char nama[100];
   	printf("Masukkan Nama Barang : ");
   	gets(nama);
	if (jml_data_barang > 0) {
		FILE *fp = fopen(file_name, "r");
	    char line[200];
		   
		if (fp == NULL) {
			printf("Gagal membuka file %s", file_name);
			exit(EXIT_FAILURE);
		} else {
			bool ada = false, ada2 = false;
			int i = 0, j = 0, k = 0;
			char tampung[100][200];
			while (fgets(line, sizeof(line), fp) != NULL) {
				char *token = strtok(line, delim);
	    		j = 0;
				ada = false;
				while (token != NULL) {
					if (j == 0) {
						if (strcmp(data_barang[i][j],nama) == 0) {
							ada = true;
							ada2 = true; //memastikan jika ketemu
						}
					}
					token = strtok(NULL, delim);
					j++;
				}
				
				if (!ada) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;\n", data_barang[i][0], data_barang[i][1], data_barang[i][2]);
					k++;
				}
				
				i++;
			}
			
			fclose(fp);
			
			printf("============================================\n");
			if (ada2) {
				fp = fopen(file_name, "w"); //reset file jadi kosong
				fclose(fp);
				if (k > 0) {
					for (i = 0; i < k; i++) {
						addToFile(tampung[i]);
					}	
				}
				printf("Sukses hapus (%s) dari data barang!\n",nama);
			} else {
				printf("Nama barang (%s) tidak ditemukan!\n",nama);
			}
		}
   	} else {
   		printf("============================================\n");
   		printf("Tidak ada data barang!\n");
    }
    
    printf("============================================\n");
    system("pause");
    menu_utama();
}

void menu(int pil) {
	if (pil == 1) viewData();
	else if (pil == 2) tambahData();
	else if (pil == 3) hapusData();
	//else if (pil == 4) transaksi
}

void menu_utama() {
	int pilihan = 0;
	while (pilihan == 0) {
		system("@cls||clear");
		printf("============================================\n");
		printf("MENU UTAMA\n");
		printf("============================================\n");
		printf("1. Lihat Data Barang\n");
		printf("2. Tambah Data Barang\n");
		printf("3. Hapus Data Barang\n");
		printf("4. Transaksi\n");
		printf("5. Logout\n");
		printf("6. Exit\n");
		printf("Pilih Menu : ");
		scanf("%d",&pilihan);
		if (pilihan <= 0 || pilihan > 6) {
			pilihan = 0;
			system("@cls||clear");
			printf("Pilihan Menu Salah!");
			system("pause");
		}
	}
	
	if (pilihan == 5) login();
	else if (pilihan == 6) exit(EXIT_SUCCESS);
	else menu(pilihan);
}

void login() {
	
}

void main() {
	getData();
	//login();
	menu_utama();
}
