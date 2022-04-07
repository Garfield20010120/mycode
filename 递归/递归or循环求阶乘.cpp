//递归求阶乘 开始：15：45 结束 14：01 
#include<stdio.h>
/*循环方法求阶乘 
int chen(int x)
{
	int a = 1;
	for(int i=1;i<=x;i++)
	{
		a = i * a;
	}
	return a;
}
*/
int chen(int x)
{
	if(x<=1)//开始打的x=0跑不出来因为一个=是赋值，两个才是等于！！！！ 
	return 1;
	else
	return (x*chen(x-1));
}
 
int main()
{
	int a = 0;
	int multi = 0;
	scanf("%d",&a);
	multi = chen(a);
	printf("%d阶乘为：%d",a,multi);
	return 0;	
} 
