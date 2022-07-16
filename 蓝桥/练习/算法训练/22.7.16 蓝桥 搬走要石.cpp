#include <bits/stdc++.h>
using namespace std;
 
const int N = 1010;
int n, m, a[N];
 
bool check(int mid)
{
	int cnt = 0, sum = 0;
	for (int i = 0; i < n;)
	{
		if (sum + a[i] <= mid)
		{
			sum += a[i];
			i++;
		}
		else if (a[i] > mid)
			return false;
		else 
		{
			cnt++;
			sum = 0;
		}
	}
	return cnt < m;
}
 
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	int l = 0, r=1e6, mid;
	while (l < r)
	{
		mid = l + r >>1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d", l);
	return 0;
}