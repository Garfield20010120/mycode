//22.5.4蓝桥杯练习-- 试题 基础练习 特殊回文数
//123321是一个非常特殊的数，它从左边读和从右边读是一样的。
//输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。 
#include<iostream>
#include<algorithm>
using namespace std;
int ans[1000005];
int main()
{
  int n,now,t=0;
  cin>>n;
  if(n%2==0)//只有偶数才有6位十进制数的可能
  {
    now=n/2;
    for(int i=9;i>=1;i--)//第一位不能为0
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
  //五位数的情况
    int l;
    if(n%2==0)
    {
      l=8;
    }
    else
      l=9;
    for(int i=l;i>=0;i=i-2)//先考虑最中间位数的情况，如果n是偶数，则最中间的一定是偶数，如果n是奇数，则中间位为奇数
    {
      if(n-i>=0)
      {
        now=(n-i)/2;
        for(int j=9;j>=1;j--)//首位不为0
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

