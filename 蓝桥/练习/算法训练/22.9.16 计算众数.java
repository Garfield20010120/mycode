import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int []array=setArray(n,input);
        int preCount=0;//存储前面出现次数最多的元素的次数
        int element=0;//元素
        for (int i=0;i<n;i++){
            int count=0;//计数
            if (i>0&&array[i]==array[i-1]){//相邻近的元素优先对比是否相等，减少循环次数
                i++;
                if (i==n){//防止数组越界
                    System.out.println(element);
                    return;
                }
            }else {//不等的参加循环比较
                for (int j=0;j<n;j++){
                    if (array[i]==array[j]){
                        count++;//计数
                    }
                }
                //count必须比preCount大才代替掉element
                //就是本次的元素的次数比前面出现次数最多的元素的次数大才可以
                if (preCount<count){
                    element=array[i];
                }
                //更新preCount，存储最大的次数
                preCount= Math.max(preCount,count);
            }
        }
        System.out.println(element);
    }
    //创建数组
    public static int[]setArray(int N,Scanner input){
        int []a=new int[N];
        for (int i=0;i<N;i++){
            a[i]=input.nextInt();
        }
        return a;
    }
}

