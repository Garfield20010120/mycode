#include<stdio.h>
//22.4.29�ṹ��1 ������ֵor��ֵ�� 
typedef struct stu
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}stu;//���� 

void print1(stu tmp)
{
	printf("name = %s\n",tmp.name);
	printf("age  = %d\n",tmp.age);
	printf("tele = %s\n",tmp.tele);
	printf("sex  = %s\n",tmp.sex);
}
//��ָ�봫ַ���ã���������ʡϵͳ���������ٿռ�ռ�� 
void print2(stu* p)
{
	printf("name = %s\n",p->name);
	printf("age  = %d\n",p->age);
	printf("tele = %s\n",p->tele);
	printf("sex  = %s\n",p->sex);
}

int main()
{
	stu s = {"�",18,"13645524612","��"};
	print1(s);//��ֵ
	print2(&s);//��ַ 
	return 0;
}
