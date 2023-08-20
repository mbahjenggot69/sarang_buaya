#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <assert.h>
#include <conio.h>


int banyak;

struct data{
    char nama[100], jenis[100], exp[100], pembuat[100];
    struct data *next;
    int kode,no;
}*head, *current, *node;

struct data obat[1000], x;
int banyak;
void delay();
void gotoxy(int x,int y){

	HANDLE handle;
	COORD coord;
	coord.X =x;
	coord.Y =y;
	handle  = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle,coord);
}

void loading(int x,int y){
	system("cls");
	int i;
	gotoxy(x,y-1);printf("Loading...");


	for(i=x;i<=x+19;i++){
	    gotoxy(i,y);printf("%c",196);
		gotoxy(i,y+1);printf("%c",196);
	}
	for(i=y;i<=y+1;i++){
	    gotoxy(x,i);printf("%c",179);
		gotoxy(x+19,i);printf("%c",179);
	}
	gotoxy(x,y);printf("%c",218);
	gotoxy(x+19,y);printf("%c",191);
	gotoxy(x,y+1);printf("%c",192);
	gotoxy(x+19,y+1);printf("%c",217);
	for ( i = x; i<=x+19;i++){
		gotoxy(i,y);printf("%c",220);
		gotoxy(i,y+1);printf("%c",223);
		Sleep(20);
	}
	system("cls");
}

