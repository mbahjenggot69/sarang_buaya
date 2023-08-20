#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int i,j,n,ulang;
		 satu :
		system("cls");
 		printf("masukan n : ");
		scanf("%d", &n);
		
		if (n<2){
			printf("INVALID\n");
			
		}
		else if (n>1){
		//	for(i=1;i<=n;i++){
		//	for(j=0;j<i;j++){
		//		printf(" ");
		//	}
		//	for(j=i;j<=n;j++){
		//		printf("%d", j);
		//	}
		//	for(j=i;j<n;j++){
		//		printf("%d", j);
		//	}
		//	printf("\n");
	//	}
		for(i=1;i<=n;i++){
			for(j=n;j>=i;j--){
				printf(" ");
			}
			for(j=1;j<=i;j++){
				printf("%d", j);
			}
			for(j=1;j<i;j++){
				printf("%d", j);
			}
			printf("\n");
			}
		}
		
		system("pause");
		printf("Ingin Mengulang ? y/t\n");
		scanf("%s", &ulang);
		if(ulang =='y'){
			goto satu;
		}
		if(ulang =='t'){
			exit(0);
		}
		
 	

return 0;
}
