#include<stdio.h>
int Strlen(const char*str)
{
	if(*str == '\0')
	return 0;//ÿ�ε��÷���һ��ֵ 
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
