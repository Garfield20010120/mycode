#include<iostream>
//22.6.5蓝桥 跳马 
using namespace std;
 
//自定义数据类型
struct MyInt
{
	int x;
	int y;
};
 
//判断是否可去
bool func(int a, int b, int x)
{
	if (1 <= a && a <= 8 && 1 <= b && b <= 8 && x != 1)
	{
		return true;
	}
	return false;
}
 
int main()
{
	int ii[9][9] = { 0 };
 
	int a, b, c, d;
	cin >> a >> b >> c >> d;
 
	ii[c][d] = 2;
 
	int num = 0;
	MyInt mi[200];
	mi[num].x = a;
	mi[num].y = b;
	num++;
 
	int MinSum = -1;
	int left = 0;
 
	//马踏八方
	while (1)
	{
		MinSum++;
		int right = num;
		for (int i = left; i < right; i++)
		{
			if (ii[mi[i].x][mi[i].y] == 2)
			{
				cout << MinSum;
				return 0;
			}
			else if (ii[mi[i].x][mi[i].y] == 0)
			{
				ii[mi[i].x][mi[i].y] = 1;
				if (func(mi[i].x - 2, mi[i].y + 1, ii[mi[i].x - 2][mi[i].y + 1]))
				{
					mi[num].x = mi[i].x - 2;
					mi[num].y = mi[i].y + 1;
					num++;
				}
				if (func(mi[i].x - 1, mi[i].y + 2, ii[mi[i].x - 1][mi[i].y + 2]))
				{
					mi[num].x = mi[i].x - 1;
					mi[num].y = mi[i].y + 2;
					num++;
				}
 
				if (func(mi[i].x + 1, mi[i].y + 2, ii[mi[i].x + 1][mi[i].y + 2]))
				{
					mi[num].x = mi[i].x + 1;
					mi[num].y = mi[i].y + 2;
					num++;
				}
				if (func(mi[i].x + 2, mi[i].y + 1, ii[mi[i].x + 2][mi[i].y + 1]))
				{
					mi[num].x = mi[i].x + 2;
					mi[num].y = mi[i].y + 1;
					num++;
				}
 
				if (func(mi[i].x + 2, mi[i].y - 1, ii[mi[i].x + 2][mi[i].y - 1]))
				{
					mi[num].x = mi[i].x + 2;
					mi[num].y = mi[i].y - 1;
					num++;
				}
				if (func(mi[i].x + 1, mi[i].y - 2, ii[mi[i].x + 1][mi[i].y - 2]))
				{
					mi[num].x = mi[i].x + 1;
					mi[num].y = mi[i].y - 2;
					num++;
				}
 
				if (func(mi[i].x - 1, mi[i].y - 2, ii[mi[i].x - 2][mi[i].y - 2]))
				{
					mi[num].x = mi[i].x - 1;
					mi[num].y = mi[i].y - 2;
					num++;
				}
				if (func(mi[i].x - 2, mi[i].y - 1, ii[mi[i].x - 2][mi[i].y - 1]))
				{
					mi[num].x = mi[i].x - 2;
					mi[num].y = mi[i].y - 1;
					num++;
				}
			}
			left = right;
		}
		//cout << endl;
		//for (int i = 1; i <= 8; i++)
		//{
		//	for (int j = 1; j <= 8; j++)
		//	{
		//		cout << ii[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//system("pause");
	}
 
	return 0;
}
