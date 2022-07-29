#include<cstdio>
#include<algorithm>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
char num[45];
long long int change(int a,int b)
{
    long long int sum=0;
    for(int i=a;i<=b;i++)
    {
        sum*=10;
        sum+=num[i]-'0';
    }
    return sum;
}
int main()
{
    long long int dp[45][8];
    int n,k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    getchar();
    for(int i=0; i<n; i++)
    {
        scanf("%c",&num[i]);
        dp[i][0]=change(0,i);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int u=0;u<i;u++)
            {
                dp[i][j]=max(dp[i][j],dp[u][j-1]*change(u+1,i));
            }
        }
    }
    printf("%I64d",dp[n-1][k]);
    return 0;
}

————————————————
版权声明：本文为CSDN博主「langzitan123」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/langzitan123/article/details/80098537