
#include <iostream>
//22.6.28 ���� ���� 
#include <algorithm>
using namespace std;
int n;
double c[1600][1600]; //�洢б�� ��ֹ������Χ  ע�⣺���������Сһ��Ҫ����Ŀ���������ݷ�Χ���ϲ��� ���߳�����֪������
int main(){
    int sum=0,Max1=0,Max2=0;
    scanf("%d",&n);
    int a[n],b[n+1]; //��ֹ������Χ
 
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
 
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]-a[j]!=0)
                c[i][j] = (double)(b[i] - b[j])/(a[i] - a[j]); // �����б�ʳ��� ��ע���0��
             else
                 c[i][j] = 999;
 
        }
      //���ŵķ�ΧΪ���ŵĸ�����һ ��i+1��n+1
        sort(c[i]+i+1,c[i]+n+1);//�Ӹߵ��׽�������ֻ���ź���ź����������У� �ҳ�������������  �ҷ��ڴ˴���Լʱ��
    }
 
    for(int i=1;i<n;i++){
        int p=i+1,q=i+2; // Ѱ����ͬб��
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
    if(n<=2) //ע��n�ķ�Χ
        printf("%d",n);
    else
        printf("%d",Max2+2); //���ʱ��2
    return 0;
}
