#include<iostream>
//22.6.19 ���� ������
using namespace std;
int main()
{ 
  int N,M;
  cin>>N>>M;
  long long A[N+1][M+1];//��i������jʱ��εĵ�ֵ����Ա����
  long long B[N+1][M+1];//��i������jʱ��εĿͻ�����
  long long C[N+1][M+1];//��i������jʱ��ε��˾�����
   
  int i,j;
   for(i=1;i<=N;i++)
    for(j=1;j<=M;j++)
    cin>>A[i][j];

  for(i=1;i<=N;i++)
    for(j=1;j<=M;j++)
    cin>>B[i][j];

  for(i=1;i<=N;i++)
    for(j=1;j<=M;j++)
    cin>>C[i][j];

//������Ա<�ͻ���   
 for(i=1;i<=N;i++)
 {
    for(j=1;j<=M;j++)
   {
    if(A[i][j]<B[i][j])
     C[i][j]*=A[i][j];
   
  else 
  C[i][j]*=B[i][j];    
 
   }
 }
long long sum=0;
 
 for(i=1;i<=N;i++)
 {
  long long max=0;
  for(j=1;j<=M;j++)
  {
   if(C[i][j]>max)
   max=C[i][j]; 
  }
  sum+=max;
 }  
 cout<<sum;
 return 0;
}
