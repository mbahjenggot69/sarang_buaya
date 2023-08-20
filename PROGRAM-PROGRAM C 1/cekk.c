#include <stdio.h>
#include <conio.h>
main()
{
int baris, kolom, matrik[3][4];
printf("Input elemen Array matrik 3x4\n");
printf("=============================\n\n");
for(baris=0; baris<3; baris++)
{
for(kolom=0; kolom<4; kolom++)
{
printf("Input Matrik[%d][%d] : ",baris+1,kolom+1);
scanf("%d", &matrik[baris][kolom]);
}
printf("\n");
}
printf("====Isi Array====\n");
printf("-----------------\n");
for(baris=0; baris<3; baris++)
{
for(kolom=0; kolom<4; kolom++)
{
printf(" %d",matrik[baris][kolom]);
}
printf("\n");
}
getch();
}
