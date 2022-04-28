#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
const long long Mod =998244353ll;
int n;
long long ans=0;
long long quickpow(long long x, long long y)
{
	long long re=1ll;
	while(y)
	{
		if(y&1ll) re=re*x%Mod;
		x=x*x% Mod;
		y>>=1;
	}
	return re;
}

int main()
{
	long long x, y;
	scanf("%d",&n);
	for(long long i=1ll;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		ans=(ans+1ll)*y%Mod*quickpow(y-x,Mod-2ll)%Mod;
		ans=(ans+Mod)%Mod;
	}
	printf("%lld",ans);
	return 0;
}

