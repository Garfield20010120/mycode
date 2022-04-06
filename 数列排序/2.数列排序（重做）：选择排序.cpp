#include<stdio.h>
//数列排序（重做）：选择排序；开始时间：15：59，结束时间 :
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
		k=i;
		for(j=i+1;j<a;j++)
		{
			if(arr1[k]>arr1[j])
			k=j;
		}
		if(k!=i)//交换位置而不是直接赋值 
		{
		l=arr1[i];
		arr1[i]=arr1[k];
		arr1[k]=l;
		}
	}
	for(i=0;i<a;i++)
	{
		printf("%d ",arr1[i]);
	}
//	printf("%s",arr1);//写法错误，只能循环一个个读，不能直接读字符串 
	return 0;
}
