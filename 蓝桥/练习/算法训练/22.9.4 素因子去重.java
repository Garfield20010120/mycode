import java.util.ArrayList;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Long n = new Scanner(System.in).nextLong();
        ArrayList<Long> list = new ArrayList<Long>();
        //从2到n找素因子
        for (long i = 2; i <= n; i++) {
            //i是素因子
            if(n%i==0 && juge(i)){
                //素因子去重
                while(n%i==0){
                    n/=i;
                }
                
                //将素因子添加到集合
                list.add(i);
                if(n<i)
                    break;
            }
        }
        
        long p = 1;
        //将所有素因子相乘，得出最后结果p
        for (int i = 0; i < list.size(); i++) {
            p*=(long)list.get(i);
        }
        System.out.println(p);
    }
    
    //判断因子是否是素数
    public static boolean juge(long m){
        int sqrt = (int) Math.sqrt(m);
        for (int i = 2; i <= sqrt; i++) {
            if(m%i==0)
                return false;
        }
        return true;
    }
}