#include <stdio.h>
int main()
{
	char a='Y';
	int b=0; 
	char password[]={};
	printf("���������룺");
	scanf("%s",password);
	printf("��ȷ������(�������ո���ַ���)��%s\n(Y&N):",password);
	//getchar();//��������scanf�����Ļس� 
	while(b=getchar()!='\n')//ע����b=getchar����b==getchar 
	{
		;
	}
	a=getchar();
	if(a=='Y')
	printf("ȷ�ϳɹ�"); 
	else
	{
	puts("����ȷ��");
	putchar(a);}
	putchar(a);
	return 0;
	 
	 
}
