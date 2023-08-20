#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

int n;

int intro(){
	system("cls");
	printf("============================================\n");
    printf("||                  LOOPS                 ||\n");
    printf("============================================\n");
    printf("MASUKAN BILANGAN : ");
	scanf("%d", &n);
}

int loops(){
	int i=0,total=0;
	//operasi
//	for (i=0;i<=n;i++){
//		total = total + i;
//	}

//	while (i<=n){
//		total = total + i;
//		i++;
//	}

	do{
		total = total + i;
		i++;	
	} while(i<=n);
	printf("HASIL = %d\n", total);
	printf("============================================\n");
	system("pause");
	return 0;
}

int main(){
	system("color 9F");
	char ulangi;
	intro();
	loops();
	printf("\n\nULANGI? y/n\n>> ");
	scanf(" %c", &ulangi);
	do {
		if (ulangi == 'y'){
			main();
		} else if (ulangi == 'n'){
			exit(0);
		}
	} while (ulangi != 'n');
	return 0;
}


