import java.util.Scanner;
 //22.7.1 蓝桥 ascii应用
public class Main {
public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	char a;
	int b=0;
	if(n>64&&n<=90) {
		a=(char) n;
		b=a-64;
		System.out.println(a+" d"+b);
	}else {
		a=(char) n;
		b=a-96;
		System.out.println(a+" x"+b);
	}
}
}