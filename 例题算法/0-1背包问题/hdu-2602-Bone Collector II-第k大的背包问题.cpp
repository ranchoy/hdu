#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 1010
using namespace std;

int v[MAX],w[MAX];//W[]表示体积,v[]表示价值
int dp[MAX][35];
int A[35],B[35];
int main()
{
    int cnt,n,m,k;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        scanf("%d %d %d",&n, &m, &k);
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
                //dp[j] = max( dp[j], dp[ j-w[i] ] + v[i]);
                for( int x=1; x<=k; x++)
                {
                    A[x] = dp[j][x];
                    B[x] = dp[j-w[i]][x]+v[i];
                }
                A[k+1]=B[k+1]=-1;
                int a=1,b=1,c=1;
                while( c<=k && (A[a]!=-1 || B[b]!=-1) )
                {
                    if( A[a] > B[b])
                    {
                        dp[j][c] = A[a];
                        ++a;
                    }
                    else
                    {
                        dp[j][c] =  B[b];
                        ++b;
                    }

                    if( dp[j][c]!=dp[j][c-1])
                    {
                        ++c;
                    }
                }
            }
        }
        printf("%d\n",dp[m][k]);
    }
    return 0;
}
