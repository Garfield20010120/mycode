#include<iostream>
//22.6.12蓝桥 算法训练 最大分解
#include<algorithm>
#include<cmath>
 using namespace std;
 const int N = 1e6;
 int a[N];
int main()
{
	int n; cin >> n;
	int i = 0;
	while(a[i ++] != 1) //除数不为1 说明可能可以分解
	{
		for(int j = n - 1; j > 0; j --) //从这个数-1开始计算
		{
			if(n % j == 0 && j != a[i - 1]) //可以整除 不等于上一个数
			{
				n = j;
				a[i] = j;
				break;
			}
		}
	}
	int res = 0;
	while(i) //把除数都加上
	{
		res += a[i--];
	}
	cout <<res;
	return 0;
}

