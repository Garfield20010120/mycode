#include<stdio.h>
//22.5.13数组指针的使用 
void print1(int arr[3][5])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d",a[i][j])
		}
	printf("\n");
	}
} 

int main()
{
	int a[3][5]={{1,2,3,4,5},{1,4,5,8,9},{4,5,6,2,7}}//三行五列（行可省略、列不行） 
	print1(&a);//二维数组实际上是传了整个第一行的地址过去 
	return 0;
} 
