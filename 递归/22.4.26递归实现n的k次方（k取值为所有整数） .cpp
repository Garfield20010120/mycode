#include<stdio.h>
//22.4.26�ݹ�ʵ��n��k�η���kȡֵΪ���������� 
double my_pow(int n,int k)
{
	if(k<0)
	{
		return (1/my_pow(n,-k));
	}
	else if(k==0)
	{
		return 1;
	}
	else if(k>0)
	{
		return n*my_pow(n,k-1);
	}
}

int main()
{
	int k = 0;
	int n = 0;
	scanf("%d%d",&n,&k);
	double x = my_pow(n,k); 
	printf("%lf\n",x);
	return 0;
} 
