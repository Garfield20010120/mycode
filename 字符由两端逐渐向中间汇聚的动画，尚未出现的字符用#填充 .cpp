#include<stdio.h>
#include<string.h>
#include<windows.h>  //sleep���� 
#include<stdlib.h>  //system���� 
//�ַ������������м��۵Ķ�������δ���ֵ��ַ���#��� 
int main()
{
	char arr1[] = "welcome to my world!";//�ַ�����char������int 
	char arr2[] = "####################";
	int left = 0;
	int right = strlen(arr1)-1;//strlen(arr1)/strlen(arr1[0])-1 �� strlen(arr1[0])������ 
	while(left<=right)
	{
		printf("%s\n",arr2);
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		Sleep(100);//100ms 
		system("cls");//cls-�����Ļ 
		left++;
		right--;
	}
	printf("%s",arr1);
	return 0;
	
}
