#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,i=0,j=0;
	int arr[100010];
	int l[100010];
	int r[100010];
	scanf("%d",&a);//a是包含几个整数 
	scanf("%d",&b);//b是包含几个区间
	scanf("%d",&c);//c是异或后判定的结果
	for(i=0;i<a;i++)
	{
		scanf("%d",&arr[i]); 
	}
	for(j=0;j<b;j++)
	{
		scanf("%d",&l[j]);
		scanf("%d",&r[j]);
	}
	for(j=0;j<b;j++)
	{
		h=1;
		if(r[j]==l[j])
		printf("no\n");
		else
		{
		//先找l和r的下标 
		for(int k=0;k<a;k++)
		{
			if(l[j]==arr[k])
			f=k;
			if(r[j]==arr[k])
			g=k;
		}
		for(int d=f;d<g;d++)
		{
		for(e=d+1;e<g+1;e++)
		{
			if ((arr[e]^arr[d])==c)
			{
			h=2;
			printf("yes\n");
			break;
			}
		}
		}
		if(h==1)
		printf("no\n");
		}
	}
	return 0;
}
