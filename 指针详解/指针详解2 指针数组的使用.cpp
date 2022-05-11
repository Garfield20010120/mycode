#include<stdio.h>
//22.5.11指针详解-数组指针 
int main()
{
	int arr1[]={1,2,3,4,5};
	int arr2[]={1,3,4,5,8};
	int arr3[]={2,4,8,2,5};
	int* arr4[]={arr1,arr2,arr3};
	for(int i=0;i<3;i++)//别忘了给i初始化，别给初始化、条件判断、调整搞混了 
	 {
	 	for(int j=0;j<5;j++)
	 	{
	 		printf("%d ",*(arr4[i]+j));
	 	}
	 	printf("\n");
	 }
	 return 0; 
} 
