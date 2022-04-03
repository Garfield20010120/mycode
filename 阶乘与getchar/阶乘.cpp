#include<stdio.h>
//计算n的阶乘
int main()
{
	int n=0;
	int i=0;
	int multi=1;
	scanf("%d",&n);
	for(i=1;i<(n+1);i++)
	{
		printf("%d",i); 
		multi=multi*i;//这里想了一会 
	}
	printf("阶乘为：%d",multi);
	return 0;
} 
