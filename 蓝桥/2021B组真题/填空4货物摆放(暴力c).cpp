#include <stdio.h>//���4����ڷ� ��ʼʱ��10��03 ����ʱ�䣺 11:20
int main()
{
	long long a[1000];//�����¼�������� 
	const long long n=2021041820210418;
	long long i;//iҲҪlonglong����������sqrt��n���� 
	int b=0,f=0,c,d,e;//b��¼������Ŀ f��¼����ڷŷ����� 
	for(i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a[b++]=i;
			a[b++]=n/i;
		}
	} 
//����1	printf("b=%d",b);
/*����2 
	for(int i=0;i<b;i++)//iҪ�ǵó�ʼ�� ���ȥ��int���ӡ����һ������ֵֹ�����ԭ���ꣿ���������� 
	{
		printf("a[%d]=%lld\n",i,a[i]);//a[i]�ĵ��ø�ʽ��%lld����%d 
	}
*/
	for (int e=0;e<b;e++)
	{
		for(int c=0;c<b;c++)
		{
			for(int d=0;d<b;d++)
			{
				if(a[e]*a[c]*a[d]==n)
				f++;
			}
		}
	}
	printf("f=%d",f);
	return 0;
} 
