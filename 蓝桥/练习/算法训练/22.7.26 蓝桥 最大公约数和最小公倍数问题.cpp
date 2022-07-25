#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int x,y,mul,cnt;
int main()
{
    cin >> x >> y;
    mul=x*y;
    for(int i=1;i*i<=mul;i++)
    {
        if(mul%i==0&&__gcd(i,mul/i)==x) cnt+=2;
    }
    cout << cnt << endl;

    return 0;
}

