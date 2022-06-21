#include <iostream>
//22.6.21 过河马 
using namespace std;
int ans = 0;
int h, l;
int dp[105][105];

/*
我自己的递推过程
int f( int m, int n )
{
	if ( dp[m][n] ) return dp[m][n];
	if ( m <= 1 || n < 1 || n > l ) return dp[m][n] = 0;
	if ( m == 2 && n == 3 ) return dp[m][n] = 1;
	if ( m == 3 && n == 2 ) return dp[m][n] = 1;
	
	return dp[m][n] = (f(m-2, n+1) % 1000000007+ f(m-1, n+2) % 1000000007+ f(m-1, n-2) % 1000000007+ f(m-2, n-1) % 1000000007 )% 1000000007;
	
}*/
int main()
{
	cin >> h >> l;
	//cout << f(h, l) << endl;
	
	dp[2][3] = dp[3][2] = 1;
	for ( int i = 1; i <= h; ++ i ) {
		for ( int j = 1; j <= l; ++j ) {
			
			if ( i == 1 ) dp[i][j] = 0;
			
            //每加一次就取一次模，防止int越界了
			if ( i - 2 > 1 && j + 1 <= l ) dp[i][j] += (dp[i-2][j+1] % 1000000007);
			dp[i][j] %= 1000000007;
			
			if ( i - 1 > 1 && j + 2 <= l ) dp[i][j] += (dp[i-1][j+2]%1000000007);
			dp[i][j] %= 1000000007;
			
			if ( i - 1 > 1 && j - 2 >= 1 ) dp[i][j] += (dp[i-1][j-2]%1000000007);
			dp[i][j] %= 1000000007;
			
			if ( i -2 > 1 && j - 1 >= 1 ) dp[i][j] += (dp[i-2][j-1]%1000000007);
			dp[i][j] %= 1000000007;
		}
	}
	cout << dp[h][l] << endl;
	return 0;
}

