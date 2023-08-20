#include <stdio.h>

int hitungpangkat(int x, int y){
	if (y == 0){ //y == 0 berfungsi mengatur jumlah berapa kali memangkatkannya
		return 1;
	}
	y--;
	return x*hitungpangkat(x,y);
}

void main(){
	int angka = 10, pangkat = 4;
	printf("%d^%d adalah %d",angka,pangkat,hitungpangkat(angka,pangkat));
}
