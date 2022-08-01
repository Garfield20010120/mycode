// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int maxn=100005;
const double eps=1e-4;
const double inf=1e15;

int n,L,R,cnt,last[maxn],dep[maxn],mx[maxn],son[maxn],tim,dfn[maxn],num[maxn];
struct edge{int to,next,w;double val;}e[maxn*2];
struct tree{int l,r;double mx;}t[maxn*5];
double ans,tmp[maxn],dis[maxn];


void addedge(int u,int v,int w)
{
    e[++cnt].to=v;e[cnt].w=w;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].w=w;e[cnt].next=last[v];last[v]=cnt;
}

void pre_dfs1(int x,int fa)
{
    dep[x]=dep[fa]+1;mx[x]=dep[x];
    for (int i=last[x];i;i=e[i].next)
    {
        if (e[i].to==fa) continue;
        pre_dfs1(e[i].to,x);
        mx[x]=max(mx[x],mx[e[i].to]);
        if (mx[e[i].to]>mx[son[x]]) son[x]=e[i].to;
    }
}

void pre_dfs2(int x,int fa)
{
    dfn[x]=++tim;
    if (son[x]) pre_dfs2(son[x],x);
    for (int i=last[x];i;i=e[i].next)
        if (e[i].to!=fa&&e[i].to!=son[x]) pre_dfs2(e[i].to,x);
}

void build(int d,int l,int r)
{
    t[d].mx=-inf;
    if (l==r)
    {
        num[l]=d;
        return;
    }
    int mid=(l+r)/2;
    build(d*2,l,mid);build(d*2+1,mid+1,r);
}

void modify(int d,int l,int r,int x,double y)
{
    if (l==r)
    {
        t[d].mx=max(t[d].mx,y);
        return;
    }
    int mid=(l+r)/2;
    if (x<=mid) modify(d*2,l,mid,x,y);
    else modify(d*2+1,mid+1,r,x,y);
    t[d].mx=max(t[d*2].mx,t[d*2+1].mx);
}

double query(int d,int l,int r,int x,int y)
{
    if (x>y) return -inf;
    if (l==x&&r==y) return t[d].mx;
    int mid=(l+r)/2;
    return max(query(d*2,l,mid,x,min(y,mid)),query(d*2+1,mid+1,r,max(x,mid+1),y));
}

void dfs(int x,int fa)
{
    modify(1,1,n,dfn[x],dis[x]);
    for (int i=last[x];i;i=e[i].next)
        if (e[i].to==son[x]) dis[e[i].to]=dis[x]+e[i].val,dfs(e[i].to,x);
    for (int i=last[x];i;i=e[i].next)
    {
        if (e[i].to==fa||e[i].to==son[x]) continue;
        dis[e[i].to]=dis[x]+e[i].val;
        dfs(e[i].to,x);
        for (int j=1;j<=mx[e[i].to]-dep[x];j++)
        {
            tmp[j]=t[num[dfn[e[i].to]+j-1]].mx;
            if (j<=R) ans=max(ans,query(1,1,n,max(1,dfn[x]+L-j),min(dfn[x]+mx[x]-dep[x],dfn[x]+R-j))+tmp[j]-2*dis[x]);
        }
        for (int j=1;j<=mx[e[i].to]-dep[x];j++) modify(1,1,n,dfn[x]+j,tmp[j]);
    }
    ans=max(ans,query(1,1,n,dfn[x]+L,min(dfn[x]+mx[x]-dep[x],dfn[x]+R))-dis[x]);
}

int main()
{
    scanf("%d%d%d",&n,&L,&R);
    for (int i=1;i<n;i++)
    {
    	int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }
    pre_dfs1(1,0);
    pre_dfs2(1,0);
    double l=0,r=1000000;t[0].mx=-inf;
    while (r-l>eps)
    {
        double mid=(l+r)/2;
        for (int i=1;i<=cnt;i++) e[i].val=e[i].w-mid;
        ans=-inf;dis[1]=0;
        build(1,1,n);
        dfs(1,0);
        if (ans<=0) r=mid;
        else l=mid;
    }
    printf("%.3lf",l);
}
