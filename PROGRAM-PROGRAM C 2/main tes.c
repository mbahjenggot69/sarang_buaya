#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <assert.h>
#include <conio.h>

void main();
void kepalamain();
void inputT();
void iTail();
void read();
void SoNIK();
void SoNAMA();
void S();
void Hapus();
void update();
void keluar();
void gotoxy(int x,int y);
void loading(int x,int y);

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


void SetColor(unsigned short color) {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}

struct data{
    char namawarga[100], email[100],tgllhr[100],nohp[100];
    struct data *next;
    int nik;
    int no;
}*head, *current, *node;

struct data penduduk[1000], x;
int banyak;

void main(){
    system("@cls||clear");
    int pilih, pil, up;
    kepalamain();
    printf("|  Anda dapat melakukan operasi berikut :             |\n");
    printf("|                                                     |\n");
    printf("|  1. Tambah Data Penduduk                            |\n");
    printf("|  2. Lihat Data Penduduk                             |\n");
    printf("|  3. Urutkan Data Penduduk                           |\n");
    printf("|  4. Cari Data Penduduk                              |\n");
    printf("|  5. Ubah Data Penduduk                              |\n");
    printf("|  6. Hapus Data Penduduk                             |\n");
    printf("|  7. Keluar                                          |\n");
    printf("|                                                     |\n");
    printf("   Masukan pilihan : ", pilih);
    scanf("%i", &pilih);
    switch(pilih){
		case 1:
			inputT();
			break;
        case 2:
            read();
			break;
        case 3:
            system("@cls||clear");
            printf("=================================================================================================|");
            gotoxy(23,1);
            printf("                   DATA PENDUDUK\t\t\t\t\t\t |");
            gotoxy(15,2);
            printf("                         DESA RAJA NANGKA\t\t\t\t\t |");
            printf("\n=================================================================================================|\n");
            printf("|Urutkan Data Berdasarkan :                                                                      |\n");
            printf("|   1. NIK                                                                                       |\n");
            printf("|   2. Nama                                                                                      |\n");
            printf("--------------------------------------------------------------------------------------------------\n");

            printf("Pilih : ");
            scanf("\n%d", &pil);

            if (pil==1){
                SoNIK();
            }
            else {
                SoNAMA();
            }
			break;
        case 4:
            S();
            break;
        case 5:
            update();
            break;
        case 6:
            Hapus();
            break;
        case 7:
            keluar();
            exit(0);
            break;
		default:
			printf("Pilihan tidak ada\n");
			printf("Press any key to continue...");
      		getch();
      		main();
	}
}

void kepalamain() {
    loading(40,1);
    printf("=======================================================");
    gotoxy(11,1);
    printf("          SELAMAT DATANG");
    gotoxy(5,2);
    printf("      Program Data Penduduk Desa Raja Nangka");
    printf("\n=======================================================\n");
    char s[64];
    SetColor(8);
    gotoxy(11,5);
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    assert(strftime(s, sizeof(s), "%c", tm));
    printf("        %s\n\n", s);
    SetColor(7);
}

void inputT(){
    system("@cls||clear");
    printf("=======================================================");
    gotoxy(9,1);
    printf("        MASUKKAN DATA PENDUDUK");
    gotoxy(5,1);
    printf("\n=======================================================\n");

    printf("Masukkan banyak data : ");
    scanf("%i", &banyak);

    for(int i=0;i<banyak;i++){
        int angka;
        printf("\nData Penduduk ke-%d :", i+1);

        printf("\nNO   \t\t: ");
        scanf("%d", &penduduk[i].no);

        printf("NIK  \t\t: ");
        scanf("%d", &penduduk[i].nik);

        fflush(stdin);
        printf("Nama Warga \t: ");
        gets(penduduk[i].namawarga);

        fflush(stdin);
        printf("Email \t\t: ");
        gets(penduduk[i].email);

        fflush(stdin);
        printf("No Handphone \t: ");
        gets(penduduk[i].nohp);

        fflush(stdin);
        printf("Tanggal Lahir \t: ");
        gets(penduduk[i].tgllhr);

        iTail(penduduk[i].nik);
    }

    printf("\n-------------------------------------------------------");
    printf("\nPress any key to continue...");
    getch();
    main();
}


