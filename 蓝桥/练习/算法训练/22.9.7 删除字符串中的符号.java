import java.util.Scanner;
 
public class Main {
public static void main(String[] args) {
	Scanner sc=new Scanner(System.in);
	String s=sc.next();
	char[] arr=new char[s.length()];
	for (int i = 0; i < s.length(); i++) {
		arr[i]=s.charAt(i);
	}
	int sum=0;
	for (int i = 0; i < arr.length; i++) {
		if(arr[i]=='*') {
			sum++;
		}else {
			break;
		}
	}
	for (int i = sum; i < arr.length; i++) {
		System.out.print(arr[i]);
	}
}
}