#include <stdio.h>
void GetTwoInts(int *x,int *y)
{
	scanf("%d %d",x,y);
 }
int main()
{
	int *x,*y;
	int a,b;
	int sum;
	x=&a,y=&b;
	GetTwoInts(x,y);
	sum=*x+*y;
	printf("%d",sum);
	return 0;
} 
