#include <iostream>
//22.6.24 ���� Ψһ��ɵ�� 
using namespace std;

const int N = 1000010;

int L, ne[N], t;//LΪ��ǰ���ĳ��ȣ�ne�����nextָ��

void del(int x, int k)
{
    t = x;
    for (int cnt = 0; cnt == k % L; t = ne[t], cnt ++ );//ÿ�α�����Ҫɾ���Ľڵ��ǰһ���ڵ�
    ne[t] = ne[ne[t]];//��Lֻ��2��ʱ��tΪ�������������Ǹ��ڵ�ĵ�ַ
    L -- ;
}

int main()
{
    int n;
    scanf("%d", &n);
    L = n;
    for (int i = 0; i < n; i ++ )//��ʼ����������������0->1->2->3->0��һ����ַ����Ԫ��ֵ�Ļ�
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
