#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define cls() system("cls")
#define ENTER 13
#define TAB 9
#define BKSP 8
#include <windows.h>
#include <string.h>
#include<time.h>

void login(),gotoab(),menu(),create(),read(),update(),deleted(), edit(),searching(),history(),
sorting(),menu8a(),prSearch(),copy_all(),kembali(),bsort_nama(),bsort_harga(),
bsort_stok(),bsort_jenis();
int n = 0, search();
COORD coord = {0,0};

struct daftar{
    char nama[50];
    char id[10];
    char harga[50];
    char jurusan[50];
    char jenis[10];

    struct daftar *next;
};

struct daftar *head = NULL, *node = NULL, *curr = NULL;

struct hist{
    char aktivitas[100];
    struct hist *next;
};

struct hist *headhist= NULL, *nodehist, *currhist, *datahist;

typedef struct{
    char nama[50];
    char id[10];
    char harga[50];
    char jurusan[50];
    char jenis[10];
}s_nama;

s_nama s_data[100];
void bsort_id(s_nama list[], int s);
void bsort_nama(s_nama list[], int s);
void bsort_harga(s_nama list[], int s);
void bsort_jurusan(s_nama list[], int s);
void bsort_jenis(s_nama list[], int s);

int main(){
    login();
    return 0;
}

getch();

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void m()
{
    int i , j;
    system("cls");
    for(i=0; i<5 ; i++)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t    Loading");
        for(j=0; j<5; j++)
    {
        printf(" . ");
        delay(450);
    }
        system("cls");;
}
system("cls");
}



