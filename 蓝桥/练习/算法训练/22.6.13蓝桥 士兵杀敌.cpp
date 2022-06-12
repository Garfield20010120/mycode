#include<iostream>
//22.6.13 蓝桥 士兵杀敌 
#include<cstdio>

using namespace std;

int N;			//士兵的个数
int	M;			//指令的条数
int a[1000000]; //a[i]: 第[1...i]个士兵的杀敌个数的和 
char str[10];   //指令						

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

