#include <stdio.h>
//22.6.22 ���� 쳲�������
#include <iostream>
using namespace std;
#include <string>
typedef long long LL;
 
LL res[100] = { 0 };
 
//sΪ���⴮
string s, s0, s1 = "0", s2 = "1";
 
//���� + �ݹ飬�м���ĵݹ� ��쳲����������� F( x )
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
 
	for (int i = 2; i <= 23; i++)	//���㵽23��s0
	{
		s0 = s1 + s2;			//ƴ��
		s1 = s2;
		s2 = s0;
 
		//����쳲�����������ÿһλ����
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
 
	//��ʼ��쳲���������
	cout <<F( n + 1 - flag) << endl;
	return 0;
}
