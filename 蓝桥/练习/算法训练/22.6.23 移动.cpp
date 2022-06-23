#include<bits/stdc++.h>
//22.6.23 移动 
using namespace std;
int num[1000005];
//所有变量的范围都没有超过2的十次方所以int类型可以满足该题；
int main()
{
    int n,m,k;
    //输入部分；
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int start = 0,mov;   //输出的起点位置和移动步数；
    for(int j = 0; j < m; j++)
    {
        cin >> mov;
        mov %= n;//将移动步数缩小到[-n，n]；
        if(mov < 0)//将移动步数缩小到[1，n]；
            mov = n+mov;
        start = (start+mov)%n;//改变输出起点；
        //输出部分；
        for(int i = start; i <start+k; i++)
        {
            i == start ? cout << num[i%n] : cout << " " << num[i%n];//注意可能start+i可能大于n，需要取余；
            //控制输出格式；
        }
        if(j != m-1)cout << endl;//控制输出格式；
    }
    return 0;
}
