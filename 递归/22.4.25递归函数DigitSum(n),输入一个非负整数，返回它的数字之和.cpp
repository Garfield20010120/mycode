#include<stdio.h>
//22.4.25дһ���ݹ麯��DigitSum(n),����һ���Ǹ�������������������֮��  eg.����1729����19 
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
