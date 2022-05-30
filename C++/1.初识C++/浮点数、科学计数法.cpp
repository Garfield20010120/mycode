#include<iostream>
//22.5.30浮点数、科学计数法 
using namespace std;
int main()
{
	float a=3.14f;//f使3.14的类型置为单精度浮点数，默认为d双精度 
	double b =3.14;
	double c=3.1415926;//浮点数小数只显示六位有效数字 
	cout<<"a=" <<a<<endl;
	cout<<"b=" <<b<<endl;
	cout<<"c=" <<c<<endl;
	float d = 3e2;
	float e = 3e-2;
	cout<<"d=" <<d<<endl;
	cout<<"e=" <<e<<endl;
	return 0;
}
