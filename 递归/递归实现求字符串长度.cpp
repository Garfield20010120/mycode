#include<stdio.h>
int Strlen(const char*str)
{
	if(*str == '\0')
	return 0;//每次调用返回一个值 
	else
	return 1+Strlen(str+1);
} 
int main()
{
	const char*p="abcdef";
	int len=Strlen(p);
	printf("%d\n",len);
	return 0;
}
