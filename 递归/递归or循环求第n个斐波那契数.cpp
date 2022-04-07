//求第n个斐波那契数（1 1 2 3 5 8...第三数等于前两数之和）开始时间16：09 结束：17：08 
#include<stdio.h>
/*1.循环（数组）方法 
int feibo(int n)
{
	int i=0;
	int a[100];
	a[1]=1;
	a[2]=1;
	if(n>=3)//开始写成了i>=3导致半天进不了循环 以后要多断点调试 
	for(i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
}
*/
int feibo(int n)//2.循环（交换）方法 
{
	int i=0;
	int a=1;
	int b=1;
	int c=0;
	if(n>=3)
	{
	for(i=3;i<=n;i++)
	{
		c=a+b;
		b=a;
		a=c;
	}
	return c;
	}
	else
	return 0;
}
/*int feibo(int n)//3.递归方法 
{
	if(n<=2)
	return 1;
	else
	return feibo(n-1)+feibo(n-2);
}
*/
int main()
{
	int b=1;
	int n=0;
	scanf("%d",&n);
	b = feibo(n);

	printf("%d",b);
	return 0;
} 

