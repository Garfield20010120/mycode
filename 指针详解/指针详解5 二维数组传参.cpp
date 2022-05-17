#include<stdio.h>
//22.5.17 二维数组传参 
void test(int arr[3][5])
{
	//法一 直接传二位数组
}
void test(int arr[][5])
{
	//法二 可省行不能省列 
} 
void test(int (*arr)[5]) 
{
	//法三 数组指针（传参传的是第一行整行的地址刚好可以用数组指针） 
}
int main()
{
	int arr[3][5]={0};
	test(arr);
	return 0;
}
