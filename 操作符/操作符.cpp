#include <stdio.h>
//22.4.11 
int main()
{
	double a = 5 / 2.0;
	int b = 5 / 2;//�̣�/��2 �ࣨ%��1
	int c = 5 % 2;//ȡģ����������������Ϊ���� 
	int d = 16 >> 1;//���Ʋ����� �ƶ�������λ 
	printf("a=%lf\nb=%d\nc=%d\nd=%d",a,b,c,d);//double ��%lf ����%d 
	return 0;
}
