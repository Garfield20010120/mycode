//���� ������Ϸ����ȫ���з� 
#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;
int main(){
	vector<int>a;
	int n,sum;
	cin>>n>>sum;
	for(int i=1;i<=n;i++)
		a.push_back(i);//��1~n֮�����װ������a 
	do{
		vector<int>b=a;//��1~n��һ������a��ֵ��b���в����������ı�a 
		//ÿһ���жϣ�Ҫ��n-1����У�ÿ��Ҫ����n-1-i�� 
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-1-i;j++){
				b[j]+=b[j+1]; 
			}
		}
		//���ĺ�һ���ǵ�һ�����֣���Ϊb[0] 
		if(b[0]==sum){
			for(int k=0;k<n;k++){
				cout<<a[k]<<" ";
			}
			cout<<endl;
			break;
		}
	}while(next_permutation(a.begin(),a.end()));
	//����ȫ���У�ÿ�ν�����洢�ڶ�̬����a�У���1~n���������н����󷵻�false��ֹѭ�� 
	return 0;
}
