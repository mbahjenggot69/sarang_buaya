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
	int hasil[3][3], hasil1[3][3];
	
	int idx;
	//int tampung[3][2], tampung2[3][2];
	for(baris=0; baris<3; ++baris){
		for(kolom=0; kolom<5; ++kolom){
			if(kolom < 2){
				if(arrayA[baris][kolom]%2 == 0 ){ // jika value matrix a = genap
					for(int idx=0;idx<=4;){
//						printf(" %d",arrayB[baris][idx]*arrayA[baris][kolom]);
						hasil[baris][idx] += arrayB[baris][idx]*arrayA[baris][kolom];
						idx+=2;
					}	
				}else{
					for(int idx=1;idx<=4;){
						hasil1[baris][idx]+= arrayB[baris][idx]*arrayA[baris][kolom];
//						printf(" %d",arrayB[baris][idx]*arrayA[baris][kolom]);
						printf(" %d ",hasil1[baris][idx]);
						idx+=2;
					}
				}
					//printf("%d ", arrayA[baris][kolom]);
				
			}	
		} printf("\n");
	}
//	for(baris=0; baris<3; baris++){
//		for(kolom=0; kolom<3; kolom++){
//			printf("%d",hasil[baris][kolom]);
//		}
//		printf("\n");
//	}

return 0;
}
