#include<iostream>
//22.6.13 ���� ʿ��ɱ�� 
#include<cstdio>

using namespace std;

int N;			//ʿ���ĸ���
int	M;			//ָ�������
int a[1000000]; //a[i]: ��[1...i]��ʿ����ɱ�и����ĺ� 
char str[10];   //ָ��						

int main(){	
	while(scanf("%d%d", &N, &M)!=EOF){
		for(int i=1; i<=N; i++){
			scanf("%d", &a[i]);
			a[i] += a[i-1]; 
		}
		for(int i=0; i<M; i++){
			int c, d;
			scanf("%s%d%d", str, &c, &d);
			if(str[0] == 'A'){
				for(int j=c; j<=N; j++){
					a[j] += d;
				}
			}else{
				printf("%d\n", a[d]-a[c-1]);
			}
		}

	}
	
	return 0; 
} 

