#include<iostream>
//22.6.15 ���� ��־�M��Σ�� 
#include<cstdio>
 using namespace std;
 const int N = 1010;
 int a[N],res[N][N];
 int n;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++) scanf("%d",&a[i]);
	for(int r = 0; r < n; r ++)
		for(int l = r; l >= 0; l --)
		{
			if(l == r) res[l][r] = 0; //ֻʣ��һ�����ˣ��������� ������� ���Ǻ���  ��û����
			else if((r - l) & 1) {
				//ż����
				res[l][r] = max(a[l] + res[l + 1][r], a[r] + res[l][r - 1]);
			} else{
				res[l][r] = min(res[l + 1][r], res[l][r - 1]);
			}
		}
	cout << res[0][n-1];
	return 0;
}
