// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.


// Runtime: 1ms      Memory:44.06MB


package backtracking;

class Solution {

    boolean check(char[][] board,int row,int col,int num){
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


    public boolean isValidSudoku(char[][] board) {
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char n=board[i][j];
                    board[i][j]='.';
                    if (check(board,i,j,n)==false) return false;
                    board[i][j]=n;
                } 
            }
        }
        return true;
    }
}

