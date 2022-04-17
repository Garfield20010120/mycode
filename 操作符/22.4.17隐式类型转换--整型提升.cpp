#include<stdio.h>
//22.4.17隐式类型转换--整型提升 
int main()
{
	char a = 0xa6;
	short b = 0xa600;//short打印是%hd(longlong是%lld) 
	int c = 0xa60000;
	printf("a=%c\nb=%hd\nc=%d\n",a,b,c) ;//均溢出
	if(a==0xa6)
	printf("a!!!");
	if(b==0xa600)
	printf("b!!!");
	if(c==0xa60000)
	printf("c!!!\n");//只有c能打印出来，因为c不需要整型提升 
	printf("%u\n",sizeof(a));//%u是输入输出格式说明符，表示按unsigned int格式输入或输出数据
	printf("%u\n",sizeof(+a)); //+c参与了运算会发生整型提升，变为int的size：4 
	return 0;
}
