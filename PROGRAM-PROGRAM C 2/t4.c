#include <stdio.h>

void main(){
	
	int num1,i,j,k,hasil;
	
	printf("Masukan tinggi : ");
	scanf("%d", &num1);
	
	//yg pertama
	for (i=0;i<num1;i++){
		//printf("%d", i);
		for (j=num1-i;j>0;j--){
			printf("%d", j);
			
		}
		printf("\n");
	}
	
}	
