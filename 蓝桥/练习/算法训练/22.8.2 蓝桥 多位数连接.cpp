#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    if (a + b > b + a) return true;
    return false;
}

int main()
{
    int n;
    string num[21];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }
    sort(num, num + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        cout << num[i];
    }
    putchar('\n');
    system("pause");
    return 0;
}
