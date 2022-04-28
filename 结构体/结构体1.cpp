#include<stdio.h>
//22.4.29结构体1 函数传值or传值？ 
typedef struct stu
{
	char name[20];
	short age;
	char tele[12];
	char sex[5];
}stu;//类型 

void print1(stu tmp)
{
	printf("name = %s\n",tmp.name);
	printf("age  = %d\n",tmp.age);
	printf("tele = %s\n",tmp.tele);
	printf("sex  = %s\n",tmp.sex);
}
//用指针传址更好，这样做节省系统开销、减少空间占用 
void print2(stu* p)
{
	printf("name = %s\n",p->name);
	printf("age  = %d\n",p->age);
	printf("tele = %s\n",p->tele);
	printf("sex  = %s\n",p->sex);
}

int main()
{
	stu s = {"李华",18,"13645524612","男"};
	print1(s);//传值
	print2(&s);//传址 
	return 0;
}
