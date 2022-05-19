#include<stdio.h>
//22.5.19解释两段函数指针相关的代码 
int main()
{
	//代码一 
	(*(void(*)())0)()
	//把0强制类型转换为：void(*)()函数指针类型-0即为一个函数的地址
	//调用0地址处的函数
	//代码二
	void(*signal(int , void(*)(int)))(int)
	//signal是一个函数声明
	//signal函数的参数有2个，第一个是int，第二个是函数指针，该函数指针指向的函数的参数是int，返回值是void
	//signal函数的返回类型也是一个函数指针 ；该函数指针指向的函数的参数是ine，返回类型是coid
	//代码二可简化如下：
	typedef void(*pfun_t)(int);//把void(*)(int)命名为pfun_t 
	pfun_t signal(int , pfun_t);
	return 0;
} 
