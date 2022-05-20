#include<stdio.h>
//22.5.20函数指针数组 
int Add(int x,int y)
{
	int z=x+y;
	return z;
}
int Sub(int x,int y)
{
	int z=x-y;
	return z;
}
int Mul(int x,int y)
{
	int z=x*y;
	return z;
}
int Div(int x,int y)
{
	int z=x/y;
	return z;
}
int main()
{
	int (*p[4])(int,int)={Add,Sub,Mul,Div};
	int i=0;
	for(i=0;i<4;i++)
	{
		printf("%d\n",p[i](2,3));
	}
	return 0;
} 
