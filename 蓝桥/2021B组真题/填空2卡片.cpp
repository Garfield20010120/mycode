#include<stdio.h>//18:50��ʼ  19:10���� 
int main()
{
	int a=0;
	int i=0;
	int b=2021;
	for(i=1;b!=0;i++)
	{
		int c=i;
		for(;c!=0;c=c/10)//����c/10!!!!! 
		{
			if(c%10==1)//���ɸ�ֵ�ˣ������� ����1 
			b--; 
		}
	}
	printf("%d",i-1);//i��ѭ�����һ 
	return 0;
} 
