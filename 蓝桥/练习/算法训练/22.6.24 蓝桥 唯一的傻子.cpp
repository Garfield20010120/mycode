#include <iostream>
//22.6.24 蓝桥 唯一的傻子 
using namespace std;

const int N = 1000010;

int L, ne[N], t;//L为当前环的长度，ne链表的next指针

void del(int x, int k)
{
    t = x;
    for (int cnt = 0; cnt == k % L; t = ne[t], cnt ++ );//每次遍历到要删除的节点的前一个节点
    ne[t] = ne[ne[t]];//当L只有2的时候t为最终留下来的那个节点的地址
    L -- ;
}

int main()
{
    int n;
    scanf("%d", &n);
    L = n;
    for (int i = 0; i < n; i ++ )//初始化环，这里是形如0->1->2->3->0的一个地址等于元素值的环
    {
        ne[i] = (i + 1) % n;
    }
    for (int i = 1; i < n; i ++ )
    {
        int x, k;
        scanf("%d%d", &x, &k);
        del(x,k);
    }
    cout << t;
    return 0;
}
