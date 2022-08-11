#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm> //包含max()函数的头文件
using namespace std;
int num[101][101]; //记录数塔
int main(){
	int n;
	while(scanf("%d", &n) != EOF){
		memset(num, 0, sizeof(num)); //初始化数塔
		for(int i=1; i<=n; i++){
			for(int j=1; j<=i; j++){
				scanf("%d", &num[i][j]); //数塔初值
			}
		}
		for(int i=n-1; i>=1; i--){ //注意是从倒数第二层开始更新的（最后一层没有必要）
			for(int j=1; j<=i; j++){
				num[i][j] += max(num[i+1][j], num[i+1][j+1]); //dp方程，来历可以自己先想想，文末是个人想法
			}
		}
		printf("%d\n", num[1][1]);
	}
	return 0;
}