void header(){
	system("color 70");
	loading(45,14);
	system("cls");

	int x=25, y=5, x2=85, y2=9;
	gotoxy(25,4);
	printf("+");
	for (int n=0;n<5;n++){
        gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(25,10);
	printf("+");
	for (int n=0;n<57;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(85,10);
	printf("+");
	for (int n=0;n<5;n++){
        gotoxy(85,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(85,4);
	printf("+");
	for (int n=0;n<57;n++){
        gotoxy(x2-2,4);
        delay(1);
        printf("=");
        x2--;
	}

    x=25, y=12, x2=85, y2=21;
	gotoxy(25,12);
	printf("+");
	for (int n=0;n<9;n++){
        gotoxy(x,y+1);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(25,22);
	printf("+");
	for (int n=0;n<57;n++){
        gotoxy(x+2,y+1);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(85,22);
	printf("+");
	for (int n=0;n<9;n++){
        gotoxy(85,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(85,12);
	printf("+");
	for (int n=0;n<57;n++){
        gotoxy(x2-2,12);
        delay(1);
        printf("=");
        x2--;
	}

	gotoxy(48,6);
    printf("SELAMAT DATANG");
    gotoxy(44,8);
    printf("Apotek Sehat Sejahtera");


    gotoxy(28,14);
    printf("1. Tambah Data Obat");
    gotoxy(28,15);
    printf("2. Lihat Data Obat");
    gotoxy(28,16);
    printf("3. Urutkan Data Obat");
    gotoxy(28,17);
    printf("4. Cari Data Obat");
    gotoxy(28,18);
    printf("5. Ubah Data Obat");
    gotoxy(28,19);
    printf("6. Hapus Data Obat");
    gotoxy(28,20);
    printf("7. Keluar");


    char s[64];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    assert(strftime(s, sizeof(s), "%c", tm));
    gotoxy(26,11);
    printf("                     %s\n\n", s);

}

void delay();
void addData();
void iTail();
void viewData();
void urutKode();
void urutNama();
void searchData();
void updateData();
void deleteData();
void exitProgram();
void main_menu();

void delay(int number_of_seconds){
    int milli_seconds = 10 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void addData(){
	int n = 12;

	for(int i=0;i<banyak;i++){
        int angka;
        ++n;
        gotoxy(14,n);
        printf("DATA  KE-%d", i+1);
        n++;
		gotoxy(14,n);
        printf("Nomor \t\t: ");
        scanf("%d", &obat[i].no);
        n++;
		gotoxy(14,n);
        printf("Kode \t\t: ");
        scanf("%d", &obat[i].kode);
        fflush(stdin);
        n++;
        gotoxy(14,n);
        printf("Nama Obat \t: ");
        gets(obat[i].nama);
        fflush(stdin);
        n++;
        gotoxy(14,n);
        printf("Jenis \t\t: ");
        gets(obat[i].jenis);
        fflush(stdin);
        n++;
        gotoxy(14,n);
        printf("Pembuat \t\t: ");
        gets(obat[i].pembuat);
        fflush(stdin);
        n++;
        gotoxy(14,n);
        printf("Expired Date \t: ");
        gets(obat[i].exp);
		n++;
        iTail(obat[i].kode);

    }
	gotoxy(14,n+2);
	system("pause");
	main_menu();
}

void iTail(int angka){
    node = (struct data *)malloc(sizeof(struct data));
    node->kode = angka;

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

void viewData(){
	int x=11, y=5, x2=108, y2=8;
	gotoxy(11,4);
	printf("+");
	for (int n=0;n<4;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,9);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,9);
	printf("+");
	for (int n=0;n<4;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,4);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,4);
        delay(1);
        printf("=");
        x2--;
	}

    x=11, y=10, x2=108, y2=27;
    for (int n=0;n<19;n++){
        gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}
	gotoxy(11,28);
	printf("+");

	gotoxy(107,28);
	printf(" +");
	for (int n=0;n<18;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}
	x=12;
	for (int n=0;n<96;n++){
        gotoxy(x,11);
        delay(1);
        printf("-");
        x++;
	}
	gotoxy(52,6);
	printf("LIHAT DATA OBAT");
	gotoxy(48,7);
	printf("Apotek Sehat Sejahtera");

	gotoxy(13,10);
	printf("NO. | Kode Obat\t| Nama Obat\t\t| Jenis Obat\t| Pabrik\t| Tanggal EXP.");

	current=head;
	for(int i=0;i<banyak;i++){
        while(current!=NULL){
        	gotoxy(13,12+i);
            printf("%d   | %d\t| %s\t\t| %s\t| %s\t| %s", obat[i].no,  obat[i].kode, obat[i].nama, obat[i].jenis, obat[i].pembuat, obat[i].exp);
            i++;
            current = current->next;
        }
    }
    gotoxy(14,28);
	system("pause");
	main_menu();
}

void urutKode(){
	int x=11, y=5, x2=108, y2=8, i, j, num=1;

	gotoxy(11,4);
	printf("+");
	for (int n=0;n<4;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,9);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,9);
	printf("+");
	for (int n=0;n<4;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,4);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,4);
        delay(1);
        printf("=");
        x2--;
	}

    x=11, y=10, x2=108, y2=27;
    for (int n=0;n<19;n++){
        gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}
	gotoxy(11,28);
	printf("+");

	gotoxy(107,28);
	printf(" +");
	for (int n=0;n<18;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}
	x=12;
	for (int n=0;n<96;n++){
        gotoxy(x,11);
        delay(1);
        printf("-");
        x++;
	}
	gotoxy(53,6);
	printf("LIHAT DATA OBAT");
	gotoxy(49,7);
	printf("Apotek Sehat Sejahtera");

	gotoxy(13,10);
	printf("NO. | Kode Obat\t| Nama Obat\t\t| Jenis Obat\t| Pabrik\t| Tanggal EXP.");


	struct data temp;
    for(i=0;i<banyak-1;i++){
        for(j=0;j<(banyak-1-i);j++){
            if(obat[j].kode > obat[j+1].kode){
                    temp = obat[j];
                    obat[j] = obat[j+1];
                    obat[j+1] = temp;
        	}
    	}
	}

    current=head;
	for(int i=0;i<banyak;i++){
        while(current!=NULL){
        	gotoxy(13,12+i);
            printf("%d   | %d\t| %s\t\t| %s\t| %s\t| %s", num,  obat[i].kode, obat[i].nama, obat[i].jenis, obat[i].pembuat, obat[i].exp);
            i++;
            num++;
            current = current->next;
        }
    }
	gotoxy(14,28);
	system("pause");
	main_menu();
}

void urutNama(){

	int x=11, y=5, x2=108, y2=8, i, j, num=1;
	gotoxy(11,4);
	printf("+");
	for (int n=0;n<4;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,9);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,9);
	printf("+");
	for (int n=0;n<4;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,4);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,4);
        delay(1);
        printf("=");
        x2--;
	}

    x=11, y=10, x2=108, y2=27;
    for (int n=0;n<19;n++){
        gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}
	gotoxy(11,28);
	printf("+");

	gotoxy(107,28);
	printf(" +");
	for (int n=0;n<18;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}
	x=12;
	for (int n=0;n<96;n++){
        gotoxy(x,11);
        delay(1);
        printf("-");
        x++;
	}
	gotoxy(53,6);
	printf("LIHAT DATA OBAT");
	gotoxy(49,7);
	printf("Apotek Sehat Sejahtera");

	gotoxy(13,10);
	printf("NO. | Kode Obat\t| Nama Obat\t\t| Jenis Obat\t| Pabrik\t| Tanggal EXP.");


    struct data temp;
    for(i=0;i<banyak-1;i++){
        for(j=0;j<(banyak-1-i);j++){
            if(strcmp(obat[j].nama, obat[j+1].nama)>0){
                    temp = obat[j];
                    obat[j] = obat[j+1];
                    obat[j+1] = temp;
        	}
    	}
	}

	current=head;
	for(int i=0;i<banyak;i++){
        while(current!=NULL){
        	gotoxy(13,12+i);
            printf("%d   | %d\t| %s\t\t| %s\t| %s\t| %s", num,  obat[i].kode, obat[i].nama, obat[i].jenis, obat[i].pembuat, obat[i].exp);
            i++;
            num++;
            current = current->next;
        }
    }

	gotoxy(14,28);
	system("pause");
	main_menu();
}

void cariKode(){
	int x=11, y=5, x2=108, y2=8, i, j;
	int cariKode;
	gotoxy(11,4);
	printf("+");
	for (int n=0;n<4;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,9);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,9);
	printf("+");
	for (int n=0;n<4;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,4);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,4);
        delay(1);
        printf("=");
        x2--;
	}

    x=11, y=10, x2=108, y2=27;
    for (int n=0;n<19;n++){
        gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}
	gotoxy(11,28);
	printf("+");

	gotoxy(107,28);
	printf(" +");
	for (int n=0;n<18;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}
	x=12;
	for (int n=0;n<96;n++){
        gotoxy(x,11);
        delay(1);
        printf("-");
        x++;
	}
	gotoxy(44,6);
	printf("CARI DATA OBAT BERDASARKAN KODE");
	gotoxy(49,7);
	printf("Apotek Sehat Sejahtera");
	gotoxy(13,10);
	printf("Masukkan Kode Obat\t: ");
	scanf("%d", &cariKode);
	for(i=0;i<=banyak;i++){
        if(obat[i].kode == cariKode){
        	gotoxy(50,13);
            printf("DATA OBAT DITEMUKAN!");
            gotoxy(39,15);
            printf("==== INFORMASI DATA DENGAN KODE %d ====", cariKode);
            gotoxy(13,17);
            printf("Kode Obat\t\t: %d", obat[i].kode);
            gotoxy(13,18);
            printf("Nama Obat\t\t: %s", obat[i].nama);
            gotoxy(13,19);
            printf("Jenis Obat\t\t: %s", obat[i].jenis);
            gotoxy(13,20);
            printf("Pabrik\t\t: %s", obat[i].pembuat);
            gotoxy(13,21);
            printf("Tanggal EXP.\t: %s", obat[i].exp);
            gotoxy(41,27);
            printf("Tekan ENTER untuk kembali ke Menu Utama");
            getch();
            break;
        } else {
	    	gotoxy(41,18);
	        printf("OBAT YANG ANDA CARI TIDAK DITEMUKAN!");
	        gotoxy(39,27);
	        printf("Tekan ENTER untuk kembali ke Menu Utama");
	        getch();
	    }
    }
	main_menu();
}

