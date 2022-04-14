#include<stdio.h>
//4.14操作符&&逻辑与、||逻辑或、&按位与、|按位或 
int main()
{
	int a = 5;
	int b = 0;
	int c = 3; 
	printf("a与b:\n%d\n%d\n%d\n%d\n",a&&b,a||b,a&b,a|b);
	printf("a与c:\n%d\n%d\n%d\n%d\n",a&&c,a||c,a&c,a|c);
	//360笔试题
	int i=0,d=0,e=2,f=3,g=4;
	i = d++ && ++b && g++;//第一个&&左边d为0，右边便不会再进行运算，所以只有一个d++，答案1、2、3、4 
	printf("360笔试题答案：%d、%d、%d、%d",d,e,f,g);
	return 0;
}
