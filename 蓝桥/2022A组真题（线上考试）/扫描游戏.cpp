#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int maxn = 2e5 + 10;
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
  return x = x * w;
}
struct point
{
    ll x, y, z;
    int id;
}a[maxn];
ll n;
__int128 L;

int Quadrant(point a)
{
    if(a.x >= 0 && a.y > 0)return 1;///y的正半轴放到第一象限
    if(a.x > 0 && a.y <= 0)return 2;///x的正半轴放到第二象限
    if(a.x <= 0 && a.y < 0)return 3;
    return 4;
}
ll cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}
bool cmp(point a, point b)
{
    if(Quadrant(a) == Quadrant(b))
    {
        if(cross(a, b) == 0)
            return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
        else
           return cross(a, b) < 0;
    }
    else
        return Quadrant(a) < Quadrant(b);
}

__int128 mi[maxn << 2];
void push_up(int o)
{
    mi[o] = min(mi[o << 1], mi[o << 1 | 1]);
}
void build(int o, int l, int r)
{
    if(l == r)
    {
        mi[o] = a[l].x * a[l].x + a[l].y * a[l].y;
        return ;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int x, __int128 val)
{
    if(l == r)
    {
        mi[o] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid)update(o << 1, l, mid, x, val);
    else update(o << 1 | 1, mid + 1, r, x, val);
    push_up(o);
}

///找右边第一个小于等于z^2的数字
ll idx;
bool query(int o, int l, int r, int L, int R, __int128 z)
{
    if(L > R)return false;
    if(l == r)
    {
        idx = l;
        return mi[o] <= z;
    }
    int mid = (l + r) >> 1;
    if(L <= mid)
    {
        if((mi[o << 1] <= z) && query(o << 1, l, mid, L, R, z))
            return true;
    }
    if(R > mid)
    {
        if((mi[o << 1 | 1] <= z) && query(o << 1 | 1, mid + 1, r, L, R, z))
            return true;
    }
    return false;
}
int ans[maxn];

int main()
{
    read(n);read(L);
    for(int i = 1; i <= n; i++)
    {
        read(a[i].x);read(a[i].y);read(a[i].z);
        a[i].id = i;
        ans[i] = -1;
    }
    sort(a + 1, a + 1 + n, cmp);
    build(1, 1, n);
    int cnt = 0;
    int lastcnt = 0;
    int last = 0;  ///上一个位置
    while(true)
    {
        bool ok = query(1, 1, n, last + 1, n, L * L);
        if(ok)L = L + a[idx].z;
        else
        {
            ok = query(1, 1, n, 1, last - 1, L * L);
            if(ok)L = L + a[idx].z;
            else break;
        }
        update(1, 1, n, idx, 1e32);
        if(last)
        {
            if(Quadrant(a[last]) == Quadrant(a[idx]) && cross(a[last], a[idx]) == 0)
                ans[a[idx].id] = lastcnt, ++cnt;
            else
                ans[a[idx].id] = ++cnt, lastcnt = cnt;
        }
        else
            ans[a[idx].id] = ++cnt, lastcnt = cnt;
        last = idx;
    }
    for(int i = 1; i <= n; i++)
    {
        cout<<ans[i];
        if(i != n)cout<<" ";
    }
    return 0;
}

} 
