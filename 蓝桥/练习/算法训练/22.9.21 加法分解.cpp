#include <iostream>

using namespace std;

const int N = 210;

int n, m, cnt, num;
int a[N], b[N][N]; 

void dfs1(int u) {
	if (u == 0) {
		printf("%d=", n);
		for (int i = 0; i < cnt; i ++ ) {
			if (i != cnt - 1) printf("%d+", a[i]);
			else printf("%d", a[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= u; i ++ ) {
		a[cnt] = i;
		cnt ++ ;
		dfs1(u - i);
		cnt -- ;
	}
}

bool panduan(int a[]) {
	int c[N] = {0};
	for (int i = 0; i < cnt; i ++ ) 
		c[a[i]] ++ ;
	for (int i = 0; i <= num; i ++ ) {
		bool st = false;
		for (int j = 0; j <= n; j ++ ) {
			if (c[j] != b[i][j]) st = true;
		}
		if (!st) return false;
	}
	return true;
}

void dfs2(int u) {
	if (u == 0) {
		if (panduan(a)) {
			for (int i = 0; i < cnt; i ++ ) {
				b[num][a[i]] ++ ;
				if (i == 0) printf("%d=", n);
				if (i != cnt - 1) printf("%d+", a[i]);
				else printf("%d", a[i]);
			}
			num ++ ;
			printf("\n");
		}
		return;
	}

	for (int i = 1; i <= u; i ++ ) {
		a[cnt] = i;
		cnt ++ ;
		dfs2(u - i);
		cnt -- ;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if (m == 1) dfs1(n);
	else dfs2(n);
	return 0;
}
