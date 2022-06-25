#include<iostream>
//2222.6.25 比较 
//#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    int lst[n];
    for (int i = 0; i < n;i++)
    {
        cin >> lst[i];
    }
    int LR[m][4];//保存所有的L和R，依次为L1,R1,L2,R2
    for (int i = 0; i < m;i++)
    {
        scanf("%d%d%d%d", LR[i], LR[i] + 1, LR[i] + 2, LR[i] + 3);
    }
    for (int i = 0; i < m;i++)//共有m行操作
    {
        for (int j = LR[i][2]-1; j < LR[i][3]; j++)//把L2-R2之间的值与L1-R1之间的值进行比较
        {
            int count = 0;//计数
            for (int k = LR[i][0]-1; k < LR[i][1];k++)
            {
                if(lst[k]<=lst[j])//不大于
                    count++;
            }
            cout << count << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
