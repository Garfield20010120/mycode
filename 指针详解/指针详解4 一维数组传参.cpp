#include <stdio.h>
22.5.16һά���鴫�� 
//��ͨһά�������飨����Ԫ�ص�ַ�� 
void test(int arr[])
{//��һ�� 
} 

void test(int *arr)
{//�ڶ��� 
} 

void test(int arr[10])
{//������ 
} 

// ָ������ 
void test1(int* arr[])
{//��һ�� 
} 

void test1(int** arr)
{//�ڶ��� 
} 

int main()
{
	int arr[10]={0};
	int* arr1[20]={0}; 
//	test(arr);
	test1(arr1); 
	return 0;
} 
