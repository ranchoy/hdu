#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 1010
using namespace std;

int v[MAX],w[MAX]; //W[]表示体积,v[]表示价值
int dp[MAX];

int main()
{
    int cnt,n,m;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        scanf("%d %d",&n, &m);
        for( int i=0; i<n; i++)
        {
            scanf("%d",&v[i]);
        }
        for( int i=0; i<n; i++)
        {
            scanf("%d",&w[i]);
        }

        memset( dp, 0, sizeof(dp));

        for( int i=0; i<n; i++)
        {
            for( int j=m; j>=w[i]; j--)
            {
                dp[j] = max( dp[j], dp[ j-w[i] ] + v[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
