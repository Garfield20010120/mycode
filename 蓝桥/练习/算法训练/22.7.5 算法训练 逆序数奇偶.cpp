#include<iostream>
#include<vector>
using namespace std;
int a[100001];//���ڴ������������
int temp[100001];//copy����ʱʹ��
int mergeSort(int a[], int left, const int& right) {
    //������ֹ����
    if (left >= right)
        return 0;
    //���м�ֵ
    int mid = (left + right) >> 1;
    //���Ͻ��еݹ飬ʹ����������������
    int inv_count = mergeSort(a, left, mid) + mergeSort(a, mid + 1, right);
    //iΪ�������±꣬jΪ�������±꣬posΪ��ʱ�����±�
    int i = left, j = mid + 1;
    int pos = 1;
    while (i <= mid && j <= right) {
        //���a[i]<a[j],��ôA[j]ʱ�������е�һ������a[i]��Ԫ�أ�a������������������ģ�
        //��ô��mid+1��j-1��Ԫ�ض�С��a[i],��a[i]������Ϊj-mid-i
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
    //�������Ƿ�ȫ������
    for (int k = i; k <= mid; k++) {
        temp[pos++] = a[k];
        inv_count += (j - mid) - 1;
    }
    //�������Ƿ�ȫ������
    for (int k = j; k <= right; k++)
        temp[pos++] = a[k];
    pos = 1;
    //��������
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
        //�ж���ż
        if (ans & 1)
            cout << "odd" << endl;
        else
            cout << "even" << endl;
    }
    return 0;
}
