#include <stdio.h>
//22.5.27���� ��ĸͼ��
/*������ĸ�������һЩ������ͼ�Σ����������һ�����ӣ�
ABCDEFG
BABCDEF
CBABCDE
DCBABCD
EDCBABC
����һ��5��7�е�ͼ�Σ����ҳ����ͼ�εĹ��ɣ������һ��n��m�е�ͼ�Ρ� 
����һ�У�������������n��m���ֱ��ʾ��Ҫ�����ͼ�ε�������������
���n�У�ÿ��m���ַ���Ϊ���ͼ�Ρ�
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

