//22.5.4���ű���ϰ-- ���� ������ϰ ���������
//123321��һ���ǳ����������������߶��ʹ��ұ߶���һ���ġ�
//����һ��������n�� �����������������λ����λʮ�������������λ����֮�͵���n �� 
#include<iostream>
#include<algorithm>
using namespace std;
int ans[1000005];
int main()
{
  int n,now,t=0;
  cin>>n;
  if(n%2==0)//ֻ��ż������6λʮ�������Ŀ���
  {
    now=n/2;
    for(int i=9;i>=1;i--)//��һλ����Ϊ0
    {
      if(now-i>=0)
      {
        for(int j=9;j>=0;j--)
        {
          if(now-i-j>=0)
          {
            for(int k=9;k>=0;k--)
            {
              if(i+j+k==now)
              {
                ans[t++]=i*100000+j*10000+k*1000+k*100+j*10+i;
              }
            }
          }
        }
      }
    }
  }
  //��λ�������
    int l;
    if(n%2==0)
    {
      l=8;
    }
    else
      l=9;
    for(int i=l;i>=0;i=i-2)//�ȿ������м�λ������������n��ż���������м��һ����ż�������n�����������м�λΪ����
    {
      if(n-i>=0)
      {
        now=(n-i)/2;
        for(int j=9;j>=1;j--)//��λ��Ϊ0
        {
          if(now-j>=0)
          {
            for(int k=9;k>=0;k--)
            {
              if(j+k==now)
                ans[t++]=j*10000+k*1000+i*100+k*10+j;
            }
          }
        
        }
      }

    }
  sort(ans,ans+t);
  for(int i=0;i<t;i++)
  {
      cout<<ans[i]<<endl;
  }
  return 0;
}

