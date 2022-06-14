#include<iostream>
//22.6.14  试题 算法训练 Sticks
#include<algorithm>

using namespace std;

int N;			//棍子的个数
int	sticks[64];	//sticks[i]: 第i+1个棍子的长度 
int sum;		//棍子长度之和 

//函数功能： 当前位置cur， 标志数组flag， 当前长度len， 目标长度target				
bool f(int cur, bool flag[], int len, int target){	
	//当前长度 = 目标长度，继续寻找下一个凑成target 
	if(len == target){
		//从仅剩的最大木棍开始凑 
		for(int i=N-1; i>=0; i--){
			//如果该木棍没有被使用 
			if(!flag[i]){
				flag[i] = true;	  	//使用该木棍 
				if(!f(i, flag, sticks[i], target)){
					flag[i] = false;
					return 0;
				}
				break; 
			}
		}
		return 1;
	}else if(len < target){			//当前长度 < 目标长度，继续寻找下一个凑成target 
		int last = 0;
		for(int i=cur-1; i>=0; i--){		//从当前位置向后找 
			if(!flag[i] && last!=sticks[i] && sticks[i] + len<=target){
				flag[i] = true;
				if(f(i, flag, sticks[i] + len, target)){
					return 1;
				}
				flag[i] = false;
				last = sticks[i];
				//	如果当前位置的木棍能局部凑成但整体失败，则以后位置也不可能成功 
				if(sticks[i] + len == target){
					return 0; 
				}
			}
		}
		return 0;	
	}else{
		return 0;
	}
}

int main(){	
	cin>>N;
	while(N){
		sum = 0;
		
		for(int i=0; i<N; i++){
			cin >> sticks[i];
			sum += sticks[i];
		}
		
		sort(sticks, sticks+N);
		
		for(int i=N; i>0; i--){
			bool flag[64] = {0};
			if((sum%i == 0) && f(N, flag, sum/i, sum/i)){
				cout<<sum/i<<endl;
				break;
			}
		}
		cin >> N;
	} 
	return 0; 
} 

