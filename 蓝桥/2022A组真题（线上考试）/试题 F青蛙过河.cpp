#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
template <typename T>
inline T read(T& x) {
  x = 0;
  T w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * w;
}
int h[maxn], sum[maxn];
int n, x;
//判断所有长度为mid的区间之和是否大于等于2x
bool check(int mid)
{
    for(int i = 1; i + mid - 1 <= n; i++)
        if(sum[i + mid - 1] - sum[i - 1] < 2 * x)return false;
    return true;
}
int main()
{
    read(n); read(x);
    for(int i = 1; i <= n - 1; i++)//预处理前缀和
        read(h[i]), sum[i] = sum[i - 1] + h[i];
    sum[n] = 1e9 + 7;
    int left = 1, right = n, ans = n;
    while(left <= right)//二分答案
    {
        int mid = (left + right) >> 1;
        if(check(mid))
            ans = mid, right = mid - 1;//求最小合法解
        else
            left = mid + 1;
    }
    cout<<ans<<endl;
    return 0;
}

