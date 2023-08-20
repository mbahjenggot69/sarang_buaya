#include <stdio.h>  
  
int main() {

	int n;
	printf("Masukkan Angka : ");
	scanf("%d",&n);
	

	int i,j;
	int angka = 1;
	
	for(i=1;i<=n;i++){
		for(j=0;j<=(n-i);j++){
			printf("  ");
		}
		for(j=0;j<(2*i-1);j++){
			printf("%d ", angka);
			if(angka == 9)  
                angka = 0;  
            else  
                angka++; 
		}
		printf("\n");  
	}
	
}
