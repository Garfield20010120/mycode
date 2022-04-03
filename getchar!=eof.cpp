#include <stdio.h>
//只能输入数字 
int main()
{
	int ch=0;
	while((ch=getchar())!=EOF)//记得把ch=getchar()括起来 
	{
		if (ch<'0'||ch>'9')//不要忘记把数字括起来 
		continue;
		putchar(ch);
	}
	
	
	return 0; 
}
