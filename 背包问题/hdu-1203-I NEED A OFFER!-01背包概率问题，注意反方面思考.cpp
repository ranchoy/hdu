#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10010
using namespace std;

int w[MAX];
double v[MAX];
double dp[10010];//不被录取概率

int main()
{
    int n,m;
    while( ~scanf("%d %d",&n,&m) && n+m )
    {
        for( int i=0; i<m; i++)
        {
            scanf("%d %lf",&w[i],&v[i]);
        }

        for( int i=0; i<=n; i++)
        {
            dp[i] =1;
        }
        for( int i=0; i<m; i++)
        {
            for( int j=n; j>=w[i]; j--)
            {
                dp[j] = min( dp[j], dp[ j-w[i] ]*(1-v[i]));
            }
        }

        printf("%.1lf%%\n",(1-dp[n])*100);
    }
    return 0;
}
