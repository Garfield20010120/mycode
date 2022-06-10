#include  <bits/stdc++.h>
//22.6.10蓝桥杯 算法训练 车的放置
using namespace std;
int N;
long long ans=1; //刚开始什么也不放也属于一种答案
bool visited[10]; //标志被放置的列
void dfs(int step) //表示从第step行开始放
{
    if(step>N) return ; //如果超过规定的棋盘边界N，跳出。
    for(int i=1;i<=N;i++)
        if(!visited[i]) //如果这一列没有被放置
        {
            visited[i]=true; //在这个位置放置它
            ans++; //该情况的答案+1
            dfs(step+1); //肯定不能在同一行放了，跳到下一行
            visited[i]=false; //回溯
        }
    dfs(step+1); //不一定从第step行开始放（即第step行没有也可以），从step+1行开始放也可以
}
int main()
{
    cin>>N;
    dfs(1);//从第一行开始搜
    cout<<ans;
    return 0;
}

