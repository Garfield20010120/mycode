#include<stdio.h>
//����1��+2��+3��+....+10�� 
int main()
{
	int n=0;
	int i=0;
	int multi=1;
	int sum=0;
	for(n=1;n<=10;n++)
	{
	for(i=1,multi=1;i<(n+1);i++)//�������治Ҫ����multi�ĳ�ʼ�� 
	{
//		printf("%d",i); 
		multi=multi*i;//��������һ�� 
	}
	printf("%d�Ľ׳�Ϊ��%d\n",n,multi);
	sum=sum+multi;
	}
	printf("�׳�֮��Ϊ��%d",sum);
	return 0;
}
