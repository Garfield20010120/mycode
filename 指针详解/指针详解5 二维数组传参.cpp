#include<stdio.h>
//22.5.17 ��ά���鴫�� 
void test(int arr[3][5])
{
	//��һ ֱ�Ӵ���λ����
}
void test(int arr[][5])
{
	//���� ��ʡ�в���ʡ�� 
} 
void test(int (*arr)[5]) 
{
	//���� ����ָ�루���δ����ǵ�һ�����еĵ�ַ�պÿ���������ָ�룩 
}
int main()
{
	int arr[3][5]={0};
	test(arr);
	return 0;
}
