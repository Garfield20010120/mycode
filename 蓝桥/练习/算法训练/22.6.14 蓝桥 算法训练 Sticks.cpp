#include<iostream>
//22.6.14  ���� �㷨ѵ�� Sticks
#include<algorithm>

using namespace std;

int N;			//���ӵĸ���
int	sticks[64];	//sticks[i]: ��i+1�����ӵĳ��� 
int sum;		//���ӳ���֮�� 

//�������ܣ� ��ǰλ��cur�� ��־����flag�� ��ǰ����len�� Ŀ�곤��target				
bool f(int cur, bool flag[], int len, int target){	
	//��ǰ���� = Ŀ�곤�ȣ�����Ѱ����һ���ճ�target 
	if(len == target){
		//�ӽ�ʣ�����ľ����ʼ�� 
		for(int i=N-1; i>=0; i--){
			//�����ľ��û�б�ʹ�� 
			if(!flag[i]){
				flag[i] = true;	  	//ʹ�ø�ľ�� 
				if(!f(i, flag, sticks[i], target)){
					flag[i] = false;
					return 0;
				}
				break; 
			}
		}
		return 1;
	}else if(len < target){			//��ǰ���� < Ŀ�곤�ȣ�����Ѱ����һ���ճ�target 
		int last = 0;
		for(int i=cur-1; i>=0; i--){		//�ӵ�ǰλ������� 
			if(!flag[i] && last!=sticks[i] && sticks[i] + len<=target){
				flag[i] = true;
				if(f(i, flag, sticks[i] + len, target)){
					return 1;
				}
				flag[i] = false;
				last = sticks[i];
				//	�����ǰλ�õ�ľ���ֲܾ��ճɵ�����ʧ�ܣ����Ժ�λ��Ҳ�����ܳɹ� 
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

