#include<stdio.h>
#include<conio.h>
int fun1(int *a,int *b);
int fun2(int *c,int *d);
int fun3(int *e,int *f);
int fun4(int *g,int *h);
int main()
{
    int i,k;
    char j;
    scanf("%d%c%d",&i,&j,&k);
    switch(j)
    {
        case '/':
            fun1(&i,&k);
            break ;
        case '*':
            fun2(&i,&k);
            break ;
        case '+':
            fun3(&i,&k);
            break ;
        case '-':
            fun4(&i,&k);
            break ; 
        default:
            printf("ERROR");
    }
    getch();
    return 0;   
}
fun1(int *a,int *b)
{
    float divide;
    float A=*a,B=*b;
    if(A % B==0)
    {
        divide=A/B;
        printf("= %.0f",divide);
    }
    else
    {
        divide=A/B;
        printf("= %.2f",divide);
    }
}
fun2(int *c,int *d)
{
    int multiply,C=*c,D=*d;
    multiply=C*D;
    printf("= %d",multiply);
}
fun3(int *e,int *f)
{
    int add,E=*e,F=*f;
    add=E+F;
    printf("= %d",add);
}
fun4(int *g,int *h)
{
    int subtract;
    int G=*g,H=*h;
    subtract=G-H;
    printf("= %d",subtract);
}

