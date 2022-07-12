#include<stdio.h>
#include<stack>//使用栈的头文件 
#include<cctype>//判断是否是数字的头文件
using namespace std;//将所有变量名字储存在std这个空间里，避免和系统变量名发生冲突 
int a,b,temp;
char str[50];
int f(int x,int y)//二元函数 
{
	return a*x+b*y;
}
int getNumber(int i,bool m)//i是当前下标，m用于判断是否为负数 
{
	int num=0;
	for(;isdigit(str[i]);i++)//判断是否为数字
	{
		num=num*10+str[i]-'0';//从最高位开始往后加 
	} 
	temp=i;//数字存完之后i要跳到后面
	if(m)//判断是否为负数
	{
		num=-num;
	} 
	return num;
}
int main()
{
	scanf("%d%d\n",&a,&b);
	gets(str);
	stack<int> num;//创建一个栈用来储存x和y 
	num.push(0);//先初始化 
	for(int i=0;i<50;i++)
	{
		if(str[i]=='-')
		{
			i++;
			num.push(getNumber(i,true));//true表示是负数，让负号和后面的数字进栈
			i=temp; 
		}
		else if(isdigit(str[i]))
		{
			num.push(getNumber(i,false));//正数进栈
			i=temp; 
		}
		if(str[i]==')')//当一次函数的xy已经都进栈后需要调用二次函数 
		{
			int y=num.top();
			num.pop();
			int x=num.top();
			num.pop();
			num.push(f(x,y));//把结果输入进栈作为下一次函数的参数 
		}
	}
	printf("%d",num.top());
	return 0;
}
