#include<bits/stdc++.h>
//22.6.27 N³µ 
using namespace std;
 
 
int main()
{
	int n;
	cin >> n;
	long long dp[21]={0};
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]*i;
	}
	cout << dp[n] << endl; 
	return 0;
}
