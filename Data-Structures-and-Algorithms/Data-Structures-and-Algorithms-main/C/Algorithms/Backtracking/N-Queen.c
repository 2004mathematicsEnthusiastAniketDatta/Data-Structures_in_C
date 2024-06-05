#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 8

void printSolution(int board[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(board[i][j])
			printf(" Q ");
			else
			printf(" . ");
		}
		printf("\n");
	}
}

bool isSafe(int board[N][N],int row,int col)
{
	int i,j;
	for(i = 0;i < col;i++)
	{
		if(board[row][i])
		return false;
	}
	//Principal digonal
	for(i = row,j = col;i >= 0 && j >= 0;i--,j--)
	{
		if(board[i][j])
		return false;
	}
    //Lower Diagonal
    for(i = row,j = col;j >= 0 && i < N;i++,j--){
    	if(board[i][j])
    	return false;
	}
	return true;
}

bool SolveNqueensUtil(int board[N][N],int col)
{
	if(col >= N)
	   return true;
	   
	int i;
	for(i=0;i<N;i++)
	{
		if(isSafe(board,i,col))
		{
			board[i][col]=1;
			if(SolveNqueensUtil(board,col+1)) 
			   return true;
			   
			   
			   board[i][col]=0;
		}
	}
	return false;
}

bool SolveNQueens(){
	int board[N][N]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},};
	if(SolveNqueensUtil(board,0) == false)
	{
	   printf("Solution does not Exist");
	   return false;
}
printSolution(board);
return true;
}

int main(){
SolveNQueens();
return 0;
}
