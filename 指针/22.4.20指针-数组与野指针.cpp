#include<stdio.h>
//22.4.20指针 -数组、野指针 
int main()
{
	//指针+数组 
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
	//野指针
//	int a = 1;
	int* q ;//=&a;
	*q = 20;//野指针——1.未初始化
	int* w = arr;
	for(int i=0;i<20;i++)
	{
		w++;//i>=10时w为野指针——2.指针越界访问 
	}
	//3.指针指向空间释放 
	printf("\n%d",*q);
	return 0;
} 
