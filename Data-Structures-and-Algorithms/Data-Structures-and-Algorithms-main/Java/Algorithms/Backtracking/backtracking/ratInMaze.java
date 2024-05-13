// Java program to find all possible paths from start to end in a 4D maze using backtracking, with obstructions.



package backtracking;


public class ratInMaze {


    public static void main(String[] args) {
        int rows=4;
        int columns=5;
        int maze[][]={
            {1,1,1,1,0},
            {1,0,1,0,0},
            {1,0,1,1,1},
            {1,1,1,0,1},

        };
        System.out.println("All Possible paths:\n");
        mazePath(0, 0, rows-1, columns-1, "",maze);
    }

    static void mazePath(int i, int j, int er, int ec, String s, int[][] maze) {
        
        if(i<0 || j<0)  return;
        if(i>er || j>ec)  return;
        if(i==er && j==ec){
            System.out.println(s);
            return;
        }  

        if(maze[i][j]==0 || maze[i][j]==-1)return;

        maze[i][j]=-1;

        mazePath(i+1, j, er, ec,s+"D",maze);
        mazePath(i, j+1, er, ec,s+"R",maze); 
        mazePath(i, j-1, er, ec,s+"L",maze);
        mazePath(i-1, j, er, ec,s+"U",maze);

        //backtracking, for different way
        maze[i][j]=1;
    }
    
}