#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define LINE 100
#define STR 30
#define NUM 15
#define MAX 100

int GetID(char CashierID[]);
void DigitValidation(char Input[], int size);
int select_option();
int OpenInventory(char UPC[][9],char Itemname[][STR],int Stock[], double Price[], int *pcount);
void CopyArray_AtoB(int arrayA[], int arrayB[], int count);
void GetUPCtoMycart(char inputUPC[],char UPC[][9],double Price[],int tempStock[],char MycartUPC[][9],
					int Mycartquan[],double Mycartprice[],int count,int *pMycount);
void Tomycart(char inputUPC[], int tempStock[], double Price[], char MycartUPC[][9], int Mycartquan[],
				double Mycartprice[], int i,int *pMycount);
void Checkstock(char inputUPC[], int tempStock[], int i);
void MyTotal(int Mycartquan[], double Mycartprice[], double Mytotal[], int Mycount);
int Transaction();
void WriteInvoice(char CashierID[], char MycartUPC[][9], int Mycartquan[], int Mycount);
void UpdateInventory(char UPC[][9], char Itemname[][STR], int Stock[], double Price[], int count);
void clearbuffer();


int main(){
	
	char CashierID[5];				
	char inputUPC[9];	
	char UPC[LINE][9];           	
	char Itemname[LINE][STR];
	int Stock[LINE];
	int tempStock[LINE];	
	double Price[LINE];	
	char MycartUPC[MAX][9];        
	int Mycartquan[MAX]={0};
	double Mycartprice[MAX];
	double Mytotal[3];
	int choice, Mycount=0, count=0;
	char transaction;
	FILE *pInventory;

		
	printf("\nWelcome to the Memory Lane inventory system program\n\n");
	choice=GetID(CashierID);
	if(choice==1){
		do{
			clearbuffer();
			choice=select_option();
			if(choice==1){
				choice= OpenInventory(UPC, Itemname, Stock, Price, &count);
				CopyArray_AtoB(Stock, tempStock, count);
				if(choice==1){
					do{
						clearbuffer();
						GetUPCtoMycart(inputUPC,UPC,Price,tempStock,MycartUPC,
											Mycartquan,Mycartprice,count,&Mycount);
						if(choice==1 && Mycount>0)
							MyTotal(Mycartquan, Mycartprice, Mytotal, Mycount);
						choice=Transaction();												
					}while(choice==1);
					if(Mycount>0){
						WriteInvoice(CashierID, MycartUPC, Mycartquan, Mycount);
						CopyArray_AtoB(tempStock, Stock, count);
						UpdateInventory(UPC, Itemname, Stock, Price, count);
					}	
				}
			}
		}while(choice==1);
	}
	printf("Good Bye\n\n");
	return 0;
}	
		
int GetID(char CashierID[]){     // get chashierID from the user
	
	int choice=1;
	printf("Please enter your cashier ID : ");
	DigitValidation(CashierID, 5);
	if(atoi(CashierID)==0)
		choice=0;
	printf("\n");
	
	return choice;
}

void DigitValidation(char Input[], int size){     // check digits 

	int i,flag;	
	do{	
		scanf("%s", Input);	
		if(atoi(Input)){
			for(i=0,flag=0; i<size && Input[i] != '\0'; i++){
				if( isdigit(Input[i]))
					flag++;
			}
			if(flag!=(size-1))
				printf("Invalid entry, please try again : ");			
		}
		else
			flag=(size-1);
	}while(flag!=(size-1));		
}

int select_option(){

	int choice;
	printf("1.Start a new invoice\n");
	printf("0.Quit\n\n");
	printf("Please select what you would like to do : ");
	scanf("%d", &choice);
	printf("\n");
	
	return choice;
}	
		
int OpenInventory(char UPC[][9],char Itemname[][STR],int Stock[], double Price[], int *pcount){

	FILE *pInventory;
	int choice=1;
	pInventory = fopen("Inventory.txt", "r");                 // open Inventory file to read
	if(pInventory){
		while(fscanf(pInventory,"%[^|]|%[^|]|%d|%lf\n",       // save the contents from file to arrays
				UPC[*pcount],Itemname[*pcount], &Stock[*pcount], &Price[*pcount])!= EOF && *pcount<LINE){				
			printf("%s|%s|%d|%.2lf\n", UPC[*pcount], Itemname[*pcount], Stock[*pcount], Price[*pcount]);
			(*pcount)++;				
		}
		fclose(pInventory);
	}
	else{
		printf("Failed to open Inventory.txt\n");
		choice=0;
	}
	return choice;	
}

void CopyArray_AtoB(int arrayA[], int arrayB[], int count){

	int i;
	for(i=0; i<count; i++){		
		arrayB[i]=arrayA[i];
	}
}	
	
