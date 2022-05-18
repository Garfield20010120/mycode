#include<stdio.h>
//22.5.18指针详解6 函数指针 
int Add(int x,int y)
{
	int z=x+y;
	return z;
}

void Print(char* str)
{
	printf("%s",str);
}
int main()
{
	int a=1;
	int b=2;
	char str[]="abcde";
	int (*p)(int,int)=Add;//&函数名 与 函数名均为函数地址 
	void (*p1)(char*)=Print;
	printf("%d\n",(*p)(a,b));
	(*p1)(str);
	return 0;
} 
