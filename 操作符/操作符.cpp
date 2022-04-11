#include <stdio.h>
//22.4.11 
int main()
{
	double a = 5 / 2.0;
	int b = 5 / 2;//商（/）2 余（%）1
	int c = 5 % 2;//取模的两个操作数必须为整数 
	int d = 16 >> 1;//右移操作符 移动二进制位 
	printf("a=%lf\nb=%d\nc=%d\nd=%d",a,b,c,d);//double 用%lf 不是%d 
	return 0;
}
