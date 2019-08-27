#include<iostream>
#include<algorithm>
#define N 10005
using namespace std;

int arr[N];

int main()
{
    int n, m;
    while(cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr+n);
        printf("%d\n", arr[(n-1)/2]);
    }
    
    return 0;
}