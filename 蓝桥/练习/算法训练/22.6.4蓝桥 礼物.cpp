#include<iostream>
//22.6.4À¶ÇÅ ÀñÎï 
#include<string.h>
using namespace std;
int check(long long mid,long long N,long long S,long long *Sum)
{
	for (int i = mid; i <= N - mid; i++)
	{
		if (Sum[i] - Sum[i - mid] <= S && Sum[i + mid] - Sum[i] <= S)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	long long N, S;
	cin >> N >> S;
	long long* W = new long long[N+1];
	long long* Sum = new long long[N+1];//Ç°×ººÍ
	memset(W, 0, sizeof(W));
	memset(Sum, 0, sizeof(Sum));
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i];
		Sum[i] = Sum[i - 1] + W[i];
			
	}
	long long l = 1, r = N;
	while (l < r)
	{
		long long mid = (l + r + 1) >> 1;
		if (check(mid, N, S, Sum))
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << 2 * l << endl;
	return 0;
}
/*
8 3
1 1 1 1 1 1 1 1

8 3
1 2 3 4 5 6 7 8

*/

