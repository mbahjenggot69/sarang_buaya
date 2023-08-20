#include <stdio.h>

void main(){
	 int num1,num2,hasil;
	 char operasi;
	 
	 printf("Input angka [1] : ");
	 scanf("%d",&num1);
	 
	 printf("Input angka [2] : ");
	 scanf("%d",&num2);
	 
	 printf("Input Operasi (+,-,*,/) : ");
	 scanf(" %c",&operasi);
	 /*
	 if (operasi == '+') {
	 	hasil = num1 + num2;
	 }else if (operasi == '-') {
	 	hasil = num1 - num2;
	 }else if (operasi == '*') {
	 	hasil = num1 * num2;
	 }else if (operasi == '/') {
	 	hasil = num1 / num2;
	 }else {
	 	hasil = 0;
	 	operasi = '?';
	 }*/
	 
	 
	 ((operasi == '+')? hasil = num1 + num2 : 
	 ((operasi == '-')? hasil = num1 - num2 :
	 ((operasi == '*')? hasil = num1 * num2 :
	 ((operasi == '/')? hasil = num1 / num2 :  0))));
	 printf("Answer %d %c %d = %d\n", num1,operasi,num2,hasil);
}
