#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
 
char delim[] = ";";
char data_barang[200][4][200];
int jml_data_barang = 0;
char *substring(char *string, int position, int length) { //alokasi memory dinamis selama runtime
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

void getData(char alamat[]) {
    FILE *fp = fopen(alamat,"r"); //buka penyimpanan file
    char line[200];
    memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0; 
    if (fp == NULL) { //Jika file tidak ditemukan/nama file tidak sama dg file_name
        printf("Gagal membuka file %s", "sparepart.txt");//maka cetak Gagal membuka file
        exit(EXIT_FAILURE);
    } else {
    	int i = 0;
        while (fgets(line, sizeof(line), fp) != NULL) { //while -> baca string dari fp distore ke line dengan max panjang 200
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

void viewData(int pauseviewer, int caller) {
	if (caller == 0){
		getData("sparepart.txt");
    	system("@cls||clear");
    	printf("============================================\n");
    	printf("||              DATA BARANG               ||\n");
    	printf("============================================\n");
    	if (jml_data_barang > 0) {
        	printf("Kode Barang\tNama Barang\tHarga\tStok\n");
        	printf("============================================\n");
        	int i;
        	for (i = 0; i < jml_data_barang; i++) {
				char nama_brg[100];
        		int kode_brg = atoi(data_barang[i][0]);
            	strcpy(nama_brg, data_barang[i][1]); //copy string dari data_darang[i][0] ke nama_brg
            	if (strlen(nama_brg) > 15) { //jika string nama_brg lebih dari 15character
                	strcpy(nama_brg, substring(nama_brg, 1, 15)); //maka yg nama barang yg dicopy dibatasi sampai 15
            	} else if (strlen(nama_brg) < 8) { //jika string nama_brg kurang dari 8character
                	snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][1], "\t");//maka yg akan dicetak 2kali panjang character
        		}//untuk ambil data -> nama_barang
            	int harga_brg = atoi(data_barang[i][2]); // untuk ambil data -> harga barang
            	int stok_brg = atoi(data_barang[i][3]);  // untuk ambil data -> stock barang
            	printf("\t%d\t%s\t%d\t%d \n",kode_brg,nama_brg,harga_brg,stok_brg);
            	kode_brg++;
        	}
    	} else {
        	printf("Tidak ada data barang!\n");
    	}
    	printf("============================================\n");
    	if (pauseviewer != 0 ){
			system("pause");
    		menu_utama();
		}
	} else if (caller != 0){
		getData("struk.txt");
    	system("@cls||clear");
    	printf("============================================\n");
    	printf("||   DATA BARANG YANG PERNAH ANDA BELI    ||\n");
    	printf("============================================\n");
    	if (jml_data_barang > 0) {
        	printf("Nama Barang\tJumlah\tHarga\n");
        	printf("============================================\n");
        	int i;
        	for (i = 0; i < jml_data_barang; i++) {
				char nama_brg[100];
            	strcpy(nama_brg, data_barang[i][0]); //copy string dari data_darang[i][0] ke nama_brg
            	if (strlen(nama_brg) > 15) { //jika string nama_brg lebih dari 15character
                	strcpy(nama_brg, substring(nama_brg, 1, 15)); //maka yg nama barang yg dicopy dibatasi sampai 15
            	} else if (strlen(nama_brg) < 8) { //jika string nama_brg kurang dari 8character
                	snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][0], "\t");//maka yg akan dicetak 2kali panjang character
        		}//untuk ambil data -> nama_barang 	
            	int stok_brg = atoi(data_barang[i][1]);  // untuk ambil data -> stock barang
            	int harga_brg = atoi(data_barang[i][2]); // untuk ambil data -> harga barang
            	printf("%s\t%d\t%d \n", nama_brg,stok_brg,harga_brg);
        	}
    	} else {
        	printf("Tidak ada data barang!\n");
    	}
    	printf("============================================\n");
		system("pause");
    	menu_utama();	
	}		
}

