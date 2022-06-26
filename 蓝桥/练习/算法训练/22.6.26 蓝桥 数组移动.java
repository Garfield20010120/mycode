import java.util.LinkedList;
import java.util.Scanner;
 
public class Main {
    static LinkedList<Integer> list = new LinkedList<>();
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), M = sc.nextInt();
        int[] arr = new int[N];
        int[] m = new int[M];
        for (int i = 0; i < N; i++) {
            arr[i] = i + 1;
            list.add(i + 1);
        }
 
        for (int i = 0; i < M; i++) {
            m[i] = sc.nextInt();
        }
 
        arr = fun(m[M - 1]);
 
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
 
    public static int[] fun(int i) {
        for (int j = 0, k = 0; j < list.size(); j++) {
            if (list.get(k) <= i) {
                list.add(list.remove(k));
            } else {
                k++;
            }
        }
 
        return list.stream().mapToInt(Integer::valueOf).toArray();
    }
 
}