
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int s[] = new int[2];
        s[0] = input.nextInt();
        s[1] = input.nextInt();
        int sw[] = new int[2];
        sw = swap(s);
        System.out.println(sw[0] + " " + sw[1]);
    }

    public static int[] swap(int s[]) {
        int t;
        t = s[0];
        s[0] = s[1];
        s[1] = t;
        return s;
    }
}

