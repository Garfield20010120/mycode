#include<stdio.h>
//4.14������&&�߼��롢||�߼���&��λ�롢|��λ�� 
int main()
{
	int a = 5;
	int b = 0;
	int c = 3; 
	printf("a��b:\n%d\n%d\n%d\n%d\n",a&&b,a||b,a&b,a|b);
	printf("a��c:\n%d\n%d\n%d\n%d\n",a&&c,a||c,a&c,a|c);
	//360������
	int i=0,d=0,e=2,f=3,g=4;
	i = d++ && ++b && g++;//��һ��&&���dΪ0���ұ߱㲻���ٽ������㣬����ֻ��һ��d++����1��2��3��4 
	printf("360������𰸣�%d��%d��%d��%d",d,e,f,g);
	return 0;
}