void GetUPCtoMycart(char inputUPC[],char UPC[][9],double Price[],int tempStock[],char MycartUPC[][9],
					int Mycartquan[],double Mycartprice[],int count,int *pMycount){

	int i, choice=2;
	do{
		printf("Enter UPC(0 to finish) : ");
		DigitValidation(inputUPC, 9);
		choice=2;
		if(atoi(inputUPC)){
			for(i=0; i<count && choice!=0; i++){
				choice = strcmp(inputUPC,UPC[i]);    
				if(choice==0){
					Tomycart(inputUPC,tempStock,Price,MycartUPC,Mycartquan,Mycartprice,i,pMycount);					
				}
				else
					choice=2;
			}
			if(choice!=0 && i!=0)
				printf("Invalid entry, please try again\n");			
		}	
		else
			choice=1;			
	}while(choice != 1);										
}

void Tomycart(char inputUPC[], int tempStock[], double Price[], char MycartUPC[][9], int Mycartquan[],
				double Mycartprice[], int i,int *pMycount){
	
	int j, flag, stock;	
	Checkstock(inputUPC, tempStock, i);
	if(tempStock[i]>0){	
		tempStock[i]-=1;
		if((*pMycount)==0){
			strcpy(MycartUPC[*pMycount], inputUPC);
			Mycartquan[*pMycount]+=1;			
			Mycartprice[*pMycount]=Price[i];
			(*pMycount)++;
		}		
		else{		
			for(j=0; j<=(*pMycount)&&flag!=0; j++){
				flag=strcmp(inputUPC,MycartUPC[j]);
				if(flag==0)
					Mycartquan[j]+=1;
				else if(flag!=0 && j==(*pMycount)){
					strcpy(MycartUPC[*pMycount], inputUPC);
					Mycartquan[*pMycount]=1;	
					Mycartprice[*pMycount]=Price[i];
					(*pMycount)++;
					flag=0;
				}
			}	
		}
	}			
}

void Checkstock(char inputUPC[], int tempStock[], int i){
	
	FILE *pWarnings;

	if(tempStock[i]==0 || tempStock[i]==1){
		pWarnings=fopen("Warnings.txt", "a");		
		if(tempStock[i]==1){
		fprintf(pWarnings, "Warning: %s has run out of stock\n", inputUPC);
		printf("Warning: %s has run out of stock\n", inputUPC);
		}
		else if(tempStock[i]==0){
		fprintf(pWarnings, "Error: %s stock was in error, attempted to drop below zero\n",inputUPC);
		printf("Error: %s stock was in error, attempted to drop below zero\n", inputUPC);
		}
		fclose(pWarnings);	
	}
}	

void MyTotal(int Mycartquan[], double Mycartprice[], double Mytotal[], int Mycount){

	int i, price, subtotal=0;
	
	for(i=0; i<Mycount; i++){
	
		price=Mycartquan[i]*Mycartprice[i];
		subtotal += price;
	}
	Mytotal[0]=subtotal;
	Mytotal[1]=subtotal*0.13;
	Mytotal[2]=Mytotal[0]+Mytotal[1];
	printf("Sub Total   : $%5.2lf\n", Mytotal[0]);
	printf("Tax (13%)   : $%5.2lf\n", Mytotal[1]);
	printf("Final Total : $%5.2lf\n\n", Mytotal[2]);	
}	

int Transaction(){
	
	char tr;
	int choice;
	clearbuffer();
	printf("Finalize the transaction(y/n)?");
	scanf("%c", &tr);
	if(tr=='y' || tr=='Y')
		choice=0;
	else if(tr=='n' || tr=='N')
		choice=1;
	return choice;
}

void WriteInvoice(char CashierID[], char MycartUPC[][9], int Mycartquan[], int Mycount){

	FILE *pInvoice;
	int i;
	time_t seconds;
	struct tm *time_struct;
	char str[25];
	
	/* will store number of seconds since January 1, 1900 */
	time(&seconds);
	/* returns a pointer to a tm structure */
	time_struct = localtime(&seconds);
	strftime(str, 24, "%H:%M:%S|%m/%d/%Y", time_struct);						
	
	clearbuffer();
	pInvoice = fopen("Invoice.txt", "a");
	fprintf(pInvoice, "%s|%s\n", CashierID,str);

	for(i=0;i<Mycount ; i++){
		fprintf(pInvoice,"%s|%d\n", MycartUPC[i], Mycartquan[i]);
	}
	fclose(pInvoice);
	printf("Invoice complete, data updated.\n");
}
	
void UpdateInventory(char UPC[][9], char Itemname[][STR], int Stock[], double Price[], int count){
		
		int i;
		FILE *pInventory;
		pInventory = fopen("Inventory.txt", "w");

		for(i=0; i<count; i++){	
			printf("%s|%s|%d|%.2lf\n", UPC[i],Itemname[i], Stock[i], Price[i]);
			fprintf(pInventory,"%s|%s|%d|%.2lf\n", UPC[i],Itemname[i], Stock[i], Price[i]);
		}	
		fclose(pInventory);
}

void clearbuffer(){
	char a;
	while((a=getchar()) != '\n' && a != EOF)	// clear the buffer to receive a character
		;
}			


