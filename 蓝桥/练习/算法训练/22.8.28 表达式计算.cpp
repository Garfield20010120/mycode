#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
stack <int> result;
stack <char> operation;
int getPriority(char op)//获取操作符的优先级
{
    if(op=='(')
        return 1;
    if(op=='+'||op=='-')
        return 2;
    if(op=='*'||op=='/')
        return 3;
}
int operate(int a,int b,char op)
{
    switch(op)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
}
void calculate()//对栈中的两个数进行运算
{
    int a=result.top();
    result.pop();
    int b=result.top();
    result.pop();
    int c=operate(b,a,operation.top());
    result.push(c);
    operation.pop();
}
int main()
{
    char s[100],num[100];
    int p=0;
    cin>>s;
    while(true)
    {
        int i=0,n;
        while(s[p]>='0'&&s[p]<='9')
        {
            num[i]=s[p];
            ++i;
            ++p;
        }
        if(s[p]=='\0')//算式全部读入
            break;
        if(i>0)//读入一个操作数
        {
            num[i]='\0';
            n=atoi(num);
            result.push(n);
        }
        else//读入一个操作符
        {
            num[0]=s[p];
            ++p;
            if(num[0]==')')
            {
                while(operation.top()!='(')
                    calculate();
                operation.pop();
            }
            else if(operation.empty()||num[0]=='('||getPriority(num[0])>getPriority(operation.top()))
//读取到的操作符的优先级大于操作符栈栈顶的操作符，则该操作符入栈
                operation.push(num[0]);
 
            else
            {
                while(!operation.empty()&&getPriority(num[0])<=getPriority(operation.top()))
//读取到的操作符的优先级小于等于操作符栈栈顶的操作符，则对结果栈进行计算，
//直到操作符栈为空或栈顶的操作符优先级大于读取到的操作符
//例如，栈中的操作符为‘+’，读取的操作符为‘*’，则直接把‘*’放入栈中，
//若栈中的操作符为‘*’，读取的操作符为‘+’，则需要把之前加的操作完成，再将‘*’入栈
                    calculate();
                operation.push(num[0]);
            }
        }
    }
    while(!operation.empty())//算式读取完毕但还有没完成的操作
        calculate();
    cout<<result.top();
    return 0;
}