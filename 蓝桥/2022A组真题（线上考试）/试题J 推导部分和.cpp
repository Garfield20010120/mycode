#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
#define ll long long
const int maxn=1e5+5;
ll val[maxn];
int fa[maxn];
int n,m,Q;
int find(int x){
	if(x==fa[x])return x;
	int oldfa=fa[x];
	fa[x]=find(fa[x]);
	val[x]+=val[oldfa];
	return fa[x];
}
int main(){
	cin>>n>>m>>Q;
	for(int i=0;i<=n;i++)fa[i]=i; 
    for(int i=1;i<=m;i++){
    	ll L,R,S;
    	cin>>L>>R>>S;
    	L--;
    	int fx=find(L),fy=find(R);
    		fa[fy]=fx;
    		val[fy]=val[L]-val[R]-S;
	}
	while(Q--){
		int L,R;
		cin>>L>>R;
		L--;
		int fx=find(L),fy=find(R);
		if(fx!=fy)
		cout<<"UNKNOWN"<<endl;
		else cout<<val[L]-val[R]<<endl;
	}
	return 0;
}
