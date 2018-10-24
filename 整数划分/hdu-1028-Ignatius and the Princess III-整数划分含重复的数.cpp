#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 125
using namespace std;

int dp[MAX][MAX];

// 整数划分(含重复的数)
void integer_division()
{
	// 初始化
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<MAX; i++)
	{
		for(int j=1; j<MAX; j++)
		{
			if(i < j)
			{
				dp[i][j] = dp[i][i];	
			}	
			else if(i == j)
			{
				dp[i][j] = dp[i][j-1] + 1;
			}
			else
			{
				dp[i][j] = dp[i-j][j] + dp[i][j-1];
			}
		}	
	} 
}

int main()
{
	int n;
	integer_division();
	while(~scanf("%d", &n))
	{
		printf("%d\n", dp[n][n]);
	}
	return 0;
}

/*
4
10
20

5
42
627
*/ 