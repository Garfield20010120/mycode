#include<iostream>
//22.5.21���Ż��� Fibonacci���� 
//Fibonacci���еĵ��ƹ�ʽΪ��Fn=Fn-1+Fn-2������F1=F2=1��
//��n�Ƚϴ�ʱ��FnҲ�ǳ�������������֪��������һ��n��Fn����10007�������Ƕ��١� 
using namespace std;
int fib(int N) {
 if (N <= 0) return 0;   //�ж�n�Ƿ�С�ڵ�����
 if (N == 1 || N == 2) return 1;//��������ֻ��һ����������ʱ�򣬺�������ֵӦ��Ϊ1
 int a = 1, b = 1;   //��n>2ʱ������a�������F(n-2)���ֵ������b�������F(n-1)��ֵ
 for (int i = 3; i <= N; i++) //ѭ�������n���ֵ
 {
  int c = (a + b) % 10007;  //��������ϸ����
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

