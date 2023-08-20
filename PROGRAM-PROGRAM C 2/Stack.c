#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX_STACK 10


typedef struct var_stack{
 	int top;
 	char data[10][10];
};

struct var_stack tumpuk;

void inisialisasi(){
 	tumpuk.top = -1;
}

int IsFull(){
 	if(tumpuk.top == MAX_STACK-1)
 	return 1;
 	else
 	return 0;
}

int IsEmpty(){
 	if(tumpuk.top == -1)
 	return 1;
 	else
 	return 0;
}

void Push(char inputan[10]){
 	tumpuk.top++;
 	strcpy(tumpuk.data[tumpuk.top],inputan);
}

void Pop(){
 	printf("Data yang terambil = %s\n",tumpuk.data[tumpuk.top]);
 	tumpuk.top--;
}

void Clear(){
 	tumpuk.top=-1;
}

void TampilStack(){
 	for(int i=tumpuk.top;i>=0;i--){
 		printf("Data : %s\n",tumpuk.data[i]);
 	}
}

int main(){
 	int pilihan;
 	inisialisasi();
 	char dt[10];
 	do{
	 	printf("1. Push\n");
	 	printf("2. Pop\n");
	 	printf("3. Print\n");
	 	printf("4. Clear\n");
	 	printf("5. Exit\n");
	 	printf("Pilihan : ");
	 	scanf("%d",&pilihan);
	 	switch(pilihan){
		 	case 1: if(IsFull() != 1){
			 	printf("Data = ");
			 	scanf("%s",dt);
			 	Push(dt);
		 		break;
		 	}
		 	else
		 		printf("\nSudah penuh!\n");
		 	break;
		 	
	 	case 2: if(IsEmpty() != 1){
		 		Pop();
		 	}
		 	else
		 		printf("\nMasih kosong!\n");
		 	break;
		 	
	 	case 3: if(IsEmpty() != 1){
		 		TampilStack();
		 	}
		 	else
		 		printf("\nMasih kosong!\n");
		 	break;
	 	
	 	case 4: Clear();{
		 		printf("\nSudah kosong!\n");
		 	}
		 	break;
		 	
	 	case 5:
	 		break;
	 	
	 	default :
		 	printf ("\nTerjadi Kesalahan Input, Menu Yang Di Input Tidak Tersedia\n");
		 	printf("\nTekan apa saja untuk kembali ke menu utama");
	 	}
	 	
	 	getch();
	 	system ("cls");
 	} while(pilihan != 5);
}
