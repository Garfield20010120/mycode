#include<stdio.h>
//22.4.21-���Ұָ�루NULL�� 
int main()
{
	//���Ұָ�� 
	int* p =NULL;//NULL��ע���д�������ڸ�ָ���ʼ�� 
	int a=10;
	p = &a;
	printf("%d",*p);
	// 
	return 0;
}
