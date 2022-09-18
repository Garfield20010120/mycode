#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int xn,xw;
	int n=0,tot=0;
 
	for(int i=1; i<=7; i++) {
		cin>>xn>>xw;
		if(xn+xw>tot) {
			tot=xn+xw;
			n=i;
		}
	}
 
	if(tot<=8) n=0;
 
	cout<<n;
 
	return 0;
}
 
 
 
/*
in:
5 3
6 2
7 2
5 3
5 4
0 4
0 6
out:
3
*/