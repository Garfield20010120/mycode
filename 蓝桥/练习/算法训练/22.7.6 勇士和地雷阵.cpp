#include<iostream>
//22.7.6 蓝桥  勇士和地雷阵
#include<algorithm>
#include<queue>
#include<cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 510;

int n;
char g[N][N];
int dist[N][N];

void bfs(int a, int b)//求a,b点到其他能到的点的距离
{
    queue<PII> store;
    store.push({a, b});
    dist[a][b] = 0;

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    while(store.size())
    {
        pair<int, int> temp = store.front();
        store.pop();

        for(int i = 0; i < 4; i++){
            int nx = temp.x + dx[i], ny = temp.y + dy[i];
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > n - 1) continue;
            if(dist[nx][ny] != 0) continue;
            if(g[nx][ny] == '*') continue;
            dist[nx][ny] = dist[temp.x][temp.y] + 1;
            store.push({nx, ny});
        }
    }

}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)  scanf("%s", &g[i]);
    
    bfs(0,0);
    int x,y,z;
    while(cin >> x >> y >> z){
        if(x == 0 && y == 0) cout << 1 << endl;
        else
            if(dist[x][y] != 0 && dist[x][y] <= z) cout << 1 << endl;
                else cout << -1 << endl;

    }
}

