#include<iostream>
//22.6.20��С���� 
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
 
int main(){
	long int i, n, a[100001], j, x, min=10000000;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	sort(a,a+n);//���������� 
	for(i=0;i<n-1;i++){
			x=fabs(a[i+1]-a[i]);//����ȡ����ֵ 
			if(x<min){
				min = x;//����Сֵ 
			}
	}
	printf("%d", min);
	return 0;
}
