#include<iostream>
#include<algorithm>
using namespace std;
 
int h[33];
 
int main()
{
//    int j[32],jj[32],
 
    string j, jj;
    cin >> j >> jj;
    int l = j.length(), ll = jj.length();
//    cout<<l<<" "<<ll<<endl;
    reverse(j.begin(), j.end());
    reverse(jj.begin(), jj.end());
    if(l < ll)
        for(int i = 0; i < ll; i++)
            h[i] = jj[i] - '0';
    else
        for(int i = 0; i < l; i++)
            h[i] = j[i] - '0';
    int jw = 0; //进位
    for(int i = 0; i < l && i < ll; i++)
    {
        h[i] = (j[i] - '0') + (jj[i] - '0') + jw;
        if(h[i] >= 10)
        {
            jw = 1;
            h[i] %= 10;
        }
        else
            jw = 0;
    }
//    for(int i=0;i<33;i++){
//        cout<<h[i];
//    }
    for(int i = 33; i >= 0; i--)
    {
        if(h[i])
        {
            int f = i;
            for(int j = f; j >= 0; j--)
                cout << h[j];
            break;
        }
    }
    cout << endl;
    return 0;
}