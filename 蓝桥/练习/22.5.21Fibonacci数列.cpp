#include<iostream>
//22.5.21蓝桥基础 Fibonacci数列 
//Fibonacci数列的递推公式为：Fn=Fn-1+Fn-2，其中F1=F2=1。
//当n比较大时，Fn也非常大，现在我们想知道，输入一个n，Fn除以10007的余数是多少。 
using namespace std;
int fib(int N) {
 if (N <= 0) return 0;   //判断n是否小于等于零
 if (N == 1 || N == 2) return 1;//假如数列只有一项或者两项的时候，函数返回值应该为1
 int a = 1, b = 1;   //当n>2时，变量a保存的是F(n-2)项的值，变量b保存的是F(n-1)的值
 for (int i = 3; i <= N; i++) //循环计算第n项的值
 {
  int c = (a + b) % 10007;  //见下面详细解释
  a = b;
  b = c;
 }
 return b;
}
int main()
{
 int n;
 cin >> n;
 //cout << fibonacci(10) << endl;
 cout << fib(n) << endl;
 //cout << fibonacci(10007) << endl;
 while (1);
 return 0;
}

