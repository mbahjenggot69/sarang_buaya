#include <stdio.h>
#include <stdlib.h>

int main(){
	int pilih,i,num1,num2,hasil;
	int j,k,l;
	do {
		printf("/============================/\n");
		printf("             MENU\n");
		printf("/============================/\n\n");
		printf("1. Faktor Bilangan\n");
		printf("2. Deret Angka\n");
		printf("3. Segitiga beranak\n");
		printf("4. Exit\n\n");
		printf("/============================/\n");
		printf(">> ");
		scanf("%d", &pilih);
		if(pilih > 4) {
			printf("INVALID");
			break;
		}
		if(pilih > 0 && pilih <5){
		switch(pilih){
		case 1:
			printf("\n----Faktor Bilangan----\n\n");
			printf("Masukan bilangan : ");
			scanf("%d", &num1);
				
			for(i=1;i<=num1;i++){    
    		hasil=hasil*i;    
			}    
 			printf("Faktorial %d adalah: %d\n\n\n\n\n",num1,hasil);
 			if(hasil>1){
 				hasil = 1;
			}
			break;
		case 2:
			printf("\n----Deret Angka----\n\n");
			printf("Masukan bilangan : ");
			scanf("%d", &num1);
			
			for(i=1;i<num1;i++){
				printf("%d + ",i);
				hasil=hasil+i;
			}
			printf("%d ",i);
			printf("\nHasil penjumlahan dari deret bilangan %d adalah %d ",num1,hasil+(i-1));
			printf("\n\n\n\n\n");
			if(hasil>1){
 				hasil = 1;
 			}
			break;
		case 3:
			
			printf("\n----Segitiga Beranak----\n\n");
			printf("Masukan tinggi segitiga : ");
			scanf("%d", &num1);
			printf("Masukan banyak segitiga : ");
			scanf("%d", &num2);
			
			for (i=1;i<=num2;i++){
				for (j=0;j<num1;j++){
					for(k=i;k<num2;k++){
						printf(" ");
					}
					for(l=(i*2);l>1;l--){
						printf("*");
					}
					for(k=i;k<num2;k++){
						printf(" ");
					}
				}
				printf("\n");
			}	
			break;
		case 4:
			printf("\nTerima kasih ^^");
			break;
		}		
	}
	}while(pilih != 4);
	return 0;
}
