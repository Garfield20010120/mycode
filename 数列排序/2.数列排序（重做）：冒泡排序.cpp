#include<stdio.h>
//数列排序（重做）：冒泡排序；开始时间：16：23，结束时间 :16:
int main()
{
	int a=0;
	int i=0;
	int j=0;
	int k=0;
	int l=0; 
	int arr1[200];
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
	scanf("%d",&arr1[i]);//scanf要取地址(&)！！ 
	}
	for(i=0;i<a-1;i++)
	{
		for(j=0;j<a-1-i;j++)
		{ 
			if(arr1[j]>arr1[j+1])
			{
			l=arr1[j];
			arr1[j]=arr1[j+1];
			arr1[j+1]=l;
			}
		}
	}
	for(i=0;i<a;i++)
	{
		printf("%d ",arr1[i]);
	}
//	printf("%s",arr1);//写法错误，只能循环一个个读，不能直接读字符串 
	return 0;
}
