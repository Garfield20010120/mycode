#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
 
int s[1000][1000];
 
int dfs(int k,int n)
{
    if(s[k][n]!=0)
        return s[k][n];
    else
        s[k][n]=dfs(k,n-1)+dfs(k-1,n-1);
    return s[k][n];
}
 
int main()
{
    int a,b;
    memset(s,0,sizeof s);
    for(int i=1;i<=1000;i++)
    {
        s[1][i]=i;
        s[i][i]=1;
    }
 
    while(~scanf("%d%d",&a,&b))
    {
        int sum=0;
        if(a==0||a==b)
            sum=1;
        else
            sum=dfs(a,b);
        printf("%d\n",sum);
    }
    return 0;
}