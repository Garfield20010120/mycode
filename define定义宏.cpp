#include<stdio.h>
#define MAX(X,Y) (X>Y?X:Y)
int main()
{
	int a=1;
	int b=8;
	int c=MAX(a,b);
	printf("c=%d\n",c);
	return 0;
}
