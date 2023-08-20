#include <stdio.h>
#include <conio.h>

int main(){
	

	int baris,kolom;
	int arrayA[3][4],arrayB[4][5];
	
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
	printf("HASIL : \n\n");
	//baris 0 kolom 0 dan baris 0 kolom 1
	
	if (arrayA[0][0] % 2 == 0 ){
		if (arrayA[0][1] % 2 == 0){
				printf("%d\t",((arrayA[0][0]*arrayB[0][0])+(arrayA[0][0]*arrayB[0][2])+(arrayA[0][0]*arrayB[0][4]))+((arrayA[0][1]*arrayB[0][0])+(arrayA[0][1]*arrayB[0][2])+(arrayA[0][1]*arrayB[0][4])));	

		}else{
				printf("%d\t",((arrayA[0][0]*arrayB[0][0])+(arrayA[0][0]*arrayB[0][2])+(arrayA[0][0]*arrayB[0][4]))+((arrayA[0][1]*arrayB[0][1])+(arrayA[0][1]*arrayB[0][3])));
			}
	}else{
		if (arrayA[0][1] % 2 == 0){
			printf("%d\t",((arrayA[0][0]*arrayB[0][1])+(arrayA[0][0]*arrayB[0][3]))+((arrayA[0][1]*arrayB[0][0])+(arrayA[0][1]*arrayB[0][2])+(arrayA[0][1]*arrayB[0][4])));	

		}else{
		printf("%d\t",((arrayA[0][0]*arrayB[0][1])+(arrayA[0][0]*arrayB[0][3]))+((arrayA[0][1]*arrayB[0][1])+(arrayA[0][1]*arrayB[0][3])));	

		}
		
	}
	//BARIS 0 KOLOM 2
	if (arrayA[0][2] % 2 == 0 ){
		printf("%d\t",((arrayA[0][2]*arrayB[0][0])+(arrayA[0][2]*arrayB[0][2])+(arrayA[0][2]*arrayB[0][4])));
	}
	else{
		printf("%d\t",((arrayA[0][2]*arrayB[0][1])+(arrayA[0][2]*arrayB[0][3])));
	}
	
	//BARIS 0 KOLOM 3
	if (arrayA[0][3] % 2 == 0 ){
		printf("%d\t",((arrayA[0][3]*arrayB[0][0])+(arrayA[0][3]*arrayB[0][2])+(arrayA[0][3]*arrayB[0][4])));
	}
	else {
		printf("%d\t",((arrayA[0][3]*arrayB[0][1])+(arrayA[0][3]*arrayB[0][3])));
	}
	
	printf("\n\n");
	//baris 1 kolom 0 dan baris 1 kolom 1
	
	if (arrayA[1][0] % 2 == 0 ){
		if (arrayA[1][1] % 2 == 0){
			printf("%d\t",((arrayA[1][0]*arrayB[1][0])+(arrayA[1][0]*arrayB[1][2])+(arrayA[1][0]*arrayB[1][4]))+((arrayA[1][1]*arrayB[1][0])+(arrayA[1][1]*arrayB[1][2])+(arrayA[1][1]*arrayB[1][4])));	

		}else{
			printf("%d\t",((arrayA[1][0]*arrayB[1][0])+(arrayA[1][0]*arrayB[1][2])+(arrayA[1][0]*arrayB[1][4]))+((arrayA[1][1]*arrayB[1][1])+(arrayA[1][1]*arrayB[1][3])));

			}
	}else{
		if (arrayA[1][1] % 2 == 0){
			printf("%d\t",((arrayA[1][0]*arrayB[1][1])+(arrayA[1][0]*arrayB[1][3]))+((arrayA[1][1]*arrayB[1][0])+(arrayA[1][1]*arrayB[1][2])+(arrayA[1][1]*arrayB[1][4])));	

		}else{
			printf("%d\t",((arrayA[1][0]*arrayB[1][1])+(arrayA[1][0]*arrayB[1][3]))+((arrayA[1][1]*arrayB[1][1])+(arrayA[1][1]*arrayB[1][3])));	

		}
		
	}
	
	//BARIS 1 KOLOM 2
	if (arrayA[1][2] % 2 == 0 ){
		printf("%d\t",((arrayA[1][2]*arrayB[1][0])+(arrayA[1][2]*arrayB[1][2])+(arrayA[1][2]*arrayB[1][4])));
	}
	else{
		printf("%d\t",((arrayA[1][2]*arrayB[1][1])+(arrayA[1][2]*arrayB[1][3])));
	}
	
	
	//BARIS 1 KOLOM 3
	if (arrayA[1][3] % 2 == 0 ){
		printf("%d\t",((arrayA[1][3]*arrayB[1][0])+(arrayA[1][3]*arrayB[1][2])+(arrayA[1][3]*arrayB[1][4])));
	}
	else{
		printf("%d\t",((arrayA[1][3]*arrayB[1][1])+(arrayA[1][3]*arrayB[1][3])));
	}
	
	printf("\n\n");
	
	
	//baris 2 kolom 0 dan baris 2 kolom 1
	
	
	if (arrayA[2][0] % 2 == 0 ){
		if (arrayA[2][1] % 2 == 0){
			printf("%d\t",((arrayA[2][0]*arrayB[2][0])+(arrayA[2][0]*arrayB[2][2])+(arrayA[2][0]*arrayB[2][4]))+((arrayA[2][1]*arrayB[2][0])+(arrayA[2][1]*arrayB[2][2])+(arrayA[2][1]*arrayB[2][4])));	

		}else{
			printf("%d\t",((arrayA[2][0]*arrayB[2][0])+(arrayA[2][0]*arrayB[2][2])+(arrayA[2][0]*arrayB[2][4]))+((arrayA[2][1]*arrayB[2][1])+(arrayA[2][1]*arrayB[2][3])));

			}
	}else{
		if (arrayA[2][1] % 2 == 0){
			printf("%d\t",((arrayA[2][0]*arrayB[2][1])+(arrayA[2][0]*arrayB[2][3]))+((arrayA[2][1]*arrayB[2][0])+(arrayA[2][1]*arrayB[2][2])+(arrayA[2][1]*arrayB[2][4])));	

		}else{
			printf("%d\t",((arrayA[2][0]*arrayB[2][1])+(arrayA[2][0]*arrayB[2][3]))+((arrayA[2][1]*arrayB[2][1])+(arrayA[2][1]*arrayB[2][3])));	

		}
		
	}
	
	//baris 2 kolom 2
	
	if (arrayA[2][2] % 2 == 0 ){
		printf("%d\t",((arrayA[2][2]*arrayB[2][0])+(arrayA[2][2]*arrayB[2][2])+(arrayA[2][2]*arrayB[2][4])));
	}
	else{
		printf("%d\t",((arrayA[2][2]*arrayB[2][1])+(arrayA[2][2]*arrayB[2][3])));
	}
	
	//baris 2 kolom 3
	
	if (arrayA[2][3] % 2 == 0 ){
		printf("%d\t",((arrayA[2][3]*arrayB[2][0])+(arrayA[2][3]*arrayB[2][2])+(arrayA[2][3]*arrayB[2][4])));
	}
	else{
		printf("%d\t",((arrayA[2][3]*arrayB[2][1])+(arrayA[2][3]*arrayB[2][3])));
	}

	//getch();

return 0;
}
