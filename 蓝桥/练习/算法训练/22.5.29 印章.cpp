#include<stdio.h>
#include<math.h>
//����n��ͼ����ӡ�£�ÿ��ͼ���ĳ��ָ�����ͬ��СA����m��ӡ�£���СA����n��ӡ�µĸ��ʡ� 
double dp[22];//һά���飬dp[i]:��i��ӡ�£�����n��ӡ�µĸ��� 
/*
Ϊʲô��һά���飿
��Ϊ�ڴ˽ⷨ���õĵ��ƹ�ʽ�У� 
��m��ӡ�£�����n��ӡ�µĸ���ֻ����m��ӡ��,����n-1��,n-2��...1�� �ĸ����й� , 
����x(x!=m)��ӡ�´���y(y>=1)��ӡ�µĸ����޹� 
*/ 
long long c_fun(int n,int m)//�������C(n,m); 
{
	long i;
	long long ans_n=1,ans_m=1,ans_nm=1;
	for(i=2;i<=n;i++)
		ans_n=ans_n*i;
	for(i=2;i<=m;i++)
		ans_m=ans_m*i;
	for(i=2;i<=n-m;i++)
		ans_nm=ans_nm*i;
	return ans_n/(ans_m*ans_nm);
	
} 
double fun(int n,int m)//���ӡ������ 
{
	int i,j;
	double t=0;
	dp[1]=1.0;//ֻ�����1�֣��ض����Դ��� 
	for(i=2;i<=n;i++)//ѭ��,���������2,3,4...n�ֵ���� 
	{
		t=0;
		for(j=1;j<i;j++)// 
		{
			t=t+c_fun(i,j)*dp[j]*pow(j,m);//���ƹ�ʽ 
					
		}
		dp[i]=1-t/pow(i,m);
		//Ҫ��1ȥ������Ϊǰ����ƹ�ʽ����������Ǵղ���ĸ���,dp�������Ǵ���ĸ��� 
	}
	return dp[n];//���ؽ�� 
} 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);//��n��ӡ�£���m�� 
	fun(n,m);//��� 
	printf("%.4lf\n",dp[n]);//dp[n]��Ϊ��� 
	return 0;
}

