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
    printf("||   PENGHITUNG BILANGAN GANJIL & GENAP   ||\n");
    printf("============================================\n");
    printf("MASUKAN BILANGAN : ");
    scanf("%d",&n);
    return 0;
}

int operasi(){
	
	int i, even = 0, odd = 0, genap = 0, ganjil = 0;
	while (i<=n){
    	if (i%2 == 0) {
    		printf("%d (Genap)\n", i);
			even++;
			genap = genap + i;
		}	
    	else if (i%2 == 1) {
   			printf("%d (Ganjil)\n", i);
			odd++;
			ganjil = ganjil + i;
		}
    	i++;
	}
		printf ("\n>> Banyak bilangan genap %d\n", even);
		printf (">> Total jumlah bilangan genap %d\n", genap);
    	printf (">> Banyak bilangan ganjil %d\n", odd);
    	printf (">> Total jumlah bilangan ganjil %d\n", ganjil);
	return 0;
}

int ulangi(){
	
	system("cls");
	char pilih;
	printf("Anda ingin mengulangi? y/n\n>> ");
	scanf(" %c", &pilih);
	if (pilih == 'y') {
	   	main();
	} else if (pilih == 'n'){
		exit(EXIT_SUCCESS);
	}
	return 0;
}

int main(){
	system("color 70");
	intro();
    operasi();
	printf("============================================\n");
	printf("KETUK UNTUK MELANJUTKAN");
    getch();
	ulangi();
	return 0;
}
