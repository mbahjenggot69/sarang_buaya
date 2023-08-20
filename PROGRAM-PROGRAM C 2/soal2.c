#include <stdio.h> //Header file
#include <stdlib.h> //Header file

void main(){ //Fungsi main
	int i,j; //tipe data dan variabel
	j=0; //nilai dari variabel
	i=0; //nilai dari variabel
	
	while(i<5){ //perulangan while
		while(j+i<5){ //sebagai pengatur baris angka terkecil
			printf("   "); //output spasi
			printf("%d",5-j-i); //output bilangan
			j++; //increment
		}
		j=0; //sebagai variabel pengatur bilangan menurun
		printf("\n"); //output ganti baris baru
		i++; //increment
		//kedua increment berhubungan dengan batas sehingga tidak error dan forever looping
	}
}
