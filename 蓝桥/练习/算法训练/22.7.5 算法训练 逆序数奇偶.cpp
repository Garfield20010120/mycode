#include<iostream>
#include<vector>
using namespace std;
int a[100001];//用于储存输入的数组
int temp[100001];//copy数组时使用
int mergeSort(int a[], int left, const int& right) {
    //定义终止条件
    if (left >= right)
        return 0;
    //求中间值
    int mid = (left + right) >> 1;
    //不断进行递归，使得数组呈现有序递增
    int inv_count = mergeSort(a, left, mid) + mergeSort(a, mid + 1, right);
    //i为左数组下标，j为右数组下标，pos为临时数组下标
    int i = left, j = mid + 1;
    int pos = 1;
    while (i <= mid && j <= right) {
        //如果a[i]<a[j],那么A[j]时右数组中第一个大于a[i]的元素，a在左右两数组是升序的，
        //那么从mid+1到j-1的元素都小于a[i],则a[i]逆序数为j-mid-i
        if (a[i] <= a[j]) {
            temp[pos] = a[i];
            ++i;
            inv_count += (j - mid) - 1;
        }
        else {
            temp[pos] = a[j];
            ++j;
        }
 
        pos++;
    }
    //左数组是否全部遍历
    for (int k = i; k <= mid; k++) {
        temp[pos++] = a[k];
        inv_count += (j - mid) - 1;
    }
    //右数组是否全部遍历
    for (int k = j; k <= right; k++)
        temp[pos++] = a[k];
    pos = 1;
    //复制数组
    for (int k = left; k <= right; k++,pos++) {
        a[k] = temp[pos];
    }
    return inv_count;
}
int main(void)
{
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = mergeSort(a, 0, n - 1);
        //判断奇偶
        if (ans & 1)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
    return 0;
}
