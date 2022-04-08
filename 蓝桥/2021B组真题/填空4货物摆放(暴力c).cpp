#include <stdio.h>//填空4货物摆放 开始时间10：03 结束时间： 11:20
int main()
{
	long long a[1000];//数组记录所有因数 
	const long long n=2021041820210418;
	long long i;//i也要longlong（遍历到了sqrt（n）） 
	int b=0,f=0,c,d,e;//b记录因数数目 f记录货物摆放方法数 
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a[b++]=i;
			a[b++]=n/i;
		}
	} 
//检查点1	printf("b=%d",b);
/*检查点2 
	for(int i=0;i<b;i++)//i要记得初始化 如果去掉int会打印出来一堆奇奇怪怪的数（原因不详？？？？？） 
	{
		printf("a[%d]=%lld\n",i,a[i]);//a[i]的调用格式是%lld而非%d 
	}
*/
	for (int e=0;e<b;e++)
	{
		for(int c=0;c<b;c++)
		{
			for(int d=0;d<b;d++)
			{
				if(a[e]*a[c]*a[d]==n)
				f++;
			}
		}
	}
	printf("f=%d",f);
	return 0;
} 
