#include<iostream> 
//22.6.9 蓝桥 粘木棍 
#include<algorithm>
using namespace std;
void solution(int n,int m,int a[])
{
	if(m==1){//如果粘成一根木棍，差值就是0 
	cout<<"0"<<endl;
	return;
	}
	int i,j,max=0,min=0,min_index=0;
	int *b;
	
	b = new int[m];
	sort(a,a+n);//将a顺序排列 
	for(i=m;i>0;i--)//先把a中最大的m个 元素放入b中 
		b[m-i] = a[n-i];
		
	max = b[m-1];
	min = b[0];
	min_index = 0;
	for(i=n-m-1;i>=0;i--)
	{
		b[min_index] += a[i];//每次加一个木棍，则必定要把这个木棍粘到最短的一根上面去 
		if(b[min_index] > max)max = b[min_index];
	
		min = 10000000;//找出当前b数组中 最短的木棍及其下标 
		for(j=0;j<m;j++)
		{
			if(min>b[j])
			{
				min = b[j];
				min_index = j;
			}
		}
		
	}
	cout<<max-min<<endl;//输出结果 
 
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
