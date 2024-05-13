// Java program to find all possible paths from start to end in a 4D maze using backtracking



package backtracking;

public class MazePath4D {
    

    
    static void print(int i, int j, int er, int ec, String s, boolean[][] isVisited) {

        if(i<0 || j<0)  return;
        if(i>er || j>ec)  return;

        //checking if cell already visited
        if(isVisited[i][j]==true) return;

       
        if(i==er && j==ec){
            System.out.println(s);
            return;
        }  

        isVisited[i][j]=true;
        print(i+1, j, er, ec,s+"D",isVisited);
        print(i, j+1, er, ec,s+"R",isVisited); 
        print(i, j-1, er, ec,s+"L",isVisited);
        print(i-1, j, er, ec,s+"U",isVisited);

        //backtracking, for different way
        isVisited[i][j]=false;
    }


    public static void main(String[] args) {
        int rows=3;
        int columns=3;
        boolean isVisited[][]=new boolean[rows][columns];
        print(0, 0, rows-1, columns-1, "",isVisited);
    }
}
