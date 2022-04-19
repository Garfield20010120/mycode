#include<stdio.h>
//22.4.19指针类型的意义 
int main()
{
	int a;
	char b;
	int* p1 = &a;
	char* p2 = &b;
	printf("p1=%p\n",p1);//指针（地址）用%p 
	printf("p1+1=%p\n",p1+1);//int*一次加四个字节 
	printf("p2=%p\n",p2);
	printf("p2+1=%p\n",p2+1);//char*一次加一个字节 
	//指针类型决定了指针一步走多远 
	return 0;
} 
