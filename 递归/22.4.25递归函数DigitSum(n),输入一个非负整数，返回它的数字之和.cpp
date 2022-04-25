#include<stdio.h>
//22.4.25写一个递归函数DigitSum(n),输入一个非负整数，返回它的数字之和  eg.输入1729返回19 
int DigitSum(unsigned int num)
{
	if(num>9)
	{
		return DigitSum(num / 10)+num%10;
	}
	else
	{
		return num;
	}
}

int main()
{
	unsigned int num = 0;
	scanf("%d",&num);
	int ret = DigitSum(num);
	printf("ret=%d\n",ret);
	return 0;
}
