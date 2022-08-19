​
import java.util.Scanner;
public class Main {
    public static void main(String[]args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 1; i < n + 1; i++){               //i控制行
            if(i == 1) {                      //第一行
                for (int j = 1; j < n; j++) {       //先输出空格
                    System.out.print(" ");
                }
                for (int j = 1; j < n + 1; j++) {    //再输出*
                    System.out.print("*");
                }
                System.out.println();
            }
 
             else{                //第一行之后的前n行（整个图像的上半部分）
                for(int j = 1; j < n - i +1 ; j ++){     //输出空格
                    System.out.print(" ");
                }
                System.out.print("*");            //只输出一个*
                for(int j = 1; j < n +(i - 1)*2 - 1 ;j++){      //输出空格
                    System.out.print(" ");
 
                }
                System.out.println("*");        //再输出一个*
            }                         //至此，图像上半部分输出完毕，下半部分就是对称
        }                 //注意 i又从1开始
 
        for(int i = 1 ; i <  n  ; i++){         //i控制行
            if(i == n - 1) {             //输出图像最后一行
                for (int j = 1; j < n; j++) {
                    System.out.print(" ");
                }
                for (int j = 1; j < n + 1; j++) {
                    System.out.print("*");
                }
                System.out.println();
            }
            else{
                for(int j = 1; j < i +1  ; j ++){
                    System.out.print(" ");
                }
                System.out.print("*");
                for(int j = 1; j < 3*n - 2*i -3; j++){
                    System.out.print(" ");
                }
                System.out.println("*");
            }
        }
    }
}
 
​