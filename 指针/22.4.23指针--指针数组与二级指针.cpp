#include<stdio.h>
//22.4.23-ָ�����������ָ�� 
int main()
{
	int a=12;
	int b=34;
	int c=56;
	int i=0;
	int* arr[]={&a,&b,&c};//ָ�����飨����ΪInt*�� 
	while(i<3)
	{
		printf("%d\n",*arr[i]);
		i++;
	} 
	int** p=&arr[0];
	printf("%d",**p);//����ָ�� 
	return 0;
} 
