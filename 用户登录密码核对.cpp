//16��07��ʼ 16:18��ʼ���� 16:37������� 
#include<stdio.h>
#include<string.h>

int main()
{
	int i=0;//int i��for������������main��������for�ĳ�ʼ������ (int i=0)�������������ѭ���� 
	char arr1[15]={0};//������char 
	char arr2[15]={0};
	strcpy(arr1,"123456");//���ַ�����strcpy 
	for(;;i++)//;��Ҫ���,�� 
	{
		printf("���������룺");
		scanf("%s",arr2);
		if (strcmp(arr1,arr2)==0)
		{
			printf("������ȷ,��¼�ɹ�\n");
			break;
		}
		else
		{
			if(i==2)
			{
			printf("����������󣬵�¼ʧ��\n");
			break;
			}
			else
			printf("����������ٴ���������\n");
		} 
	}
	printf("�������������%d",i+1);
	return 0;
}
