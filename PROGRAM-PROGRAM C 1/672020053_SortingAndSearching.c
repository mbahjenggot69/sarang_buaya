#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


int n,list;
struct dataPenduduk{
	char nama[200], lahir[200], hp[200], email[200];
	int nik;
}pdd[200];

void addData(){
	system("cls");
	printf("===============================================\n");
    printf("||           TAMBAH DATA PENDUDUK            ||\n");
    printf("===============================================\n"); 
	printf("NIK: ");
	scanf(" %d", &pdd[list].nik);
	printf("\nNama: ");
	scanf (" %[^\n]%*c", &pdd[list].nama);
	printf("\nTanggal Lahir: ");
	scanf (" %[^\n]%*c", &pdd[list].lahir);
	printf("\nNomor HP: ");
	scanf (" %s", &pdd[list].hp);
	printf("\nEmail: ");
	scanf (" %[^\n]%*c", &pdd[list].email);
	n++; list++;
	printf("\nSUKSES MENAMBAH DATA PENDUDUK!\n");
	getch();
}

void viewData(){
	int num,i;
	system("cls");
	printf("===============================================================================================\n");
    printf("||                                   LIHAT DATA PENDUDUK                                     ||\n");
    printf("===============================================================================================\n");
    printf("Nomor\t|NIK\t\t|Nama Warga\t|Email\t\t|No. Handphone\t|Tanggal Lahir");
    printf("\n===============================================================================================\n");
    do {
		printf("%d\t|",num+1);
    	printf("%d\t|%s\t|%s\t|%s\t|%s\n", pdd[num].nik, pdd[num].nama, pdd[num].email, pdd[num].hp, pdd[num].lahir);	
    	num++;
	} while (num<n);
    printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
    getch();
}

void sortDataNIK(){
	system("cls");
	int i,j,num;
    struct dataPenduduk temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<(n-1-i);j++){
            if(pdd[j].nik > pdd[j+1].nik){
                    temp = pdd[j];
                    pdd[j] = pdd[j+1];
                    pdd[j+1] = temp;
        	}
    	}
	}
	
	printf("===============================================================================================\n");
    printf("||                                      HASIL SORTING                                        ||\n");
    printf("===============================================================================================\n");
    printf("Nomor\t|NIK\t\t|Nama Warga\t|Email\t\t|No. Handphone\t|Tanggal Lahir");
    printf("\n===============================================================================================\n");
    do {
		printf("%d\t|",num+1);
    	printf("%d\t|%s\t|%s\t|%s\t|%s\n", pdd[num].nik, pdd[num].nama, pdd[num].email, pdd[num].hp, pdd[num].lahir);	
    	num++;
	} while (num<n);
	printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
	getch();
}

void sortDataName(){
	system("cls");
	int i,j,num;
    struct dataPenduduk temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<(n-1-i);j++){
            if(strcmp(pdd[j].nama, pdd[j+1].nama)>0){
                    temp = pdd[j];
                    pdd[j] = pdd[j+1];
                    pdd[j+1] = temp;
        	}
    	}
	}
	printf("===============================================================================================\n");
    printf("||                                      HASIL SORTING                                        ||\n");
    printf("===============================================================================================\n");
    printf("Nomor\t|NIK\t\t|Nama Warga\t|Email\t\t|No. Handphone\t|Tanggal Lahir");
    printf("\n===============================================================================================\n");
    do {
		printf("%d\t|",num+1);
    	printf("%d\t|%s\t|%s\t|%s\t|%s\n", pdd[num].nik, pdd[num].nama, pdd[num].email, pdd[num].hp, pdd[num].lahir);	
    	num++;
	} while (num<n);
	printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
	getch();
}

void searchData(){
	int num,NIK;
	system("cls");
 	printf("==============================================\n");
    printf("||            CARI DATA PENDUDUK            ||\n");
    printf("==============================================\n"); 
    printf("MASUKAN NIK : ");
    scanf("%d", &NIK);
 	printf("\n==============================================\n");
    printf("||              HASIL PENCARIAN             ||\n");
    printf("==============================================\n"); 
    for(num=0;num<n;num++){
        if(pdd[num].nik == NIK){
            printf("DATA PENDUDUK DITEMUKAN!\n\n");
            printf("==== INFORMASI DATA DENGAN NIK %d ====\n", NIK);
            printf("NIK\t\t: %d\n", pdd[num].nik);
            printf("NAMA\t\t: %s\n", pdd[num].nama);
            printf("TANGGAL LAHIR\t: %s\n", pdd[num].lahir);
            printf("NOMOR HP\t: %s\n", pdd[num].hp);
            printf("EMAIL\t\t: %s\n", pdd[num].email);
            printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
            getch();
            break;
            
        }
        
    }
    if (num == n){
        printf("DATA PENDUDUK DENGAN NIK %d TIDAK DITEMUKAN\n", NIK);
        printf("\n\n\nTekan ENTER untuk kembali ke Menu Utama");
        getch();
    }
}

void temp_menu(){
	system("cls");
	printf("==============================================\n");
    printf("||  PROGRAM DATA PENDUDUK DESA RAJA NANGKA  ||\n");
    printf("==============================================\n");
    printf("|| 1. TAMBAH DATA PENDUDUK                  ||\n");
	printf("|| 2. LIHAT DATA PENDUDUK                   ||\n"); 
	printf("|| 3. URUTKAN DATA PENDUDUK                 ||\n"); 
	printf("|| 4. CARI DATA PENDUDUK                    ||\n"); 
	printf("|| 5. EXIT                                  ||\n");
	printf("==============================================\n");
    printf("PILIH MENU : ");
}

void temp_submenu(){
	system("cls");
	printf("==============================================\n");
    printf("||          SORTING DATA PENDUDUK           ||\n");
    printf("==============================================\n");
    printf("|| 1. BERDASARKAN NIK                       ||\n");
	printf("|| 2. BERDASARKAN NAMA                      ||\n");
	printf("|| 3. KEMBALI                               ||\n");
	printf("==============================================\n");
    printf("PILIH MENU : "); 
}

int main(){
	system("color 9F");
	int pilih,choice;
	do {
		temp_menu();
		scanf("%d",&pilih);
		if (pilih == 1){
			addData();
		} else if (pilih == 2){
			viewData();
		} else if (pilih == 3){
			temp_submenu();
			scanf("%d", &choice);
			if (choice == 1){
				sortDataNIK();
				main();
			} else if (choice == 2){
				sortDataName();
				main();
			} else if (choice == 3){
				main();
			} else {
				printf ("\nINPUTAN ANDA SALAH!");
				exit(1);
			}
		} else if (pilih == 4){
			searchData();
			main();
		} else if (pilih == 5){
			exit(0);
		} else {
			printf ("\nINPUTAN ANDA SALAH!");
			exit(1);
		}
	} while (pilih != 5);
	return 0;
}


