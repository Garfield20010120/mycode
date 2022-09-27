#include <iostream>
using namespace std;
 
int main()
{
    int n,m;
    int A[50000];//存储每个学生的答案
    int temp;
    int ans[2000000];//存储同一个答案的学生的人数//这里先开始定义的数组太小了，导致错误
    int sum = 0;
    cin>>n>>m;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin>>temp;
            A[i] = (A[i]<<1) + temp;//将每个学生的答案用二进制存储起来
        }
        ans[A[i]]++;//记录每个答案的学生的人数
    }
    int r = (1<<m) - 1;
    for(int i = 0;i < n;i++)
    {
        temp = A[i] ^ r;//按位取反
        sum += ans[temp];
    }
    cout<<sum/2<<endl;
    return 0;
}