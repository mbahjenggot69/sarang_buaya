#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
 
int papan[8];
 
// 1. Penempatan posisi ratu 
void bolehJalan(int baris,int n){
	int kolom; int cariSolusi(int baris, int kolom); void cetakPapan(int n);
	char pilih;
	for(kolom=1;kolom<=n;++kolom){
		if(cariSolusi(baris,kolom)){
	   		papan[baris]=kolom;
	   		if(baris==n){ 
	    		cetakPapan(n); //cetak solusi
	    		exit(0);
	   		} else { 
	    		bolehJalan(baris+1,n);
			}
	 	}
	} 
}
 
//2. Perizinan jalan
int cariSolusi(int baris,int kolom){
	int i;
	
	for(i=1;i<=baris-1;++i){
	  	if(papan[i]==kolom){
	  		return 0;
		} else{
	  		if(abs(papan[i]-kolom)==abs(i-baris)){
	  			return 0;
			}
		}
	}
	return 1;
}

// 3. Cetak papan
void cetakPapan(int n){
	int i,j,Q = 1;
	
	printf("\n"); 
	for(i=1;i<=n;++i){
	  	printf("\n\n",i);
	  	for(j=1;j<=n;++j){
	   		if(papan[i]==j){
	   			printf(" %d\t", Q);
				   Q++; 
			} else {
				printf(" 0\t"); 
			}
		}
	}
}

int main(){
	int i,j,n = 8;
	system("color 9F");
	printf("8 Queens");
	bolehJalan(1,n);
	return 0;
}

