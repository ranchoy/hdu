// 题意：3*n的矩形可不可以以由1*2的矩形拼成，可以输出种类数，不可以输出0
// dp[n] = 3*dp[n-2] + 2*dp[n-4] + 2*dp[n-6] + ... + 2*dp[0] = 4*dp[n-2] - dp[n-4];
#include<cstdio>
#define MAX 31

int dp[MAX];// 宽为i的图形种类有dp[i]个

int main()
{
    int n;
    dp[0] = 1;
    dp[2] = 3;
    dp[1] = dp[3] = 0;
    for(int i=4; i<=30; i++)
    {
        if(i&1)
            dp[i] = 0;
        else
            dp[i] = 4*dp[i-2] - dp[i-4];
    } 
    
    while(~scanf("%d", &n) && n!=-1)
    {
        printf("%d\n", dp[n]);
    }
    return 0;
}

/*
2
8
12
-1

3
153
2131
*/