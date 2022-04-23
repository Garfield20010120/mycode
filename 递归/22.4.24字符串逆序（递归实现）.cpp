#include<stdio.h>
//22.4.24字符串逆序（递归实现） 
//题目：编写一个函数 reverse_string(char * string)(递归实现)
//实现：将参数字符串中的字符反向排列 
// 要求：不能使用c函数库中的字符串操作函数
//#include<string.h> //自己编一个也行 

//常规做法 
int strlen(char* arr)
{
	int a = 0;
	while(*arr != '\0')
	{
		arr++;
		a++;
	}
	return a;
}
/*
void reverse_string(char arr[])
{
	int left = 0;
	int right = strlen(arr)-1;
	while(left<right)//这里一开始加了个；调了半天。。 
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	
}
*/
//递归
 void reverse_string(char arr[])
 {
 	char tmp = arr[0] ;
 	int len = strlen(arr);
 	arr[0]=arr[len-1];
 	arr[len-1]='\0';
 	if(strlen(arr+1)>=2)
 	{
 		reverse_string(arr+1);
 	}
 	arr[len - 1] = tmp;
 }
int main()
{
	char arr[] = "abcdefgh";
	reverse_string(arr);
	printf("%s\n",arr);
	return 0;
}
