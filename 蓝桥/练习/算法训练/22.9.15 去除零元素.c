#include <stdio.h>

#include <string.h>

 

 

void CompactIntegers(int array[], int *n)

{

    int i,j;

    int k = *n;//k为数组中元素个数

    for (i = 0; i <k; i ++) {

        

        //从指定的0开始，让

        if (array[i]==0) {

            for (j = i; j < k-1; j++) {

                array[j]=array[j+1];//将0后面的元素都往前移

            }

            array[k]=0;

            i--;//减和再加，让i还为当期值，因为后面的元素往前移了。

            k--;//删除为0 的元素

        }

    }

    

    *n = k;

}

 

int main(int argc, const char * argv[]) {

 

    //输入数据

    int n,i;

    scanf("%d",&n);

    int count[n];

    for (i = 0; i < n; i ++) {

        scanf("%d",&count[i]);

    }

    

 

    CompactIntegers(count, &n);

 

    //打印删除数组中的0元素后的元素个数和元素

    printf("%d\n",n);

    for (i = 0 ; i < n; i ++) {

        printf("%d ",count[i]);

    }

    return 0;

}