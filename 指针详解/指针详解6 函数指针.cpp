#include<stdio.h>
//22.5.18ָ�����6 ����ָ�� 
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
	int (*p)(int,int)=Add;//&������ �� ��������Ϊ������ַ 
	void (*p1)(char*)=Print;
	printf("%d\n",(*p)(a,b));
	(*p1)(str);
	return 0;
} 
