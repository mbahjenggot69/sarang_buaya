#include <stdio.h>
#include <conio.h>

int main(){
	

	int baris,kolom;
	int arrayA[3][4],arrayB[4][5], result[3][3];
	
	printf("=============================\n");
	printf("ARRAY A : \n\n");
	
	
	
	for(baris=0; baris<3; baris++){
		for(kolom=0; kolom<4; kolom++){
			scanf("%d",&arrayA[baris][kolom]);
		}
		printf("\n");
	}
	printf("=============================\n");
	printf("ARRAY B : \n\n");

	for(baris=0; baris<4; baris++){
		for(kolom=0; kolom<5; kolom++){
			scanf("%d",&arrayB[baris][kolom]);
		}
		printf("\n");
	}
	printf("=============================\n");
//	printf("HASIL : \n\n");
	
	for(baris=0; baris<3; baris++){
		for(kolom=0; kolom<4; kolom++){
			if(arrayA[baris][kolom]%2 == 0){
				printf("%d ",arrayA[baris][kolom]);
			}
		}
		printf("\n");
	}


return 0;
}
