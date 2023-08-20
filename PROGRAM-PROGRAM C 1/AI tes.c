#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

#define N 8

void cetakPapan(int papan[N][N]){
	
	printf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",papan[i][j]);
		}
		printf("\n");
	}
}

int bolehJalan(int x,int y,int i,int xmove[N],int ymove[N],int papan[N][N]){
	
	if (x+xmove[i] >= 0 && x+xmove[i] < N && y+ymove[i] >= 0 && y+ymove[i] < N && papan[x+xmove[i]][y+ymove[i]]==0){
		return 1;
	} else {
		return 0;
	}
}

int cariSolusi(int x,int y,int lkh,int xmove[N],int ymove[N],int papan[N][N]){
	
	if (lkh>N*N) {
		return 1;
	} else {//8 kemungkinan langkah
		for(int i=0;i<N;i++){
			int next_x = x + xmove[i];
			int next_y = y + ymove[i];
			//apakah boleh jalan?
			if (bolehJalan(x,y,i,xmove,ymove,papan) == 1){
				papan[x+xmove[i]][y+ymove[i]] = lkh;
				//printf("Langkah L = %i\n", i);
				//cetakPapan(papan); //cetak papan 1 per 1
				//getch();
				if(cariSolusi(next_x,next_y,lkh+1,xmove,ymove,papan)==1){
					return 1;
				} else {
					papan[next_x][next_y]=0;
				}
			}
		}
	}
	return 0;
}

int main(){
	
	//inisialisasi papan
	int papan[N][N];
	//isi papan dengan nilai 0 untuk N x N
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			papan[x][y] = 0;
//			printf("%d ", papan[x][y]);
		}
//		printf("\n");
	}
	
	//inisialisasi langkah kuda
	papan[0][0] = 1;
	int xmove[] = {1,2,2,1,-1,-2,-2,-1};
	int ymove[] = {-2,-1,1,2,2,1,-1,-2};
	
	cetakPapan(papan);
	
	//solusi next step saja +1
	if (cariSolusi(0,0,2,xmove,ymove,papan) == 0){
		printf("tidak ada solusi");
	} else {
		cetakPapan(papan);
	}
	return 0;
}
