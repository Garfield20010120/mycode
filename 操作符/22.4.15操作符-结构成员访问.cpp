//22.4.15������ �ṹ��Ա���ʣ�.��->�� 
#include<stdio.h>
#include<string.h>
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
	struct Stu* ps = &S1; //Ҫ������ 
	strcpy(S1.name,"����");//"." ������strcpy 
	ps->age = 22;//"->"ǰҪ��ָ�벻Ȼ�ᱨ��[Error] base operand of '->' has non-pointer type 'Stu' 
	printf("%s\n",S1.name);
	printf("%d\n",S1.age);
	printf("%s\n",ps->name);
	printf("%d\n",(*ps).age);
	return 0;
}
