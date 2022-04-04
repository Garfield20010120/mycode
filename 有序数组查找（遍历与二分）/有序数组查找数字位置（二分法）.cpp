#include<stdio.h>
//有序数组查找数字位置（二分法） 时间复杂度（log2（n）） 
int main()
{
	int arr[]={1,2,4,6,8,9,13,18};
	int sz =sizeof(arr)/sizeof(arr[0]); 
	int target=0;
	printf("请输入您想查找的数字:");
	scanf("%d",&target);
	int left=0;
	int right =sz-1;
	for(;left<=right;)//或while（left<=right） 
	{
		int mid= (left+right)/2;
		if (arr[mid]>target)
			{
				right=mid-1;
			}
		else if(arr[mid]<target)
			{
				left=mid+1;
			}
		else if(arr[mid]==target)//注意=和==的区别 
			{
				printf("找到了，下标为：%d\n",mid);
				break;//别忘了出循环 
			}
	}
	if(left>right)
	printf("该数组无该数字\n");
	return 0;
}
