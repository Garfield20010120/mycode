#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;
const int maxn = 1010;
const int maxm = 20010;
struct node {
    int v,net;
    ll w;
    node(){}
    node(int v,int net,ll w):v(v),net(net),w(w){}
}e[maxm];
int head[maxn],cnt,dis[maxn],n,cur[maxn];
bool vis[maxn];
void addedge(int u,int v,ll w) {
    e[cnt]=node(v,head[u],w);
    head[u]=cnt++;
    e[cnt]=node(u,head[v],0);
    head[v]=cnt++;
}
bool bfs(int st,int ed) {
    if(st==ed) return false;
    for(int i=1;i<=n;i++)
        dis[i]=inf,vis[i]=false;
    dis[ed]=inf;
    vis[ed]=false;
    dis[st]=0;
    queue<int>que;
    que.push(st);
    while(!que.empty()) {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=head[u];~i;i=e[i].net) {
            int v=e[i].v;
            if(e[i].w>0&&dis[v]>dis[u]+1) {
                dis[v]=dis[u]+1;
                if(!vis[v]) {
                    que.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    return dis[ed]!=inf;
}
ll dfs(int st,ll maxflow,int ed) { ///maxflow表示当前的源点能流出的最大流
    if(st==ed) {
        return maxflow;
    }
    ll res=0;
    for(int &i=cur[st];~i;i=e[i].net) {    ///没记错的话叫当前弧优化
        int v=e[i].v;
        if(e[i].w>0&&dis[v]==dis[st]+1) {
            ll f=dfs(v,min(maxflow-res,e[i].w),ed);
            res+=f;
            e[i].w-=f;
            e[i^1].w+=f;
            if(res==maxflow) return res;
        }
    }
    if(!res) dis[st] = inf;///炸点优化？？
    return res;
}
ll Dicnic(int st,int ed) {
    ll maxFlow = 0;
    while(bfs(st,ed)) {
        for(int i=1;i<=n;i++)
            cur[i]=head[i];
        maxFlow+=dfs(st,inf,ed);
    }
    return maxFlow;
}
int main()
{
    int m;
    cin>>n>>m;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    cout<<Dicnic(1,n)<<endl;
    return 0;
}