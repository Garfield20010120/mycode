#include <bits/stdc++.h>
//22.6.29 自行车摆放 
using namespace std;
 
list<int>::iterator loc[100003];       //该链表专门记录每个自行车序号的存储地址 
 
int main(){
	int num;
	cin>>num;   //自行车总数
	list<int> row;
	int x;
	cin>>x;
	row.push_back(x);
	loc[x]=row.begin();  //第一个自行车的地址
	list<int>::iterator temp=row.begin();
	for(int i=0;i<num-1;i++){
		int n;        //下一辆要停的自行车编号
		int a;        //停在哪辆车旁边
		int pos;      //停在左边还是右边   0左1右
		cin>>n>>a>>pos;
		temp=loc[a];    //找到a的地址 
		switch(pos){
			case 0:
				row.insert(temp,n);
				loc[n]=--temp;   //记录n的地址 
				break;
			case 1:
				row.insert(++temp,n);   //a的后一个地址 
				loc[n]=--temp;
				break;
		}
	}
	for(list<int>::iterator it=row.begin();it!=row.end();it++)
		cout<<*it<<" ";
	
	return 0;
	
}
