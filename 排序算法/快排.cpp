#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 1005
using namespace std;

int n;
int arr[MAX];

void qsort(int left, int right)
{
    if (left > right) return;

    int num, l, r, mid;
    
    l = left;
    r = right;
    num = arr[left];
    while(l < r)
    {
        while(l < r && arr[r] > num) r--;
        while(l < r && arr[l] < num) l++;
        swap(arr[l], arr[r]);
    }
    arr[l] = num;
    qsort(left, l-1);
    qsort(l+1, right);
}

int main()
{
    while(~scanf("%d", &n) && n!=0)
    {
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        qsort(0, n-1);

        for(int i=0; i<n; i++)
            printf("%d ", arr[i]);
        printf("\n");   
    }
}

/*
7
8 7 6 12 1 2 4

1 2 4 6 7 8 12
*/