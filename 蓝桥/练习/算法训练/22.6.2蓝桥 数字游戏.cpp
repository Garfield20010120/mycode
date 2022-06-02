//蓝桥 数字游戏——全排列法 
#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
int main(){
	vector<int>a;
	int n,sum;
	cin>>n>>sum;
	for(int i=1;i<=n;i++)
		a.push_back(i);//将1~n之间的数装进数组a 
	do{
		vector<int>b=a;//将1~n的一种排列a赋值给b进行操作，而不改变a 
		//每一次判断，要对n-1层进行，每层要计算n-1-i次 
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1-i;j++){
				b[j]+=b[j+1]; 
			}
		}
		//最后的和一定是第一个数字，即为b[0] 
		if(b[0]==sum){
			for(int k=0;k<n;k++){
				cout<<a[k]<<" ";
			}
			cout<<endl;
			break;
		}
	}while(next_permutation(a.begin(),a.end()));
	//进行全排列，每次将结果存储在动态数组a中，当1~n的所有排列结束后返回false终止循环 
	return 0;
}
