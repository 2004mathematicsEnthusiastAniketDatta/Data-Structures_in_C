#include <stdio.h>
#define N 8
int issafe(int board[N][N],int row,int col){
	for(int x=0;x<N;x++){
		if (board[row][x] == 1){
			return 0;
		}
	}
	for(int x=row,y=col;x>=0 && y>=0;x--,y--){
		if(board[x][y]==1){
			return 0;
		}
	}
	for(int x=row,y=col;x<N && y>=0;x++,y--){
			if(board[x][y]==1){
			return 0;
		}
	}
	return 1;
}
int solveNqueens(int board[N][N],int col){
	 if (col == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueens(board, col + 1)) {
                return 1;
            }
            board[i][col] = 0;
        }
    }
    return 0;
}

