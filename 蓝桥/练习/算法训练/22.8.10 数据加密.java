import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in) ;
        int n = input.nextInt() ;
        int a = (n / 1000 + 5) % 10 ;
        int b = (((n / 100) % 10) + 5) % 10;
        int c = (((n / 10) % 10) + 5) % 10 ;
        int d = ((n % 10) + 5 ) % 10 ;
        int result = d*1000 + c * 100 + b * 10 + a ;
        System.out.println(result) ;
    }
}

