#include<stdio.h>
int main()
{
	int arr[200010];
	int a=0,b=0,c=0,i=0;
	long long sum=0;
	scanf("%d",&a);
	for(i=0;i<a;i++)
	{
		scanf("%d",&arr[i]);// &arr[i]差点忘记取地址了 
	}
	for(b=0;b<a-1;b++)
	{
		for(int c=b+1;c<a;c++)
		{
			sum=sum+arr[b]*arr[c];
		}
	}

	printf("%lld",sum);
	return 0;
}
