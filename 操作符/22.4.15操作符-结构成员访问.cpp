//22.4.15������ �ṹ��Ա���ʣ�.��->�� 
#include<stdio.h>
struct Stu
{
	char name[20];
	int age;
	char id[20];
};//�����и��ֺ� 

int main()
{
	int a = 0;
	struct Stu S1 = {"����",21,"20220415"};
//	S1.name = "����";//"." ������strcpy 
//	S1->age = 22;//"->"
	printf("%s\n",S1.name);
	printf("%d\n",S1.age);
	return 0;
}
