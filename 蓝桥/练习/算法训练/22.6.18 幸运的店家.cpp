#include<iostream>
//22.6.18�㷨ѵ�� ���˵ĵ�� 
#include<algorithm>

using namespace std;

long long int n;			
long long int ans;

int main(){	
	cin>>n;
	if (n % 3) {
		ans = (n / 3) + 1;
	}
    else {
        while (n % 3 == 0){
        	n /= 3;
        } 
        ans = (n / 3) + 1;
    }
    
    cout << ans << endl;
	return 0; 
} 

