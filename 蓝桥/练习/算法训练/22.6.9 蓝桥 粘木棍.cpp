#include<iostream> 
//22.6.9 ���� ճľ�� 
#include<algorithm>
using namespace std;
void solution(int n,int m,int a[])
{
	if(m==1){//���ճ��һ��ľ������ֵ����0 
	cout<<"0"<<endl;
	return;
	}
	int i,j,max=0,min=0,min_index=0;
	int *b;
	
	b = new int[m];
	sort(a,a+n);//��a˳������ 
	for(i=m;i>0;i--)//�Ȱ�a������m�� Ԫ�ط���b�� 
		b[m-i] = a[n-i];
		
	max = b[m-1];
	min = b[0];
	min_index = 0;
	for(i=n-m-1;i>=0;i--)
	{
		b[min_index] += a[i];//ÿ�μ�һ��ľ������ض�Ҫ�����ľ��ճ����̵�һ������ȥ 
		if(b[min_index] > max)max = b[min_index];
	
		min = 10000000;//�ҳ���ǰb������ ��̵�ľ�������±� 
		for(j=0;j<m;j++)
		{
			if(min>b[j])
			{
				min = b[j];
				min_index = j;
			}
		}
		
	}
	cout<<max-min<<endl;//������ 
 
}
int main()
{
	int n,m,i;
	int *a;
	cin>>n>>m;
	 a = new int[n];
	 
	for(i=0;i<n;i++)
		cin>>a[i];
	solution(n,m,a);
	return 0;
}