void cariNama(){
	int x=11, y=5, x2=108, y2=8, i, j;
	char cariNama[20];
	gotoxy(11,4);
	printf("+");
	for (int n=0;n<4;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,9);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,9);
	printf("+");
	for (int n=0;n<4;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,4);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,4);
        delay(1);
        printf("=");
        x2--;
	}

    x=11, y=10, x2=108, y2=27;
    for (int n=0;n<19;n++){
        gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}
	gotoxy(11,28);
	printf("+");

	gotoxy(107,28);
	printf(" +");
	for (int n=0;n<18;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}
	x=12;
	for (int n=0;n<96;n++){
        gotoxy(x,11);
        delay(1);
        printf("-");
        x++;
	}
	gotoxy(44,6);
	printf("CARI DATA OBAT BERDASARKAN NAMA");
	gotoxy(49,7);
	printf("Apotek Sehat Sejahtera");
	gotoxy(13,10);
	printf("Masukkan Nama Obat\t: ");
	scanf(" %s", &cariNama);
	for(i=0;i<=banyak;i++){
		if (strcmp(cariNama, obat[i].nama) == 0){
    		gotoxy(50,13);
            printf("DATA OBAT DITEMUKAN!");
            gotoxy(39,15);
            printf("==== INFORMASI DATA DENGAN SESUAI NAMA ====");
            gotoxy(13,17);
            printf("Kode Obat\t\t: %d", obat[i].kode);
            gotoxy(13,18);
            printf("Nama Obat\t\t: %s", obat[i].nama);
            gotoxy(13,19);
            printf("Jenis Obat\t\t: %s", obat[i].jenis);
            gotoxy(13,20);
            printf("Pabrik\t\t: %s", obat[i].pembuat);
            gotoxy(13,21);
            printf("Tanggal EXP.\t: %s", obat[i].exp);
            gotoxy(41,27);
            printf("Tekan ENTER untuk kembali ke Menu Utama");
            getch();
            break;
	    } else {
	    	gotoxy(41,18);
	        printf("OBAT YANG ANDA CARI TIDAK DITEMUKAN!");
	        gotoxy(39,27);
	        printf("Tekan ENTER untuk kembali ke Menu Utama");
	        getch();
	   	}
    }
	main_menu();
}

