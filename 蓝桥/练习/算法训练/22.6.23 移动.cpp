#include<bits/stdc++.h>
//22.6.23 �ƶ� 
using namespace std;
int num[1000005];
//���б����ķ�Χ��û�г���2��ʮ�η�����int���Ϳ���������⣻
int main()
{
    int n,m,k;
    //���벿�֣�
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int start = 0,mov;   //��������λ�ú��ƶ�������
    for(int j = 0; j < m; j++)
    {
        cin >> mov;
        mov %= n;//���ƶ�������С��[-n��n]��
        if(mov < 0)//���ƶ�������С��[1��n]��
            mov = n+mov;
        start = (start+mov)%n;//�ı������㣻
        //������֣�
        for(int i = start; i <start+k; i++)
        {
            i == start ? cout << num[i%n] : cout << " " << num[i%n];//ע�����start+i���ܴ���n����Ҫȡ�ࣻ
            //���������ʽ��
        }
        if(j != m-1)cout << endl;//���������ʽ��
    }
    return 0;
}
