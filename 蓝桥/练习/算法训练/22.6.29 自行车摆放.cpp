#include <bits/stdc++.h>
//22.6.29 ���г��ڷ� 
using namespace std;
 
list<int>::iterator loc[100003];       //������ר�ż�¼ÿ�����г���ŵĴ洢��ַ 
 
int main(){
	int num;
	cin>>num;   //���г�����
	list<int> row;
	int x;
	cin>>x;
	row.push_back(x);
	loc[x]=row.begin();  //��һ�����г��ĵ�ַ
	list<int>::iterator temp=row.begin();
	for(int i=0;i<num-1;i++){
		int n;        //��һ��Ҫͣ�����г����
		int a;        //ͣ���������Ա�
		int pos;      //ͣ����߻����ұ�   0��1��
		cin>>n>>a>>pos;
		temp=loc[a];    //�ҵ�a�ĵ�ַ 
		switch(pos){
			case 0:
				row.insert(temp,n);
				loc[n]=--temp;   //��¼n�ĵ�ַ 
				break;
			case 1:
				row.insert(++temp,n);   //a�ĺ�һ����ַ 
				loc[n]=--temp;
				break;
		}
	}
	for(list<int>::iterator it=row.begin();it!=row.end();it++)
		cout<<*it<<" ";
	
	return 0;
	
}