void updateData(){
	system("@cls||clear");
    int up, i, upp;
    int found=0;
    char jawaban;
    int *n = &banyak;
    printf("ID Obat yang ingin diupdate : ");
    scanf("%d", &up);

    for(int i=0;i<*n;i++){
        printf("+------------------------------------------------------------------------+\n");
        gotoxy(3,7);
    	printf("Kode");
        gotoxy(13,7);
    	printf("Nama Obat");
    	gotoxy(28,7);
    	printf("Jenis Obat");
    	gotoxy(43,7);
        printf("Pabrik");
    	gotoxy(63,7);
    	printf("Tanggal Exp");
        printf("\n+------------------------------------------------------------------------+\n");

        if(obat[i].kode == up){
            found=1;
            gotoxy(3,9);
            printf("%-9d %-14d %-14s %-19s %-12s", obat[i].kode,  obat[i].nama, obat[i].jenis, obat[i].pembuat, obat[i].exp);
            gotoxy(3,9+i+1);
            gotoxy(0,11);
            printf("Ingin mengubah data Obat?[y/n] : ");
            scanf(" %c", &jawaban);
            if(jawaban == 'y' || jawaban == 'Y'){
                printf("+------------------------------------------------------------------------+\n");
                printf("|  1. Kode Obat                                                                 |\n");
                printf("|  2. Nama Obat                                                                 |\n");
                printf("|  3. Jenis Obat		                                                        |\n");
                printf("|  4. Pabrik                                                                    |\n");
                printf("|  5. Tanggal Expired                                                           |\n");
                printf("|  6. Semua Data Obat                                                       |\n");
                printf("\nIngin update apa? : ");
                scanf("%d", &upp);
                printf("\n+------------------------------------------------------------------------+\n");
                if(upp == 1){
                    printf("Masukkan data baru untuk Obat dengan ID %d : ", up);

                printf("Kode Obat \t\t: ");
                scanf("%d", &obat[i].kode);
                }
                else if(upp == 2){
                    printf("Masukkan data baru untuk Obat dengan ID %d : ", up);
                    fflush(stdin);
                    printf("Nama Obat \t: ");
                    gets(obat[i].nama);
                }
                else if( upp ==3){
                    printf("Masukkan data baru untuk Obat dengan ID %d : ", up);
                    fflush(stdin);
                    printf("Jenis Obat \t\t: ");
                    gets(obat[i].jenis);
                }
                else if( upp == 4){
                    printf("Masukkan data baru untuk Obat dengan ID %d : ", up);

                    fflush(stdin);
                    printf("Pabrik \t: ");
                    gets(obat[i].pembuat);
                }
                else if( upp == 5){
                    printf("Masukkan data baru untuk Obat dengan ID %d : ", up);
                        fflush(stdin);
                        printf("Tanggal Expired \t: ");
                        gets(obat[i].exp);
                }
                else if(upp==6){
                    printf("Masukkan data baru untuk penduduk dengan ID %d : \n", up);

                    printf("Kode Obat \t\t: ");
                    scanf("%d", &obat[i].kode);

                    fflush(stdin);
                    printf("Nama Obat \t: ");
                    gets(obat[i].nama);

                    fflush(stdin);
                    printf("Jenis Obat \t\t: ");
                    gets(obat[i].jenis);

                    fflush(stdin);
                    printf("Pabrik \t: ");
                    gets(obat[i].pembuat);

                    fflush(stdin);
                    printf("Tanggal Expired \t: ");
                    gets(obat[i].exp);
                }
                else{
                    printf("Maaf pilihan tidak ada!");
                    printf("\n\nPress any key to continue...");
                    getch();
                    main();
                }
                printf("\n\n\t\t       Terimakasih data sudah diupdate");
            }
            else{
                printf("\n--------------------------------------------------------------------------");
                printf("\nPress any key to continue...");
                getch();
                main();
            }
        }
    }

    if(found==0){
        printf("\n\t\t     Maaf ID yang dimasukkan tidak ada!\n");
    }

    printf("\n--------------------------------------------------------------------------");
    printf("\n");
    printf("Press any key to continue...");
    getch();

	main_menu();
}

