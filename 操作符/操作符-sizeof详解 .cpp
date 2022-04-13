//22.4.13操作符-sizeof详解 
#include<stdio.h>
int main()
{
	int arr[10];
	printf("%d\n",sizeof(int [10]));//40：int [10]是arr的类型 
	
	short a = 0;
	int b = 10;
	int c = a + b;//c=10
	int d = sizeof(a = a + b);//d=2:sizeof返回的是short类型（2） 
	printf("a=%d\nc=%d\nd=%d\n",a,c,d);//a仍为0：sizeof里的表达式不参与运算 
	return 0;
} 
