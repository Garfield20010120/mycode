#include<stdio.h>
//����������������ѡ�����򣻿�ʼʱ�䣺15��59������ʱ�� :
int main()
{
	int a=0;
	int i=0;
	int j=0;
	int k=0;
	int l=0; 
	int arr1[200];
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
	scanf("%d",&arr1[i]);//scanfҪȡ��ַ(&)���� 
	}
	for(i=0;i<a-1;i++)
	{
		k=i;
		for(j=i+1;j<a;j++)
		{
			if(arr1[k]>arr1[j])
			k=j;
		}
		if(k!=i)//����λ�ö�����ֱ�Ӹ�ֵ 
		{
		l=arr1[i];
		arr1[i]=arr1[k];
		arr1[k]=l;
		}
	}
	for(i=0;i<a;i++)
	{
		printf("%d ",arr1[i]);
	}
//	printf("%s",arr1);//д������ֻ��ѭ��һ������������ֱ�Ӷ��ַ��� 
	return 0;
}
