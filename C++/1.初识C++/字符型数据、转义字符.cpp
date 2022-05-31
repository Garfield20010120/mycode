#include<iostream>
//22.5.31字符型数据、转义字符 
using namespace std;
int main()
{
	//字符型数据 
	char a='a';
	int c=a;
	cout << a << endl;
	cout << (int)a << endl;//强制转换 char存储的实际上并不是字符而是ascii码 
	cout << c<< endl;
	cout << "char字符型变量所占内存："<<sizeof(char)<<endl;//占一个字节 short2个 int4个 float4个 float8个 long4-8个 long long8个 
	//转义字符\  eg.\n换行 \t tab填充 
	cout << "hello world\n";//\n与endl的区别：\n只代表换行的转义字符 endl除了代表换行，还紧跟着清出缓冲槽
	cout << "hello\tworld"<<endl;
	cout << "hel\tworld"<<endl;
	cout << "h\tworld"<<endl;
	return 0;
}
