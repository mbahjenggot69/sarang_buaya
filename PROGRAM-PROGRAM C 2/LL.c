#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct tnode
    {
        int x, y;
        struct tnode *nextptr;
    };


    struct tnode *head=NULL,*curr=NULL, *node=NULL;
    int i, juml;
	
	printf("=====LINKED LIST=====\n\n");
	printf("Masukkan input : ");
	scanf("%d", &juml);
	
	for (i=0; i<juml; i++)
    {    	
		printf("Masukkan nilai ke-%d = ", i+1);
		scanf("%d", &x);
		}
    
}

