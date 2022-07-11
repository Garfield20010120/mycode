#include<bits/stdc++.h>
//22.7.11 蓝桥 A的B的C次方次方
using namespace std;
typedef long long ll;
const int mod=1000000007;
ll exp_mod(ll a,ll n,ll b)
{
    ll t;
    if(n==0)return 1%b;
    if(n==1)return a%b;
    t=exp_mod(a,n/2,b);
    t=(t%b)*(t%b)%b;
    if((n&1)==1)t=(t%b)*(a%b)%b;
    return t;
}
int main()
{
    ll a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    ll tmp=0;
    tmp=exp_mod(a,exp_mod(b,c,mod-1),mod);
    printf("%lld",tmp);
    return 0;
}

