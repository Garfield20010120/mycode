#include<stdio.h>//18:50开始  19:10结束 
int main()
{
	int a=0;
	int i=0;
	int b=2021;
	for(i=1;b!=0;i++)
	{
		int c=i;
		for(;c!=0;c=c/10)//不是c/10!!!!! 
		{
			if(c%10==1)//别搞成赋值了！！！！ 先找1 
			b--; 
		}
	}
	printf("%d",i-1);//i出循环会加一 
	return 0;
} 
