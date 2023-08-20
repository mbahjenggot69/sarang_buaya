#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <assert.h>
#include <conio.h>

struct data{
    char nama[100], jenis[100], exp[100], pembuat[100];
    struct data *next;
    int kode;
}*head, *current, *node;

struct data obat[1000], x;

int banyak;

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
	system("color 02");
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

void header(){
	loading(45,14);
	system("cls");
	system("color 70");
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

void delay(int number_of_seconds){
    int milli_seconds = 10 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

void addData(){
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
	
	int n = 12;
	for(int i=0;i<banyak;i++){
        int angka;
        ++n;
        gotoxy(14,n);
        printf("DATA  KE-%d", i+1);
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
        printf("Pabrik \t\t: ");
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
            printf("%d   | %d\t| %s\t\t| %s\t| %s\t| %s", i+1,  obat[i].kode, obat[i].nama, obat[i].jenis, obat[i].pembuat, obat[i].exp);
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
	int x=11, y=5, x2=108, y2=8, i=0;
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
	for(i=0;i<banyak;i++){
        if(obat[i].kode == cariKode){
        	gotoxy(50,13);
            printf("DATA OBAT DITEMUKAN!");
            gotoxy(39,15);
            printf("==== INFORMASI OBAT DENGAN KODE %d ====", cariKode);
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
        }
    }
    if(i == banyak){
	    gotoxy(41,18);
	    printf("OBAT YANG ANDA CARI TIDAK DITEMUKAN!");
	    gotoxy(39,27);
	    printf("Tekan ENTER untuk kembali ke Menu Utama");
	    getch();
	}
	main_menu();
}

void cariNama(){
	int x=11, y=5, x2=108, y2=8, i=0;
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
	for(i=0;i<banyak;i++){
		if (strcmp(cariNama, obat[i].nama) == 0){	
    		gotoxy(50,13);
            printf("DATA OBAT DITEMUKAN!");
            gotoxy(39,15);
            printf("==== INFORMASI OBAT DENGAN SESUAI NAMA ====");
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
	    } 
    }
    if(i == banyak){
	    gotoxy(41,18);
	    printf("OBAT YANG ANDA CARI TIDAK DITEMUKAN!");
	    gotoxy(39,27);
	    printf("Tekan ENTER untuk kembali ke Menu Utama");
	    getch();
	}
	main_menu();
}

void updateData(){
	int x=11, y=5, x2=108, y2=8, i, j, update, cariKode, found=0;
    char jawaban;

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
	printf("UPDATE DATA OBAT");
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
            printf("==== INFORMASI OBAT DENGAN KODE %d ====", cariKode);
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
            printf("Data ingin diubah? [y/n] >> ");
            scanf(" %c", &jawaban);
            if (jawaban == 'y'){
            	system("cls");
            	x=11, y=5, x2=108, y2=8;

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
				
				gotoxy(51,6);
				printf("UPDATE DATA OBAT");
				gotoxy(49,7);
				printf("Apotek Sehat Sejahtera");
				gotoxy(13,10);
				printf("Kode Obat\t: %d", cariKode);
			    gotoxy(13,12);
			    printf("DATA YANG INGIN DIUBAH?");    
				gotoxy(13,14);
			    printf("1. Kode Obat");
			    gotoxy(13,15);
			    printf("2. Nama Obat");
			    gotoxy(13,16);
			    printf("3. Jenis Obat");
			    gotoxy(13,17);
			    printf("4. Pabrik");
			    gotoxy(13,18);
			    printf("5. Tanggal EXP");
			    gotoxy(13,19);
            	printf("6. Semua Data Obat");
            	gotoxy(13,21);
            	printf("Pilihan Anda : ");
            	scanf("%d", &update);
            	
            	if(update == 1){
            		system("cls");
            		
            		int x=11, y=9, x2=108, y2=12;
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
		            gotoxy(50,10);
					printf("UPDATE KODE OBAT");
					gotoxy(48,11);
					printf("Apotek Sehat Sejahtera");
		            gotoxy(13,15);
		            printf("Masukkan Kode Baru Obat : ");
		            scanf("%d", &obat[i].kode);
                	
                	
                } else if(update == 2){
                	system("cls");
                	
                	int x=11, y=9, x2=108, y2=12;
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
		            gotoxy(50,10);
					printf("UPDATE NAMA OBAT");
					gotoxy(48,11);
					printf("Apotek Sehat Sejahtera");
		            gotoxy(13,15);
		            printf("Masukkan Nama Baru Obat : ");
                    fflush(stdin);
                    gets(obat[i].nama);
                    
                } else if( update ==3){
                	system("cls");
                	
                	int x=11, y=9, x2=108, y2=12;
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
		            gotoxy(49,10);
					printf("UPDATE JENIS OBAT");
					gotoxy(48,11);
					printf("Apotek Sehat Sejahtera");
		            gotoxy(13,15);
		            printf("Masukkan Jenis Baru Obat : ");
                    fflush(stdin);
                    gets(obat[i].jenis);
            
                } else if( update == 4){
                	system("cls");
                	
                	int x=11, y=9, x2=108, y2=12;
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
		            gotoxy(49,10);
					printf("UPDATE PABRIK OBAT");
					gotoxy(48,11);
					printf("Apotek Sehat Sejahtera");
		            gotoxy(13,15);
		            printf("Masukkan Pabrik Baru Obat : ");
                    fflush(stdin);
                    gets(obat[i].pembuat);
                	
                } else if( update == 5){
                	system("cls");
                	
                	int x=11, y=9, x2=108, y2=12;
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
		            gotoxy(46,10);
					printf("UPDATE TANGGAL EXP. OBAT");
					gotoxy(48,11);
					printf("Apotek Sehat Sejahtera");
		            gotoxy(13,15);
		            printf("Masukkan Tanggal EXP. Baru Obat : ");
                    fflush(stdin);
                    gets(obat[i].exp);
                    
                } else if(update == 6){
                	system("cls");
                	
                	
                    int x=11, y=9, x2=108, y2=12;
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
		            gotoxy(50,10);
					printf("UPDATE DATA OBAT");
					gotoxy(48,11);
					printf("Apotek Sehat Sejahtera");
					
		            gotoxy(13,15);
		            printf("Masukkan Kode Baru Obat\t\t: ");
                    scanf("%d", &obat[i].kode);
                    
                    gotoxy(13,16);
		            printf("Masukkan Nama Baru Obat\t\t: ");
                    fflush(stdin);
                    gets(obat[i].nama);
                    
                    gotoxy(13,17);
		            printf("Masukkan Jenis Baru Obat\t\t: ");
                    fflush(stdin);
                    gets(obat[i].jenis);
                    
                    gotoxy(13,18);
		            printf("Masukkan Pabrik Baru Obat\t\t: ");
                    fflush(stdin);
                    gets(obat[i].pembuat);
                    
                    gotoxy(13,19);
		            printf("Masukkan Tanggal EXP. Baru Obat\t: ");
                    fflush(stdin);
                    gets(obat[i].exp);
                } 
                
                system("cls");
                int x=11, y=11, x2=108, y2=17, i;
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
				
				gotoxy(45,14);
			    printf("DATA OBAT BERHASIL DI-UPDATE!");
			    gotoxy(13,25);
            	
			} else if (jawaban == 'n'){
				gotoxy(51,27);
			    printf("DATA TIDAK DIUBAH!");
                gotoxy(39,28);
	        	printf("Tekan ENTER untuk kembali ke Menu Utama");
	        	getch();
                
			} else {
				gotoxy(46,18);
				printf ("INPUTAN ANDA SALAH!");
				gotoxy(39,27);
	        	printf("Tekan ENTER untuk kembali ke Menu Utama");
	        	getch();
			}
            break;
            
        } else {
	    	gotoxy(41,18);
	        printf("OBAT YANG ANDA CARI TIDAK DITEMUKAN!");
	        gotoxy(39,27);
	        printf("Tekan ENTER untuk kembali ke Menu Utama");
	    }
    }
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
	printf("Masukkan Kode Obat yang Ingin Dihapus\t: ");
	scanf("%d", &delData);
	
	for(i=0;i<=banyak;i++){
        if(obat[i].kode == delData){
        	found=1;
            gotoxy(37,13);
            printf("==== INFORMASI OBAT DENGAN KODE %d ====", delData);
            gotoxy(13,15);
            printf("Kode Obat\t\t: %d", obat[i].kode);
            gotoxy(13,16);
            printf("Nama Obat\t\t: %s", obat[i].nama);
            gotoxy(13,17);
            printf("Jenis Obat\t\t: %s", obat[i].jenis);
            gotoxy(13,18);
            printf("Pabrik\t\t: %s", obat[i].pembuat);
            gotoxy(13,19);
            printf("Tanggal EXP.\t: %s", obat[i].exp);
            gotoxy(13,24);
            printf("Data ingin dihapus? [y/n] >> ");
            scanf(" %c", &jawaban);
            if (jawaban == 'y'){
            	for(int j=i; j<=banyak; j++){
                	obat[j] = obat[j + 1];
				}
                banyak--;
                hapus = head;
                head = head->next;
                free(hapus);
                gotoxy(48,27);
                printf("DATA BERHASIL DIHAPUS!");
                gotoxy(39,28);
	        	printf("Tekan ENTER untuk kembali ke Menu Utama");
                getch();
            	main_menu();
			} else if (jawaban == 'n'){
				gotoxy(50,27);
			    printf("DATA TIDAK DIHAPUS!");
                gotoxy(39,28);
	        	printf("Tekan ENTER untuk kembali ke Menu Utama");
                getch();
				main_menu();
			} else {
				gotoxy(46,18);
				printf ("INPUTAN ANDA SALAH!");
				gotoxy(39,27);
	        	printf("Tekan ENTER untuk kembali ke Menu Utama");
				getch();
				main_menu();
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
	int x=11, y=11, x2=108, y2=17, i;
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
    char id[20], pass[20], ch, z=0;
    int x=11, y=11, x2=108, y2=17, i;
    
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
    while((ch=getch())!=13) {
          pass[z++]=ch;
          printf("%c",'*');
    }
    pass[z]='\0';
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
			system("color 9F");
            addData();
			break;
			
        case 2:
        	loading(45,14);
        	system("cls");
        	system("color E0");
            viewData();
			break;
			
        case 3:
        	loading(45,14);
            system("cls");
            system("color 2F");
            int x=11, y=9, x2=108, y2=12;
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
            gotoxy(50,10);
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
            	system("color 2F");
                urutKode();
            }
            else {
            	loading(45,14);
            	system("cls");
            	system("color 2F");
                urutNama();
            }
			break;
			
        case 4:
        	loading(45,14);
        	system("cls");
        	system("color BF");
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
            	system("color BF");
                cariKode();
            }
            else {
            	loading(45,14);
            	system("cls");
            	system("color BF");
                cariNama();
            }
            break;
            
        case 5:
        	loading(45,14);
        	system("cls");
        	system("color CF");
            updateData();
            break;
            
        case 6:
        	loading(45,14);
        	system("cls");
        	system("color 06");
            deleteData();
            break;
            
        case 7:
        	loading(45,14);
        	system("cls");
        	system("color F4");
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
	loginPage();
	main_menu();
	return 0;
}