void deleteData(){
	int x=11, y=5, x2=108, y2=8, i, j;
	int delData, found=0;
	char jawaban;
	struct data*hapus;
	gotoxy(11,4);
	printf("+");
	for (int n=0;n<4;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,9);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,9);
	printf("+");
	for (int n=0;n<4;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,4);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,4);
        delay(1);
        printf("=");
        x2--;
	}

    x=11, y=10, x2=108, y2=27;
    for (int n=0;n<19;n++){
        gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}
	gotoxy(11,28);
	printf("+");

	gotoxy(107,28);
	printf(" +");
	for (int n=0;n<18;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}
	x=12;
	for (int n=0;n<96;n++){
        gotoxy(x,11);
        delay(1);
        printf("-");
        x++;
	}
	gotoxy(53,6);
	printf("HAPUS DATA OBAT");
	gotoxy(49,7);
	printf("Apotek Sehat Sejahtera");
	gotoxy(13,10);
	printf("Masukkan Kode Obat\t: ");
	scanf("%d", &delData);

	for(i=0;i<=banyak;i++){
        if(delData == obat[i].kode ){
            gotoxy(37,15);
            printf("==== INFORMASI DATA DENGAN KODE %d ====", delData);
            gotoxy(13,17);
            printf("Kode Obat\t\t: %d", obat[i].kode);
            gotoxy(13,18);
            printf("Nama Obat\t\t: %s", obat[i].nama);
            gotoxy(13,19);
            printf("Jenis Obat\t\t: %s", obat[i].jenis);
            gotoxy(13,20);
            printf("Pabrik\t\t: %s", obat[i].pembuat);
            gotoxy(13,21);
            printf("Tanggal EXP.\t: %s", obat[i].exp);
            gotoxy(13,24);
            found=1;
            printf("Data ingin dihapus? [y/n] >> ");
            scanf(" %c", &jawaban);
            if (jawaban == 'y'){
            	for(int j=i; j<=banyak; j++){
                obat[j] = obat[j + 1];}
                banyak--;
                hapus = head;
                head = head->next;
                free(hapus);
                printf("Data berhasil dihapus");
                printf("\nPress any key to continue...");
                getch();
            	main_menu();
			} else if (jawaban == 'n'){
			    printf("Data tidak dihapus");
                printf("\nPress any key to continue...");
                getch();
				main_menu();
			} else {
				printf ("\nINPUTAN ANDA SALAH!");
				exit(1);
			}
            getch();
            break;
        } else {
	    	gotoxy(41,18);
	        printf("OBAT YANG ANDA CARI TIDAK DITEMUKAN!");
	        gotoxy(39,27);
	        printf("Tekan ENTER untuk kembali ke Menu Utama");
	        getch();
	        main_menu();
	    }
    }

}

