#include<iostream>
#include<cstdio>
#define MAX 101
using namespace std;

int dp[MAX][MAX];

// h(n) = h(n-1) * (4*n-2) / (n+1);
void get_catelan()
{
    int len,yu,temp;
    dp[1][0] = dp[1][1] = 1;
    dp[2][0] = 1;dp[2][1] = 2;
    len = 1;
    for(int i=3; i<MAX; i++)
    {
        yu = 0;
        for(int j=1; j<=len; j++)// 大数乘法
        {
            temp = dp[i-1][j] * (4*i - 2) + yu;
            dp[i][j] = temp % 10;
            yu = temp / 10;
        }

        while(yu)
        {
            dp[i][++len] = yu % 10;
            yu /= 10;
        }

        for(int j=len; j>=1; j--)
        {
            temp = dp[i][j] + yu * 10;
            dp[i][j] = temp / (i+1);
            yu = temp % (i+1);
        }

        while(dp[i][len] == 0)
        {
            len --;
        }
        dp[i][0] = len;
    }
}

int main()
{
    int n;
    get_catelan();
    while(~scanf("%d", &n) && n)
    {
        for(int j=dp[n][0]; j>=1; j--)
        {
            printf("%d", dp[n][j]);
        }printf("\n");
    }
    return 0;
}

/*
1
2
3
100

1
2
5
896519947090131496687170070074100632420837521538745909320
*/