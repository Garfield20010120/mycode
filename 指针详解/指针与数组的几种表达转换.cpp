#include<stdio.h>
//5.15指针与数组的几种表达转换 
int main()
{
	int arr[10]={1,2,3,4,5,6,7,8,9,10};
	int i=0;
	int*p=arr;//arr相当于&arr[0]，而指针p指向的便是arr[0]，某种意义上来说arr等同与p 
	for(i=0;i<10;i++)
	{
		//四种表达均等同 
		printf("%d ",p[i]);
		printf("%d ",*(p+i));
		printf("%d ",arr[i]);
		printf("%d ",*(arr+i)); 
	}
	return 0;
} 
