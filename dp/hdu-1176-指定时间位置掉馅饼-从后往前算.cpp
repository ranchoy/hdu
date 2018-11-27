#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 100001
using namespace std;

int dp[MAX][12];// 第i秒的第j位置下落东西

int main()
{
    int n,m,pos,t;
    while(~scanf("%d", &n) && n!=0)
    {
        // 初始化
        m = 0;
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<n; i++)
        {
            scanf("%d %d", &pos, &t);
            dp[t][pos] ++;
            m = max(m, t);
        }

        for(int i=m-1; i>=0; i--)
        {
            for(int j=0; j<=10; j++)//不只10个位置，测试数据有问题
            {
                dp[i][j] += max(dp[i+1][j-1], max(dp[i+1][j], dp[i+1][j+1]));
            }
        }

        printf("%d\n", dp[0][5]);
    }
    return 0;
}

/*
6
5 1
4 1
6 1
7 2
7 2
8 3

4
0
*/