void gotoab(int a, int b){
    coord.X=a;
    coord.Y=b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

void login(){
    cls();
    struct tm *Sys_T;
    char user[10]="admin";
    char pass[10]="admin";
    int p=0;
    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    system("COLOR 2");
    gotoab(34,9);printf("============================================================");
    gotoab(34,11);printf("============================================================");
    gotoab(34,10);printf("                 %s", asctime (Sys_T)              );
    gotoab(34,18);printf("============================================================");
    gotoab(34,20);printf("============================================================");
    gotoab(34,12);printf("                                                     ");
    gotoab(34,13);printf("                                                     ");
    gotoab(34,14);printf("                                                     ");
    gotoab(34,15);printf("                                                     ");
    gotoab(34,16);printf("                                                     ");
    gotoab(34,17);printf("                                                     ");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoab(58,7);printf("MENU LOGIN");
    gotoab(35,19);printf("BOOKING TIKET V1.0");
    gotoab(41,14);printf("ID (admin)         : ");
    gotoab(41,15);printf("Password (admin)   : ");

    //gotoab(34,19);printf("\t\t\t\t     %s", ctime(&t));
    gotoab(60,14);scanf("%s", &user);

    gotoab(60,15);
    char ch;
    int i = 0;
    while(1){
        ch = getch();

        if(ch == ENTER || ch == TAB){
            pass[i] = '\0';
            break;
        }else if(ch == BKSP){
            if(i > 0){
                i--;
                printf("\b\b");
            }
        }else{
            pass[i++] = ch;
            printf("*");
        }
    }
            if(strcmp(user, "admin") == 0 && strcmp(pass, "admin") == 0)
                {
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("\n\t\t                               Login Sukses                       \n");
                    getch();
                    printf("\n");
                    m();
                    printf("\n\t\t                 -------   Selamat Datang Admin   ------                \n");
                    printf("\n\t\t            -------   Tekan Enter Untuk Melanjutkan   ------                \n");
                    getch();
                    menu();
            }else {
                    cls();
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("\n\t\t                       Username atau Password tidak valid \n", 2-n);
                    getch();
                    n++;
             }if(n>2){
                    printf("\n");
                    printf("\n");
                    printf("\n");
                    printf("\n\t\t\t                         Akun Terblokir");
                    getch();
                    exit(0);
            }
        login();
    }

void kembali(){
        char enter;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        printf("\n\t\t\t\t       |Tekan Enter untuk kembali ke menu awal|");
        while((enter = getchar()) != '\n');
        enter = getchar();
        system("cls");
        menu();
}

int z=0;

void create(){
    int a, max;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    gotoab(0,0);printf("                                     |==========================================|");
    gotoab(0,2);printf("                                     |==========================================|");
    gotoab(0,8);printf("                                     |==========================================|");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoab(45,1);printf("     Masukkan Data Baru ");
    gotoab(42,4);printf("      Maksimum input data: 10");
    gotoab(42,6);printf("Berapa banyak yang mau diinputkan ? ");
    scanf("%d", &max);
    cls();

    if(max > 10){
        printf("Batas maksimum 10 data!");
        exit(0);
    }

    headhist = NULL;
    head = NULL;
    for(a=0; a<max; a++){
        //Alokasi memori untuk data baru
        node = (struct daftar*) malloc(sizeof(struct daftar));

        z = 0;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        gotoab(0,0);printf("                                   |============================================|");
        gotoab(0,2);printf("                                   |============================================|");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoab(40,1);printf("              Input Menu              ");
        gotoab(52,3+(6*a));printf("nama ke - %d", a+1);
        gotoab(52,4+(6*a));printf("ID Booking \t :"); scanf(" %[^\n]s", &node->id); //ubah int ke char array
        gotoab(52,5+(6*a));printf("Nama \t :"); scanf(" %[^\n]s", &node->nama);
        gotoab(52,6+(6*a));printf("Harga \t\ :"); scanf(" %[^\n]s", &node->harga);
        gotoab(52,7+(6*a));printf("Jurusan/Lokasi \t\ :"); scanf(" %[^\n]s", &node->jurusan);
        gotoab(52,8+(6*a));printf("Jenis \t :"); scanf(" %[^\n]s", &node->jenis);

        //Kondisi tidak ada data
        if(head == NULL){
            head = node;
            curr = node;
        }
        //Kondisi sudah ada data
        else{
            curr->next = node;
            curr = node;
        }
    }
    curr->next = NULL;
    z += max+1; //Sebagai penanda
    n += max;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    gotoab(0,(6*a)+3);printf("                                     |=============================================|");

    datahist = (struct hist*) malloc(sizeof(struct hist));
    char job[100];
    sprintf(job, "Admin memasukkan %d data baru", max);
    strcpy(datahist->aktivitas, job);

    if(headhist == NULL){
        headhist = datahist;
        currhist = datahist;
    }else{
        currhist -> next = datahist;
        currhist = datahist;
    }
    currhist -> next = NULL;
}

void read(){
    struct daftar *ct;
    ct = (struct daftar*) malloc(sizeof(struct daftar));;
    ct = head;

    int i = 5, j;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        gotoab(0,0); printf("|====================================================================================================================|");
        gotoab(0,2); printf("|====================================================================================================================|");
        gotoab(0,4); printf("|====================================================================================================================|");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        gotoab(40,1);printf("           Database Booking      ");
        gotoab(0,3);printf("ID Booking");
        gotoab(24,3);printf("Nama ");
        gotoab(47,3);printf("Harga");
        gotoab(76,3);printf("Jurusan/Lokasi");
        gotoab(106,3);printf("Jenis");

        //ketika data di ct tidak kosong
    while(ct != NULL){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        //ubah char ke int
        gotoab(1,i);sscanf(ct->id,"%d",&j);printf("%d",j);
        gotoab(24,i);printf("%s", ct->nama);
        gotoab(47,i);printf("%s", ct->harga);
        gotoab(76,i);printf("%s", ct->jurusan);
        gotoab(106,i);printf("%s", ct->jenis);
        ct = ct->next;
        i++;
    }
    printf("\n");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        gotoab(0,i); printf("|====================================================================================================================|");

    datahist = (struct hist*) malloc(sizeof(struct hist));
    strcpy(datahist->aktivitas, "Admin melihat database");

    if(headhist == NULL){
        headhist = datahist;
        currhist = datahist;
    }else{
        currhist -> next = datahist;
        currhist = datahist;
    }
    currhist -> next = NULL;
}

void update(){
    int a, b = 0, max;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        gotoab(0,0); printf("                               |================================================|");
        gotoab(0,2); printf("                               |================================================|");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        gotoab(40,1);printf("             TAMBAHDATA                  ");
        gotoab(40,4);printf("Berapa Data yang Mau Ditambahkan ? ");
        gotoab(75,4);scanf("%d", &max);
        cls();

        for(a=z; a<z + max; a++){
            node = (struct daftar*) malloc(sizeof(struct daftar));

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        gotoab(0,0); printf("                                  |=============================================|");
        gotoab(0,2); printf("                                  |=============================================|");

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            gotoab(40,1);printf("             TAMBAH DATA                 ");
            gotoab(52,3+(6*b));printf("nama ke - %d",a+1);
            gotoab(52,4+(6*b));printf("ID Booking \t\t :"); scanf(" %[^\n]s", &node->id);
            gotoab(52,5+(6*b));printf("Nama \t\t :"); scanf(" %[^\n]s", &node->nama);
            gotoab(52,6+(6*b));printf("Harga \t\t :"); scanf(" %[^\n]s", &node->harga);
            gotoab(52,7+(6*b));printf("Jurusan/Lokasi \t :"); scanf(" %[^\n]s", &node->jurusan);
            gotoab(52,8+(6*b));printf("Jenis \t\t :"); scanf(" %[^\n]s", &node->jenis);

            b++;

        if(head == NULL){
            head = node;
            curr = node;
        }else{
            curr->next = node;
            curr = node;
        }
    }
    curr->next = NULL;
    z += max;
    n += max;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        gotoab(0, (6*b)+3); printf("|==========================================================================================================|\n");


        datahist =(struct hist*) malloc(sizeof(struct hist));
        char job[100];
        sprintf(job, "Admin menambahkan %d data baru", max);
        strcpy(datahist->aktivitas, job);

if(headhist == NULL){
    headhist = datahist;
    currhist = datahist;
}else {
    currhist -> next = datahist;
    currhist = datahist;
}
currhist -> next = NULL;
}

void deleted(){
    char idbu[30];


    gotoab(0,0); printf("|====================================================================================================================|");
    gotoab(0,2); printf("|====================================================================================================================|");
    gotoab(45,1); printf("ID Booking yang akan dihapus : ");
    gotoab(60,4); scanf("%s", &idbu);

    curr = head;
    struct daftar *next;
    int cek = 0;
    while(curr != NULL){
        next = (struct daftar*) malloc(sizeof(struct daftar));
        next = curr->next;

        int cmp = strcmp(curr->id, idbu);
        cmp = 1;

        if(curr->next != NULL){
            cmp = strcmp(next->id, idbu);
        }

        if(cmp == 0){
            if(curr->next != NULL){
                head = next;
            }else{
                head = NULL;
            }
            cek = 1;
            break;

        }else if(cmp == 0){
            curr->next = next->next;
            cek = 1;
            break;
        }

        if(curr->next != NULL){
            curr = curr->next;
        }else{
            break;
        }
    }

     if(cek == 0){
        gotoab(47,6);printf(">> Data tidak ditemukan ! <<\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        gotoab(0,7);printf("==================================================================\n");
     }else{
        gotoab(47,6);printf(">> Data berhasil dihapus ! <<\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        gotoab(0,7);printf("===================================================================\n");

     }

     curr = head;
     while(curr != NULL){
        if(curr->next != NULL){
            curr = curr->next;
        }else{
            break;
        }
     }

     n-= 1;

     datahist = (struct hist*) malloc(sizeof(struct hist));
     char job[100];
     sprintf(job, "Admin menghapus data dengan kode nama = %s ", idbu);
     strcpy(datahist->aktivitas, job);

     if(headhist == NULL)
     {
         headhist = datahist;
         currhist = datahist;
     }else{
         currhist -> next = datahist;
         currhist = datahist;
     }
     currhist -> next = NULL;
     kembali();
}


void edit(){
    int input1;
    char cari[10], newval[30], nama[30], harga[30], stok[30], jenis[30];
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    gotoab(0,0);printf("                                         |======================================|");
    gotoab(0,2);printf("                                         |======================================|");
    gotoab(0,11);printf("                                        |=======================================|");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoab(44,1);printf("              EDIT DATA                      ");
    gotoab(47,4);printf("Data apa yang ingin anda edit? \n");
    gotoab(47,5);printf("1. Nama");
    gotoab(47,6);printf("2. Harga");
    gotoab(47,7);printf("3. Jurusan/Lokasi");
    gotoab(47,8);printf("4. Jenis");
    gotoab(47,9);printf("Pilihan : ");
    gotoab(56,9);scanf("%d", &input1);
    gotoab(47,10);printf("Masukkan ID Booking : ");
    gotoab(70,10);scanf("%s",cari);
    search(cari);
    cls();


        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    gotoab(0,0);printf("                                     |==========================================|");
    gotoab(0,2);printf("                                     |==========================================|");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoab(40,1);printf("               EDIT DATA                          \n");

    if(searchEdit(cari)==1){

    gotoab(45,3);scanf(" %[^\n]s", &newval);
    switch(input1)
    {
    case 1:
        strcpy(curr->nama, newval);
        break;
    case 2:
        strcpy(curr->harga, newval);
        break;
    case 3:
        strcpy(curr->jurusan, newval);
        break;
    case 4:
        strcpy(curr->jenis, newval);
        break;
    }
}else{
        gotoab(47,4);printf("  Data tidak ditemukan ! \n");
}

    curr = head;
    while(curr != NULL){
        if(curr->next != NULL){
            curr = curr->next;
        }else{
            break;
        }

    }

    datahist = (struct hist*) malloc(sizeof(struct hist));
    strcpy(datahist->aktivitas, "Admin melakukan edit data");

    if(headhist == NULL)
    {
        headhist = datahist;
        currhist = datahist;
    }else{
        currhist -> next = datahist;
        currhist = datahist;
    }
    currhist -> next = NULL;

}

int searchEdit(char idbu[50])
{
    curr = head;
    int cmp;
    while(curr != NULL){
        cmp=strcmp(curr->id, idbu);
        if(cmp == 0){
                return 1;
        }
        curr = curr->next;
    }
    return 0;
}

int search(char cr[50], int num)
{
    if(num>5||num<1)
    {
        return 2;
    }
   curr = head;
   int cmp;
   while(curr != NULL)
   {
       switch(num)
       {
       case 1:
        cmp = strcmp(curr->id, cr);
        break;
       case 2:
        cmp = strcmp(curr->nama, cr);
        break;
       case 3:
        cmp = strcmp(curr->harga, cr);
        break;
       case 4:
        cmp = strcmp(curr->jurusan, cr);
        break;
       case 5:
        cmp = strcmp(curr->jenis, cr);
        break;
       }

    if(cmp== 0){
        return 1;
    }
    curr = curr->next;
   }
   return 0;
}


void searching()
{
    int input;
    char cari[30];

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    gotoab(0,0);printf("                                     |==========================================|");
    gotoab(0,2);printf("                                     |==========================================|");
    gotoab(0,12);printf("                                     |==========================================|");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoab(40,1); printf("                  CARI DATA                        ");
    gotoab(40,4); printf("Masukkan Nama Menu : ");
    gotoab(40,5); printf("1. ID Booking");
    gotoab(40,6); printf("2. Nama");
    gotoab(40,8); printf("Masukkan pilihan : ");
    gotoab(59,8); scanf("%d", &input);

    switch(input){
    case 1:
        gotoab(40,9);printf("Masukkan ID Menu yang ingin dicari : ");
        scanf("%s", &cari);
        break;
    case 2:
        gotoab(40,9);printf("Masukkan Nama Menu yang ingin dicari : ");
        scanf(" %[^\n]s", cari);
        break;

    }

    cls();
   if(search(cari,input)==1)
   {
       prSearch();
   }else if(search(cari,input)==2){
       gotoab(40,12);printf("Input tidak valid");
   }else{
       gotoab(40,12);printf("Tidak ditemukan data !");
   }

    while(curr != NULL)
    {
        if(curr->next != NULL)
        {
            curr=curr->next;
        }else{
        break;
        }
    }

    datahist = (struct hist*) malloc(sizeof(struct hist));
    strcpy(datahist->aktivitas, "Admin mencari data");

    if(headhist == NULL){
        headhist = datahist;
        currhist = datahist;
    }
    currhist->next=NULL;
   }

void prSearch(){
   cls();
   struct daftar *ct;
   ct = (struct daftar*) malloc(sizeof (struct daftar));
   ct = curr;
   int i = 5, j;
      gotoab(0,0); printf("|====================================================================================================================|");
      gotoab(40, 1) ;printf("          Hasil Rencarian ");
      gotoab(0,2); printf("|====================================================================================================================|");
      gotoab(0, 3); printf("|ID Booking");
      gotoab(24,3); printf("Nama");
      gotoab(47,3); printf ("Harga");
      gotoab(76,3); printf ("Jurusan/Lokasi");
      gotoab(106, 3); printf("Jenis |");
      gotoab(0,4); printf("|====================================================================================================================|");

      //ubah char ke int
      gotoab (1,i);sscanf (ct->id, "%d", &j); printf("%03d", j);
      gotoab (24,i);printf("%s", ct->nama) ;
      gotoab (47,i);printf("%s", ct->harga);
      gotoab (76,i);printf ("%s", ct->jurusan);
      gotoab (106,i);printf("%s", ct->jenis) ;
      i++;

   printf("\n");
}

void history (){
    int i = 5, j;
    struct hist *ct;
    ct = (struct hist*) malloc(sizeof(struct hist));;
    ct = headhist;

       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    gotoab(0,0);printf("                                     |==========================================|");
    gotoab(0,2);printf("                                     |==========================================|");


       SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), 15);
    gotoab(40,1);printf("             History Aktivitas  ");
    gotoab(0,3);printf("                                                         Aktivitas ");

       //ketika data di ct tidak kosong
    while (ct != NULL){
        gotoab(1,i);printf("%s", ct->aktivitas);
        ct = ct->next;
        i++;
    }
    printf("\n");
}

void copy_all(){
   int i = 0;
   memset(s_data, 0, sizeof s_data);

   curr = head;
   if(curr == NULL){
      printf("NO DATA!");
   }
   else{
      while(curr != NULL){
          strcpy(s_data[i].id, curr->id);
          strcpy(s_data[i].nama, curr->nama);
          strcpy(s_data[i].harga, curr->harga);
          strcpy(s_data[i].jurusan, curr->jurusan);
          strcpy(s_data[i].jenis, curr->jenis);
         i++;
         if(curr->next != NULL){
            curr = curr->next;
        }else{
        break;
        }
    }
    sorting();
   }
}
void sorting(){

       bsort_nama(s_data, n);

}

void sorting1(){
    cls();
    struct daftar *dt;
    dt = (struct daftar*) malloc(sizeof(struct daftar));;
    dt = head;
        int i,j;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    gotoab(0,0); printf("|====================================================================================================================|");
    gotoab(0,2); printf("|====================================================================================================================|");
    gotoab(0,4); printf("|====================================================================================================================|");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoab(40,1);printf("           Hasil Sorting            ");
    gotoab(0,3);printf ("ID Booking");
    gotoab(24,3);printf("Nama");
    gotoab(47,3);printf("Harga");
    gotoab(76,3);printf("Jurusan/Lokasi");
    gotoab(106,3);printf("Jenis");

    for(i = 0; i < n ; i++){
        while(dt != NULL){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    //ubah char ke int
    gotoab(1,5+i);printf(dt->id,"%d",&j);
    gotoab(24,5+i);printf ("%s", dt->nama);
    gotoab(47,5+i);printf ("%s", dt->harga);
    gotoab(76,5+i);printf ("%s", dt->jurusan);
    gotoab(106,5+i);printf("%s", dt->jenis);
    dt = dt->next;
    i++;
    }
    }
    printf("\n");

    getch();
    cls();
    menu();
}

void bsort_nama(s_nama list[100], int s){
    s_nama tmp;
    int j,i;

    for(j=0;j<n;j++){
        for(i = 0; i < s-1; i++){
            if (strcmp(list[i].nama, list[i+i].nama) > 0){
                tmp = list[1];
                list[i] = list[i+1];
                list[i+1]=tmp;
            }
        }

    }
    sorting1();
}


void bsort_harga(s_nama list[100], int s){
    s_nama tmp;
    int j, i;

    for(j=0;j<n;j++){
       for (i=0;1<s-1;i++){
          if(strcmp(list[i].harga, list[i+1].harga)>0){
             tmp = list[i];
             list[i] = list[i+1];
             list[i+1] = tmp;
          }
       }
    }
    sorting1 ();
}

void bsort_stok(s_nama list[100], int s){
    s_nama tmp;
    int j, i;

    for(j=0; j<n; j++){
       for(i=0; i<s-1; i++){
         if (strcmp(list[i].jurusan, list[i+1].jurusan)>0){
             tmp = list[i];
             list[i] = list[i+1];
             list[i+1] = tmp;
         }
       }
    }
    sorting1();
}

void bsort_jenis(s_nama list[100], int s){
    s_nama tmp;
    int j, i;

    for(j=0;j<n;j++){
       for(i=0;i<s-1;i++){
         if (strcmp(list[i].jenis, list[i+1].jenis)>0){
             tmp = list[i];
             list[i] = list[i+1];
             list[i+1] = tmp;
         }
       }
    }
    sorting1();
}

void menu(){
    int pilihan, b = 1;

    do{
    cls();

    gotoab(21,5);printf("                       PROGRAM  BOOKING TIKET V1.0                         ");

    gotoab(21,5);printf("                       PROGRAM  BOOKING TIKET V1.0                         ");
    gotoab(102,5);printf("                                                                      ");
    gotoab(21,4);printf(" ===================================================================   ");
    gotoab(21,6);printf(" ===================================================================   ");
    gotoab(21,7);printf("                                                                       ");
    gotoab(21,8);printf("                                                                       ");
    gotoab(21,9);printf("                                                                       ");
    gotoab(21,10);printf("                                                                      ");
    gotoab(21,11);printf("                                                                      ");
    gotoab(21,12);printf("                                                                      ");
    gotoab(21,13);printf("                                                                      ");
    gotoab(21,14);printf("                                                                      ");
    gotoab(21,15);printf("                                                                      ");
    gotoab(21,16);printf("                                                                      ");
    gotoab(21,17);printf("                                                                      ");
    gotoab(21,18);printf("                                                                      ");
    gotoab(21,19);printf(" ===================================================================  ");
    gotoab(21,20);printf("                                                                      ");
    gotoab(21,21);printf(" ===================================================================  ");



        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    gotoab(30,8);printf("Menu: ");
    gotoab(30,9);printf ("1. Booking Tiket");
    gotoab(30,10);printf("2. Daftar Booking");
    gotoab(30,11);printf("3. Hapus Data");
    gotoab(30,12);printf("4. Edit Data");
    gotoab(30,13);printf("5. Pencarian Data");
    gotoab(30,14);printf("6. Urutkan Data");
    gotoab(30,15);printf("7. Riwayat Aktivitas");
    gotoab(30,16);printf("8. Logout");
    gotoab(30,17);printf("9. Keluar Program ");
    gotoab(30,20);printf("Masukkan Pilihan :");
    gotoab(50,20);scanf("%d", &pilihan);
    cls();

    switch (pilihan)
    {
        case 1:
            cls();
            update();
            kembali();
            break;
        case 2:
            cls();
            read();
            kembali();
            break;
        case 3:
            cls();
            deleted();
            break;
        case 4:
            cls();
            edit();
            kembali();
            break;
        case 5:
            cls();
            searching();
            kembali();
            break;
        case 6:
            cls();
            sorting();
            kembali();
            break;
        case 7:
            cls();
            history();
            kembali();
            break;
        case 8:
            cls();
            login();
            break;
        case 9:
            cls();
            getch();
            exit(0);
            break;
        default:
            cls();
            menu();
            }
            }while(b ==1);
}
