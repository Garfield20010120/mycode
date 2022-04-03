#include <stdio.h>
int main()
{
	char a='Y';
	int b=0; 
	char password[]={};
	printf("请输入密码：");
	scanf("%s",password);
	printf("请确认密码(已消除空格后字符串)：%s\n(Y&N):",password);
	//getchar();//用以消掉scanf残留的回车 
	while(b=getchar()!='\n')//注意是b=getchar不是b==getchar 
	{
		;
	}
	a=getchar();
	if(a=='Y')
	printf("确认成功"); 
	else
	{
	puts("放弃确认");
	putchar(a);}
	putchar(a);
	return 0;
	 
	 
}
