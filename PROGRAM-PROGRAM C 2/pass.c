#include <stdio.h>
#include <conio.h>

void main()
{
 char pasword[10],usrname[10], ch;
 int i;


 printf("Enter User name: ");
 gets(usrname);
 printf("Enter the password <any 8 characters>: ");

 for(i=0;i<8;i++)
 {
  ch = getch();
  pasword[i] = ch;
  ch = '*' ;
  printf("%c",ch);
 }

}

 