bool addToFile(char inputan[], char alamat[]) {	
    FILE *fp = fopen(alamat,"a+"); //a+ untuk reading and appending(menambahkan) 
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
    printf("||              TAMBAH BARANG             ||\n");
    printf("============================================\n");
    
    char kode_barang[10], nama[100], harga[50], stok[50], hasil[200];
    
	int kd_brg = atoi(data_barang[jml_data_barang-1][0]);
    printf("Masukkan Nama Barang : ");
    gets(nama); //scan barang dan ditampung di variabel nama dalam bentuk string
    if (strlen(nama) > 15) {
        strcpy(nama, substring(nama, 1, 15)); //jika nama > 15 maka yg dicopy dibatasi sampai 15 character
    }
    printf("Masukkan Harga Barang : ");
    gets(harga); //scan harga dan ditampung di variabel harga dalam bentuk string
    int hargaa = atoi(harga); //konversi harga (str) => hargaa (int)
    if (hargaa < 1000) hargaa = 1000; //jika harga < 1000 maka harga dijadikan 1000
    else if (hargaa > 9999999) hargaa = 9999999; //jika harga > 9999999 maka harga dijadikan 9999999
    printf("Masukkan Stok Barang : ");
    gets(stok); //scan barang dan ditampung di variabel stok dalam bentuk string
    int stokk = atoi(stok); //konversi stok (str) => stokk (int)
    if (stokk < 1) stokk = 1; //jika stok barang < 1 maka dijadikan 1
    else if (stokk > 10000) stokk = 10000; //jika stok barang > 10000 maka dijadikan 10000
    printf("============================================\n");
    snprintf(hasil, sizeof hasil, "%d;%s;%d;%d;\n",kd_brg+1, nama, hargaa, stokk); //menampung nama,hargaa dan stokk kedalam buffer hasil
    if (addToFile(hasil, "sparepart.txt")) { //menambahkan yg telah ditampung di buffer ke dalam file
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
	viewData(0,0);
	printf("============================================\n");
    printf("||           HAPUS DATA BARANG            ||\n");
    printf("============================================\n");
    char nama[100];
    printf("Masukkan Nama Barang : ");
    gets(nama); //scan barang dan ditampung di variabel nama dalam bentuk string
    if (jml_data_barang > 0) { 
		FILE *fp = fopen("sparepart.txt", "r"); //membaca file
        char line[200];
        if (fp == NULL) { // jika file tidak ditemukan / void 
            printf("Gagal membuka file %s", "sparepart.txt");
            exit(EXIT_FAILURE);
        } else {
    		bool ada = false, ada2 = false;
            int i = 0, j = 0, k = 0;
            char tampung[100][200];
            while (fgets(line, sizeof(line), fp) != NULL) { //selama string dari file dalam 1 baris tidak sm dg NULL
                char *token = strtok(line, delim); //string dalam line dipisahkan delimiter ";" per kata
                j = 0;
                ada = false;
                while (token != NULL) { //selama token tidak habis atau belum kosong
                	if (j == 1) {
                        if (strcmp(data_barang[i][j],nama) == 0) { //mengcompare nama dengan data_barang[i][j]. Jika cocok(true)
                            //printf("%d",data_barang[i][j]);
							ada = true;
                            ada2 = true; //memastikan jika ketemu
                    	}
                    }
        			token = strtok(NULL, delim);
                    j++;
                }
            	if (!ada) {
                //data barang yg bukan dihapus akan ditampung di array tampung
                	snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s;\n", data_barang[i][0], data_barang[i][1], data_barang[i][2], data_barang[i][3]);
                    k++;
                }
                i++;
            }   
    	fclose(fp);
        printf("============================================\n");
        if (ada2) {
        	fp = fopen("sparepart.txt", "w"); //reset file jadi kosong
        	fclose(fp);
            if (k > 0) {
                for (i = 0; i < k; i++) {
                	addToFile(tampung[i], "sparepart.txt");
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
////transaksi -> DI COMMENT 
//void tambahkurang(char nama[100], int diambil){
//   if (jml_data_barang > 0) {
//        FILE *fp = fopen("triallist.txt", "r");
//        char line[200];
//        if (fp == NULL) {
//            printf("Gagal membuka file");
//            exit(EXIT_FAILURE);
//        } else {
//            bool ada = false, ada2 = false;
//            int i = 0, j = 0, k = 0;
//            char tampung[100][200];
//            while (fgets(line, sizeof(line), fp) != NULL) {
//                char *token = strtok(line, delim);
//                j = 0;
//                ada = false;
//                while (token != NULL) {
//                    if (j == 1) {
//                        if (strcmp(data_barang[i][j],nama) == 0) {
//                            ada = true;
//                            ada2 = true; //memastikan jika ketemu
//                        }
//                    }
//                    token = strtok(NULL, delim);
//                    j++;
//                }
//                if (!ada) {
//            //data barang yg bukan dihapus akan ditampung di array tampung
//                	snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s;\n", data_barang[i][0], data_barang[i][1], data_barang[i][2], data_barang[i][3]);
//                }
//				else{
//					
//                	int stokk = atoi( data_barang[i][3]);
//					int stock_saat_ini;
//					char values[100] ;
//					stock_saat_ini = stokk - diambil;
////					printf("%d",stock_saat_ini);
//					sprintf(values,"%d",stock_saat_ini); // konversi dari integer ke string-> karena snprintf nya pake string
//					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s;\n", data_barang[i][0], data_barang[i][1], data_barang[i][2], values);
//				}
//                k++;
//            	i++;
//			}
//            fclose(fp);
//            if (ada2) {
//                fp = fopen("triallist.txt", "w"); //reset file jadi kosong
//				fclose(fp);
//                if (k > 0) {
//                    for (i = 0; i < k; i++) {
//                        addToFile(tampung[i], "triallist.txt"); 
//                        printf("%s", tampung[i]);
//                    }         
//				}
//                printf("Sukses membeli %s !\n",nama);
//            } else {
//                printf("Nama barang (%s) tidak ditemukan!\n",nama);
//            }
//        }
//    } else {
//        printf("Tidak ada data barang!\n");
//    }
//    printf("===========================================\n");
//}
void transaksi(){
	char val[200];
	FILE *fp = fopen("sparepart.txt", "r");
    getData("sparepart.txt");
    system("@cls||clear");
    printf("===========================================\n");
    printf("||             DAFTAR BARANG             ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d         ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("===========================================\n");
	viewData(0,0); // panggil fungsi pakai parameter
	
	//start

	int i, stock, stokk, kode_beli, nomor, uang, brg, hasill, hargaa[100], total, choice, buffer2[100], tot_jml_beli, buffer[100];
	char harga[50], stok[50], hasil[200],str[100], konf_pembelian[1];
	char collection_nama_barang[100][100];
	
	printf(">> Masukkan jumlah item yang akan dibeli: ");
	scanf("%d", &brg);
	
	printf("\n===========================================\n");
	total = 0; 
	for (i=0;i<brg;i++){
		
	    printf(">> Barang nomor berapa yang ingin dibeli : ");
	    scanf("%d", &buffer[i]);
	    buffer[i] = buffer[i] - 1; 
	    printf(">> Masukkan Jumlah Barang : ");
	    scanf("%d", &buffer2[i] );	    	
		hargaa[i] = atoi(data_barang[buffer[i]][2]) * buffer2[i];
		printf("Harga barang %d : %d\n", i+1, hargaa[i]);	 
		total+= hargaa[i];
	}   
	
	printf("\n===========================================\n");
	printf("Total pembelian : Rp.%d", total);
	printf("\n===========================================\n");
	printf("\n========= KONFIRMASI PEMBELIAN =========="); // PENGECEKAN UNTUK KONFIRMASI PEMBELIAN
    printf("\nApakah anda yakin ingin membeli item tersebut? (Y)es/(N)o => ");
   	scanf("%s",&konf_pembelian);
	if (strcmp(konf_pembelian, "Y")== 0|| strcmp(konf_pembelian,"y") == 0 ){
		    printf("\n>> Masukkan uang anda : ");
		    scanf("%d", &uang);
		 	printf("\n>> Tekan enter untuk lanjut ke pembayaran\n");
		    getch();	
		    if (uang < total) {
		   	 	printf(">> Mohon maaf uang anda kurang Rp. %d\n", total-uang);
		   	 	printf(">> Transaksi gagal\n");
		   	 	system("pause");
		    	transaksi();
			}else {	
		 		//struk
		// 		char l=219;
		//    	printf("PROCESSING . . .\n");
		//    	for (int i=0;i<5;i++){
		//        Beep(300,500);
		//        Beep(400,500);
		//        Beep(800,500);
		//        printf("%c%c",l,l); 
		//    }
				for (i=0;i<brg;i++){
					char nama_brg[100];
					printf("Jumlah : %d\n", buffer2[i]);
					stokk = atoi(data_barang[buffer[i]][3]);
					hasill = stokk - buffer2[i] ;
					printf("%d",buffer[i]);
					sprintf(harga,"%d",hargaa[i]);
					sprintf(hasil,"%d",hasill);
					strcpy(nama_brg, data_barang[buffer[i]][1]);
					snprintf(collection_nama_barang[i], sizeof collection_nama_barang[i], "%s;%s;%s;%s;\n", data_barang[buffer[i]][0], nama_brg, harga ,hasil);
					printf("STOK BARANG SEKARANG : %d\n", hasill);
//	======================================================== FUNGSI TAMBAH KURANG ========================================================

			 if (jml_data_barang > 0) {
			        FILE *fp = fopen("sparepart.txt", "r");
			        char line[200];
			        if (fp == NULL) {
			            printf("Gagal membuka file");
			            exit(EXIT_FAILURE);
			        } else {
			            bool ada = false, ada2 = false;
			            int x = 0, j = 0, k = 0;
			            char tampung[100][200];
			            while (fgets(line, sizeof(line), fp) != NULL) {
			                char *token = strtok(line, delim);
			                j = 0;
			                ada = false;
			                while (token != NULL) {
			                    if (j == 1) {
			                    	//printf("%s",data_barang[x][j]);
			                    	//printf("%s",nama_brg);
			                        if (strcmp(data_barang[x][j],nama_brg) == 0) {
			                            ada = true;
			                            ada2 = true; //memastikan jika ketemu
			                        }
			                    }
			                    token = strtok(NULL, delim);
			                    j++;
			                }
			                if (!ada) {
			            //data barang yg bukan dihapus akan ditampung di array tampung
			                	snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s;\n", data_barang[x][0], data_barang[x][1], data_barang[x][2], data_barang[x][3]);
			                }
							else{
			                	int stokk = atoi( data_barang[x][3]);
								int stock_saat_ini;
								char values[100] ;
								stock_saat_ini = stokk - buffer2[i];
			//					printf("%d",stock_saat_ini);
								sprintf(values,"%d",stock_saat_ini); // konversi dari integer ke string-> karena snprintf nya pake string
								snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s;\n", data_barang[x][0], data_barang[x][1], data_barang[x][2], values);
							}
			                k++;
			            	x++;
						}
			            fclose(fp);
			            if (ada2) {
			                fp = fopen("sparepart.txt", "w"); //reset file jadi kosong
							fclose(fp);
			                if (k > 0) {
			                    for (x = 0; x < k; x++) {
			                        addToFile(tampung[x], "sparepart.txt"); 
			                        //printf("%s", tampung[x]);
			                    }         
							}
			                printf("Sukses membeli %s !\n",nama_brg);
			            } else {
			                printf("Nama barang (%s) tidak ditemukan!\n",nama_brg);
			            }
			        }
			    } else {
			        printf("Tidak ada data barang!\n");
			    }
			    printf("===========================================\n");

//============================================= END OF FUNGSI TAMBAH KURANG =====================================================
				}
				getch();
				system("cls");
		    	printf("tekan enter untuk melihat invoice. . .\n");
		    	getch();
		    	system("cls");
		    	printf("=======================================\n");
		    	printf("               BENGKEL YOI                \n");
		    	printf("       Jl. Fatmawati 67, Salatiga \n");
				printf("%d-%02d-%02d | %02d:%02d:%02d | KASIR 1-BAMBANG\n\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
				printf("=======================================\n\n\n");
				for (i=0;i<brg;i++){
					printf("%d\t%s\t%d\t\n\n", buffer2[i],data_barang[buffer[i]][1],hargaa[i]);
				}
				printf("                  ---------------------\n");
				printf("                 Total       Rp. %d\n",total);
				printf("                 Pembayaran  Rp. %d\n",uang);
				printf("                 Kembalian   Rp. %d\n",uang-total);
				printf("\n\n             Terima kasih              \n");
				printf("      Silakan Berbelanja Kembali       \n");
				printf("=======================================\n");
				for (i=0;i<brg;i++){
					snprintf(val, sizeof val, "%s;%d;%d;\n", data_barang[buffer[i]][1], buffer2[i], hargaa[i]);
				}
				addToFile(val, "struk.txt");
				system("pause");
				menu_utama();
		}
	}else{
		 printf("\nTRANSAKSI DIBATALKAN, TEKAN SEMBARANG TOMBOL UNTUK KEMBALI ...");
//		 system("pause");
		 menu_utama();
	}
}
	
void menu(int pil) {
    if (pil == 1) viewData(1,0);
    else if (pil == 2) tambahData();
    else if (pil == 3) hapusData();
    else if (pil == 4) transaksi();
    else if (pil == 5) viewData(0,1);
} 

void login(){
    system("cls");
    printf("================================================\n");
    printf("||        SELAMAT DATANG DI BENGKEL YOI       ||\n");
    printf("|| SILAKAN LOGIN DAHULU SEBELUM BERBELANJA ^^ ||\n");
    printf("================================================\n");          
    printf("press enter to continue. . .");
    getch();
//    Beep(300,350);
//    Beep(400,350);
    system("cls");
    char pin[10];
    printf("===================================\n");
    printf("||             LOGIN             ||\n");
    printf("===================================\n");
//    Beep(300,350);
//    Beep(400,350);
    printf("\nMASUKKAN PIN ANDA\t: ");
    scanf("%s", pin);
//    Beep(300,350);
//    Beep(400,350);
    system("cls");
    printf("Selamat Datang %s",pin);
    getch();
//    Beep(300,400);
//    Beep(400,400);
//    Beep(600,400);
//    Beep(800,450);
}

void menu_utama(){

    char pilih;
    int pilihan = 0;
    while (pilihan == 0) {
        system("@cls||clear");
        printf("============================================\n");
        printf("||               MENU UTAMA               ||\n");
        time_t t = time(NULL);
  		struct tm tm = *localtime(&t);
  		printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        printf("============================================\n");
        printf("|| 1. Lihat Data Barang                   ||\n");
        printf("|| 2. Tambah Data Barang                  ||\n");
        printf("|| 3. Hapus Data Barang                   ||\n");
        printf("|| 4. Transaksi                           ||\n");
        printf("|| 5. Lihat Struk                         ||\n");
    	printf("|| 6. Logout                              ||\n");
        printf("|| 7. Exit                                ||\n");     
    	printf("============================================\n");
        printf("Pilih Menu : ");
        scanf("%d",&pilihan);
        if (pilihan <= 0 || pilihan > 7) {
            pilihan = 0;
            system("cls");
            printf("Pilihan Menu Salah!");
            getch();
            menu_utama();
        }
    }
    if (pilihan == 6) {
        printf("Anda yakin ingin logout ? y/n\n >> ");
        scanf(" %c", &pilih);
        if (pilih == 'y'){
        	login();
            menu_utama();
        } else if (pilih == 'n') menu_utama();
    } else if (pilihan == 7) exit(EXIT_SUCCESS);
    else menu(pilihan); // dihubungkan ke fungsi menu
}

void main() {
	system("color 9E");
//	Beep(1000,1100);
//    char l=219;
//    printf("LOADING . . .\n");
//    for (int i=0;i<10;i++){
//        Beep(300,500);
//        Beep(400,500);
//        Beep(800,500);
//        printf("%c%c",l,l); 
//    }
	getData("sparepart.txt");
   // login();
    menu_utama();
}
