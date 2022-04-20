#include<stdio.h>
//22.4.21-规避野指针（NULL） 
int main()
{
	//规避野指针 
	int* p =NULL;//NULL（注意大写）可用于给指针初始化 
	int a=10;
	p = &a;
	printf("%d",*p);
	// 
	return 0;
}
