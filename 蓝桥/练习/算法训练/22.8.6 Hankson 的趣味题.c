#include<stdio.h>
//辗转相除法求最大公因数
int gcd(int x, int y)
{
    return !y?x:gcd(y,x%y);
}
int main()
{
    int n,i,x,y;
    scanf("%d",&n);
    //开始对n组数据处理
    for(i=0; i<n; i++)
    {
        int a0,a1,b0,b1;
        int ans=0;
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        //枚举从1到sqrt(b)的数
        for(x=1; x*x<=b1; x++)
        {
            if(b1%x==0)
            {
                //运用我们分析的1，2，3判断
                if(x%a1==0&&gcd(x/a1,a0/a1)==1&&gcd(b1/b0,b1/x)==1)
                {
                    //如果成立那就加一
                    ans++;
                }
                //由b1=x*y可以直接得出另一个因数即y             
                y=b1/x;
                if(x==y)
                {
                    continue;
                }
                 if(y%a1==0&&gcd(y/a1,a0/a1)==1&&gcd(b1/b0,b1/y)==1)
                {
                    ans++;
                }
            }
        }
        //输出ans(符合条件的因子的个数即可)
        printf("%d\n",ans);
    }
       return 0;
}



