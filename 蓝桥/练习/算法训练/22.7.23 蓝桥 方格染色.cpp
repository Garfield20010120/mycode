#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=1000010;
const int mod=1e9;
 
int f[maxn<<1],g[maxn<<1],n,m,k;
 
struct node
{
	int x,y,w;
}e[maxn];
 
int findfa(int x)
{
	if(f[x]==x) return x;
	int fx=findfa(f[x]);
	g[x]^=g[f[x]];
	return f[x]=fx;
}
 
inline int poww(int x,int y)
{
	int tmp=x,s=1;
	while(y)
	{
		if(y&1)
			s=1ll*s*tmp%mod;
		tmp=1ll*tmp*tmp%mod;
		y>>=1;
	}
	return s;
}
 
inline int cal()
{
	int N=n+m;
	for(int i=1;i<=N;i++) f[i]=i,g[i]=0;
	f[n+1]=1;
	for(int i=1;i<=k;i++)
	{
		int x=e[i].x,y=e[i].y+n;
		if(findfa(x)==findfa(y))
		{
			if(g[x]^g[y]^e[i].w)
				return 0;
		}
		int fx=findfa(x),fy=findfa(y);
		g[fx]=g[x]^g[y]^e[i].w;
		f[fx]=fy;
	}
	int cnt=0;
	for(int i=1;i<=N;i++)
		if(findfa(i)==i)
			cnt++;
	return poww(2,cnt-1);
}
 
int w,ans;
 
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
		if(e[i].x==1&&e[i].y==1)
		{
			w=i;
			continue;
		}
		if(!((e[i].x&1)|(e[i].y&1))) e[i].w^=1;
	}
	if(w)
	{
		if(e[w].w)
			for(int i=1;i<=k;i++) e[i].w^=1;
		ans=cal();
	}
	else
	{
		ans=cal();
		for(int i=1;i<=k;i++) e[i].w^=1;
		(ans+=cal())%=mod;
	}
	cout<<ans;	
}