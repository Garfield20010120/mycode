#include<stdio.h>
//22.5.13����ָ���ʹ�� 
void print1(int arr[3][5])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%d",a[i][j])
		}
	printf("\n");
	}
} 

int main()
{
	int a[3][5]={{1,2,3,4,5},{1,4,5,8,9},{4,5,6,2,7}}//�������У��п�ʡ�ԡ��в��У� 
	print1(&a);//��ά����ʵ�����Ǵ���������һ�еĵ�ַ��ȥ 
	return 0;
} 
