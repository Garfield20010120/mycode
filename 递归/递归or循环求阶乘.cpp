//�ݹ���׳� ��ʼ��15��45 ���� 14��01 
#include<stdio.h>
/*ѭ��������׳� 
int chen(int x)
{
	int a = 1;
	for(int i=1;i<=x;i++)
	{
		a = i * a;
	}
	return a;
}
*/
int chen(int x)
{
	if(x<=1)//��ʼ���x=0�ܲ�������Ϊһ��=�Ǹ�ֵ���������ǵ��ڣ������� 
	return 1;
	else
	return (x*chen(x-1));
}
 
int main()
{
	int a = 0;
	int multi = 0;
	scanf("%d",&a);
	multi = chen(a);
	printf("%d�׳�Ϊ��%d",a,multi);
	return 0;	
} 