void exitProgram(){
	int x=11, y=11, x2=108, y2=17, i, j;
	gotoxy(11,10);
	printf("+");
	for (int n=0;n<7;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,18);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,18);
	printf("+");
	for (int n=0;n<7;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,10);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,10);
        delay(1);
        printf("=");
        x2--;
	}

	gotoxy(37,14);
    printf("TERIMA KASIH SUDAH MENGGUNAKAN APLIKASI KAMI!");
    gotoxy(13,25);
}

void loginPage(){
	system("color 70");
	system("cls");
    char id[20], pass[20], ch;
    int x=11, y=11, x2=108, y2=17, i, j;

	gotoxy(11,10);
	printf("+");
	for (int n=0;n<7;n++){
    	gotoxy(x,y);
        delay(1);
        printf("|");
        y++;
	}

	gotoxy(11,18);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x+2,y);
        delay(1);
        printf("=");
        x++;
	}

	gotoxy(108,18);
	printf("+");
	for (int n=0;n<7;n++){
        gotoxy(x2,y2);
        delay(1);
        printf("|");
        y2--;
	}

	gotoxy(108,10);
	printf("+");
	for (int n=0;n<94;n++){
        gotoxy(x2-2,10);
        delay(1);
        printf("=");
        x2--;
	}

	gotoxy(45,12);
    printf("Harap login terlebih dahulu!");
    gotoxy(14,14);
    printf("Username : ");
    scanf("%s", &id);
    gotoxy(14,15);
    printf("Password : ");
    scanf("%s", &pass);
    if (strcmp(id, "admin") == 0 && strcmp(pass, "ganteng") == 0){
    	gotoxy(48,25);
        printf("Selamat Datang %s!", id);
        getch();
        main_menu();
    }
    else {
    gotoxy(46,25);
   	printf("Username / Password Salah!");
   	getch();
   	loginPage();
    }
	main_menu();
}

