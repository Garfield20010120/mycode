#include<stdio.h>
//5.15ָ��������ļ��ֱ��ת�� 
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int i=0;
	int*p=arr;//arr�൱��&arr[0]����ָ��pָ��ı���arr[0]��ĳ����������˵arr��ͬ��p 
	for(i=0;i<10;i++)
	{
		//���ֱ�����ͬ 
		printf("%d ",p[i]);
		printf("%d ",*(p+i));
		printf("%d ",arr[i]);
		printf("%d ",*(arr+i)); 
	}
	return 0;
} 
