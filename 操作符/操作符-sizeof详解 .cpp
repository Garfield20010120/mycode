//22.4.13������-sizeof��� 
#include<stdio.h>
int main()
{
	int arr[10];
	printf("%d\n",sizeof(int [10]));//40��int [10]��arr������ 
	
	short a = 0;
	int b = 10;
	int c = a + b;//c=10
	int d = sizeof(a = a + b);//d=2:sizeof���ص���short���ͣ�2�� 
	printf("a=%d\nc=%d\nd=%d\n",a,c,d);//a��Ϊ0��sizeof��ı��ʽ���������� 
	return 0;
} 
