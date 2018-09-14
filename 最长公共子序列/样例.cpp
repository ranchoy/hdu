#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10010
using namespace std;

int m,n;
int dp[MAX][MAX];
char s1[MAX],s2[MAX];

int lcs(char *s1, char *s2, int m, int n)
{
	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main()
{
	while(~scanf("%s MN %s", s1, s2))
	{
		memset(dp, 0, sizeof(dp));
		cout << lcs(s1, s2, strlen(s1), strlen(s2)) << endl;
	}
	return 0;
}