#include<stdio.h>

void main(){
	char nama[] ="Yanuar Christy Ade Utama";
	char nim[] ="672020053";
	int jumlah;
	
	printf("Nama : %s\n",&nama);
	printf("NIM : %s\n",&nim);
	
	
	printf("Jumlah anak ayam (3 - 10) : ");
	scanf ("%d",&jumlah);
	
	if (jumlah<3 || jumlah>10){
		printf("Jumlah anak ayam hanya boleh 3 - 10 ekor. Maaf ya...");
	} 
	else {
		int i;
		printf("Anak ayam turunlah %i\n",jumlah);
		for(i=jumlah-1;i>1;i--){
			printf("Mati satu tinggallah %i",i);	
			printf("\n");
		}
	printf("Mati satu tinggal induknya :(\n");
	printf("Lagu ini dituliskan oleh %s dengan NIM %s",nama,nim);
	}
}
