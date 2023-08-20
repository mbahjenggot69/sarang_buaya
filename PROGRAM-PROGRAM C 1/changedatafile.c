#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

char file_name[] = "triallist.txt";
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
	FILE *fp = fopen("triallist.txt","r"); //buka penyimpanan file
    char line[200];
	
	memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0;  
	   
	if (fp == NULL) { //Jika file tidak ditemukan/nama file tidak sama dg file_name
		printf("Gagal membuka file %s", file_name);//maka cetak Gagal membuka file
		exit(EXIT_FAILURE);
	} else {
		int i = 0;
		while (fgets(line, sizeof(line), fp) != NULL) { //while -> baca string dari fp distore ke line dengan max panjang 200 
		//Silver Queen;20000;40;
			char *token = strtok(line, delim); 
    		
    		int j = 0;
			while (token != NULL) {//looping perkata
				strcpy(data_barang[i][j], token);//copy string dari token ke data_barang perkata
				token = strtok(NULL, delim);//kosongkan kata
				j++;//ganti kolom
			}
			
			i++;//ganti baris
			jml_data_barang++;
		}
	}
	fclose(fp);//close file
}

void viewData() {
    getData();
    system("@cls||clear");
    printf("============================================\n");
   	printf("||              DATA BARANG               ||\n");
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
		   		
			}//untuk ambil data -> nama_barang
            int harga_brg = atoi(data_barang[i][1]); // untuk ambil data -> harga barang
            int stok_brg = atoi(data_barang[i][2]);  // untuk ambil data -> stock barang

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

bool modifyFile(int idx){
    return true;
}

void tambahData() {
	scanf("%c");
	system("@cls||clear");
	printf("============================================\n");
   	printf("||              TAMBAH BARANG             ||\n");
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
   	printf("||           HAPUS DATA BARANG            ||\n");
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
void transaksi(){
	getData();
    system("@cls||clear");
    printf("===========================================\n");
	printf("||             DAFTAR BARANG             ||\n");
   	printf("===========================================\n");
   	int i;
    if (jml_data_barang > 0) {
        printf("Nomor\tNama Barang\tHarga\tStok\n");
   		printf("===========================================\n");
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
            int k;
			for(k=0;k<i;k++);
            printf("%d.\t%s\t%d\t%d \n",k+1,nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("Tidak ada data barang!\n");
    }
    printf("==========================================\n");
	printf("Barang yang ingin Anda beli ?");
	scanf("%c");
	char nama[100], harga[50], stok[50], hasil[200];
   	int nomor;
	printf("\n\n>> Barang nomor berapa yang ingin dibeli : ");
 	scanf("%d", &nomor);
 	
 	nomor -=1;
   	/*if (strlen(nama) > 15) {
   		strcpy(nama, substring(nama, 1, 15));
	}*/
   	int stock;
   	printf(">> Masukkan Jumlah Barang : ");
   	scanf("%d", &stock);
   	gets(data_barang);
   	int stokk = atoi(data_barang[nomor][2]);
   	int hasill;
   	hasill=stokk-stock;
   	printf("Stok barang sekarang : %d\n", hasill);
   	
   	//struk
   	int hargaa = atoi(data_barang[nomor][1]);
   	printf("===========================================\n");
	printf("%d\t%s\t  %d\n", stock,data_barang[nomor][0],hargaa*stock);
	printf("===========================================\n");
	int k = 0;
	i = 0;
	char tampung[100][200];

	FILE *fp = fopen("triallist.txt","w");
	if(fp!=NULL) {
   		fscanf(fp,"%d", &data_barang[nomor][2]);     
	} fprintf(fp,"%d", hasill);      
	fclose(fp);                   
	
	system("pause");
	menu_utama();
}

void menu(int pil) {
	if (pil == 1) viewData();
	else if (pil == 2) tambahData();
	else if (pil == 3) hapusData();
	else if (pil == 4) transaksi();
}

void login(){

	system("cls");
	printf("================================================\n");
	printf("||         SELAMAT DATANG DI ONDIMART         ||\n");
	printf("|| SILAKAN LOGIN DAHULU SEBELUM BERBELANJA ^^ ||\n");
	printf("================================================\n");	
	printf("press enter to continue. . .");
	getch();
	system("cls");
	char nim[10];
	char nama[40];
	printf("===================================\n");
	printf("||             LOGIN             ||\n");
	printf("===================================\n");
	printf("MASUKAN NAMA ANDA	: ");
	scanf("%[^\n]%*c", nama);
	printf("\nMASUKAN NIM ANDA	: ");
	scanf("%s", nim);
	system("cls");
	printf("Selamat Datang %s (%s)", nama,nim);
	getch();
}
void menu_utama(){
	char pilih;
	int pilihan = 0;
	while (pilihan == 0) {
		system("@cls||clear");
		printf("============================================\n");
		printf("||               MENU UTAMA               ||\n");
		printf("============================================\n");
		printf("|| 1. Lihat Data Barang                   ||\n");
		printf("|| 2. Tambah Data Barang                  ||\n");
		printf("|| 3. Hapus Data Barang                   ||\n");
		printf("|| 4. Transaksi                           ||\n");
		printf("|| 5. Logout                              ||\n");
		printf("|| 6. Exit                                ||\n");
		printf("============================================\n");

		printf("Pilih Menu : ");
		scanf("%d",&pilihan);
		if (pilihan <= 0 || pilihan > 6) {
			pilihan = 0;
			system("cls");
			printf("Pilihan Menu Salah!");
			getch();
			menu_utama();
		}
	}
	
	if (pilihan == 5) {
		printf("Anda yakin ingin logout ? y/n\n >> ");
		scanf(" %c", &pilih);
			if (pilih == 'y'){
				login();
				menu_utama();
			} else if (pilih == 'n') menu_utama();
		}
	else if (pilihan == 6) exit(EXIT_SUCCESS);
	else menu(pilihan);
}
void main() {
	getData();
	//login();
	menu_utama();
}
