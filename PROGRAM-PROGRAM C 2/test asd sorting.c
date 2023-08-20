#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 256
 
//char menu[max][max];
int cek;
int length = 5;
 
struct Buah{
    char nama[255];
    int harga;
}buah[max];
 
void input(){
    int i;
    for (i=0; i<length; i++){
        printf("Buah ke-%i\n", i+1);
        printf("Masukkan nama buah : ");
        scanf(" %[^\n]", &buah[i].nama);
        printf("Masukkan harga buah : ");
        scanf("%i", &buah[i].harga);
        cek = 1;
    }
}
 
void print(){
    int i;
    printf("No.\t||\tNama Buah\t||\tHarga\t\t||\n");
    for(i=0; i<length; i++){
        printf("%i.\t\t", i+1);
        printf("%s\t\t\t", buah[i].nama);
        printf("%i\n", buah[i].harga);
    }
}
 
void bubbleSortNama(){
    int i, j;
    struct Buah temp;
    for(i = 0; i < length - 1; i++){
        for(j = 0; j < (length - 1 - i); j++){
            if(strcmp(buah[j].nama, buah[j+1].nama)>0){
                    temp = buah[j];
                    buah[j] = buah[j+1];
                    buah[j+1] =  temp;
        	}
    	}
	}
}
 
void displayArrayChar(){
    int i;
    printf("No.\t||\tNama Buah\t||\tHarga\t\t||\n");
    for(i=0; i<length; i++){
        printf("%i.\t\t", i+1);
        printf("%s\t\t\t", buah[i].nama);
        printf("%i\n", buah[i].harga);
}
}
 
 
void bubbleSortharga(){
    int i, j;
    struct Buah temp;
    for(i = 0; i < length - 1; i++){
        for(j = 0; j < (length - 1 - i); j++){
            if(buah[j].harga > buah[j+1].harga){
                    temp = buah[j];
                    buah[j] = buah[j+1];
                    buah[j+1] = temp;
            }
        }
    }
}
 
void displayArrayharga(){
    int i;
    printf("No.\t||\tNama Buah\t||\tHarga\t\t||\n");
    for(i=0; i<length; i++){
        printf("%i.\t\t", i+1);
        printf("%s\t\t\t", buah[i].nama);
        printf("%i\n", buah[i].harga);
}
}
 
void LinearSearchHarga(){
    int hargainput, i;
    printf("Masukkan harga yang ingin dicari : ");
    scanf("%i", &hargainput);
 
    for(i = 0; i<length; i++){
        if(buah[i].harga == hargainput){
            printf("Harga %i ditemukan pada menu ke-%i / pada buah %s\n", hargainput, i+1, buah[i].nama);
            printf("\nNo.\t||\tNama Buah\t||\tHarga\t\t||\n");
            printf("%i.\t\t", i+1);
            printf("%s\t\t\t", buah[i].nama);
            printf("%i\n", buah[i].harga);
            break;
        }
    }
    if (i == length){
        printf("Harga %i tidak ditemukan\n", hargainput);
    }
}
 
int fungsinama(char namainput[max]){
    int i;
    for(i = 0; i<length;i++){
        if(strcmp(buah[i].nama, namainput) == 0){// || strcmp(tolower(buah[i].nama), tolower(namainput) == 0) || strcmp(toupper(buah[i].nama), toupper(namainput) == 0)){
            return i;
        }
    }
}
 
void LinearSearchNama(){
    char akhir;
    char input[max];
    char x;
    printf("Masukkan nama buah : ");
    scanf("%s", &input);
    for(int i = 0; input[i]; i++){
        x = input[i];
        if(x >= 65 && x <= 90){
            akhir = x + 32;
            input[i] = akhir;
        }
        else{
            input[i] = x;
        }
    }
    printf("\n");
    int hasil = fungsinama(input);
    if(hasil == -1){
        printf("Buah %s tidak ditemukan pada menu", input);
    }
    else{
        printf("Buah %s ditemukan pada menu ke-%i\n", input, hasil+1);
        printf("\nNo.\t||\tNama Buah\t||\tHarga\t\t||\n");
        printf("%i.\t\t", hasil+1);
        printf("%s\t\t\t", buah[hasil].nama);
        printf("%i\n", buah[hasil].harga);
    }
 
}
 
int main(){
    int pil;
start:
    system("cls");
    printf("=======================================\n");
    printf("==+++      Tugas 3 - Sorting      +++==\n");
    printf("=======================================\n");
    printf("1. Input nama buah & harga\n");
    printf("2. Tampilkan data (raw)\n");
    printf("3. Tampilkan data (sorted by nama)\n");
    printf("4. Tampilkan data (sorted by harga)\n");
    printf("5. Cari data (nama)\n");
    printf("6. Cari data (harga)\n");
    printf("7. Exit\n");
    printf("Masukkan pilihan : ");
    scanf("%i", &pil);
 
    if(pil == 1){
        system("cls");
        input();
        printf("Data berhasil dimasukkan\n");
        system("pause");
        goto start;
    }
 
    else if(pil == 2){
            if(cek != 1){
                printf("Data belum dimasukkan\n");
                system("pause");
                goto start;
            }
            else{
                system("cls");
                printf("==========================================================\n");
                printf("============     Menampilkan Data Mentah     =============\n");
                printf("==========================================================\n");
                printf("\n");
                print();
                printf("\n");
                system("pause");
                goto start;
            }
 
    }
    else if(pil == 3){
        if(cek != 1){
            printf("Data belum dimasukkan\n");
            system("pause");
            goto start;
        }
        else{
        system("cls");
        printf("=========================================================\n");
        printf("=====      Mengurutkan/Sorting berdasarkan nama     =====\n");
        printf("=========================================================\n");
        printf("\n");
        bubbleSortNama();
        displayArrayChar();
        printf("\n");
        system("pause");
        goto start;
        }
    }
 
    else if(pil == 4){
        if(cek != 1){
            printf("Data belum dimasukkan\n");
            system("pause");
            goto start;
        }
        else{
        system("cls");
        printf("=========================================================\n");
        printf("=====     Mengurutkan/Sorting berdasarkan harga     =====\n");
        printf("=========================================================\n");
        printf("\n");
        bubbleSortharga();
        displayArrayharga();
        printf("\n");
        system("pause");
        goto start;
        }
    }
    else if(pil == 5){
 
        if(cek != 1){
            printf("Data belum dimasukkan\n");
            system("pause");
            goto start;
        }
        else{
        system("cls");
        printf("============================================================\n");
        printf("======       Mencari/Searching berdasarkan nama       ======\n");
        printf("============================================================\n");
        printf("\n");
        LinearSearchNama();
        printf("\n");
        system("pause");
        goto start;
        }
    }
    else if(pil == 6){
        if(cek != 1){
            printf("Data belum dimasukkan\n");
            system("pause");
            goto start;
        }
        else{
        system("cls");
        printf("===========================================================\n");
        printf("======      Mencari/Searching berdasarkan harga      ======\n");
        printf("===========================================================\n");
        printf("\n");
        LinearSearchHarga();
        printf("\n");
        system("pause");
        goto start;
        }
    }
    else if(pil == 7){
        exit(EXIT_SUCCESS);
    }
    else{
        printf("Pilihan tidak ditemukan, tekan spasi untuk kembali\n");
        system("pause");
        goto start;
    }
 
    printf("\n\n");
 
    return 0;
}
