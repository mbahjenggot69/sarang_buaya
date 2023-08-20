#include <stdio.h>
#include <stdlib.h>

int main(){

	int pilih,i,num1,num2,hasil;
	int j,k,l;

	printf("\n----Segitiga Beranak----\n\n");
			printf("Masukan tinggi segitiga : ");
			scanf("%d", &num1);
			printf("Masukan banyak segitiga : ");
			scanf("%d", &num2);
			for (i=0;i<num1;i++){
				for (j=0;j<=i;j++){
					for(k=num1;k>i;k--){
						printf(" ");
					}
					for(l=0;l+j<=i;l++){
						printf("*");
					}
					
				}
				printf("\n");
			}
}
