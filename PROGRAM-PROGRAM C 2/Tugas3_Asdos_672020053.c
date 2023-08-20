#include<stdlib.h>
#include<stdio.h>

void main(){
	int j,n;

	printf("Masukan Jumlah Data Simpanan : ");
	scanf("%d", &n);
	
	int x[n];
	for (int i=0;i<n;i++){
		printf("\nInput data ke - %d : ",i);
		scanf("%d", &x[i]);		
		
	}
	printf("\nData Dalam Simpanan : ");
	for(int i=0;i<n;i++){
		if (j<x[i]) {
			j=x[i];
		}
		printf("%d ",x[i]);
	}
	printf("\nData Terbesar : %d",j);

} 
	

