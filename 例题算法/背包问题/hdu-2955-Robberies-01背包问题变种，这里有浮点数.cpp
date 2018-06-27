#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 105
#define EPS 0.000000001
using namespace std;
//把金额作为背包容量,不被抓概率作为dp[i]值，注意dp[0]=1，不然求解都为0
int v[MAX];//金额
double dp[MAX*MAX];//拿i金额不被抓的概率
double p[MAX];//被抓概率

int main()
{
    int cnt;
    double rate;
    int n,sum;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        sum = 0;
        memset( dp, 0, sizeof(dp));
        scanf("%lf %d",&rate,&n);
        for( int i=0; i<n; i++)
        {
            scanf("%d %lf",&v[i],&p[i]);
            sum += v[i];
        }

        if( rate < EPS)
        {
            printf("0\n");
            continue;
        }
        dp[0] = 1;//dp[0]为1
        for( int i=0; i<n; i++)
        {
            for( int j=sum; j>=v[i]; j--)
            {
                dp[j] = max( dp[j], dp[j-v[i]]*(1-p[i]) );
            }
        }

        for( int i=sum; i>=0; i--)
        {
            if( dp[i] - (1-rate) > EPS)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
