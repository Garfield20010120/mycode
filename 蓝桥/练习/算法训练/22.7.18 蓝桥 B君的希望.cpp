#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main()
{
    int n,hei;
    int ans = 0;
    scanf("%d%d", &n, &hei);
    int lst[n] = {0};//ɽ�ĸ߶�
    int len[n] = {0};//����������еĳ���
    for (int i = 0; i < n;i++)
        scanf("%d", lst + i);
    len[0] = 1;//��һ��ǰ��û�б���С�ģ�������1
    for (int i = 1; i < n;i++)
    {
        int Max = 0;//��¼��ĵ�������
        for (int j = 0; j < i;j++)
        {
            if (lst[i] >lst[j])//��ǰɽ��֮ǰĳһ��ɽ��
            {
                Max = max(len[j], Max);//ȡ��ĵ������� 
            }
        }
        len[i] = Max + 1;
        ans = max(len[i], ans);
    }
    cout << ans<<endl;
    system("pause");
    return 0;
}
