#include <stdio.h>
//22.5.27蓝桥 字母图形
/*利用字母可以组成一些美丽的图形，下面给出了一个例子：
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
这是一个5行7列的图形，请找出这个图形的规律，并输出一个n行m列的图形。 
输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。
输出n行，每个m个字符，为你的图形。
*/ 
int main()
{
	int r,c,i,j,k,rs,cs;
	char arr[26][26];
	scanf("%d%d",&r,&c);
	for(i=0;i<c;i++)
	 {
	 	rs=0; 
	    for(j=i;c-j>0;j++)
		{
			if(j==i)
			{
				 arr[i][j]='A'; continue;
			}
			rs++;
			arr[i][j]='A'+rs;
		}	
		cs=0;
		for(k=i;r-k>0;k++)
		{
			if(k==i)continue;
			cs++;
			arr[k][i]='A'+cs;
		}
	 }
	 for(i=0;i<r;i++)
	 {
	 	for(j=0;j<c;j++)
	 	{
	 		printf("%c",arr[i][j]);
	 	}
	 	printf("\n");
	 }
	return 0;
}

