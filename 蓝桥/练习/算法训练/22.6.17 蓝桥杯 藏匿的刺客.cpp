#include <bits/stdc++.h>
//22.6.17 À¶ÇÅ±­ ²ØÄäµÄ´Ì¿Í 
using namespace std;
const int N = 1010;
struct Range{
	int l , r;

	bool operator<(const Range &w) const{
		return r < w.r;
	}
}range[N];

int n;

int main(){
	cin >> n;
	
	for (int  i = 0 ; i < n ; i ++ )
		cin >> range[i].l >> range[i].r;

	sort(range, range + n);
    
	int minr = range[0].r;
	
    int res = 1;
    for (int i = 1; i < n ; i ++)
        if (range[i].l > minr){
            res ++;
            minr = range[i].r;
        }

	cout << res << endl;

	return 0;
}
