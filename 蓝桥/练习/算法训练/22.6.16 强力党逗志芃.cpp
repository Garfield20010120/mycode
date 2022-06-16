#include<iostream>
//22.6.16 ǿ������־�M
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 210;

int n,m;
int q[N];
int h[N],e[N],ne[N],idx;
int dp[N][N];//��iΪ���ڵ㣬�ܻ��ѵĵ���������j����󷽰�
bool st[N];//�Ƿ���ǰ��
int res = 0;//�˺�������ֵ


void add(int x,int y)
{
    e[idx] = y,ne[idx] = h[x],h[x] = idx++;
}

void dfs(int u)
{
    for(int i = h[u];i != -1; i = ne[i])//ѭ����Ʒ��
    {
        int son = e[i];
        dfs(son);

        for(int j = m - 1; j >= 0; j--)//ѭ��ʣ��ĵ���
            for(int k = 0; k <= j; k++)//ѭ������
                dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[son][k]);
    }

    //����ǰ�Ľڵ�1
    for(int i = m; i >= 1; i--) dp[u][i] = dp[u][i - 1] + q[u];
    dp[u][0] = 0;
}

int main()
{
    cin >> n >> m;
    memset(h, -1 ,sizeof h);

    for(int i = 1; i <= n; i++)//��ȡÿ���ڵ��ֵ
        cin>>q[i];

    for(int i = 1; i < n; i++)//��ȡ�ڵ�֮��Ĺ�ϵ
    {
        int x,y;
        cin >> x >> y;
        add(x,y);//xΪy�ĸ��ڵ�
        st[y] = true;
    }

    int root;//Ѱ�Ҹ��ڵ�
    for(int i = 1; i <= n; i++)
        if(st[i] == false){
            root = i;
            break;
        }
    
    dfs(root);
	
    cout << dp[root][m] << endl;

    return 0;
}

