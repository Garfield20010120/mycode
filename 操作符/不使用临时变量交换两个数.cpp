//4.12不使用临时变量交换两个数 
#include<stdio.h>
int main()
{
	int a=10;
	int b=20;
/*加减法交换——缺陷:可能溢出 
	a=a+b;
	b=a-b;
	a=a-b;
*/
//操作符交换——用异或交换(不会溢出 ∵不会进位)，但平时工作还是用临时变量（可读性高且效率高） 
	a=a^b;
	b=a^b;//b=a^b^b==a
	a=a^b;//a=a^b^a==b
		//a^a=0 b^b=0 n^0=n
	printf("a=%d,b=%d",a,b); 
	return 0;
} 
