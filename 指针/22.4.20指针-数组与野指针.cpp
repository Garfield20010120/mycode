#include<stdio.h>
//22.4.20ָ�� -���顢Ұָ�� 
int main()
{
	//ָ��+���� 
	int arr[10] = {0};
	int* p = arr;
	int i = 0;
	for(i=0;i<10;i++)
	{
		*(p + i) = i+1;
	}
	for(i=0;i<10;i++)
	{
	printf("%d",arr[i]);
	}
	//Ұָ��
//	int a = 1;
	int* q ;//=&a;
	*q = 20;//Ұָ�롪��1.δ��ʼ��
	int* w = arr;
	for(int i=0;i<20;i++)
	{
		w++;//i>=10ʱwΪҰָ�롪��2.ָ��Խ����� 
	}
	//3.ָ��ָ��ռ��ͷ� 
	printf("\n%d",*q);
	return 0;
} 
