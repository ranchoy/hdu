#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
//两个人平分财产，要求两个人背包尽可能一样，第一个人背包价值要大于等于第二个人的背包
using namespace std;

int val[50010];
int dp[250010];

int main()
{
    int n,m,k,sum;
    int v,num;
    while( ~scanf("%d",&n) && n>0)
    {
        k = 0;
        sum = 0;
        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&v,&num);
            while( num-- )
            {
                val[k++] = v;
                sum += v;
            }

        }
        m = sum/2;
        for( int i=0; i<k; i++)
        {
            for( int j=m; j>=val[i]; j--)
            {
                dp[j] = max( dp[j], dp[j-val[i]]+val[i]);
            }
        }
        printf("%d %d\n",sum-dp[m],dp[m]);
    }
    return 0;
}
