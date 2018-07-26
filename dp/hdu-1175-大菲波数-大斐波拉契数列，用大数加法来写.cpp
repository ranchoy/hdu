//f(n) = f(n-1) + f(n-2);f(1)=f(2)=1;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;

int arr[MAX][MAX];
    
void fibonacci()
{
    arr[1][0] = arr[1][1] = 1;
    arr[2][0] = arr[2][1] = 1;
    int len=1,yu=0,temp;
    for(int i=3; i<MAX; i++)
    {
        for(int j=1; j<=len; j++)
        {
            temp = arr[i-1][j] + arr[i-2][j] + yu;
            arr[i][j] = temp%10;
            yu = temp/10;
        }
        while(yu)
        {
            arr[i][++len] = yu%10;
            yu /= 10;
        }
        arr[i][0] = len;
    }
}

int main()
{
    int n,t;
    cin >>t;
    fibonacci();
    while(t--)
    {
        scanf("%d", &n);
        for(int j=arr[n][0]; j>=1; j--)
        {
            printf("%d", arr[n][j]);
        }printf("\n");
    }
    return 0;
}