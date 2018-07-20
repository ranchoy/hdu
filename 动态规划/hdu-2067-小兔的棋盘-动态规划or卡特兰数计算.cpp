//求(0,0)到(n,n)有多少种走法，注意是关于y=x对称的，只要求一半
//dp[i][j] = dp[i-1][j];(i==j)
//dp[i][j] = dp[i-1][j] + dp[i][j-1];(i!=j)
//这道题可以用卡特兰数求
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 36
using namespace std;

__int64 dp[MAX][MAX];//注意数的大小

void solve()
{
	memset(dp, 0, sizeof(dp));
	for(int j=0; j<=MAX; j++)
	{
		dp[0][j] = 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	}
	
	for(int i=1; i<MAX; i++)
	{
		for(int j=1; j<MAX; j++)
		{
			if(i==j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}
}

int main()
{
	int n,cnt=1;
	solve();
	while(~scanf("%d", &n) && n!=-1)
	{
		printf("%d %d %I64d\n", cnt++, n, dp[n][n]*2);	
	} 
	return 0;
} 
