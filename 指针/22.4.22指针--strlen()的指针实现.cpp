#include<stdio.h>
//22.4.22ָ��--strlen()��ָ��ʵ�� 23:18-23.29
int mystrlen(char* x)
{
	char* first=&x[0];
	char* end=&x[0];
	for(;*end!='\0';end++)//�ǵý����� 
	{
		;
	}
	return (end-first);
}
int main()
{
	char arr[] = "hello world!";//�洢��hello world!\0
	int len = mystrlen(arr);
	printf("%d",len);
	return 0;
}
