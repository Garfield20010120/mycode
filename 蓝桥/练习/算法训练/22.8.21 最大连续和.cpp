#include<bits/stdc++.h>
using namespace std;
 
int a[1000001]={0};
int dp[1000001]={0};
int main()
{
	int n;
	cin >> n ;
 
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	dp[0]=a[0];            //初始化dp
	for(int i=1;i<n;i++)
	{
		dp[i]=max(a[i]+dp[i-1],a[i]);   //求出每个位置的最大值（i包括在内） 
	}
	for(int i=1;i<n;i++)    //求出排在i前面（可以不用包括i）的小朋友的和最大值 
	{
		if(dp[i]<dp[i-1])
		{
			dp[i]=dp[i-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << dp[i] << " ";     //输出结果
	}
	return 0;
}