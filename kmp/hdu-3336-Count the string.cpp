#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200005

using namespace std;

char str[N];

void cal_next(char *str, int len, int *next)
{
    int k = -1;
    next[0] = -1;
    for(int i=1; i<len; i++)
    {
        while( k>-1 && str[i]!=str[k+1] )
        {
            k = next[k];
        }
        if( str[i]==str[k+1] )
        {
            k++;
        }
        next[i] = k;
    }
}

int main()
{
    int n,len,res;
    int next[N],dp[N];
    scanf("%d",&n);
    while(n--)
    {
        res=0;
        scanf("%d",&len);
        scanf("%s", str);
        memset(dp, 0, sizeof(dp));
        cal_next(str, len, next);
        for(int i=1; i<=len; i++)
        {
            dp[i] = dp[ next[i-1] + 1 ] + 1;
            res = (res + dp[i])%10007;
        }
        printf("%d\n",res);
    }
    return 0;
}

