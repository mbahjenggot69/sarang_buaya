#include <stdio.h>
#define MAX 5 // define untuk membuat variabel mutlak

void enQueue(int);
void deQueue();
void tampil();
int items[MAX], depan = -1, belakang = -1;

void enQueue(int value) {
 	if (belakang == MAX - 1)
 		printf("\nQueue Sudah Penuh!!");
 	else {
 		if (depan == -1)
 		depan = 0;
 		belakang++;
 		items[belakang] = value;
 		printf("\nData Masuk -> %d", value);
 	}
}

void deQueue() {
 	if (depan == -1){
 		printf("\nQueue Kosong!!");

	} else {
 		printf("\nDihapus : %d", items[depan]);
 		depan++;
 		if (depan > belakang) {
 			depan = belakang = -1;
		}
 		
 	}
}

// Function to print the queue
void tampil() {
 	if (belakang == -1){
 		printf("\nQueue Sudah Full!!!");
	} else {
 		int i;
 		printf("\nIsi Queue adalah :\n");
		for (i = depan; i <= belakang; i++) {
			printf("%d ", items[i]);
		}
 	}
 	printf("\n");
}

int main(){
 	deQueue();
 	enQueue(1);
 	enQueue(2);
 	enQueue(3);
 	enQueue(4);
 	enQueue(5);
 	enQueue(6);
 	enQueue(7);
 	tampil();
 	deQueue();
 	tampil();
 	return 0;
}
