#include<iostream>
//22.7.9 蓝桥 互质数个数
#include<string>
#include<vector>
using namespace std;
 
int main(){
    int n;
    vector<int>v;
    
    cin>>n;
    int ans=n;
    /*短除法分解质因子*/
    for(int i=2;i*i<=n;i++){
    	if(n%i==0) v.push_back(i);
    	while(n%i==0){
    		n/=i;
    	}
    }
    if(n>1) v.push_back(n);
    /*欧拉函数*/
    for(int i=0;i<v.size();i++){
    	ans-=ans/v[i];
    }
    cout<<ans<<endl;
    
	return 0;
}