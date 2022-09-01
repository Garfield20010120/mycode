import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        if(T>1000) 
            System.exit(0);
        while(T>0) {
            int n = in.nextInt();
            int[] a = new int[n];
            int[] b = new int[n];
            for(int i=0;i<n;i++) {
                a[i] = in.nextInt();
            }
            for(int i=0;i<n;i++) {
                b[i] = in.nextInt();
            }

            int k1 = 0;
            int k2 = 0;
            for(int i=0;i<n;i++) {
                for(int j=i+1;j<n;j++) {
                    if(a[j]<a[i]) {
                        k1 = a[i];
                        a[i] = a[j];
                        a[j] = k1;
                    }
                }
            }

            for(int i=0;i<n;i++) {
                for(int j=i+1;j<n;j++) {
                    if(b[j]>b[i]) {
                        k2 = b[i];
                        b[i] = b[j];
                        b[j] = k2;
                    }
                }
            }


            int sum = 0;
            for(int i=0;i<n;i++) {
                sum += a[i]*b[i];
            }
            System.out.println(sum);
            T--;

        }
        in.close();
    }
}
