#include <iostream>
//22.6.30 蓝桥 进击的青蛙 
using namespace std;
const int N = 1e6+5;
typedef long long LL;//long long
LL dp[N], n;

int main()
{
	cin >> n;
	for ( int i = 1; i <= n; ++i ) {
		cin >> dp[i];
	}
    //初始值：
	dp[1] == 0 ? dp[1] = 1 : dp[1] = 0;
	dp[2] == 0 ? dp[2] = dp[1] + 1 : dp[2] = 0;
	dp[3] == 0 ? dp[3] = dp[1] + dp[2] + 1 : dp[3] =0;
	
    //dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	for ( int i = 4; i <= n; ++i ) {
		if ( dp[i] == 1 ) dp[i] = 0;
		else {
			dp[i] = (dp[i-1] % 1000000007 + dp[i-2] % 1000000007 +dp[i-3] % 1000000007 ) % 1000000007;
		}
	}
	
    //当dp[n] == 0的时候，就是跳不到n这个点
	if ( !dp[n] ) cout << "No Way!\n";
    //跳的到
	else cout << dp[n] << '\n';
	
	return 0;
}

