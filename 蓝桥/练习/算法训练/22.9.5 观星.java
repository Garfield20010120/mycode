import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in) ;
        int n = input.nextInt() ;
        int [] arr = new int [n] ;
        int count = 0 ;
        for(int i=0; i<n; i++){
            arr[i] = input.nextInt();
        }
        for(int i=arr.length-1; i>0; i--){
            for(int j=0; j<i; j++){
                if(arr[j] > arr[j+1]){
                    int temp = arr[j] ;
                    arr[j] = arr[j+1] ;
                    arr[j+1]  = temp ;
                    count ++ ;
                }
            }
        }
        System.out.println(count) ;
    }
}

