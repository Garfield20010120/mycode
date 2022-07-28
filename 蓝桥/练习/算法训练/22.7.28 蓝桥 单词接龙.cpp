#include <bits/stdc++.h>
using namespace std;
int n, avl[21], maxn; char ch;
struct QString {
    string _c_str;
    void init() { cin >> _c_str; }
    void append(string _str) { _c_str.append(_str); }
    int size() { return _c_str.size(); }
    char head() { return _c_str.at(0); }
    string left(int _n){ 
        string _str;
        _str.resize(_n);
        for(int i = 0; i < _n; i ++) _str[i] = _c_str.at(i);
        return _str;
    }
    string right(int _n) {
        string _str;
        _str.resize(_n);
        for(int i = _c_str.size() - _n; i < _c_str.size(); i ++)
            _str[i - _c_str.size() + _n] = _c_str.at(i);
        return _str;
    }
} a[21], __str__;
int linkable(QString _a, QString _b) {
    int size = min(_a.size(),_b.size()) - 1;
    for(int i = 1; i <= size; i ++)
        if(_a.right(i) == _b.left(i))
            return i;
    return 0;
}
void dfs(string _str, int k) {
    avl[k] ++;
    QString _l_str__ = __str__;
    __str__.append(_str);
    maxn = max(maxn, __str__.size());
    for(int i = 1; i <= n; i ++)
        if(avl[i] < 2 && linkable(__str__, a[i]))
            dfs(a[i].right(a[i].size() - linkable(__str__, a[i])), i);
    avl[k] --;
    __str__ = _l_str__;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) a[i].init();
    cin >> ch;
    for(int i = 1; i <= n; i ++)
        if(a[i].head() == ch)
            dfs(a[i]._c_str,i);
    printf("%d", maxn);
    return 0;
}