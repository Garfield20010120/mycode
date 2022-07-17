#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main()
{
    int n,hei;
    int ans = 0;
    scanf("%d%d", &n, &hei);
    int lst[n] = {0};//山的高度
    int len[n] = {0};//保存递增序列的长度
    for (int i = 0; i < n;i++)
        scanf("%d", lst + i);
    len[0] = 1;//第一个前面没有比他小的，所以是1
    for (int i = 1; i < n;i++)
    {
        int Max = 0;//记录最长的递增序列
        for (int j = 0; j < i;j++)
        {
            if (lst[i] >lst[j])//当前山比之前某一座山高
            {
                Max = max(len[j], Max);//取最长的递增序列 
            }
        }
        len[i] = Max + 1;
        ans = max(len[i], ans);
    }
    cout << ans<<endl;
    system("pause");
    return 0;
}
