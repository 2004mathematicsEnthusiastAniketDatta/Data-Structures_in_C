// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


// Runtime: 5ms      Memory:44.78MB


package backtracking;

import java.util.ArrayList;
import java.util.List;

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

    void check(int board[][],int n,int row,List<List<String>> ans){

        if(row==n){
            List<String> l=new ArrayList<>();
            for(int i=0;i<n;i++){
                String str="";
                for(int j=0;j<n;j++){
                    if(board[i][j]==1) str+="Q";
                    else str+=".";
                }
                l.add(str);
            }
            ans.add(l);
            return;
        }

        for(int col=0;col<n;col++){
            if(isSafe(board,row,col,n)){
                board[row][col]=1;
                check(board,n,row+1,ans);
                board[row][col]=0;
            }     
        }
        return;
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans= new ArrayList<>();
        int board[][]=new int[n][n];
        check(board,n,0,ans);
        return ans;   
    }
}
