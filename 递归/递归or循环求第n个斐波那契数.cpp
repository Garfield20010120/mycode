//���n��쳲���������1 1 2 3 5 8...����������ǰ����֮�ͣ���ʼʱ��16��09 ������17��08 
#include<stdio.h>
/*1.ѭ�������飩���� 
int feibo(int n)
{
	int i=0;
	int a[100];
	a[1]=1;
	a[2]=1;
	if(n>=3)//��ʼд����i>=3���°��������ѭ�� �Ժ�Ҫ��ϵ���� 
	for(i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
}
*/
int feibo(int n)//2.ѭ�������������� 
{
	int i=0;
	int a=1;
	int b=1;
	int c=0;
	if(n>=3)
	{
	for(i=3;i<=n;i++)
	{
		c=a+b;
		b=a;
		a=c;
	}
	return c;
	}
	else
	return 0;
}
/*int feibo(int n)//3.�ݹ鷽�� 
{
	if(n<=2)
	return 1;
	else
	return feibo(n-1)+feibo(n-2);
}
*/
int main()
{
	int b=1;
	int n=0;
	scanf("%d",&n);
	b = feibo(n);

	printf("%d",b);
	return 0;
} 

