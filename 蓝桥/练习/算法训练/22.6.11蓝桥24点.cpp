#include<iostream>
//22.6.11 ����24�� 
using namespace std;

int n;					//n��������� 
int nums[4];			//4������ 
int ans;				//������24�����ֵ 

//�������ܣ� ����n����������nums��	Ѱ�����Ĳ�����24��ֵ��
void f(int nums[], int n){
	//ֻ��1����ʱ���Ƚ����ֵ 
	if(n==1){
		//�������������24���������ֵ 
		if(nums[n-1]<=24){
			ans = ans<nums[n-1]?nums[n-1]:ans;
		}
		return ;
	}
	
	//��������������� 
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			int a=nums[i], b=nums[j];
			
			nums[j] = a + b;		//�ӷ��ͳ˷����н����� 
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			nums[j] = a * b;
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			nums[j] = a - b;		//�����ͳ��������н����� 
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			nums[j] = b - a;
			nums[i] = nums[n-1];
			f(nums, n-1);
			
			if(b!=0 && a%b==0){		//��������Ϊ0 
				nums[j] = a / b;
				nums[i] = nums[n-1];
				f(nums, n-1);
			}
			
			if(a!=0 && b%a==0){
				nums[j] = b / a;
				nums[i] = nums[n-1];
				f(nums, n-1);
			}
			
			nums[i] = a;    //�ָ��ֳ� 
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
		ans = 0;			//������24���������������Ϊ���� 
		f(nums, 4);
		cout<<ans<<endl;
	}

	return 0; 
} 

