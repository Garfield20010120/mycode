#include<stdio.h>
//22.4.24�ַ������򣨵ݹ�ʵ�֣� 
//��Ŀ����дһ������ reverse_string(char * string)(�ݹ�ʵ��)
//ʵ�֣��������ַ����е��ַ��������� 
// Ҫ�󣺲���ʹ��c�������е��ַ�����������
//#include<string.h> //�Լ���һ��Ҳ�� 

//�������� 
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
	while(left<right)//����һ��ʼ���˸������˰��졣�� 
	{
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	
}
*/
//�ݹ�
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
