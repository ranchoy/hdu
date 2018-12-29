// 最长公共子序列，dp[i][j]： a(0,i)和b(0,j)最长公共子序列长度为dp[i][j]
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10010
using namespace std;

int dp[MAX][MAX];
char a[MAX],b[MAX];

void print(int i, int j)
{
    if(i == 0 || j == 0)
        return;

    if(dp[i][j] == dp[i-1][j])
    {
        print(i-1, j);
    }
    else if(dp[i][j] == dp[i][j-1])
    {
        print(i, j-1);
    }
    else
    {
        print(i-1, j-1);
        printf("%c", a[i-1]);
    }
}

int main()
{
    int n,m,t;
    scanf("%d", &t);
    while(t--)
    {
        // 初始化
        memset(dp, 0, sizeof(dp));

        scanf("%s %s", a, b);

        n = strlen(a);
        m = strlen(b);
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=m; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if(a[i-1] == b[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        printf("%d ", dp[n][m]);
        print(n, m);
        printf("\n");
    }
    return 0;
}

/*
7
abcdef bacfd

3 acd
*/