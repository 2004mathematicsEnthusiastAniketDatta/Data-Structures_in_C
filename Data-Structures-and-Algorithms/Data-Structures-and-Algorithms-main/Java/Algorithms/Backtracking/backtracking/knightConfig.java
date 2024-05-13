// There is a knight on an n x n chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every 
// cell on the board exactly once.

// You are given an n x n integer matrix grid consisting of distinct integers from the range [0, n * n - 1] where grid[row][col] 
// indicates that the cell (row, col) is the grid[row][col]th cell that the knight visited. The moves are 0-indexed.

// Return true if grid represents a valid configuration of the knight's movements or false otherwise.

// Note that a valid knight move consists of moving two squares vertically and one square horizontally, or 
// two squares horizontally and one square vertically. The figure below illustrates all the possible eight moves of a knight from some cell.



// Runtime: 1ms      Memory:44.38MB


package backtracking;

class Solution {

    boolean check(int[][] grid,int row, int col,int num,int n){

        //base case
        if(grid[row][col]==n*n-1) return true;

        // 8 conditions
        int i,j;

        //Up left
        i=row-2;
        j=col-1;
        if(i>=0 && j>=0){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        //Up Right
        i=row-2;
        j=col+1;
        if(i>=0 && j<n){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        //Down Left
        i=row+2;
        j=col-1;
        if(i<n && j>=0){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        //Down Right
        i=row+2;
        j=col+1;
        if(i<n && j<n){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        //Left Up
        i=row-1;
        j=col-2;
        if(i>=0 && j>=0){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        //Left Down
        i=row+1;
        j=col-2;
        if(i<n && j>=0){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        //Right Up
        i=row-1;
        j=col+2;
        if(i>=0 && j<n){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        //Right Down
        i=row+1;
        j=col+2;
        if(i<n && j<n){
            if(grid[i][j]==num+1)
                return check(grid,i,j,num+1,n);
        }

        return false;


    }


    public boolean checkValidGrid(int[][] grid) {
        if(grid[0][0]!=0) return false;
        int n=grid.length;
        return check(grid,0,0,0,n);
    }
}