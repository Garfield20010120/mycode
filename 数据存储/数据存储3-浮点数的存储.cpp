#include<stdio.h>
//�洢3-�������Ĵ洢 
int main()
{
	int n = 9;
	float* pf=(float*)&n;
	printf("n��ֵΪ��%d\n",n);
	printf("*pf��ֵΪ��%f\n",*pf);
	
	*pf=9.0;
	printf("�ĺ�nֵ:%d\n",n);
	printf("�ĺ�*pfֵ��%f\n",*pf);
	//n��ֵΪ��9
	//*pf��ֵΪ��0.000000
	//�ĺ�nֵ:1091567616
	//�ĺ�*pfֵ��9.000000 
	return 0;
}
