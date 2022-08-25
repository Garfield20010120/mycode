#include<stdio.h>
int sum=0;//方案数
void fun(int m,int n,int num); 
int main()
{
	int m,n; 
	scanf("%d%d",&m,&n);
	fun(m,n,0);//递归
	printf("%d",sum);
	return 0;
}
void fun(int m,int n,int num)//num是体育组可租的鞋数
{
	if(num<0||m<0||n<0)
	{
		return;
	}
	if(m==0&&n==0)
	{
		sum++;return;
	}
	fun(m-1,n,num+1);
	fun(m,n-1,num-1);
} 
