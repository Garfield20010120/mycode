#include<stdio.h>
//22.5.10指针详解1__指针大小、字符指针 
void test(char arr[])//arr[]才是形参类型（不要漏括号） 
{
	int sz=sizeof(arr)/sizeof(arr[0]);
	//sizeof(arr)为arr[0]的地址大小（64位为8，32位4）
	//sizeof(arr[0])为arr[0]的大小，因为类型为char故为1 
	printf("%d\n",sz);
}

int main()
{
	char arr[10] = "abcdefg";
	test(arr);//传址 arr为arr[0]的地址 
	char* p=arr;
	//普通指针打印数组法 
	printf("%s\n",arr);
	printf("%s\n",p);
	//写法二
	char* p1="abcdefg";
	printf("%c\n",*p1); //事实上是首字母的地址赋给p1了(即p1里存的是a的地址)
	printf("%s\n",p1); 
	char str1[]="abcd";
	char str2[]="abcd";
	const char* str3="abcd";//加const后abcd作为一个常量字符串，单独存在一个内存区域，str3和str4同时指向该字符串首字母 
	const char* str4="abcd";
	if(str1==str2)
	printf("str1==str2\n");
	else
	printf("str1!=str2\n");
	if(str3==str4)
	printf("str3==str4\n");
	else
	printf("str3!=str4\n");
	return 0;
}
