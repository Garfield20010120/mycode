#include<stdio.h>
//22.5.22蓝桥-数列特征-问题描述
//给出n个数，找出这n个数的最大值，最小值，和。
//输入格式
//第一行为整数n，表示数的个数。
//第二行有n个数，为给定的n个数，每个数的绝对值都小于10000。
//输出格式
//输出三行，每行一个整数。第一行表示这些数中的最大值，第二行表示这些数中的最小值，第三行表示这些数的和。
int main(){
int n,i,j,max=-10001,min=10001,sum=0;//这一行数据很重要 
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
max=(max<a[i])?a[i]:max;//这里运用的是选择表达式，是C语言中的唯一一个三目表达式
min=(min>a[i])?a[i]:min;
sum+=a[i];
}
printf("%d\n",max);
printf("%d\n",min);
printf("%d\n",sum);
return 0;
} 

