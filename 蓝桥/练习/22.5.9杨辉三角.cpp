//����������ֳ�Pascal�����Σ����ĵ�i+1����(a+b)i��չ��ʽ��ϵ����
//����һ����Ҫ�����ǣ��������е�ÿ�����ֵ����������ϵ�������ӡ�����n���������ǰn�С�
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
