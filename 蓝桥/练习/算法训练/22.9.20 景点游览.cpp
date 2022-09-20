#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n,greater<int>());
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	} 
//    sort(a,a+n);
//    for(i=n-1;i>=0;i--)
//    {
//    	printf("%d ",a[i]);
//	}
	return 0;
}
