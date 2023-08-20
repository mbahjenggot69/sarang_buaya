#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//enum --> tipe data yang kita buat
enum State {Working = 1, Failed = 0};
enum HeroClass {Mage, Tank, Support, Assassin, Marksman};

int main() {
	
	
	enum HeroClass myHero = Tank;
	
	switch (myHero){
		case Mage:
			printf("Pergi ke mid");
			break;
		case Tank:
			printf("roaming");
			break;
		case Support:
			printf("roaming");
			break;
		case Assassin:
			printf("Pergi ke jungle");
			break;
		case Marksman:
			printf("Pergi ke bot");
			break;
	}
	
//	bool isUser = true;
//	bool isAdmin = false;
//	
//	if (isUser) {
//		printf("welcome user");
//	} else {
//		printf("please create new acc");
//	}

	// kondisi ? adalah true, : adalah false
//	isUser ? printf("welcome user") : printf("pls");
	
//	if (isUser && isAdmin) {
//		printf("welcome admin");
//	} else if (isUser){
//		printf("welcome user");
//	} else {
//		printf("please create new acc");
//	}

//	if (isUser) {
//		if(isAdmin){
//			printf("welcome admin");
//		} else {
//			printf("welcome user");
//		}
//	} else {
//		printf("please create new acc");
//	}

//	
//	int counter = 0;
//	printf("while\n");
//	while(counter <= 10) {
//		printf("%d \n", counter);
//		counter += 2;
//	}
	
//		printf("do while\n");
//		do {
//			printf("%d \n", counter);
//			counter++;
//		} while(counter <= 10);

//	int nim[5] ={
//	672020001,
//	672020002,
//	672020003,
//	672020004,
//	672020005,
//	672020006,
//	};
//	printf("%d", nim[1]);
//
//	for (int i=0;i<5;i++) {
//		printf("%d\n", nim[i]);
//	}
	
//	for(int i=5;i>0;i--){
//		for(int j=i;j>0;j--){
//			printf("* ");
//		}
//		printf("\n");
//	}
	
	return 0;
}
