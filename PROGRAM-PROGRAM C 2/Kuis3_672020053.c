#include <stdio.h>

void main(){
	
	int i,j,k;
	int jml = 3;
	int satu[jml][jml], dua[jml][jml];
	
	printf("INPUT MATRIKS A : \n");
	k = 1;
	for(i=0;i<jml;i++){
		for(j=0;j<jml;j++){
			printf("[A %d] : ",k);
			scanf("%d",&satu[i][j]);
			k++;
		}
	}
	
	printf("\n\nINPUT MATRIKS B : \n");
	k = 1;
	for(i=0;i<jml;i++){
		for(j=0;j<jml;j++){
			printf("[B %d] : ",k);
			scanf("%d",&dua[i][j]);
			k++;
		}
	}
	
	printf("\n\nMATRIKS A : \n");
	for(i=0;i<jml;i++){
		for(j=0;j<jml;j++){
			printf("%d\t",satu[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMATRIKS B : \n");
	for(i=0;i<jml;i++){
		for(j=0;j<jml;j++){
			printf("%d\t",dua[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMATRIKS A + B : \n");
	for(i=0;i<jml;i++){
		for(j=0;j<jml;j++){
			printf("%d\t",satu[i][j]+dua[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMATRIKS A - B : \n");
	for(i=0;i<jml;i++){
		for(j=0;j<jml;j++){
			printf("%d\t",satu[i][j]-dua[i][j]);
		}
		printf("\n");
	}
	
	printf("\n\nMATRIKS A * B : \n");
	for(i=0;i<jml;i++){
		for(j=0;j<jml;j++){
			printf("%d\t",satu[i][j]*dua[i][j]);
		}
		printf("\n");
	}
}
