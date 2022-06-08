#include<iostream>
//22.6.8蓝桥杯 娜神平衡
using namespace std;
#include<algorithm>
 
//数量n，限制r
int n, r;
 
//左堆，左堆数量
int L[101] = { 0 }; int L_ = 0;
//右堆，右堆数量
int R[101] = { 0 }; int R_ = 0;
 
//原始数据
int date[101] = { 0 };
//标记对应数据状态：已选 或 未选
bool ind[101] = { 0 };
 
//打印数组 - 无回车
void print(int ii[], int n)
{
	for (int i = 1; i <= n; i++)
		cout << ii[i] << " ";
	return;
}
 
//递归调用
bool func(int L_R = 0)
{
	//差值(绝对值)
	int temp = L_R > 0 ? L_R : -L_R;
 
	//若绝对值超出，则结束(注意temp不要去绝对值啊)
	if (temp > r)
	{
		return false;
	}
 
	//当所有数据都能用上时 - 就代表可以结束了
	if (L_ + R_ == n)
	{
		//排序 - 升序
		sort(L + 1, L + L_);
		sort(R + 1, R + R_);
 
		//寻找第一个数据
		for (int i = 1; i <= L_; i++)
		{
			if (date[1] == L[i])
			{
				print(L, L_);
				cout << endl;
				print(R, R_);
				return true;
			}
		}
		print(R, R_);
		cout << endl;
		print(L, L_);
		return true;
	}
 
	int i;
	for (i = 1; i <= n; i++)
	{
		//检查状态：若没有使用(false)
		if (!ind[i])
		{
			//标记为已使用(true)
			ind[i] = true;
 
			//加给左堆
			L[++L_] = date[i];
			//选定之后，往后继续
			if (func(L_R + date[i]))
				break;
 
			//取出
			L[L_] = 0;
			L_--;
 
			//加给右堆
			R[++R_] = date[i];
			//选定之后，往后继续
			if (func(L_R - date[i]))
				break;
 
			//取出
			R[R_] = 0;
			R_--;
 
			//就当无事发生
			ind[i] = false;
		}
	}
	//若能走到这里，i能到n：返回1；i没到n，返回0
	//告诉上层的判断：该层及其以下 递归能不能遍历完 所有的元素
	return !(i == n + 1);
}
 
 
int main()
{
	cin >> n >> r;
 
	//输入数据
	for (int i = 1; i <= n; i++)
		cin >> date[i];
 
	//开始递归
	func();
 
	return 0;
}
