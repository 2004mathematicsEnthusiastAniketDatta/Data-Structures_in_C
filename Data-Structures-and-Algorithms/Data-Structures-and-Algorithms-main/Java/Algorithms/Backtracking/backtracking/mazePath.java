// Java program to find all possible paths from start to end in a 2D maze



package backtracking;

public class mazePath {

    //total possible paths
    static int maze(int i, int j, int er, int ec) {
        if(i>er || j>ec)  return 0;
        if(i==er && j==ec)  return 1;
        int downways=maze(i+1, j, er, ec);
        int rightways=maze(i, j+1, er, ec);
        int total=downways+rightways;
        return total;
    }

    //print possible paths
    static void print(int i, int j, int er, int ec, String s) {
        if(i>er || j>ec)  return;
        if(i==er && j==ec){
            System.out.println(s);
            return;
        }  
        print(i+1, j, er, ec,s+"D");
        print(i, j+1, er, ec,s+"R"); 
    }


    public static void main(String[] args) {
        int rows=3;
        int columns=3;
        int count=maze(1,1,rows,columns);
        System.out.println(count);
        print(1, 1, rows, columns, "");
    }


}
