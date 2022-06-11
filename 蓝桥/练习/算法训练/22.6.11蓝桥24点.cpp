#include<iostream>
//22.6.11 蓝桥24点 
using namespace std;

int n;					//n组测试数据 
int nums[4];			//4个数字 
int ans;				//不超过24的最大值 

//函数功能： 在有n个数的数组nums中	寻找最大的不超过24的值。
void f(int nums[], int n){
	//只有1个数时，比较最大值 
	if(n==1){
		//如果该数不大于24，更新最大值 
		if(nums[n-1]<=24){
			ans = ans<nums[n-1]?nums[n-1]:ans;
		}
		return ;
	}
	
	//遍历两个数的组合 
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			int a=nums[i], b=nums[j];
			
			nums[j] = a + b;		//加法和乘法具有交换律 
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			nums[j] = a * b;
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			nums[j] = a - b;		//减法和除法不具有交换律 
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			nums[j] = b - a;
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			if(b!=0 && a%b==0){		//除数不能为0 
				nums[j] = a / b;
				nums[i] = nums[n-1];
				f(nums, n-1);
			}
			
			if(a!=0 && b%a==0){
				nums[j] = b / a;
				nums[i] = nums[n-1];
				f(nums, n-1);
			}
			
			nums[i] = a;    //恢复现场 
			nums[j] = b;
		}
	} 
}

int main(){	
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<4; j++){
			cin >> nums[j];
		}
		ans = 0;			//不超过24的最大整数不可能为负数 
		f(nums, 4);
		cout<<ans<<endl;
	}

	return 0; 
} 

