#include  <bits/stdc++.h>
//22.6.10���ű� �㷨ѵ�� ���ķ���
using namespace std;
int N;
long long ans=1; //�տ�ʼʲôҲ����Ҳ����һ�ִ�
bool visited[10]; //��־�����õ���
void dfs(int step) //��ʾ�ӵ�step�п�ʼ��
{
    if(step>N) return ; //��������涨�����̱߽�N��������
    for(int i=1;i<=N;i++)
        if(!visited[i]) //�����һ��û�б�����
        {
            visited[i]=true; //�����λ�÷�����
            ans++; //������Ĵ�+1
            dfs(step+1); //�϶�������ͬһ�з��ˣ�������һ��
            visited[i]=false; //����
        }
    dfs(step+1); //��һ���ӵ�step�п�ʼ�ţ�����step��û��Ҳ���ԣ�����step+1�п�ʼ��Ҳ����
}
int main()
{
    cin>>N;
    dfs(1);//�ӵ�һ�п�ʼ��
    cout<<ans;
    return 0;
}

