//22.4.15操作符 结构成员访问（.和->） 
#include<stdio.h>
struct Stu
{
	char name[20];
	int age;
	char id[20];
};//这里有个分号 

int main()
{
	int a = 0;
	struct Stu S1 = {"郭子",21,"20220415"};
//	S1.name = "鸽子";//"." 这里用strcpy 
//	S1->age = 22;//"->"
	printf("%s\n",S1.name);
	printf("%d\n",S1.age);
	return 0;
}
