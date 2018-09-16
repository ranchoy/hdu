#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;

int dp[MAX][MAX];//dp[n][m]把整数n划分成不大于m的划分数,包含重复的数 

void solve() 
{
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
				dp[i][j] = dp[i][j-1] + dp[i-j][j];//不含j，至少有一个j 
			}
		}
	}
} 


int main()
{
	solve();
	int n,m;
	while(~scanf("%d %d", &n, &m))
	{
		cout << dp[n][m] << endl;
	}
	return 0;
}