#include<iostream> 
#include<algorithm>
#include<cstring>
//22.5.24给出一个包含n个整数的数列，问整数a在数列中的第一次出现是第几个。 
using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
PII a[N];
int n, k;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i + 1;
	
	cin >> k;
	sort(a, a + n);

	int l = 0, r = n - 1;
	while(l < r) 
	{
		int mid = (l + r) / 2;
		if(a[mid].first >= k) r = mid;
		else l = mid + 1;
	}
	if(a[r].first == k) cout << a[r].second;
	else cout << "-1";
	return 0;
}

