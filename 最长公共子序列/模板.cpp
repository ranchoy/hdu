// dp[i][j]表示两个字符串长度分别(i, j)时最长公共子序列长度
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 105
using namespace std;

int n, m;
int dp[MAX][MAX];
char a[MAX], b[MAX];

void lcs(char *a, char *b, int n, int m)
{
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
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

int main()
{
    int cnt;
    scanf("%d", &cnt);
    while(cnt--)
    {
        scanf("%s %s", a, b);
        n = strlen(a);
        m = strlen(b);

        lcs(a, b, n, m);
        
        printf("%d\n", dp[n][m]);
    }
    return 0;
}