#include<stdio.h>
//����n�Ľ׳�
int main()
{
	int n=0;
	int i=0;
	int multi=1;
	scanf("%d",&n);
	for(i=1;i<(n+1);i++)
	{
		printf("%d",i); 
		multi=multi*i;//��������һ�� 
	}
	printf("�׳�Ϊ��%d",multi);
	return 0;
} 
