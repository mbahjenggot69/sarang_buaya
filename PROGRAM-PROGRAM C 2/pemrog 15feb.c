#include<stdio.h>

void main(){

	int tinggi;
	printf("Masukan tinggi (3 -10) : ");
	scanf("%d",&tinggi);
	
	if (tinggi<3 || tinggi>10){
		printf("Tinggi hanya boleh 3 - 10");
	}
	else {
		int i,j;
		for (i=0;i<tinggi;i++){
			for (j=tinggi-i;j>0;j--){
				printf(" ");
			}
			for (j=0;j<i*2+1;j++){
				printf("*");
			}
			for (j=tinggi-i;j>0;j--){
				printf(" ");
			}
		//printf("\n");
			
			for (j=0;j<i+1;j++){
				printf("-");
			}
			for (j=tinggi-i;j>0;j--){
				printf("+");
			}
			for (j=tinggi-i;j>0;j--){
				printf("+");
			}
			for (j=0;j<i+1;j++){
				printf("-");
			}
			printf("\n");
		}
		
	}
}
