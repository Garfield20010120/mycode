#include<cstdio>
#include<iostream>
using namespace std;
const int mm=1111111;
const int mn=111111;
const int oo=1e9;
int node,src,dest,edge;
int ver[mm],flow[mm],cost[mm],next[mm];
int head[mn],dis[mn],q[mn],p[mn],vis[mn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0;i<node;++i)head[i]=-1,vis[i]=0;
    edge=0;
}
void addedge(int u,int v,int f,int c)
{
    ver[edge]=v,flow[edge]=f,cost[edge]=c,next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=0,cost[edge]=-c,next[edge]=head[v],head[v]=edge++;
}
bool spfa()
{
    int i,u,v,l,r=0,tmp;
    for(i=0;i<node;++i)dis[i]=oo;
    dis[q[r++]=src]=0;
    p[dest]=p[src]=-1;
    for(l=0;l!=r;(++l>=mn)?l=0:l)
        for(i=head[u=q[l]],vis[u]=0;i>=0;i=next[i])
            if(flow[i]&&dis[v=ver[i]]>(tmp=dis[u]+cost[i]))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if(vis[v])continue;
                vis[q[r++]=v]=1;
                if(r>=mn)r=0;
            }
    return p[dest]>=0;
}
int spfaflow()
{
    int i,ret=0,delta;
    while(spfa())
    {
        for(i=p[dest],delta=oo;i>=0;i=p[ver[i]])
            if(flow[i^1]<delta)delta=flow[i^1];
        for(i=p[dest];i>=0;i=p[ver[i]])
            flow[i]+=delta,flow[i^1]-=delta;
        ret+=delta*dis[dest];
    }
    return ret;
}
int a[111][111];
int i,j,k,l,n,m,ans;
int main()
{
    while(~scanf("%d",&n))
    {
        for(m=0,i=1;i<=n;++i)
            for(j=1;j<=n;++j)
            {
                scanf("%d",&a[i][j]);
                if(i<j&&a[i][j]>1)++m;
            }
        prepare(m+n+2,0,m+n+1);
        for(k=0,i=1;i<=n;++i)
            for(j=i+1;j<=n;++j)
            {
                if(a[i][j]<2)
                {
                    if(a[i][j])addedge(src,m+j,1,0);
                    else addedge(src,m+i,1,0);
                }
                else
                {
                    ++k;
                    addedge(src,k,1,0);
                    addedge(k,m+i,1,0);
                    addedge(k,m+j,1,0);
                }
            }
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                addedge(m+i,dest,1,j*2-1);
        ans=n*(n-1)*(n-2)/3+n*(n-1)/2;
        ans=(ans-spfaflow())/2;
        for(k=0,i=1;i<=n;++i)
            for(j=i+1;j<=n;++j)
                if(a[i][j]>1)
                    for(l=head[++k];l>=0;l=next[l])
                        if(!flow[l])
                        {
                            if(ver[l]-m==i)a[j][i]=1,a[i][j]=0;
                            else a[i][j]=1,a[j][i]=0;
                        }
        printf("%d\n",ans);
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                printf("%d%c",a[i][j],j<n?' ':'\n');
    }
    return 0;
}
 