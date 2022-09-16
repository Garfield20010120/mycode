import java.util.Scanner;

public class Main {
    public static int count  = 0;
    public static void permutation(String prefix, char [] arr, int M){
        if(prefix.length() == arr.length){
            count ++ ;
            if(count == M){
                for(int i=0; i<prefix.length(); i++){
                    System.out.print(prefix.charAt(i) + " ") ;
                }
                System.exit(0) ;
            }
        }
        for(int i=0; i<arr.length; i++){
            char c = arr[i] ;
            if(f(arr,c) > f(prefix.toCharArray(),c)) {
                permutation(prefix + c, arr, M);
            }
        }
    }
    public static int f(char [] arr, char c){
        int sum = 0 ;
        for(int i=0; i<arr.length; i++){
            if(c == arr[i]){
                sum ++ ;
            }
        }
        return sum ;
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int N = input.nextInt() ;
        int M = input.nextInt() ;
        String s = "" ;
        for(int i=1; i<=N; i++){
            s += i ;
        }
        permutation("", s.toCharArray(), M) ;
    }
}
