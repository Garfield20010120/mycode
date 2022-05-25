#include<iostream>
//22.5.26常量 
using namespace std;
#define day 7//宏常量 
int main()
{
	cout<<"一周共有"<<day<<"天"<<endl;
	const int month = 12;//const修饰的常量 
	cout<<"一年共有"<<month<<"个月"<<endl;
	return 0;
} 
