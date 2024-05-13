// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.


// Runtime: 2ms      Memory:40.01MB


package backtracking;

class Solution {
   
    boolean isSafe(int board[][],int row,int col,int n){
    //check row and column
    for(int i=0;i<n;i++){
        if(board[i][col]==1) return false;
    }
    for(int j=0;j<n;j++){
        if(board[row][j]==1) return false;
    }
    //check 4 diagonal directions
    int i=row;
    int j=col;
    //n-e
    while(i>=0 && j<n){
        if(board[i][j]==1) return false;
        i--;
        j++;
    }
    i=row;
    j=col;
    //s-e
    while(i<n && j<n){
        if(board[i][j]==1) return false;
        i++;
        j++;
    }
    i=row;
    j=col;
    //s-w
    while(i<n && j>=0){
        if(board[i][j]==1) return false;
        i++;
        j--;
    }
    i=row;
    j=col;
    //n-w
    while(i>=0 && j>=0){
        if(board[i][j]==1) return false;
        i--;
        j--;
    }
    return true;
}

int check(int board[][],int n,int row,int ans){

    if(row==n){
        return 1;
    }

    int c=0;
    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]=1;
            c+=check(board,n,row+1,ans);
            board[row][col]=0;
        }     
    }
    return c;
}
public int totalNQueens(int n) {
    int ans= 0;
    
    int board[][]=new int[n][n];
    
    return check(board,n,0,ans);
}
}