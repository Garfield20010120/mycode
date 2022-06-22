#include <stdio.h>
//22.6.22 蓝桥 斐波那契串
#include <iostream>
using namespace std;
#include <string>
typedef long long LL;
 
LL res[100] = { 0 };
 
//s为待测串
string s, s0, s1 = "0", s2 = "1";
 
//数组 + 递归，有记忆的递归 求斐波那契型数列 F( x )
LL F(int x)
{
	if (x == 0 || x == 1)
	{
		res[x] = x;
		return res[x];
	}
	if(res[x - 1] != 0 && res[x-2] != 0)
		res[x] = res[x - 1] + res[x - 2] + 1;
	else
		res[x] = F(x - 1) + F(x - 2) + 1;
	return res[x];
}
 
int main( )
{
	LL n;
	cin >> n >> s;
	int flag = 0;
	
	s1 = "0", s2 = "1";
 
	for (int i = 2; i <= 23; i++)	//先算到23的s0
	{
		s0 = s1 + s2;			//拼接
		s1 = s2;
		s2 = s0;
 
		//对于斐波那契数串的每一位数字
		for (int j = 0; j < (int)(s0.length() - s.length()); j++)
		{
			if (s == s0.substr(j, s.length()))
			{
				flag = i;
				break;
			}
		}
		if (flag == i)
			break;
	}
 
	//开始求斐波那契数列
	cout <<F( n + 1 - flag) << endl;
	return 0;
}
