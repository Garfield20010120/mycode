#include<stdio.h>
//��ʼʱ�䣺14��45������ʱ�� :15:11���������Ƶ��ԣ�15��42������ȷ��ojֻ����42/100 
int main()
{
	int a=0;
	int i=0;
	int j=0;
	int k=0;
	int arr1[200];
	int arr2[200];
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
	scanf("%d",&arr1[i]);//scanfҪȡ��ַ(&)���� 
	}
//��ӡ����	for(i=0;i<a;i++)
//	{
//		printf("%d ",arr1[i]);
//	}
	for(i=0;i<a;i++)
	{int j=0,k=0;
		for(;j<a;j++)//����int j=0,int k=0
		{
		if (arr1[i]>arr1[j])
		k++;
		}
//kֵ����		printf("%d ",k);
	arr2[k]=arr1[i];
	}
	for(i=0;i<a;i++)
	{
		printf("%d ",arr2[i]);
	}
//	printf("%s",arr1);//д������ֻ��ѭ��һ������������ֱ�Ӷ��ַ��� 
//	printf("%s",arr2);
	return 0;
}
