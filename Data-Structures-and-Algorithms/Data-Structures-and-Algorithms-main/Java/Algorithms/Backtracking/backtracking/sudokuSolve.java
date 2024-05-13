// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


// Runtime: 6ms      Memory:41.08MB 


package backtracking;

class Solution {

    int c=0;

    boolean check(char[][] board,int row,int col,char num){
        for (int i=0;i<9;i++){
            if(board[i][col]==num) return false;
        }
        for (int j=0;j<9;j++){
            if(board[row][j]==num) return false;
        }

        int sr=(row/3)*3;
        int sc=(col/3)*3;

        for (int i=sr;i<=sr+2;i++){
            for (int j=sc;j<=sc+2;j++){
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }


    public void solver(char[][] board,int row,int col) {

        if(row>8){
            c=1;
            return;
        } 

       
        if (board[row][col]!='.'){
            if(col<8)  solver(board,row,col+1) ;
            else solver(board,row+1,0) ;
        }
        else{
            for(char i='1';i<='9';i++){
                if(check(board,row,col,i)){
                    board[row][col]=i;
                    if(col<8)  solver(board,row,col+1);
                    else solver(board,row+1,0);
                    if(c==0) board[row][col]='.';
                }
            }
            return;
        }
        
            
    }
    
    public void solveSudoku(char[][] board) {
        solver(board,0,0);
    }
}