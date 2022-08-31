#include<iostream>
#include<malloc.h>
using namespace std;
int main()
{
	int n;
	int sum = 0;
	int average = 0;
	int *array;
	cin>>n;
	array = (int*)malloc(100*sizeof(int));
	for(int i = 0; i < n; i++)
	{
		cin>>array[i];
		sum += array[i];
	}
	average = sum/n;
	cout<<sum<<" "<<average;
	free(array);
	array = NULL;
	return 0;
} 