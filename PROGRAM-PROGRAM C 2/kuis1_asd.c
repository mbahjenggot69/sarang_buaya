#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

	
int main() {

	system("color 9F");
	printf("INPUT MATRIKS A :\n");
	int arrayA[2][2], arrayB[2][2];
	int i,j,n,baris,kolom;
	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("Masukan matriks elemen [%d][%d] = ", baris,kolom);
			scanf(" %d", &arrayA[baris][kolom]);
		}
	}
	printf("\nMATRIKS A :\n");	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("%d\t", arrayA[baris][kolom]);
		}
	printf("\n");	
	}
	printf("\nBILANGAN GANJIL MATRIKS A : \n");
	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			if (arrayA[baris][kolom]%2 != 0){
			printf("%d\t", arrayA[baris][kolom]);
			} 
		}
	printf("\n");	
	}
	printf("\nBILANGAN GENAP MATRIKS A : \n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			if (arrayA[baris][kolom]%2 == 0){
			printf("%d\t", arrayA[baris][kolom]);
			} 
		}
	printf("\n");	
	}
	printf("\n==========================================\n");
	printf("\nINPUT MATRIKS B : \n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("Masukan matriks elemen [%d][%d] = ", baris,kolom);
			scanf(" %d", &arrayB[baris][kolom]);
		}
	}
	printf("\nMATRIKS B : \n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("%d\t", arrayB[baris][kolom]);
		}
	printf("\n");	
	}
	printf("\nBILANGAN GANJIL MATRIKS B : \n");
	
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			if (arrayB[baris][kolom]%2 != 0){
			printf("%d\t", arrayB[baris][kolom]);
			}
		}
	printf("\n");	
	}
	printf("\nBILANGAN GENAP MATRIKS B : \n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			if (arrayB[baris][kolom]%2 == 0){
			printf("%d\t", arrayB[baris][kolom]);
			} 
		}
	printf("\n");	
	}
	printf("\n==========================================\n");
	printf("\nHASIL PENJUMLAHAN MATRIKS A + MATRIKS B :\n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("%d\t", (arrayA[baris][kolom]+arrayB[baris][kolom]));
		}
	printf("\n");	
	}
	
	printf("\nHASIL PENGURANGAN MATRIKS A - MATRIKS B :\n");
	for(baris=0;baris<2;baris++){
		for(kolom=0;kolom<2;kolom++){
			printf("%d\t", (arrayA[baris][kolom]-arrayB[baris][kolom]));
		}
	printf("\n");	
	}
	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <conio.h>
//
//int main() {
//	system("color 9F");
//	int i,j,n=9;
//	int array[9] = {10,6,9,3,5,2,20,11,9};
//	
//	printf(" INDEX\tNILAI\tHISTOGRAM\n");
//   	for (i=0;i<n;i++) {
//   		printf(" %d\t", i);
//   		printf("%d\t", array[i]);
//   		for (j=0;j<array[i];j++){
//   			printf("*");
//		   }
//      	printf("\n");
//   	}
//	return 0;
//}

