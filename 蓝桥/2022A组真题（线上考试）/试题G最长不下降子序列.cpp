#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, k;
int num[N];
int mm[N];
int len = 0;
int ans;
int back_up[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) {
		if (num[i] >= mm[len]) {
			mm[++len] = num[i];
		} else {
			*lower_bound(mm + 1, mm + len + 1, num[i]) = num[i];
		}
		int back_upL = len;
		int back_upI = i;
		memcpy(back_up, mm, sizeof mm);
		if (n - i >= k) {
			int ss = mm[len];
			for (int j = 1; j <= k; j++) {
				mm[++len] = ss;
			}
			i += (k + 1);
			for (; i <= n; i++) {
				if (num[i] >= mm[len]) {
					mm[++len] = num[i];
				} else {
					*lower_bound(mm + 1, mm + len + 1, num[i]) = num[i];
				}
			}
			ans = max(ans, len);
			i = back_upI;
			len = back_upL;
			memcpy(mm, back_up, sizeof mm);
		}
	}
	cout << ans;
	return 0;
}

