#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
char ch1[maxn],ch2[maxn];
char ch[maxn];
char zhuan[maxn],zhuan1[maxn];
map<char,bool>s,s1;
int main(){
	cin>>ch1+1>>ch2+1>>ch+1;
	int len=strlen(ch1+1),len2=strlen(ch+1);
	if(len<26){puts("Failed");return 0;}
	for(int i=1;i<=len;i++){
		if(!s1[ch2[i]])zhuan1[ch2[i]]=ch1[i],s1[ch2[i]]=true;
		else if(s1[ch2[i]]&&zhuan1[ch2[i]]!=ch1[i]){puts("Failed");return 0;}
		if(!s[ch1[i]])zhuan[ch1[i]]=ch2[i],s[ch1[i]]=true;
		else if(s[ch1[i]]&&zhuan[ch1[i]]!=ch2[i]){puts("Failed");return 0;}//两遍对照判断是否重复出现了
	}
	for(int i=1;i<=len2;i++)cout<<zhuan[ch[i]];
	return 0;
}
