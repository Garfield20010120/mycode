//22.4.15操作符 结构成员访问（.和->） 
#include<stdio.h>
#include<string.h>
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
	struct Stu* ps = &S1; //要先声明 
	strcpy(S1.name,"鸽子");//"." 这里用strcpy 
	ps->age = 22;//"->"前要用指针不然会报错：[Error] base operand of '->' has non-pointer type 'Stu' 
	printf("%s\n",S1.name);
	printf("%d\n",S1.age);
	printf("%s\n",ps->name);
	printf("%d\n",(*ps).age);
	return 0;
}
