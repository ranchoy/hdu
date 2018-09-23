#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;

int dp[MAX][MAX];//dp[n][k]把整数n划分成k个数的划分法,dp[n][k];    

void solve() 
{
	memset(dp, 0, sizeof(dp));
	
	for(int i=1; i<MAX; i++) 
	{
		for(int j=1; j<MAX; j++) 
		{
			if(i < j) 
			{
				dp[i][j] = 0;
			}
			else if(i == j) 
			{
				dp[i][j] = 1;
			}
			else
			{
				dp[i][j] = dp[i-j][j] + dp[i-1][j-1];//dp[i][j]分成两个：1.不含1的k个数(先拿出j个1分到每一份，然后把剩余i-j分成j份即dp[i-j][j]), 2.至少有一个1即dpp[i-1][j-1] 
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

/**
5 4 
1
6 3
3
*/ 