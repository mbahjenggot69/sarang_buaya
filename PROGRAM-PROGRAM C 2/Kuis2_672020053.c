#include <stdio.h>

void main(){
	
	int num1,i,j,k;
	
	printf("Masukkan tinggi : ");
	scanf("%d", &num1);
	
	//yg pertama
	for(i=num1;i>0;i--){
		for(j=num1;j>0;j--){
			printf("%d", j);
		}
		printf("\n");
	}	
	printf("\n\n\n");
	
	//yg kedua
	for (i=0;i<num1;i++){
		//printf("%d", i);
		for (j=num1-i;j>0;j--){
			printf("%d", j);
		}
		for (k=0;k<=j;k++){
			printf("%d", i-j-k);
			
		}
		printf("\n");
	}
	printf("\n\n\n");
	
	//yg ketiga
	for (i=0;i<num1;i++){
		for (j=1;j<i+1;j++){
			printf("X");
		}
		for (j=0;j<=num1-1;j++){	
		printf("%d",j+num1-i);
		}
		printf("\n");
	}
}

