//边数比较多，用狄杰特斯拉算法
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 10005;           //结点数上限（牧场数）
const int MAX_P = 100005;          //边数上限（道路数）
int father[MAX_N];           //保存N个结点的父结点
int node[MAX_N];         //保存N个结点（牧场）
struct EDGE{
    int s;   //源点
    int d;    //目的点
    int value;  //权值
}edge[MAX_P];

//找到x号结点的父结点
int find(int x){
    if (father[x] == x)            //找到了根结点
        return x;
    else{
        int grandFather = find(father[x]);           //找父结点的父结点
        father[x] = grandFather;                          
        return grandFather;
    }
}

//自定义小于，用于sort算法
int sort_Edge(const EDGE& a, const EDGE &b){
    return a.value < b.value;
}
int main(){
    int n,p;
    scanf("%d%d", &n, &p);
    int minn = 10000;
    for (int i = 1; i <= n; i++){
        scanf("%d", &node[i]);
        father[i] = i;
        if (node[i] < minn)
            minn = node[i];
    }
    for (int j = 1; j <= p; j++){
        int from, to, value;
        scanf("%d%d%d", &from, &to, &value);
        edge[j].s = from;
        edge[j].d = to;
        edge[j].value = node[from] + node[to] + 2 * value;        //每条边的权值等价于两连接结点权重加上两倍边的权重
    }
    sort(edge + 1, edge + 1 + p,sort_Edge);
    //要取n-1条边
    int sum = 0;
    int count = 0;     //记数，选择到了n-1条边即最小生成树构造完成，退出循环
    for (int k = 1; k <= p; k++){
        if (count == n - 1)
            break;
        int fatherA = find(edge[k].s);
        int fatherB = find(edge[k].d);
        if (fatherA != fatherB){        //如果edge[k]的s和d结点不是同一个父亲，也就是不形成环，即选择
            sum += edge[k].value;
            father[fatherB] = fatherA;          //写成father[edge[k].d] = edge[k].s   是不对的！！！因为在算的过程张是有方向的，这样可能会导致原来连上的线路断开
            count++;
        }
    }
    sum += minn;        //最后加上结点权值最小的结点
    cout << sum << endl;
    return 0;
}