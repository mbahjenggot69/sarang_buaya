/* 	Contoh Struct Sederhana
	Author: Yanuarchr
	February 23th, 2023
*/
#include <stdio.h>
#include <string.h>

//ini cara membuatnya
struct lahir {
	int tgl, bln, thn;
} ;


struct mahasiswa {
	int nim;
	char nama[20];
	float ipk;
	struct lahir lh;
};


int main(){
	//ini cara memakainya
	struct mahasiswa mh; //tp ingat mh belum bisa diisi
	//karena mh masih mempunyai sub di dlmnya
	mh.nim=672020053;
	strcpy(mh.nama,"Yanuarchr");
	mh.ipk=4.0;
	mh.lh.tgl=14;
	mh.lh.bln=1;
	mh.lh.thn=2002;
	
	printf("NIM: %i\n",mh.nim);
	printf("Nama: %s\n",mh.nama);
	printf("IPK: %f\n",mh.ipk);
	printf("Tgl Lahir: %d\n",mh.lh.tgl);
	printf("Bulan Lahir: %d\n",mh.lh.bln);
	printf("Tahun Lahir: %d\n",mh.lh.thn);
}

