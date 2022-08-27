import java.util.Arrays;
import java.util.Scanner;
 
public class Main {
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		//输入字符串
		Scanner sc = new Scanner(System.in);
        String str = (sc.nextLine());
        
        //将字符串对象中的字符转换为一个字符数组
         char[] arr=str.toCharArray();
         //排序
         Arrays.sort(arr);
         int num=0;
         for (int i = 0; i < arr.length; i++) {
			if(arr[i]>90) {
				num=i;
			}
		}
         for (int i = arr.length-1; i >= num; i--) {
			System.out.print(arr[i]);
		}
         //输出
         for (int i = 0; i < num; i++) {
			System.out.print(arr[i]);
		}
       
	}
}