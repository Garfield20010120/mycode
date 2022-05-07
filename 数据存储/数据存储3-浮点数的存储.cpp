#include<stdio.h>
//存储3-浮点数的存储 
int main()
{
	int n = 9;
	float* pf=(float*)&n;
	printf("n的值为：%d\n",n);
	printf("*pf的值为：%f\n",*pf);
	
	*pf=9.0;
	printf("改后n值:%d\n",n);
	printf("改后*pf值：%f\n",*pf);
	//n的值为：9
	//*pf的值为：0.000000
	//改后n值:1091567616
	//改后*pf值：9.000000 
	return 0;
}
