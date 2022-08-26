import java.util.Scanner;
 
public class Main {
	static int x;
	public static void f(String s,int n) {
		if (n == 0) {
			System.out.println(x+"="+s.substring(1));//去除等号后第一个数字的符号位
			return ;}
		
		
           for(int i=1;i<=n;i++) {
        	   f(s+"+"+i,n-i);
           }
 
	}
 
	public static void main(String[] args) {
		Scanner s1=new Scanner(System.in);
		x=s1.nextInt();
		f("",x);
 
	}
 
}