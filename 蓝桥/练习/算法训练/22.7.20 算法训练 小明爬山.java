import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in) ;
        int n = input.nextInt() ;
        int [] dp = new int [n] ;
        int [] res = new int [n] ;
        Arrays.fill(dp, 1) ;
        int result = Integer.MIN_VALUE ;
        for(int i=0; i<n; i++){
            res[i] = input.nextInt() ;
        }
        for(int i=1; i<res.length; i++){
            for(int j=i-1; j>=0; j--){
                if(res[i]> res[j]) {
                    dp[i] = Math.max(dp[i], dp[j]+1); //动态规划
                }
            }
        }
        for(int k=0; k<dp.length; k++){
            if(dp[k] > result){
                result = dp[k] ;
            }
        }
        System.out.println(result);
    }
}
