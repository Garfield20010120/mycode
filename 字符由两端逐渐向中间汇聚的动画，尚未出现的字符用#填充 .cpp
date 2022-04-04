#include<stdio.h>
#include<string.h>
#include<windows.h>  //sleep声明 
#include<stdlib.h>  //system声明 
//字符由两端逐渐向中间汇聚的动画，尚未出现的字符用#填充 
int main()
{
	char arr1[] = "welcome to my world!";//字符请用char，别用int 
	char arr2[] = "####################";
	int left = 0;
	int right = strlen(arr1)-1;//strlen(arr1)/strlen(arr1[0])-1 中 strlen(arr1[0])出不来 
	while(left<=right)
	{
		printf("%s\n",arr2);
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		Sleep(100);//100ms 
		system("cls");//cls-清空屏幕 
		left++;
		right--;
	}
	printf("%s",arr1);
	return 0;
	
}
