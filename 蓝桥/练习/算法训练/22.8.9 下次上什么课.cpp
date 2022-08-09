#include<bits/stdc++.h>
using namespace std;
int num[10];
int f(int H,int T){
	if(T == 0){
		num[H]++;
		return 1;
	}
	if(H == 1){
		return f(2,T - 1) + f(4,T - 1);
	}
	if(H == 2){
		return f(3,T - 1);
	}
	if(H == 3){
		return f(1,T - 1) + f(2,T - 1);
	}
	if(H == 4){
		return f(3,T - 1) + f(1,T - 1);
	} 
}
int main(){
	int H,T;
	cin>>H>>T;
	int S = f(H,T);
	int max = num[1],P = 1;
	for(int i = 2;i <= 4;i++){
		if(num[i] > max){
			max = num[i];
			P = i;
		}
	}
	cout<<P<<" "<<S<<endl;
	return 0;
} 