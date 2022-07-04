#include<iostream>
//22.7.4 Ԥ��ү�ı���
#include<cstring>
#include<map>
#include<set>
using namespace std;
 
struct English{
	string str;
	bool operator<(const English& str1)const
	{
		return this->str<str1.str;
	}
};
 
int main()
{
	set<int> pages;
	map<English,int> word;
	int n;                       //������������ 
	cin>>n;
	for (int i=0;i<n;i++)
	{
		getchar();
		English W;
		getline(cin,W.str,' ');
		int n;
		cin>>n;
		if(word.count(W)&&n<word[W])
		    word[W]=n;
		else
		    word.insert(pair<English,int>(W,n));
	}
	int m;                       //Ҫ���������� 
	cin>>m;
	getchar();
	for (int i=0;i<m;i++)
	{
		English W;
		getline(cin,W.str,'\n');
		if(word.count(W)==1)
			pages.insert(word[W]);
	}
	cout<<pages.size();
	return 0;
}
