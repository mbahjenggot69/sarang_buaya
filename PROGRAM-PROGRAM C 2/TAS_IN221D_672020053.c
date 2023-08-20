//YANUAR CHRISTY ADE UTAMA (672020053)
//JOSHUA WILLIAM HARIYANTO (672020047)
//FIERYANDO (672020064)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main();
void loginPage();
void menu_utama();
void goShop();
void iTail();
void invoice();
void bankInvoice();
void viewBank();
void viewSaldo();
void addSaldo();

struct data{
    char namabarang[100];
    struct data *next;
    int jumlah,harga,biaya;
    int no;
}*head, *current, *node;

struct data barang[1000];
int banyak=0,total, saldo=1000000;

void goShop(){
	system("cls");
	printf("============================================\n");
    printf("||              TOKO XIXIXI               ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("============================================\n");

    int i,angka,pilih;
    printf("Masukkan jumlah barang yang ingin dibeli : ");
    scanf("%d", &banyak);
    for(i=0;i<banyak;i++){
		printf("\nBarang ke-%d", i+1);

		fflush(stdin);
		printf("\nNama Barang \t: ");
		scanf(" %[^\n]%*c", &barang[i].namabarang);

		printf("Jumlah Barang \t: ");
		scanf("%d",&barang[i].jumlah);

		printf("Harga Barang \t: ");
		scanf("%d",&barang[i].harga);

		iTail(barang[i].harga);
    }
    printf("\n============================================\n");
    printf("Pilih Metode Pembayaran (1. Tunai / 2. Bank) : ");
    scanf("%d", &pilih);
    if (pilih == 1){
    	invoice();
	} else if (pilih == 2){
		bankInvoice();
	} else {
		printf ("\nINPUTAN ANDA SALAH!");
		exit(1);
	}
}

void invoice(){
    system("cls");
	int i,j,total=0,duit,kembalian,kekurangan;
	char pilih;
	for(i=0;i<banyak;i++){
		total=total+barang[i].harga*barang[i].jumlah;
	}
	current=head;
	printf("============================================\n");
    printf("||              TOKO XIXIXI               ||\n");
    printf("||        Jl. Fatmawati 67, Salatiga      ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("============================================\n");
    printf("|| Nama Barang\t| Qty\t| Harga\t| Biaya   ||");
    printf("\n============================================\n\n");
	for(i=0;i<banyak;i++){
        while(current!=NULL){
            barang[i].biaya= barang[i].jumlah*barang[i].harga;
            printf("  %s\t|%d\t|%d\t|%d\n",barang[i].namabarang, barang[i].jumlah, barang[i].harga, barang[i].biaya);
            i++;
            current = current->next;
    	}
    }
    printf("\n                  --------------------------\n");
    printf("                     Total       Rp. %d\n",total);
    printf("                     Pembayaran  Rp. ");
    scanf("%d", &duit);
    if (duit == total){
        printf(" \n");
        printf("\n\n||              Terima kasih               ||\n");
	    printf("||      Silakan Berbelanja Kembali         ||\n");
	    printf("=============================================\n");
		printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
    getch();
    } else if(duit>total){
        kembalian = duit - total;
    	printf("                     Kembalian   Rp. %d", kembalian);
    	printf("\n\n||              Terima kasih               ||\n");
	    printf("||      Silakan Berbelanja Kembali         ||\n");
	    printf("=============================================\n");
		printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
	    getch();
    } else if (duit < total){
        kekurangan = total -  duit;
    	printf("\nMaaf, uang anda kurang Rp. %d", kekurangan);
    	printf("\nBayar menggunakan bank? (y/n)\n>> ");
    	scanf(" %c", &pilih);
    	if (pilih == 'y'){
    		saldo=saldo-kekurangan;
    		printf("\nSALDO ANDA SEKARANG Rp. %d", saldo);
    		printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
    		getch();

		} else if(pilih == 'n'){
			printf("\nMAAF, PEMBAYARAN ANDA DIBATALKAN");
			printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
			getch();
		}
	}
    menu_utama();
}

void bankInvoice(){
	system("cls");
	int i,j,total=0;
	for(i=0;i<banyak;i++){
		total=total+barang[i].harga*barang[i].jumlah;
	}
	current=head;
	printf("============================================\n");
    printf("||              TOKO XIXIXI               ||\n");
    printf("||        Jl. Fatmawati 67, Salatiga      ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("============================================\n");
    printf("|| Nama Barang\t| Qty\t| Harga\t| Biaya   ||");
    printf("\n============================================\n\n");
	for(i=0;i<banyak;i++){
        while(current!=NULL){
            barang[i].biaya= barang[i].jumlah*barang[i].harga;
            printf("  %s\t|%d\t|%d\t|%d\n",barang[i].namabarang, barang[i].jumlah, barang[i].harga, barang[i].biaya);
            i++;
            current = current->next;
        }
    }
    printf("\n                  --------------------------\n");
    printf("                     Total       Rp. %d\n", total);
    printf("                     Pembayaran  Rp. %d\n", total);
    printf("                     Sisa Saldo  Rp. %d\n", saldo-total);
    printf(" \n");
    printf("\n\n||              Terima kasih               ||\n");
	printf("||      Silakan Berbelanja Kembali         ||\n");
	printf("=============================================\n");
	printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
	saldo=saldo-total;
	getch();
	menu_utama();
}

void viewBank(){
	int pilih;
	system("cls");
	printf("============================================\n");
    printf("||                BANK JAGO               ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("============================================\n");
    printf("|| 1. LIHAT SALDO                         ||\n");
    printf("|| 2. TAMBAH SALDO                        ||\n");
    printf("|| 3. KEMBALI                             ||\n");
    printf("============================================\n");
    printf(" Pilih Menu : ");
}

void viewSaldo(){
	system("cls");
	printf("============================================\n");
    printf("||                BANK JAGO               ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("============================================\n");
    printf("\n SALDO ANDA Rp. %d", saldo);
    printf("\n\n||                                        ||\n");
    printf("============================================\n");
    printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
    getch();
}

void addSaldo(){
	system("cls");
	int addSaldo;
	printf("============================================\n");
    printf("||                BANK JAGO               ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("============================================\n");
    printf(" TAMBAH SALDO Rp. ");
    scanf("%d", &addSaldo);
    printf("\n\n TAMBAH SALDO Rp. %d BERHASIL!", addSaldo);
    saldo=saldo+addSaldo;
    printf("\n SALDO ANDA SEKARANG Rp. %d", saldo);
    printf("\n\n||                                        ||\n");
    printf("============================================\n");
    printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
    getch();
}

void iTail(int angka){
    node = (struct data *)malloc(sizeof(struct data));
    node->harga = angka;

    if(head==NULL){
        head = node;
        current = node;
    }
    else{
        current->next = node;
        current = node;
    }
    current->next = NULL;
}

void menu_utama(){
    int pilih,choice;
    system("cls");
    printf("============================================\n");
    printf("||               MENU UTAMA               ||\n");
    time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	printf("||         %d-%02d-%02d | %02d:%02d:%02d          ||\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("============================================\n");
    printf("|| 1. BELANJA                             ||\n");
    printf("|| 2. TABUNGAN                            ||\n");
    printf("|| 3. LOG OUT                             ||\n");
    printf("|| 4. EXIT                                ||\n");
    printf("============================================\n");
    printf(" Pilih Menu : ");
    scanf("%d",&pilih);
    do {
		if (pilih == 1){
			goShop();
		} else if (pilih == 2){
			viewBank();
			scanf("%d",&choice);
			if (choice == 1){
				viewSaldo();
			} else if (choice == 2){
				addSaldo();
			} else if (choice == 3){
				menu_utama();
			} else {
				printf ("\nINPUTAN ANDA SALAH!");
				exit(1);
			}
		} else if (pilih == 3){
			main();
		} else if (pilih == 4){
			exit(0);
		} else {
			printf ("\nINPUTAN ANDA SALAH!");
			exit(1);
		}
	} while (pilih != 4);
}

void loginPage(){
	system("cls");
	char password[10],nama[40],ch;

    printf("================================================\n");
    printf("||        SELAMAT DATANG DI TOKO XIXIXI       ||\n");
    printf("||  SILAHKAN LOGIN DAHULU SEBELUM BERBELANJA  ||\n");
    printf("================================================\n");

    printf("Masukkan username\t\t: ");
    scanf("%s", nama);
    Beep(300,350);
    Beep(400,350);
	printf("Masukkan passsword (4 karakter)\t: ");
    for(int i=0;i<4;i++){
		ch = getch();
	  	password[i] = ch;
	  	ch = '*' ;
	  	printf("%c",ch);
	}
    system("cls");
    printf("===== Selamat Datang %s =====\n\n", nama);

    char l=220;
    printf("CEK SUHU TUBUH . . .\n");
    for (int i=0;i<10;i++){
        Beep(300,500);
        Beep(400,500);
        Beep(800,500);
        printf("%c%c",l,l);
    }
    printf("\n");
    srand(time(0));
    int lower=36,upper=37,count=1;
	int i;
    for (i=0;i<count;i++){
        int num = (rand()%
           (upper - lower + 1)) + lower;
        printf("Suhu tubuh Anda %d.4",num);
    }
    printf("\n\n===== Selamat Berbelanja =====", nama);
    getch();
}

int main(){
	system("color 9E");
	loginPage();
	menu_utama();
	return 0;
}

