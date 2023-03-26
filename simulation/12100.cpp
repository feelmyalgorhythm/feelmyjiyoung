#include<stdio.h>

using namespace std;

int N, answer=0;
int board[22][22];
bool checked[22][22];

void initChecked(){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			checked[i][j]=false;
}

void printBoard(int board[22][22]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
	printf("\n");
}

void findMax(int board[22][22]){
	
	int result=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]>result)
				result=board[i][j];
		}
	}
	if(result>answer)
		answer=result;
		
	//printBoard(board);
	
	return;
}


void moveLeft(int board[22][22]){
	initChecked();
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j]==0)
				continue;
				
			for(int k=j;k>0;k--){
				if(board[i][k-1]!=0){
					if(board[i][k]==board[i][k-1] && !checked[i][k]){ 
						board[i][k-1]*=2;
						board[i][k]=0;
						checked[i][k]=true;
					}
					break;
				}
				else{ 
					board[i][k-1]=board[i][k];
					board[i][k]=0;
				}
			}	
		}
	}
	
	findMax(board);
}

void moveRight(int board[22][22]){
	initChecked();
	for(int i=0;i<N;i++){
		for(int j=N-1;j>=0;j--){
			if(board[i][j]==0)
				continue;
				
			for(int k=j;k<N-1;k++){
				if(board[i][k+1]!=0){
					if(board[i][k]==board[i][k+1] && !checked[i][k+1]){ 
						board[i][k+1]*=2;
						board[i][k]=0;
						checked[i][k+1]=true;
					}
					break;
				}
				else{ 
					board[i][k+1]=board[i][k];
					board[i][k]=0;
				}
				
			}	
		}
	}
	
	findMax(board);
}

void moveUp(int board[22][22]){
	initChecked();
	for(int i=0;i<N;i++){
		for(int j=1;j<N;j++){
			if(board[j][i]==0)
				continue;
				
			for(int k=j;k>0;k--){
				if(board[k-1][i]!=0){
					if(board[k][i]==board[k-1][i] && !checked[k-1][i]){ 
						board[k-1][i]*=2;
						board[k][i]=0;
						checked[k-1][i]=true;
					}
					break;
				}
				else{ 
						board[k-1][i]=board[k][i];
						board[k][i]=0;
				}
			}	
		}
	}
	
	findMax(board);
}

void moveDown(int board[22][22]){
	initChecked();
	for(int i=0;i<N;i++){
		for(int j=N-1;j>=0;j--){
			if(board[j][i]==0)
				continue;
				
			for(int k=j;k<N-1;k++){
				if(board[k+1][i]!=0){
					if(board[k+1][i]==board[k][i] && !checked[k+1][i]){ 
						board[k+1][i]*=2;;
						board[k][i]*=0;
						checked[k+1][i]=true;
					}
					break;
				}
				else{ 
						board[k+1][i]=board[k][i];
						board[k][i]=0;
				}
			}	
		}
	}
	findMax(board);
}

void moveBoard(int count, int direction, int board[22][22]){
	int tmp[22][22];
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			tmp[i][j]=board[i][j];

	if(count==5){
		return;
	}
	
	if(direction==0){
		moveLeft(tmp);
	}else if(direction==1){
		moveRight(tmp);
	}else if(direction==2){
		moveUp(tmp);
	}else{
		moveDown(tmp);
	}
	
	
	for(int i=0;i<4;i++){
		moveBoard(count+1, i, tmp);
	}
	
}

int main(){
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			scanf("%d",&board[i][j]);
	}
	
	for(int i=0;i<4;i++){
		moveBoard(0,i, board);
	}	
	
	printf("%d",answer);
	return 0;
}