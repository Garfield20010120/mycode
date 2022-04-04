#include<stdio.h>
//有序数组查找数字位置（遍历法） 时间复杂度（n） 
int main()
{
	int arr[]={1,2,4,6,8,9,13,18};
	int sz =sizeof(arr)/sizeof(arr[0]); 
	int target=0;
	printf("请输入您想查找的数字:");
	scanf("%d",&target);
	int left=0;
	int right =sz-1;
	for(;left<=right;left++)//或while（left<=right） 
	{
		if(arr[left]==target)
		{
			printf("找到了，下标为%d",left);
			break;
		}
	}
	if(left>right)
	printf("该数组无该数字\n");
	return 0;
}
