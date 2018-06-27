#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define MAX 1010

using namespace std;
int a[MAX],dp[MAX];
int cmp( int a, int b)
{
    return a<b;
}
int main()
{
    int n,m,mx;
    while(~scanf("%d",&n) && n!=0)
    {
        for( int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        if( m<5 )//小于5
        {
            printf("%d\n",m);
            continue;
        }
        memset(dp,0,sizeof(dp));
        sort(a,a+n,cmp);
        mx = a[n-1];
        m = m - 5;//先减去5,用来减去最大的
        for( int i=0; i<n-1; i++)
        {
            for( int j=m; j>=a[i]; j--)
            {
                dp[j] = max( dp[j], dp[j-a[i]]+a[i]);
            }
        }
        printf("%d\n",m+5-dp[m]-mx);
    }
}
