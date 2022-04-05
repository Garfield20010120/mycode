//16：07开始 16:18开始调试 16:37调试完毕 
#include<stdio.h>
#include<string.h>

int main()
{
	int i=0;//int i放for外面作用整个main函数，放for的初始化部分 (int i=0)作用域仅存在于循环内 
	char arr1[15]={0};//密码用char 
	char arr2[15]={0};
	strcpy(arr1,"123456");//改字符串用strcpy 
	for(;;i++)//;不要打成,了 
	{
		printf("请输入密码：");
		scanf("%s",arr2);
		if (strcmp(arr1,arr2)==0)
		{
			printf("密码正确,登录成功\n");
			break;
		}
		else
		{
			if(i==2)
			{
			printf("三次密码错误，登录失败\n");
			break;
			}
			else
			printf("密码错误，请再次输入密码\n");
		} 
	}
	printf("密码输入次数：%d",i+1);
	return 0;
}
