#include <stdio.h>  
  
int main()  
{  
    int num, i, row = 1, number = 1;  
  
    printf("Enter the maximum no of rows for Pyramid\n");  
    scanf("%d", &num);  
  
    while(row <= num)  
    {  
        i = 0;  
        while(i <= (num-row))  
        {  
            printf("  ");  
            i++;  
        }  
  
        i = 0;  
        while(i < (2*row-1))  
        {  
            printf("%d ", number);  
  
            if(number == 9)  
                number = 0;  
            else  
                ++number;  
  
            ++i;  
        }  
        printf("\n");  
        row++;  
    }  
    return 0;  
}  
