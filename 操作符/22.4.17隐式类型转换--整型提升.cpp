#include<stdio.h>
//22.4.17��ʽ����ת��--�������� 
int main()
{
	char a = 0xa6;
	short b = 0xa600;//short��ӡ��%hd(longlong��%lld) 
	int c = 0xa60000;
	printf("a=%c\nb=%hd\nc=%d\n",a,b,c) ;//�����
	if(a==0xa6)
	printf("a!!!");
	if(b==0xa600)
	printf("b!!!");
	if(c==0xa60000)
	printf("c!!!\n");//ֻ��c�ܴ�ӡ��������Ϊc����Ҫ�������� 
	printf("%u\n",sizeof(a));//%u�����������ʽ˵��������ʾ��unsigned int��ʽ������������
	printf("%u\n",sizeof(+a)); //+c����������ᷢ��������������Ϊint��size��4 
	return 0;
}
