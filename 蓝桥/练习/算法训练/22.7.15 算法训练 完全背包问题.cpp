#include <iostream>
using namespace std;
int dp[1001][1001];//dp[i][j]表示前i个物品放到容量j的背包里的最大价值
 
int main() {
	int N, M;
	cin >> N >> M;
	int W[N + 1], V[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}
	for (int i = 0; i <= 1001; i++) {//当容量为0或个数为0时没有价值
		dp[i][0] = dp[0][i] = 0;
	}
	for (int i = 1; i <= N - 1; i++) {//简单的冒泡排序
		for (int j = 1; j <= N - i; j++) {
			if (W[j] > W[j + 1]) {
				int temp = W[j];
				W[j] = W[j + 1];
				W[j + 1] = temp;
 
				temp = V[j];
				V[j] = V[j + 1];
				V[j + 1] = temp;
			}
		}
	}
	//核心代码
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j];//不选第i个物品时
			for (int k = 1; k <= j / W[i]; k++) {
				int A = dp[i - 1][j - k * W[i]] + k * V[i];//选k个物品i时的价值
				dp[i][j] = dp[i][j] > A ? dp[i][j] : A;
			}
		}
	}
	cout << dp[N][M];
}