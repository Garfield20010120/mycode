#include<iostream>
//2222.6.25 �Ƚ� 
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
    int LR[m][4];//�������е�L��R������ΪL1,R1,L2,R2
    for (int i = 0; i < m;i++)
    {
        scanf("%d%d%d%d", LR[i], LR[i] + 1, LR[i] + 2, LR[i] + 3);
    }
    for (int i = 0; i < m;i++)//����m�в���
    {
        for (int j = LR[i][2]-1; j < LR[i][3]; j++)//��L2-R2֮���ֵ��L1-R1֮���ֵ���бȽ�
        {
            int count = 0;//����
            for (int k = LR[i][0]-1; k < LR[i][1];k++)
            {
                if(lst[k]<=lst[j])//������
                    count++;
            }
            cout << count << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
