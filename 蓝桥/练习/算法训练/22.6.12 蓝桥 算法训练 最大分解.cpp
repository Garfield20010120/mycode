#include<iostream>
//22.6.12���� �㷨ѵ�� ���ֽ�
#include<algorithm>
#include<cmath>
 using namespace std;
 const int N = 1e6;
 int a[N];
int main()
{
	int n; cin >> n;
	int i = 0;
	while(a[i ++] != 1) //������Ϊ1 ˵�����ܿ��Էֽ�
	{
		for(int j = n - 1; j > 0; j --) //�������-1��ʼ����
		{
			if(n % j == 0 && j != a[i - 1]) //�������� ��������һ����
			{
				n = j;
				a[i] = j;
				break;
			}
		}
	}
	int res = 0;
	while(i) //�ѳ���������
	{
		res += a[i--];
	}
	cout <<res;
	return 0;
}

