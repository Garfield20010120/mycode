#include<stdio.h>
//计算1！+2！+3！+....+10！ 
int main()
{
	int n=0;
	int i=0;
	int multi=1;
	int sum=0;
	for(n=1;n<=10;n++)
	{
	for(i=1,multi=1;i<(n+1);i++)//条件里面不要忘了multi的初始化 
	{
//		printf("%d",i); 
		multi=multi*i;//这里想了一会 
	}
	printf("%d的阶乘为：%d\n",n,multi);
	sum=sum+multi;
	}
	printf("阶乘之和为：%d",sum);
	return 0;
}
