#include<stdio.h>
//22.5.5���ݴ洢1���С�������жϵ�ǰ�������ֽ��� �����orС�ˣ� 
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
		printf("С��\n");
	} 
	else
	{
		printf("���\n");
	}
	return 0;
} 
