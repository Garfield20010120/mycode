#include<stdio.h>
//22.5.5数据存储1设计小程序来判断当前机器的字节序 （大端or小端） 
int check()
{
	int a=1;
	return (*(char*)&a);
} 

int main()
{
	int ret=check();
	if(ret==1)
	{
		printf("小端\n");
	} 
	else
	{
		printf("大端\n");
	}
	return 0;
} 
