//杨辉三角形又称Pascal三角形，它的第i+1行是(a+b)i的展开式的系数。
//它的一个重要性质是：三角形中的每个数字等于它两肩上的数字相加。给出n，输出它的前n行。
#include<stdio.h>
#define N 35
 
int main()
{
    int n=0,a[N][N];
    scanf("%d",&n);
    a[0][0]=1;
 
    for(int i=1;i<n;i++)
    {
        a[i][0]=1;
        for(int j=1;j<i;j++)
            a[i][j] = a[i-1][j-1]+a[i-1][j];
        a[i][i]=1;
    }
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
        
    return 0;
}
