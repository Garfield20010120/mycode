//22.5.28���� ���������
//153��һ���ǳ��������������������ÿλ���ֵ������ͣ���153=1*1*1+5*5*5+3*3*3���������������������������λʮ��������
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