void main_menu(){
	header();
	int pilih, pil;
	gotoxy(25,23);
    printf("   Masukkan pilihan : ", pilih);
    scanf("%d", &pilih);
    switch(pilih){
		case 1:
			loading(45,14);
			system("cls");
			//TABEL PEDOMAN
			int x=11, y=5, x2=108, y2=8;
			gotoxy(11,4);
			printf("+");
			for (int n=0;n<4;n++){
            	gotoxy(x,y);
            	delay(1);
            	printf("|");
            	y++;
			}

			gotoxy(11,9);
			printf("+");
			for (int n=0;n<94;n++){
            	gotoxy(x+2,y);
            	delay(1);
            	printf("=");
            	x++;
			}

			gotoxy(108,9);
			printf("+");
			for (int n=0;n<4;n++){
            	gotoxy(x2,y2);
            	delay(1);
            	printf("|");
            	y2--;
			}

			gotoxy(108,4);
			printf("+");
			for (int n=0;n<94;n++){
            	gotoxy(x2-2,4);
            	delay(1);
            	printf("=");
            	x2--;
			}

            x=11, y=10, x2=108, y2=27;
            for (int n=0;n<19;n++){
            	gotoxy(x,y);
            	delay(1);
            	printf("|");
            	y++;
			}
			gotoxy(11,28);
			printf("+");

			gotoxy(107,28);
			printf(" +");
			for (int n=0;n<18;n++){
            	gotoxy(x2,y2);
            	delay(1);
            	printf("|");
            	y2--;
			}
			gotoxy(52,6);
			printf("TAMBAH DATA OBAT");
			gotoxy(49,7);
			printf("Apotek Sehat Sejahtera");
			gotoxy(14,10);
            printf("Masukkan banyak data : ");
    		scanf("%d", &banyak);
            addData();
			break;

        case 2:
        	loading(45,14);
        	system("cls");
            viewData();
			break;

        case 3:
        	loading(45,14);
            system("cls");
            x=11, y=9, x2=108, y2=12;
			gotoxy(11,8);
			printf("+");
			for (int n=0;n<4;n++){
            	gotoxy(x,y);
            	delay(1);
            	printf("|");
            	y++;
			}

			gotoxy(11,13);
			printf("+");
			for (int n=0;n<94;n++){
            	gotoxy(x+2,y);
            	delay(1);
            	printf("=");
            	x++;
			}

			gotoxy(108,13);
			printf("+");
			for (int n=0;n<4;n++){
            	gotoxy(x2,y2);
            	delay(1);
            	printf("|");
            	y2--;
			}

			gotoxy(108,8);
			printf("+");
			for (int n=0;n<94;n++){
            	gotoxy(x2-2,8);
            	delay(1);
            	printf("=");
            	x2--;
			}

			x=11, y=14, x2=108, y2=20;

            for (int n=0;n<7;n++){
            	gotoxy(x,y);
            	delay(1);
            	printf("|");
            	y++;
			}
			gotoxy(11,21);
			printf("+");

			for (int n=0;n<94;n++){
            	gotoxy(x+2,y);
            	delay(1);
            	printf("=");
            	x++;
			}

			gotoxy(107,21);
			printf(" +");
			for (int n=0;n<7;n++){
            	gotoxy(x2,y2);
            	delay(1);
            	printf("|");
            	y2--;
			}

            gotoxy(47,10);
			printf("URUTKAN DATA OBAT");
			gotoxy(48,11);
			printf("Apotek Sehat Sejahtera");
            gotoxy(13,15);
            printf("Urutkan Data Berdasarkan : ");
            gotoxy(15,16);
            printf("1. Kode");
            gotoxy(15,17);
            printf("2. Nama");
			gotoxy(13,19);
            printf("Pilih : ");
            scanf("\n%d", &pil);

            if (pil==1){
            	loading(45,14);
            	system("cls");
                urutKode();
            }
            else {
            	loading(45,14);
            	system("cls");
                urutNama();
            }
			break;

        case 4:
        	loading(45,14);
        	system("cls");
        	x=11, y=9, x2=108, y2=12;
			gotoxy(11,8);
			printf("+");
			for (int n=0;n<4;n++){
            	gotoxy(x,y);
            	delay(1);
            	printf("|");
            	y++;
			}

			gotoxy(11,13);
			printf("+");
			for (int n=0;n<94;n++){
            	gotoxy(x+2,y);
            	delay(1);
            	printf("=");
            	x++;
			}

			gotoxy(108,13);
			printf("+");
			for (int n=0;n<4;n++){
            	gotoxy(x2,y2);
            	delay(1);
            	printf("|");
            	y2--;
			}

			gotoxy(108,8);
			printf("+");
			for (int n=0;n<94;n++){
            	gotoxy(x2-2,8);
            	delay(1);
            	printf("=");
            	x2--;
			}

			x=11, y=14, x2=108, y2=20;

            for (int n=0;n<7;n++){
            	gotoxy(x,y);
            	delay(1);
            	printf("|");
            	y++;
			}
			gotoxy(11,21);
			printf("+");

			for (int n=0;n<94;n++){
            	gotoxy(x+2,y);
            	delay(1);
            	printf("=");
            	x++;
			}

			gotoxy(107,21);
			printf(" +");
			for (int n=0;n<7;n++){
            	gotoxy(x2,y2);
            	delay(1);
            	printf("|");
            	y2--;
			}

            gotoxy(52,10);
			printf("CARI DATA OBAT");
			gotoxy(48,11);
			printf("Apotek Sehat Sejahtera");
            gotoxy(13,15);
            printf("Cari Data Berdasarkan : ");
            gotoxy(15,16);
            printf("1. Kode");
            gotoxy(15,17);
            printf("2. Nama");
			gotoxy(13,19);
            printf("Pilih : ");
            scanf("\n%d", &pil);

            if (pil==1){
            	loading(45,14);
            	system("cls");
                cariKode();
            }
            else {
            	loading(45,14);
            	system("cls");
                cariNama();
            }
            break;

        case 5:
        	loading(45,14);
        	system("cls");
            updateData();
            break;

        case 6:
        	loading(45,14);
        	system("cls");
            deleteData();
            break;

        case 7:
        	loading(45,14);
        	system("cls");
            exitProgram();
            exit(0);
            break;

		default:
			loading(45,14);
			system("cls");
			printf("Pilihan tidak ada\n");
			printf("Press any key to continue...");
      		getch();
      		main_menu();
	}
}

int main(){
	//loginPage();
	main_menu();
	return 0;
}
