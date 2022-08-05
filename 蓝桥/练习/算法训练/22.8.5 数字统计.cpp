#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int l, r, count = 0;
	cin >> l >> r;
	for(int i = l; i <= r; i++)
	{
		int num = i;
		while(num)
		{
			if(num % 10 == 2) count++;
			num /= 10;
		}
	}
	cout << count << endl;
	return 0;
}