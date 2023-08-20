//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <windows.h>
//
//void menu(){
//	system("cls");
//	printf("============================================\n");
//    printf("||            CRAZY LINKED LIST           ||\n");
//    printf("============================================\n");
//    printf("|| 1. INPUT DATA                          ||\n");
//	printf("|| 2. EXIT                                ||\n");
//	printf("============================================\n");
//    printf("PILIH MENU : ");
//}
//
//struct tnode{
//  	int data;
//  	struct tnode* next;
//};
//
//void headNode(struct tnode** Nhead, int newData){
//  	struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
//  	newNode->data = newData;
//  	newNode->next = (*Nhead);
//  	(*Nhead) = newNode;
//}
//
//void tailNode(struct tnode** Nhead, int newData){
//  	struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
//  	struct tnode* last = *Nhead; 
//  	newNode->data = newData;
//  	newNode->next = NULL;
//  	if (*Nhead == NULL){
//  		*Nhead = newNode;
//  		return;
//  	}
//  	while (last->next != NULL) 
//		last = last->next;
//  		last->next = newNode;
//  		return;
//}
//
//void afterHead(struct tnode* nodeBehind, int newData){
//  	if (nodeBehind == NULL) {
//  		printf("NULL");
//  		return;
//  	}
//  	struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
//  	newNode->data = newData;
//  	newNode->next = nodeBehind->next;
//  	nodeBehind->next = newNode;
//}
//void printNode(struct tnode* node){
//  	while (node != NULL) {
//  		printf(" %d ", node->data);
//  		node = node->next;
//  	}
//}
//
//int main(){
//	struct tnode *head = NULL;
//	int pilih, headd, tail, insert;
//	char pilih2;
//	do{
//		menu();
//		scanf("%d",&pilih);
//		if (pilih == 1){
//			printf("\nMasukkan data awal\t: ");
//			scanf("%d", &headd);
//			headNode(&head, headd);
//			printf("Masukkan data akhir\t: ");
//			scanf("%d", &tail);
//			tailNode(&head, tail);
//			printf("Sisipkan data baru\t: ");
//			scanf("%d", &insert);
//			afterHead(head->next,insert);
//			printf("Nilai link sekarang\t: ");
//  			printNode(head);
//			getch();
//		} else if (pilih == 2){
//			exit(0);
//		} else {
//			printf ("\nINPUTAN ANDA SALAH!");
//			exit(1);
//		}
//	}
//	while (pilih != 2);
//	return 0;
//}

// Linked list operations in C

#include <stdio.h>
#include <stdlib.h>

// Create a node
struct Node {
  int data;
  struct Node* next;
};

// Insert at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
  // Allocate memory to a node
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  // insert the data
  new_node->data = new_data;

  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

// Insert a node after a node
void insertAfter(struct Node* prev_node, int new_data) {
  if (prev_node == NULL) {
  printf("the given previous node cannot be NULL");
  return;
  }

  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Insert the the end
void insertAtEnd(struct Node** head_ref, int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = *head_ref; /* used in step 5*/

  new_node->data = new_data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
  *head_ref = new_node;
  return;
  }

  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// Print the linked list
void printList(struct Node* node) {
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}

// Driver program
int main() {
  struct Node* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);;
  
  
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

}
