#include<stdio.h>
#include<string.h>
void sort(char **pa, int n)//冒泡排序
{
    int i, j;
    char *tmp = NULL;
     
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-1-i; j++){
            if(strcmp((*pa+j), *(pa+j+1)) > 0){//返回值：（1）字符串1=字符串2，返回0（2）字符串1>字符串2，返回一个正整数（3）字符串1<字符串2，返回一个负整数。
	//strcmp()函数是根据ACSII码的值来比较两个字符串的；strcmp()函数首先将s1字符串的第一个字符值减去s2第一个字符，若差值为零则继续比较下去；若差值不为零，则返回差值。              
			    tmp = *(pa + j);
                *(pa + j) = *(pa + j + 1);
                *(pa + j + 1) = tmp;
            }
        }
    }
}

int main()
{
	//字符数组初始化时，数组大小一定要大于字符串长度+1，否则编译错误（字符串数组最后有\0）。 
	char *a1[]={"adc","dSf","Acb","dsa"};//A-65 a-97
//	char (*arr)[6]=&a1;
	sort(a1,4);
	for(int i=0;i<4;i++)
	{
	printf("%s ",*(a1+i));
	}
	return 0;
}
