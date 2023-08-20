#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct tnode
    {
        int x;
        struct tnode *next;
    };

    struct tnode *head=NULL,*curr=NULL, *node=NULL;
    int i;

    for (i=0; i<5; i++)
    {
        node = (struct tnode *)malloc (sizeof(struct tnode));
        node -> x = i;

        if (head == NULL)
        {
            head = node;
            curr = node;
        }
        else
        {
            curr -> next = node;
            curr = node;
        }
    }

    curr -> next = NULL;
    curr = head;


    while (curr != NULL)
    {
        printf("%d ", curr -> x);
        curr = curr -> next;
    }

    printf("\n");
}
