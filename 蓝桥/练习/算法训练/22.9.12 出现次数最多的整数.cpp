#include<iostream>
#include<map>
using namespace std;
map<int,int> mp;
map<int,int> ::iterator it;
int main()
{
    int n;
    cin>>n;
    if(n<=0)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    it=mp.begin();
    int maxn=it->first;
    for(it=mp.begin();it!=mp.end();it++)
    {
        if(it->second>mp[maxn])
        {
            maxn=it->first;
        }
    }
    cout<<maxn<<endl;
    return 0;
}

