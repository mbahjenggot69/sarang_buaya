#include <stdio.h>
int main(){
	
	int i, j, n;
	scanf("%d", &n);  // ‘n’ must be odd
	int num1 = n / 2 * 3;
// right arrow
	printf("Right Arrow\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
// center horizontal, upper right diagonal, bottom right diagonal
			if(i == n /2 || j - i == n / 2 || i + j == num1)
			printf("*");
			else
			printf(" ");
		}
		printf("\n");
	}


return 0;

}
