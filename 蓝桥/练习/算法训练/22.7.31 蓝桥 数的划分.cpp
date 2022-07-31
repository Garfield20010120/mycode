//dp动态规划求解
#include <iostream>
#include<math.h>
#include<memory.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int dp[250][10];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - j][j] + dp[i - 1][j - 1];
		}
	}

	cout << dp[n][k] << endl;
	return 0;
}
