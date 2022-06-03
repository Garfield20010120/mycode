#include<iostream>
//22.6.3无聊的逗 
using namespace std;
 
#define N 70000     //得容纳2^15种情况
 
int arr[N] = { 0 }, b[N] = { 0 };
 
int main() {
	int n, temp, ans = 0;
 
	cin >> n;                //下面我们假设 n = 4
 
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
                                            
	for (int i = 0; i < (1 << n); i++) {//抽取0到15的情况，0000(一个都不取)-1111(全取)
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j))) {      //当j=2,判断有哪根木棍(1010)&(0010)=0010,拥有2木棍
				arr[i] += b[j];		//i的二进制，为1的就是选了该木棍，把选了的加起来
			}
		}
	}
 
	for (int i = 0; i < (1 << n); i++) {
		//temp是i的补集，0001的补集是1110。自己验证
		temp = (1 << n) - 1 - i;		
 
		//枚举出tem的子集，相当于选定i后，列出第二根合成长度的所有情况
        //for (int j = 0; j <= temp; j++) {
		//	if ((i&j) == 0 && arr[i] == arr[j]) {			
		//		ans = max(ans, arr[i]);
		//	}
        //}
        //这个式子求子集更快，避免重复比较
        for (int j = temp; j; j = (j - 1) & temp) {
			if (arr[i] == arr[j]) {			
				ans = max(ans, arr[i]);
			}
         }
	}
 
	cout << ans << endl;
 
	return 0;
}
