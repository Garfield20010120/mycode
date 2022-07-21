#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<bitset>
#include<algorithm>
#include<cstring>
#include<map>
#include<stack>
#include<set>
#include<cmath>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
 
const int maxn = 2010;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
typedef long long LL;
const LL INF = 1E15;
const int inf = 2139062143;
const int T = 8;
 
struct Event{
	int key,pos,typ;
	Event(){}
	Event(int key,int pos,int typ): key(key),pos(pos),typ(typ){}
	bool operator < (const Event &B) const{
		if (key < B.key) return 1;
		if (key > B.key) return 0;
		if (typ < B.typ) return 1;
		return 0;
	}
}E[maxn*T];
 
struct Point{
	int key,Num;
	Point(){}
	Point(int key,int Num): key(key),Num(Num){}
	bool operator < (const Point &B) const {return key < B.key;}
};
 
struct Edg{
	int to,w;
	Edg(){}
	Edg(int to,int w): to(to),w(w){}
};
 
int n,Ti,sx,sy,tx,ty,cx,cy,tox,toy,tot,ax[maxn],Mark[maxn][maxn]
	,cnt,Cnt,Begin,End,px1[maxn],py1[maxn],px2[maxn],py2[maxn],ay[maxn]
	,Left[maxn*T],Right[maxn*T],num[maxn][maxn],unable[maxn*20];
LL dis[maxn*20];
bool vis[maxn*20];
 
vector <Point> px[maxn];
vector <Point> py[maxn];
vector <Edg> v[maxn*20];
queue <int> Q;
 
