#include<iostream>
//22.5.31�ַ������ݡ�ת���ַ� 
using namespace std;
int main()
{
	//�ַ������� 
	char a='a';
	int c=a;
	cout << a << endl;
	cout << (int)a << endl;//ǿ��ת�� char�洢��ʵ���ϲ������ַ�����ascii�� 
	cout << c<< endl;
	cout << "char�ַ��ͱ�����ռ�ڴ棺"<<sizeof(char)<<endl;//ռһ���ֽ� short2�� int4�� float4�� float8�� long4-8�� long long8�� 
	//ת���ַ�\  eg.\n���� \t tab��� 
	cout << "hello world\n";//\n��endl������\nֻ�����е�ת���ַ� endl���˴����У�����������������
	cout << "hello\tworld"<<endl;
	cout << "hel\tworld"<<endl;
	cout << "h\tworld"<<endl;
	return 0;
}
