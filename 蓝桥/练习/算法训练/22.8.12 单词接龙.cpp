#include <iostream>

using namespace std;

int n;
string s[22], ln;
char c;
int b[105];
int l;

void dfs()//还未判断每个单词只能使用两次
{
	string z;
	for (int j = ln.length() - 1; j >=0; j--)
	{
		z.append(ln.begin() + j, ln.end());

		for (int k = 0; k < n; k++)
		{
			if (b[k]< 2 && s[k].compare(0, z.length(), z) == 0)
			{
				b[k]++;
				int o = ln.length();
				int p = s[k].length() - j;
				ln.append(s[k].begin() + (ln.length() - j), s[k].end());
				if (ln.length() > l)
				{
					l = ln.length();
				}

				dfs();
				b[k]--;
				ln.erase(o, ln.length() - 1);
			}
		}
		z.clear();
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cin >> c;

	ln = c;
	dfs();
cout << l;

return 0;
}
