#include <stdio.h>
#include <stdlib.h>

int main(){
	system("color 9F");
	struct tnode{   
		int x;
        struct tnode *next;
    };
    struct tnode *head=NULL,*curr=NULL, *node=NULL;
    int i,n,temp;
    
	printf("===== LINKED LIST =====\n\n");
	printf("Masukkan jumlah data = ");
	scanf("%d", &n);
	printf("\n");
	
    for (i=0; i<n; i++){
    	printf("Masukkan data ke-%i = ", i+1);
		scanf("%d", &temp);
            node = (struct tnode *)malloc (sizeof(struct tnode));
            node -> x = temp; 
        if (head == NULL){
			head = node;
            curr = node;
        } else{
            curr -> next = node;
            curr = node;
		}
    }
    
    printf("Hasilnya adalah = ");
    curr -> next = NULL; curr = head;
    while (curr != NULL){
        printf("%d ", curr -> x);
        curr = curr -> next;
    } 
	printf("\n");
	return 0;
}

