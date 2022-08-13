import java.util.Scanner;
 
public class Main {
    public static int sum;
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        dg(n);
        System.out.println(sum);
    }
 
    public static void dg(int n) {
        // 每出现一个原数，sum+1
        sum++;
        // 左边添加不超过原数一半的自然数，作为新原数
        for (int i = 1; i <= n / 2; i++) {
            dg(i);
        }
    }
}