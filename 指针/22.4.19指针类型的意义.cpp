#include<stdio.h>
//22.4.19ָ�����͵����� 
int main()
{
	int a;
	char b;
	int* p1 = &a;
	char* p2 = &b;
	printf("p1=%p\n",p1);//ָ�루��ַ����%p 
	printf("p1+1=%p\n",p1+1);//int*һ�μ��ĸ��ֽ� 
	printf("p2=%p\n",p2);
	printf("p2+1=%p\n",p2+1);//char*һ�μ�һ���ֽ� 
	//ָ�����;�����ָ��һ���߶�Զ 
	return 0;
} 
