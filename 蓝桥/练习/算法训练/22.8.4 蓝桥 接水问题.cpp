#include<cstdio>
using namespace std;
int main()
{
	int n,m,i,j,time=0,a[10000]={0};
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(m==1)//m等于1的时候只能一个人一个人的接水，所以求和就行
		for(i=0;i<n;i++)
			time+=a[i];
	else
	{
		for(i=m;i<n;i++)
		{
			int min=0;
			for(j=1;j<m;j++)
				if(a[j]<a[min])
					min=j;
			a[min]+=a[i];
		}
		for(i=0;i<m;i++)
			time=time>a[i]?time:a[i];
	}
	printf("%d\n",time);
}

