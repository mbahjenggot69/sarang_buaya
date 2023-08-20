#include <stdio.h>

void main(){
	float i,j,hasil;
	
	printf("Masukan bb : ");
	scanf("%f",&i);
	printf("Masukan tb :");
	scanf("%f",&j);
	
	hasil = i/(j*j);
	
	if (hasil<18.5){
		printf("%.2f kurang",hasil);
	}
	else if (hasil>18,5 && hasil<25){
		printf("%.2f sehat",hasil);
	}
	else if (hasil>25){
		printf("%.2f gemuk",hasil);
	}
	
}
