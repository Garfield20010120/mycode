//22.5.28蓝桥 特殊的数字
//153是一个非常特殊的数，它等于它的每位数字的立方和，即153=1*1*1+5*5*5+3*3*3。编程求所有满足这种条件的三位十进制数。
#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
for(int i=100;i<=999;i++)
{
	a=i%10;
	b=i/10%10;
	c=i/100;
	
	if(a*a*a+b*b*b+c*c*c==i)
		cout<<i<<endl;

}
	return 0;
}

