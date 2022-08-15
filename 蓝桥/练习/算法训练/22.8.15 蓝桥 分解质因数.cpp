#include <iostream>
#include <cstring>
 
using namespace std;
 
const int MAX=10002;
 
bool is_prime(int x)
{
    if(x<2) return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
 
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        for(int i=a;i<=b;i++)
        {
            cout<<i<<"=";
            if(is_prime(i))
            {
                cout<<i<<endl;
                continue;
            }
            int temp=i;
            int k=2;
            bool flag=0;
            while(k*k<=i)
            {
                if(temp%k==0)
                {
                    if(flag)
                    {
                        cout<<"*";
                    }
                    cout<<k;
                    temp/=k;flag=1;
 
                }
                else
                {
                    k++;
                }
            }
            if(temp!=1)
                cout<<"*"<<temp<<endl;
            else
                cout<<endl;
        }
    }
    return 0;
}