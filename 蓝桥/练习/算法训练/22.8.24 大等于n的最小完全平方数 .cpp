#include <stdio.h>
#include <math.h>
int main(int argc,char argv[])
{
    double n;
    long long int root;
 
    scanf("%lf", &n);
    root = (long long int)ceil(sqrt(n));
    printf("%lld", root * root);
    return 0;
}
