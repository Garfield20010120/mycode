#include <stdio.h>
//ֻ���������� 
int main()
{
	int ch=0;
	while((ch=getchar())!=EOF)//�ǵð�ch=getchar()������ 
	{
		if (ch<'0'||ch>'9')//��Ҫ���ǰ����������� 
		continue;
		putchar(ch);
	}
	
	
	return 0; 
}