void iTail(int angka){
    node = (struct data *)malloc(sizeof(struct data));
    node->nik = angka;

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

void read(){
    system("@cls||clear");
    printf("================================================================================================|");
    gotoxy(23,1);
    printf("                   DATA PENDUDUK\t\t\t\t\t\t|");
    gotoxy(15,2);
    printf("                         DESA RAJA NANGKA\t\t\t\t\t|");
    printf("\n================================================================================================|\n");
    current = head;
    int banyak;

    if(head == NULL) {
        printf("|                                                                       \t\t\t|\n");
        printf("|  Data Masih Kosong                                                    \t\t\t|\n");
        printf("|  Silahkan isi terlebih dahulu di menu 1                               \t\t\t|\n");
        printf("|                                                                       \t\t\t|");
        printf("\n------------------------------------------------------------------------------------------------|\n");
        printf("Press any key to continue...");
        getch();
        main();
        return;
    }
    gotoxy(3,5);
    printf("NO");
    gotoxy(13,5);
    printf("NIK");
    gotoxy(28,5);
    printf("Nama Warga");
    gotoxy(43,5);
    printf("Email");
    gotoxy(63,5);
    printf("No Handphone");
    gotoxy(80,5);
    printf("Tanggal Lahir");
    printf("\n+-----------------------------------------------------------------------------------------------+\n");
    gotoxy(3,7);
    for(int i=0;i<banyak;i++){
        while(current!=NULL){
            printf("%-9d %-14d %-14s %-19s %-12s \t%s", penduduk[i].no,  penduduk[i].nik, penduduk[i].namawarga, penduduk[i].email, penduduk[i].nohp, penduduk[i].tgllhr);
            gotoxy(3,7+i+1);
            i++;
            current = current->next;
        }
    }

    printf("\n+-----------------------------------------------------------------------------------------------+\n");
    printf("Press any key to continue...");
    getch();
    main();
}

void SoNIK(){
    system("@cls||clear");
    printf("================================================================================================|");
    gotoxy(23,1);
    printf("               DATA PENDUDUK BERDASARKAN NIK\t\t\t\t|");
    gotoxy(15,2);
    printf("                            DESA RAJA NANGKA\t\t\t\t\t|");
    printf("\n================================================================================================|\n");

    int i,j;
    int *n= &banyak;

    if(head == NULL) {
        printf("|                                                                       \t\t\t|\n");
        printf("|  Data Masih Kosong                                                    \t\t\t|\n");
        printf("|  Silahkan isi terlebih dahulu di menu 1                               \t\t\t|\n");
        printf("|                                                                       \t\t\t|");
        printf("\n------------------------------------------------------------------------------------------------|\n");
        printf("Press any key to continue...");
        getch();
        main();
        return;
    }

    for(i=0; i<=*n-1; i++){
        for(j=i; j<*n; j++){
            if(penduduk[i].nik > penduduk[j].nik){
                x = penduduk[i];
                penduduk[i] = penduduk[j];
                penduduk[j]= x;
            }
        }
    }

    gotoxy(3,5);
    printf("NO");
    gotoxy(13,5);
    printf("NIK");
    gotoxy(28,5);
    printf("Nama Warga");
    gotoxy(43,5);
    printf("Email");
    gotoxy(63,5);
    printf("No Handphone");
    gotoxy(83,5);
    printf("Tanggal Lahir");
    printf("\n+-----------------------------------------------------------------------------------------------+\n");
    gotoxy(3,7);
    for(int i=0;i<banyak;i++){
            printf("%-9d %-14d %-14s %-19s %-12s \t%s", penduduk[i].no,  penduduk[i].nik, penduduk[i].namawarga, penduduk[i].email, penduduk[i].nohp, penduduk[i].tgllhr);
            gotoxy(3,7+i+1);

    }

    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    main();
}

void SoNAMA(){
    system("@cls||clear");
    printf("================================================================================================|");
    gotoxy(23,1);
    printf("              DATA PENDUDUK BERDASARKAN NAMA\t\t\t\t|");
    gotoxy(15,2);
    printf("                            DESA RAJA NANGKA\t\t\t\t\t|");
    printf("\n================================================================================================|\n");
    int i,j;
    int *n= &banyak;

    if(head == NULL) {
        printf("|                                                                       \t\t\t|\n");
        printf("|  Data Masih Kosong                                                    \t\t\t|\n");
        printf("|  Silahkan isi terlebih dahulu di menu 1                               \t\t\t|\n");
        printf("|                                                                       \t\t\t|");
        printf("\n------------------------------------------------------------------------------------------------|\n");
        printf("Press any key to continue...");
        getch();
        main();
        return;
    }

    for(i=0; i<=*n-1; i++){
        for(j=i;j<*n; j++){
            if(strcmp(penduduk[i].namawarga,penduduk[j].namawarga) > 0){
                x=penduduk[i];
                penduduk[i]=penduduk[j];
                penduduk[j]=x;
            }
        }
    }
    gotoxy(3,5);
    printf("NO");
    gotoxy(13,5);
    printf("NIK");
    gotoxy(28,5);
    printf("Nama Warga");
    gotoxy(43,5);
    printf("Email");
    gotoxy(63,5);
    printf("No Handphone");
    gotoxy(83,5);
    printf("Tanggal Lahir");
    printf("\n+-----------------------------------------------------------------------------------------------+\n");
    gotoxy(3,7);
    for(int i=0;i<banyak;i++){
        printf("%-9d %-14d %-14s %-19s %-12s \t%s", penduduk[i].no,  penduduk[i].nik, penduduk[i].namawarga, penduduk[i].email, penduduk[i].nohp, penduduk[i].tgllhr);
        gotoxy(3,7+i+1);
    }
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    main();
}

void S(){
    system("@cls||clear");
    printf("================================================================================================|");
    gotoxy(23,1);
    printf("                CARI DATA PENDUDUK\t\t\t\t\t|");
    gotoxy(15,2);
    printf("                         DESA RAJA NANGKA\t\t\t\t\t|");
    printf("\n================================================================================================|\n");
    int cari,i;
    int ketemu=0;
    int *n= &banyak;

    if(head == NULL) {
        printf("|                                                                       \t\t\t|\n");
        printf("|  Data Masih Kosong                                                    \t\t\t|\n");
        printf("|  Silahkan isi terlebih dahulu di menu 1                               \t\t\t|\n");
        printf("|                                                                       \t\t\t|");
        printf("\n------------------------------------------------------------------------------------------------|\n");
        printf("Press any key to continue...");
        getch();
        main();
        return;
    }

    printf("Masukkan NIK Penduduk yang Ingin Dicari : ");
    scanf("%d", &cari);

    SetColor(8);
    printf("\n+-----------------------------------------------------------------------------------------------+\n");
    SetColor(7);

    gotoxy(3,7);
    printf("NO");
    gotoxy(13,7);
    printf("NIK");
    gotoxy(28,7);
    printf("Nama Warga");
    gotoxy(43,7);
    printf("Email");
    gotoxy(63,7);
    printf("No Handphone");
    gotoxy(80,7);
    printf("Tanggal Lahir");
    printf("\n+-----------------------------------------------------------------------------------------------+\n");
    gotoxy(3,9);
    for(int i=0;i<*n;i++){
            if(penduduk[i].nik==cari){
                printf("%-9d %-14d %-14s %-19s %-12s \t%s", penduduk[i].no,  penduduk[i].nik, penduduk[i].namawarga, penduduk[i].email, penduduk[i].nohp, penduduk[i].tgllhr);
                gotoxy(3,9+i+1);
                ketemu=1;
            }
    }
    if(ketemu==0){
        printf("\n\t\t     Maaf NIK Penduduk yang dimasukkan tidak ada!\n");
    }
    gotoxy(0,11);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    printf("Press any key to continue...");
    getch();
    main();
}

void Hapus(){
    system("@cls||clear");
    printf("==========================================================================");
    gotoxy(20,1);
    printf("          HAPUS DATA PENDUDUK");
    gotoxy(15,2);
    printf("\n==========================================================================\n");
    char jawab;
    int i, cari;
    int ketemu=0;
    struct data*hapus;

    if(head == NULL) {
        printf("|                                                                         |\n");
        printf("|  Data Masih Kosong                                                      |\n");
        printf("|  Silahkan isi terlebih dahulu di menu 1                                 |\n");
        printf("|                                                                         |");
        printf("\n--------------------------------------------------------------------------\n");
        printf("Press any key to continue...");
        getch();
        main();
        return;
    }

    printf("Masukan ID Penduduk yang ingin dihapus : ");
    scanf("%d", &cari);

    SetColor(8);
    printf("+------------------------------------------------------------------------+\n");
    SetColor(7);

    gotoxy(3,7);
    printf("NO");
    gotoxy(13,7);
    printf("NIK");
    gotoxy(28,7);
    printf("Nama Warga");
    gotoxy(43,7);
    printf("Email");
    gotoxy(63,7);
    printf("No Handphone");
    gotoxy(80,7);
    printf("Tanggal lahir");
    printf("\n+------------------------------------------------------------------------+\n");
    gotoxy(3,9);
    for(int i=0;i<banyak;i++){
            if(cari == penduduk[i].nik){
            printf("%-9d %-14s %-14s %-19s %-12s", penduduk[i].no,  penduduk[i].nik, penduduk[i].namawarga, penduduk[i].email, penduduk[i].nohp,penduduk[i].tgllhr);
            gotoxy(3,9+i+1);
            ketemu=1;
            gotoxy(0,11);
            SetColor(8);
            printf("--------------------------------------------------------------------------\n");
            SetColor(7);

            printf("Data ingin dihapus?[y/n]");
            scanf(" %c", &jawab);
                if(jawab == 'y' || jawab == 'Y'){
                    for(int j=i; j<=banyak; j++){
                        penduduk[j] = penduduk[j + 1];
                    }banyak--;
                    hapus = head;
                    head = head->next;
                    free(hapus);
                    printf("\n\t\t     Data Penduduk dengan ID %d telah dihapus", cari);
                    printf("\n\n--------------------------------------------------------------------------\n");
                    printf("\nPress any key to continue...");
                    getch();
                }
                else if(jawab == 'n' || jawab == 'N'){
                    printf("\nPress any key to continue...");
                    getch();
                }
                break;
            }
    }
    if(ketemu==0){
        printf("\n\t\t     Maaf ID yang dimasukkan tidak ada!\n");
        printf("\n--------------------------------------------------------------------------\n");
        printf("Press any key to continue...");
        getch();
    }
}

void update(){
    system("@cls||clear");
    printf("==========================================================================");
    gotoxy(20,1);
    printf("          GANTI DATA PENDUDUK");
    printf("\n==========================================================================\n");

    int up, i, upp;
    int ketemu=0;
    char jawab;
    int *n = &banyak;

    if(head == NULL) {
        printf("|                                                                         |\n");
        printf("|  Data Masih Kosong                                                      |\n");
        printf("|  Silahkan isi terlebih dahulu di menu 1                                 |\n");
        printf("|                                                                         |");
        printf("\n--------------------------------------------------------------------------\n");
        printf("Press any key to continue...");
        getch();
        main();
        return;
    }

    printf("ID Penduduk yang ingin diupdate : ");
    scanf("%d", &up);

    for(int i=0;i<*n;i++){
        SetColor(8);
        printf("+------------------------------------------------------------------------+\n");
        SetColor(7);

   	 gotoxy(3,7);
    	printf("NO");
   	 gotoxy(13,7);
    	printf("NIK");
    	gotoxy(28,7);
    	printf("Nama Warga");
    	gotoxy(43,7);
   	 printf("Email");
    	gotoxy(63,7);
    	printf("No Handphone");
   	 gotoxy(80,7);
    	printf("Tanggal lahir");
   	 printf("\n+------------------------------------------------------------------------+\n");

        if(penduduk[i].nik == up){
            ketemu=1;
            gotoxy(3,9);
            printf("%-9d %-14s %-14s %-19s %-12s", penduduk[i].no,  penduduk[i].nik, penduduk[i].namawarga, penduduk[i].email, penduduk[i].nohp,penduduk[i].tgllhr);
            gotoxy(3,9+i+1);
            gotoxy(0,11);



            printf("Ingin mengubah data penduduk?[y/n] : ");
            scanf(" %c", &jawab);

            if(jawab == 'y' || jawab == 'Y'){
                SetColor(8);
                printf("+------------------------------------------------------------------------+\n");
                SetColor(7);

                printf("|  1. NIK Penduduk                                                        |\n");
                printf("|  2. Nama Penduduk                                                        |\n");
                printf("|  3. Email Penduduk		                                              |\n");
                printf("|  4. No Handphone Penduduk                                                   |\n");
                printf("|  5. Semua Data Penduduk                                                  |\n");
                printf("\nIngin update apa? : ");
                scanf("%d", &upp);

                SetColor(8);
                printf("\n+------------------------------------------------------------------------+\n");
                SetColor(7);

                if(upp == 1){
                    printf("Masukkan data baru untuk penduduk dengan ID %d : ", up);

                    fflush(stdin);
                    printf("\nNama  \t\t: ");
                    gets(penduduk[i].nik);
                }
                else if(upp == 2){
                    printf("Masukkan data baru untuk penduduk dengan ID %d : ", up);

                    fflush(stdin);
                    printf("\nUmur \t\t: ");
                    gets(penduduk[i].namawarga);
                }
                else if( upp ==3){
                    printf("Masukkan data baru untuk penduduk dengan ID %d : ", up);

                    printf("\nGolongan Darah \t: ");
                    scanf("%s", &penduduk[i].email);
                }
                else if( upp == 4){
                    printf("Masukkan data baru untuk penduduk dengan ID %d : ", up);

                    fflush(stdin);
                    printf("\nDiagnosis \t: ");
                    gets(penduduk[i].nohp);
                }
                else if(upp==5){
                    printf("Masukkan data baru untuk penduduk dengan ID %d : \n", up);

                    fflush(stdin);
                    printf("NIK  \t\t: ");
                    gets(penduduk[i].nik);

                    fflush(stdin);
                    printf("Nama \t\t: ");
                    gets(penduduk[i].namawarga);

                    printf("Email \t: ");
                    scanf("%s", &penduduk[i].email);

                    fflush(stdin);
                    printf("Nomor Handphone \t: ");
                    gets(penduduk[i].nohp);
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

    if(ketemu==0){
        printf("\n\t\t     Maaf ID yang dimasukkan tidak ada!\n");
    }

    printf("\n--------------------------------------------------------------------------");
    printf("\n");
    printf("Press any key to continue...");
    getch();
    main();
}

void keluar(){
    system("@cls||clear");

    printf("==========================================================================");
    gotoxy(17,1);
    printf("             SELAMAT TINGGAL");
    printf("\n\t\tTerimakasih telah mengunjungi program ini\n");
    printf("==========================================================================\n");
    printf("Press any key to exit...");
    getch();
}


	

