import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in) ;
        String s1 = input.next() ;
        String s2 = input.next() ;
        if(s1.compareTo(s2) > 0){
            System.out.println("1") ;
        }else if(s1.compareTo(s2) < 0){
            System.out.println("-1") ;
        }else{
            System.out.println("0") ;
        }

    }
}
