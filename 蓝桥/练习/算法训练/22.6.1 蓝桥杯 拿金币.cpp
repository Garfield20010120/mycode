//22.6.1蓝桥 算法训练 拿金币
#include<iostream>
using namespace std;
int dp[1000][1000];
int dp1[1000][1000];
int n;
 
int walk(int dp[1000][1000],int i,int j)
{
    if (i >= n - 1 && j >= n - 1)
    {
        return dp[n-1][n-1];  
    }
    else if(dp1[i][j]==-1)//如果该位置尚未被访问
    {   
        if (i <n && j < n)
        {
            int r1 = dp[i][j] + walk(dp, i , j+1);
            int r2= dp[i][j] + walk(dp, i+1,j);
            dp1[i][j] = max(r1, r2);
            return max(r1, r2);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return dp1[i][j];
    }
}
 
int main()
{
    cin >> n;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cin >> dp[i][j];
            dp1[i][j] = -1;
        }
    }
    cout << walk(dp,0,0);
}
 
