#include <stdio.h>
22.5.16一维数组传参 
//普通一维整型数组（传首元素地址） 
void test(int arr[])
{//第一种 
} 

void test(int *arr)
{//第二种 
} 

void test(int arr[10])
{//第三种 
} 

// 指针数组 
void test1(int* arr[])
{//第一种 
} 

void test1(int** arr)
{//第二种 
} 

int main()
{
	int arr[10]={0};
	int* arr1[20]={0}; 
//	test(arr);
	test1(arr1); 
	return 0;
} 
