#include <stdio.h>

void main (){  

	int i,angka,faktorial;   
	//int faktorial = 1; 
 
printf("Masukan angka : ");    
scanf("%d",&angka);    
    for(i=1;i<=angka;i++){    
    	faktorial=faktorial*i;    
	}    
  printf("Faktorial %d adalah: %d",angka,faktorial);     
}

