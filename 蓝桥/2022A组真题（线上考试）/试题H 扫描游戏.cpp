#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int INF = 0x3f3f3f3f;
struct node
{
    long long x, y, z, id;
    double theta;
    bool operator<(const node &tmp) const { return theta < tmp.theta; }
};

vector<node> vec;
int out[N];
node tmp;
void solve()
{
    int n;
    long long L;
    scanf("%d %lld", &n, &L);
    for (int i = 1; i <= n; i++)
    {
        out[i] = -1;
        tmp.id = i;
        scanf("%lld %lld %lld", &tmp.x, &tmp.y, &tmp.z);
        tmp.theta = atan2(tmp.y, tmp.x);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int len = (int)vec.size();
    int p = -1;
    for (int i = len - 1; i >= 0; i--)
    {
        if (vec[i].x >= 0)
        {
            p = i;
            break;
        }
    }
    if (p == -1)
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if (vec[i].y <= 0)
            {
                p = i;
                break;
            }
        }
    }

    if (p == -1)
        p = (int)vec.size() - 1;

    vector<node> tmp = vec;
    vec.clear();
    for (int i = p; i >= 0; i--)
        vec.push_back(tmp[i]);
    for (int i = (int)tmp.size() - 1; i > p; i--)
        vec.push_back(tmp[i]);
    int rk = 0, sum = 0;
    node pre;
    pre.theta = INF;
    while (1)
    {
        vector<node> now;
        int m = vec.size();
        for (int i = 0; i < m; i++)
            if (vec[i].x != INF)
                now.push_back(vec[i]);
        m = now.size();
        bool flag = 0;
        for (int i = 0; i < m; i++)
        {
            if (L * L >= now[i].x * now[i].x + now[i].y * now[i].y)
            {
                L += now[i].z;
                now[i].x = INF; //±ê¼Ç
                flag = 1;
                if (fabs(now[i].theta - pre.theta) <= 1e-6)
                    out[now[i].id] = rk;
                else
                {
                    rk = sum + 1;
                    out[now[i].id] = rk;
                }
                sum++;
                pre = now[i];
            }
        }
        if (!flag)
            break;
        vec = now;
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", out[i], i == n ? '\n' : ' ');
}
int main()
{
    solve();
    return 0;
}

