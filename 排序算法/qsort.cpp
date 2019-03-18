#include<iostream>
#include<cstring>
#define MAX 105
using namespace std;

int n;
int arr[MAX];

void qsort(int *arr, int left, int right)
{ 
    if(left >= right)
    {
        return;
    }
    int k = arr[left]; // 基准
    int l = left, r = right;
    while(l < r)
    {
        while(arr[r] > k && l < r)
            r--;
        arr[l] = arr[r];
        while(arr[l] < k && l < r)
            l++;
        arr[r] = arr[l];
    }
    arr[l] = k;// 基准
    qsort(arr, left, l-1);
    qsort(arr, l+1, right);
}

int main()
{
    while(~scanf("%d", &n) && n)
    {
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        qsort(arr, 0, n-1);

        for(int i=0; i<n-1; i++)
            printf("%d ", arr[i]);
        printf("%d\n", arr[n-1]);
    }
    return 0;
}
/*
5
2 3 1 5 8
1 2 3 5 8
*/