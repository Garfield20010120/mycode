#include<stdio.h>
//22.5.10ָ�����1__ָ���С���ַ�ָ�� 
void test(char arr[])//arr[]�����β����ͣ���Ҫ©���ţ� 
{
	int sz=sizeof(arr)/sizeof(arr[0]);
	//sizeof(arr)Ϊarr[0]�ĵ�ַ��С��64λΪ8��32λ4��
	//sizeof(arr[0])Ϊarr[0]�Ĵ�С����Ϊ����Ϊchar��Ϊ1 
	printf("%d\n",sz);
}

int main()
{
	char arr[10] = "abcdefg";
	test(arr);//��ַ arrΪarr[0]�ĵ�ַ 
	char* p=arr;
	//��ָͨ���ӡ���鷨 
	printf("%s\n",arr);
	printf("%s\n",p);
	//д����
	char* p1="abcdefg";
	printf("%c\n",*p1); //��ʵ��������ĸ�ĵ�ַ����p1��(��p1������a�ĵ�ַ)
	printf("%s\n",p1); 
	char str1[]="abcd";
	char str2[]="abcd";
	const char* str3="abcd";//��const��abcd��Ϊһ�������ַ�������������һ���ڴ�����str3��str4ͬʱָ����ַ�������ĸ 
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
