#include<iostream>
//22.6.3���ĵĶ� 
using namespace std;
 
#define N 70000     //������2^15�����
 
int arr[N] = { 0 }, b[N] = { 0 };
 
int main() {
	int n, temp, ans = 0;
 
	cin >> n;                //�������Ǽ��� n = 4
 
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
                                            
	for (int i = 0; i < (1 << n); i++) {//��ȡ0��15�������0000(һ������ȡ)-1111(ȫȡ)
		for (int j = 0; j < n; j++) {
			if ((i & (1 << j))) {      //��j=2,�ж����ĸ�ľ��(1010)&(0010)=0010,ӵ��2ľ��
				arr[i] += b[j];		//i�Ķ����ƣ�Ϊ1�ľ���ѡ�˸�ľ������ѡ�˵ļ�����
			}
		}
	}
 
	for (int i = 0; i < (1 << n); i++) {
		//temp��i�Ĳ�����0001�Ĳ�����1110���Լ���֤
		temp = (1 << n) - 1 - i;		
 
		//ö�ٳ�tem���Ӽ����൱��ѡ��i���г��ڶ����ϳɳ��ȵ��������
        //for (int j = 0; j <= temp; j++) {
		//	if ((i&j) == 0 && arr[i] == arr[j]) {			
		//		ans = max(ans, arr[i]);
		//	}
        //}
        //���ʽ�����Ӽ����죬�����ظ��Ƚ�
        for (int j = temp; j; j = (j - 1) & temp) {
			if (arr[i] == arr[j]) {			
				ans = max(ans, arr[i]);
			}
         }
	}
 
	cout << ans << endl;
 
	return 0;
}
