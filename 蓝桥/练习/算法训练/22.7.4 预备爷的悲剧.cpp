#include<iostream>
//22.7.4 预备爷的悲剧
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
	int n;                       //给出单词数量 
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
	int m;                       //要背单词数量 
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
