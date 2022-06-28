
#include <iostream>
//22.6.28 蓝桥 共线 
#include <algorithm>
using namespace std;
int n;
double c[1600][1600]; //存储斜率 防止超出范围  注意：所开数组大小一定要比题目所给的数据范围大上不少 否者出错都不知道在哪
int main(){
    int sum=0,Max1=0,Max2=0;
    scanf("%d",&n);
    int a[n],b[n+1]; //防止超出范围
 
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
 
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]-a[j]!=0)
                c[i][j] = (double)(b[i] - b[j])/(a[i] - a[j]); // 即算出斜率出来 且注意除0错
             else
                 c[i][j] = 999;
 
        }
      //且排的范围为你排的个数加一 即i+1到n+1
        sort(c[i]+i+1,c[i]+n+1);//从高到底进行排序（只有排好序才好求出最长等序列） 找出最长的相等子序列  且放在此处节约时间
    }
 
    for(int i=1;i<n;i++){
        int p=i+1,q=i+2; // 寻找相同斜率
        for(int j=i+1;j<=n;j++){
//            printf("%.3f ",c[i][j]);
            if(c[i][p]!=c[i][q]){
                p=q;q++;
                Max1 = max(Max1,sum);
                sum = 0;
            }
            else{
                sum++;
                q++;
            }
        }
//        printf("\n");
        Max2 = max(Max1,Max2);
        sum = 0;
        Max1 = 0;
    }
    if(n<=2) //注意n的范围
        printf("%d",n);
    else
        printf("%d",Max2+2); //输出时加2
    return 0;
}
