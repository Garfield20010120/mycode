#include<stdio.h>
int main(){
	int x,y,z,x1,y1,z1,p,ans,r,i,ans1;
	scanf("%d %d %d %d %d %d %d",&x,&y,&z,&x1,&y1,&z1,&p);
	ans=(x1*y*z + x*y1*z + x*y*z1)/(x*y*z);
	r=(x1*y*z + x*y1*z + x*y*z1)%(x*y*z);;
	printf("%d.",ans);
	 for(i=0;i<p;i++){
	 		r*=10;
	 		ans=r/(x*y*z);
	 		r%=(x*y*z);
	 		if(i==p-1){	//当计算到最后一位小数时
	 			ans1=r*10/(x*y*z);//需计算其后一位的值 
	 			if(ans1>=5){	//如果值大于5则需向ans进一位 
	 				ans++;
				 }
			 } 
			printf("%d",ans);
	 }
	 return 0;
}
