#include<iostream>
//22.7.13 蓝桥 三角形面积
#include<cstdio>
using namespace std;
 
int main(){
	int a, h, s;
	scanf("%d %d", &a, &h);
	s=a*h;
	if(s%2==0){
		printf("%d", s/2);
	} 
	else{
		printf("%.1f", s/2.0);
	}
	return 0;
}