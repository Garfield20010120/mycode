#include<iostream>
//22.6.7����Ǳ�� 
using namespace std;
 
//���� 3^x  %5218 - �ݹ� - ����ʱ�����ڴ泬��
int func01(long long int x)
{
	if (x == 0)
		return 1;
	else if (x == 1)
		return 3;
	else if (x == 2)
		return 9;
	else if (x == 3)
		return 27;
 
	long long int x1 = x >> 1;
 
	int temp = func01(x1);
 
	if (x & 1)
		temp = temp * temp * 3;
	else
		temp = temp * temp;
 
	temp %= 5218;
 
	return temp;
}
 
//���� 3^x  %5218 - ����
int func02(long long int x)
{
	int y = 1;
	int sum = 3;//3Ϊ����
 
	while (x)
	{
		if (x & 1)//��y������
			y = y * sum % 5218;
 
		sum = sum * sum % 5218;
		x /= 2;
	}
	return y;
}
 
int main()
{
	long long int N; cin >> N;
 
	long long int x = N % 3;//�ж�2������
 
	long long int y = N / 3;//�ж�3������
 
	int z;
 
	if (N == 1) //���գ����޴��жϣ�N = 1 ʱ ��M = 12
	{
		cout << 1;
		return 0;
	}
 
	if (x == 0)
	{
		z = func02(y);
	}
	else if (x == 1)
	{
		z = func02(y - 1) * 4;
	}
	else // x == 2
	{
		z = func02(y) * 2;
	}
 
	z %= 5218;
 
	cout << z;
 
	return 0;
 
}
 
