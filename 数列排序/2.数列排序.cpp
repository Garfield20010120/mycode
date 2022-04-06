#include<stdio.h>
//开始时间：14：45，结束时间 :15:11上网找相似调试；15：42测试正确；oj只得了42/100 
int main()
{
	int a=0;
	int i=0;
	int j=0;
	int k=0;
	int arr1[200];
	int arr2[200];
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
	scanf("%d",&arr1[i]);//scanf要取地址(&)！！ 
	}
//打印测试	for(i=0;i<a;i++)
//	{
//		printf("%d ",arr1[i]);
//	}
	for(i=0;i<a;i++)
	{int j=0,k=0;
		for(;j<a;j++)//不是int j=0,int k=0
		{
		if (arr1[i]>arr1[j])
		k++;
		}
//k值测试		printf("%d ",k);
	arr2[k]=arr1[i];
	}
	for(i=0;i<a;i++)
	{
		printf("%d ",arr2[i]);
	}
//	printf("%s",arr1);//写法错误，只能循环一个个读，不能直接读字符串 
//	printf("%s",arr2);
	return 0;
}
