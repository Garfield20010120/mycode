import java.util.Scanner;
 
public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n = sc.nextInt();
    /**
     * 存放下标表示的数字后面的运算符
     * 用 1、2、3 代替
     * 1代表'+'、2代表'-'、3代表' '
     */
    static int[] mark = new int[n];
 
    public static void main(String[] args) {
        dg(1, 2, 1);
    }
 
    /**
     * 输出和为零的表达式
     */
    public static void print() {
        System.out.print("1");
        for (int i = 1; i < n; ++i) {
            if (mark[i] == 1) {
                System.out.print("+");
            } else if (mark[i] == 2) {
                System.out.print("-");
            } else {
                System.out.print(" ");
            }
            System.out.print(i + 1);
        }
        System.out.println();
    }
 
    /**
     * @param sum   表达式总和
     * @param x     现在的数
     * @param index mark[]下标
     */
    public static void dg(int sum, int x, int index) {
        // 如果条件满足 输出表达式
        if (sum == 0 && x - 1 == n) {
            print();
            return;
        }
        // 当不满足时 返回
        if (sum != 0 && x - 1 == n) {
            return;
        }
        // 因为按ASCII排序输出所以运算符的顺序为 ' '、'+'、'-'
        // 当前的运算符为' ' 只要判断前一个运算符是'+'或'-'
        // 不必判断是否为' ' 因为测试数据不超过9，所以不可能有两个空连续不放运算符
        mark[index] = 3;
        if (x - 1 > 1) {
            if (mark[index - 1] == 1) {
                dg(sum + (x - 1) * 9 + x, x + 1, index + 1);
            }
            if (mark[index - 1] == 2) {
                dg(sum - (x - 1) * 9 - x, x + 1, index + 1);
            }
        } else {
            dg(sum + (x - 1) * 9 + x, x + 1, index + 1);
        }
        mark[index] = 1;
        dg(sum + x, x + 1, index + 1);
        mark[index] = 2;
        dg(sum - x, x + 1, index + 1);
    }
}