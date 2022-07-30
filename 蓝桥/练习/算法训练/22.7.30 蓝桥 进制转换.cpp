#include <iostream>
#include <cmath>
using namespace std;
int n, m; 
char a[20];
int main(int argc, char** argv) {
	cin >> n >> m;
	cout << n << "=";
	int i = 0;
	while (n) {
		int temp = n % m;
		int t1 = n;
		n /= m;
		//为负数，则商先加1再取余 
		//除数*商 + 余数 = 被除数 
		if (temp < 0) {
			while (temp < 0) {
				n++;
				temp = t1 - n * m;
			}
		}
		if (temp < 10) {
			a[i++] = temp + '0';
		}
		else
			a[i++] = temp + 'A' - 10;
	}
	for (int j = i - 1; j >= 0; --j) {
		cout << a[j];
	}
	cout << "(base" << m << ")" << endl;
	return 0;
}
