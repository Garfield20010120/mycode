#include<stdio.h>
//���������������λ�ã����ַ��� ʱ�临�Ӷȣ�log2��n���� 
int main()
{
	int arr[]={1,2,4,6,8,9,13,18};
	int sz =sizeof(arr)/sizeof(arr[0]); 
	int target=0;
	printf("������������ҵ�����:");
	scanf("%d",&target);
	int left=0;
	int right =sz-1;
	for(;left<=right;)//��while��left<=right�� 
	{
		int mid= (left+right)/2;
		if (arr[mid]>target)
			{
				right=mid-1;
			}
		else if(arr[mid]<target)
			{
				left=mid+1;
			}
		else if(arr[mid]==target)//ע��=��==������ 
			{
				printf("�ҵ��ˣ��±�Ϊ��%d\n",mid);
				break;//�����˳�ѭ�� 
			}
	}
	if(left>right)
	printf("�������޸�����\n");
	return 0;
}
