#include<iostream>
//22.6.20最小距离 
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
	sort(a,a+n);//给数组排序 
	for(i=0;i<n-1;i++){
			x=fabs(a[i+1]-a[i]);//做差取绝对值 
			if(x<min){
				min = x;//找最小值 
			}
	}
	printf("%d", min);
	return 0;
}