int getint()
{
	char ch = getchar();
	int ret = 0,tmp = 1;
	while (ch < '0' || '9' < ch) {
		if (ch == '-') tmp = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
		ret = ret*10 + ch - '0',ch = getchar();
	return ret*tmp;
}
 
void Work()
{
	cx = cy = 1;
	sort(ax + 1,ax + tox + 1);
	for (int i = 2; i <= tox; i++)
		if (ax[i] != ax[i-1])
			ax[++cx] = ax[i];
	sort(ay + 1,ay + toy + 1);
	for (int i = 2; i <= toy; i++)
		if (ay[i] != ay[i-1])
			ay[++cy] = ay[i];
	for (int i = 1; i <= n; i++) {
		px1[i] = lower_bound(ax + 1,ax + cx + 1,px1[i]) - ax;
		py1[i] = lower_bound(ay + 1,ay + cy + 1,py1[i]) - ay;
		px2[i] = lower_bound(ax + 1,ax + cx + 1,px2[i]) - ax;
		py2[i] = lower_bound(ay + 1,ay + cy + 1,py2[i]) - ay;
	}
	sx = lower_bound(ax + 1,ax + cx + 1,sx) - ax;
	sy = lower_bound(ay + 1,ay + cy + 1,sy) - ay;
	tx = lower_bound(ax + 1,ax + cx + 1,tx) - ax;
	ty = lower_bound(ay + 1,ay + cy + 1,ty) - ay;
}
 
void Add(int x,int y) {ax[++tox] = x; ay[++toy] = y;}
void Read()
{
	sx = getint();
	sy = getint();
	tx = getint();
	ty = getint();
	tox = toy = 0;
	Add(sx,sy);
	Add(tx,ty);
	n = getint();
	for (int i = 1; i <= n; i++) {
		px1[i] = getint();
		py1[i] = getint();
		px2[i] = getint();
		py2[i] = getint();
		if (px1[i] > px2[i]) swap(px1[i],px2[i]);
		if (py1[i] > py2[i]) swap(py1[i],py2[i]);
		Add(px1[i],py1[i]);
		Add(px2[i],py2[i]);
	}
}
 
void SPFA()
{
	for (int i = 1; i <= cnt; i++)
		dis[i] = INF,vis[i] = 0;
	Q.push(Begin);
	dis[Begin] = 0;
	vis[Begin] = 1;
	while (!Q.empty()) {
		int k = Q.front(); 
		vis[k] = 0; Q.pop();
		for (int i = 0; i < v[k].size(); i++) {
			int to = v[k][i].to;
			LL w = v[k][i].w;
			if (dis[to] > dis[k] + w) {
				dis[to] = dis[k] + w;
				if (vis[to]) continue;
				vis[to] = 1;
				Q.push(to);
			}
		}
	}
	if (dis[End] == INF) puts("No Path");
	else printf("%lld\n",dis[End]);
	for (int i = 1; i <= cnt; i++) v[i].clear();
}
 
int New(int x,int y,int WA)
{
	if (Mark[x][y] == Cnt) {
		if (WA == -1)
			unable[num[x][y]] = WA;
		return -1;
	}
	Mark[x][y] = Cnt;
	++cnt;
	px[x].push_back(Point(ay[y],cnt));
	py[y].push_back(Point(ax[x],cnt));
	unable[cnt] = WA;
	num[x][y] = cnt;
	return cnt;
}
 
void Add_Edgs()
{
	for (int i = 1; i <= cx; i++) {
		if (!px[i].size()) continue;
		sort(px[i].begin(),px[i].end());
		for (int j = 1; j < px[i].size(); j++) {
			int A = px[i][j-1].Num,B = px[i][j].Num;
			int w = px[i][j].key - px[i][j-1].key;
			if (unable[A] != 0) v[A].push_back(Edg(B,w));
			if (unable[B] != 2) v[B].push_back(Edg(A,w));
		}
		px[i].clear();
	}
	for (int i = 1; i <= cy; i++) {
		if (!py[i].size()) continue;
		sort(py[i].begin(),py[i].end());
		for (int j = 1; j < py[i].size(); j++) {
			int A = py[i][j-1].Num,B = py[i][j].Num;
			int w = py[i][j].key - py[i][j-1].key;
			if (unable[A] != 1) v[A].push_back(Edg(B,w));
			if (unable[B] != 3) v[B].push_back(Edg(A,w));
		}
		py[i].clear();
	}
}
 
void Modify(int o,int l,int r,int pos,int typ)
{
	if (l == r) {
		if (typ == 1) Left[o] = Right[o] = l;
		else Left[o] = inf,Right[o] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) Modify(o<<1,l,mid,pos,typ);
	else Modify(o<<1|1,mid + 1,r,pos,typ);
	Left[o] = min(Left[o<<1],Left[o<<1|1]);
	Right[o] = max(Right[o<<1],Right[o<<1|1]);
}
 
int Lower(int o,int l,int r,int ql,int qr)
{
	if (ql > qr) return inf;
	if (ql <= l && r <= qr) return Left[o];
	int mid = (l + r) >> 1,ret = inf;
	if (ql <= mid) ret = Lower(o<<1,l,mid,ql,qr);
	if (ret < inf) return ret;
	if (qr > mid) ret = Lower(o<<1|1,mid+1,r,ql,qr);
	return ret;
}
 
int Upper(int o,int l,int r,int ql,int qr)
{
	if (ql > qr) return 0;
	if (ql <= l && r <= qr) return Right[o];
	int mid = (l + r) >> 1,ret = 0;
	if (qr > mid) ret = Upper(o<<1|1,mid+1,r,ql,qr);
	if (ret) return ret;
	if (ql <= mid) ret = Upper(o<<1,l,mid,ql,qr);
	return ret;
}
 
void Pre_Clear()
{
	sort(E + 1,E + tot + 1);
	memset(Left,127,sizeof(Left));
	memset(Right,0,sizeof(Right));
}
 
void Build()
{
	cnt = tot = 0; ++Cnt;
	Begin = New(sx,sy,-1); 
	End = New(tx,ty,-1); 
	for (int i = 1; i <= n; i++) {
		E[++tot] = Event(py1[i],px1[i],1);
		E[++tot] = Event(py2[i] + 1,px1[i],2);
		E[++tot] = Event(py1[i],px1[i],5);
		E[++tot] = Event(py2[i],px1[i],3);
		E[++tot] = Event(py1[i],px2[i],1);
		E[++tot] = Event(py2[i] + 1,px2[i],2);
		E[++tot] = Event(py1[i],px2[i],6);
		E[++tot] = Event(py2[i],px2[i],4);
	}
	E[++tot] = Event(sy,sx,3);
	E[++tot] = Event(sy,sx,6);
	E[++tot] = Event(ty,tx,3);
	E[++tot] = Event(ty,tx,6);
	Pre_Clear();
	for (int i = 1; i <= tot; i++) {
		if (E[i].typ == 1) Modify(1,1,cx,E[i].pos,1);
		else if (E[i].typ == 2) Modify(1,1,cx,E[i].pos,-1);
		else if (E[i].typ == 3 || E[i].typ == 5) {
			New(E[i].pos,E[i].key,-1);
			int po = Upper(1,1,cx,1,E[i].pos - 1);
			if (po) New(po,E[i].key,3);
		}
		else {
			New(E[i].pos,E[i].key,-1);
			int po = Lower(1,1,cx,E[i].pos + 1,cx);
			if (po < inf) New(po,E[i].key,1);
		}
	}
	
	tot = 0;
	for (int i = 1; i <= n; i++) {
		E[++tot] = Event(px1[i],py1[i],1);
		E[++tot] = Event(px2[i] + 1,py1[i],2);
		E[++tot] = Event(px1[i],py1[i],5);
		E[++tot] = Event(px2[i],py1[i],6);
		E[++tot] = Event(px1[i],py2[i],1);
		E[++tot] = Event(px2[i] + 1,py2[i],2);
		E[++tot] = Event(px1[i],py2[i],3);
		E[++tot] = Event(px2[i],py2[i],4);
	}
	E[++tot] = Event(sx,sy,3);
	E[++tot] = Event(sx,sy,6);
	E[++tot] = Event(tx,ty,3);
	E[++tot] = Event(tx,ty,6);
	Pre_Clear();
	for (int i = 1; i <= tot; i++) {
		if (E[i].typ == 1) Modify(1,1,cy,E[i].pos,1);
		else if (E[i].typ == 2) Modify(1,1,cy,E[i].pos,-1);
		else if (E[i].typ == 5 || E[i].typ == 6) {
			New(E[i].key,E[i].pos,-1);
			int po = Upper(1,1,cy,1,E[i].pos - 1);
			if (po) New(E[i].key,po,2);
		}
		else {
			New(E[i].key,E[i].pos,-1);
			int po = Lower(1,1,cy,E[i].pos + 1,cy);
			if (po < inf) New(E[i].key,po,0);
		}
	}
	Add_Edgs();
}
 
int main()
{
	#ifdef DMC
		freopen("DMC.txt","r",stdin);
	#endif
	
	cin >> Ti;
	while (Ti--) {
		Read();
		Work();
		Build();
		SPFA();
	}
	return 0;
}