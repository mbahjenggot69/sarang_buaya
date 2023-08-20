#include <stdio.h>

int main () {
   int str[50];
	int i;
   printf("Enter a string : ");
   for(i=0;i<4;i++ ){
   	scanf("%d", &str[i]);
   }
	printf("%d, %d, %d", str[0],str[1],str[2] );

   return(0);
}


