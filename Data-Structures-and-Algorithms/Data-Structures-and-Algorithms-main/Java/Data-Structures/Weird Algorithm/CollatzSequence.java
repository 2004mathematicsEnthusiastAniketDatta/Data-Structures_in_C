import java.util.Scanner;
public class CollatzSequence{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        StringBuilder result = new StringBuilder();
        while(n!=1){
            result.append(n).append(" ");
            if(n%2 == 0)
            {
                n/=2;
            }
            else{
                n=n*3+1;
            }
            }
        result.append(n);

    System.out.println(result.toString());

    }
}        

