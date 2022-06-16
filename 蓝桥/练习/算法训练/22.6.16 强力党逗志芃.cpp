#include<iostream>
//22.6.16 强力党逗志芃
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 210;

int n,m;
int q[N];
int h[N],e[N],ne[N],idx;
int dp[N][N];//以i为根节点，总花费的点数不超过j的最大方案
bool st[N];//是否有前驱
int res = 0;//伤害的最大的值


void add(int x,int y)
{
    e[idx] = y,ne[idx] = h[x],h[x] = idx++;
}

void dfs(int u)
{
    for(int i = h[u];i != -1; i = ne[i])//循环物品组
    {
        int son = e[i];
        dfs(son);

        for(int j = m - 1; j >= 0; j--)//循环剩余的点数
            for(int k = 0; k <= j; k++)//循环决策
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
    }

    //将当前的节点1
    for(int i = m; i >= 1; i--) dp[u][i] = dp[u][i - 1] + q[u];
    dp[u][0] = 0;
}

int main()
{
    cin >> n >> m;
    memset(h, -1 ,sizeof h);

    for(int i = 1; i <= n; i++)//读取每个节点的值
        cin>>q[i];

    for(int i = 1; i < n; i++)//读取节点之间的关系
    {
        int x,y;
        cin >> x >> y;
        add(x,y);//x为y的父节点
        st[y] = true;
    }

    int root;//寻找根节点
    for(int i = 1; i <= n; i++)
        if(st[i] == false){
            root = i;
            break;
        }
    
    dfs(root);
	
    cout << dp[root][m] << endl;

    return 0;
}

