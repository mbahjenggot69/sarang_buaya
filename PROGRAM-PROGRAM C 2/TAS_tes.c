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
void viewBank();

struct data{
    char namabarang[100];
    struct data *next;
    int jumlah,harga;
    int no;
int biaya;
}*head, *current, *node;

struct data barang[1000],x;
int banyak;
int total=0;


void goShop(){
    int i;
    printf("Masukkan jumlah barang yang ingin dibeli : ");
    scanf("%i",&banyak);
    for(i=0;i<banyak;i++){
    int angka;
	printf("Barang yang ingin dibeli ke %d", i+1);

	fflush(stdin);
	printf("\nNama Barang \t\t:");
	gets(barang[i].namabarang);

	printf("Jumlah Barang \t\t:");
	scanf("%d",&barang[i].jumlah);

	printf("Harga Barang \t\t: ");
	scanf("%d",&barang[i].harga);

	iTail(barang[i].harga);
    }
    printf("\n-------------------------------------------------------");
    printf("\nPress any key to continue...");
    getch();
    invoice();
}

void invoice(){
    system("@cls||clear");
	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
	int i,j,total=0,duit,kembalian,kekurangan;
	for(i=0;i<banyak;i++){
		total=total+barang[i].harga*barang[i].jumlah;

	}
	current=head;
	printf("=======================================\n");
    printf("               TOKO XIXIXI             \n");
    printf("       Jl. Fatmawati 67, Salatiga \n");
  	printf("%d-%02d-%02d | %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	printf("=======================================\n\n\n");
	 for(i=0;i<banyak;i++){
        while(current!=NULL){
            barang[i].biaya= barang[i].jumlah*barang[i].harga;
            printf("%s\t%d\t%d\t%d\n",barang[i].namabarang, barang[i].jumlah, barang[i].harga, barang[i].biaya);
            i++;
            current = current->next;
        }
    }
    printf("                  ---------------------\n");
    printf("                     Total       Rp. %d\n",total);
    printf("                     Pembayaran  Rp. ");
    scanf("%d", &duit);
    if (duit == total){
        printf("Pembayaran Berhasil\nTerima Kasih");
    }else if(duit>total){
        kembalian = duit - total;
    printf("                     Kembalian   Rp%d", kembalian);
    }else if (duit < total){
        kekurangan = total -  duit;
    printf("Maaf uang anda kurang Rp%d", kekurangan);}
    printf("\n\n             Terima kasih              \n");
    printf("      Silakan Berbelanja Kembali       \n");
    printf("=======================================\n");

    getch();
    menu_utama();
}



void viewBank(){

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
    int pilih;
    system("@cls||clear");
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
    printf("Pilih Menu : ");
    scanf("%d",&pilih);
    do {
		if (pilih == 1){
			goShop();
		} else if (pilih == 2){
			viewBank();
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
	//loginPage();
	menu_utama();
	return 0;
}
