// dp[i][j] = max(dp[i][j-1], dp[i-1][k]) + arr[j]; (i-1<= k <= j-1)
// 表示在选取第j个数字的前提下，把这j个数分成i组的最大和为dp[i][j]
// 然后这i组划分情况有两种：
// 1. (x1,y1)、(x2,y2) ... (xi, yi)其中(xi,yi)是arr数组(arr[?]... arr[j]) 
// 2. (x1,y1)、(x2,y2) ... (xi-1,yi-1)、(arr[j])  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000005
#define INF 0x7fffffff
using namespace std;

int n,m;
int arr[MAX],dp[MAX],pre[MAX];// dp[j]表示dp[i][j]，pre[j]表示dp[i-1][j]

int main()
{
	int mx;
	while(~scanf("%d %d", &m, &n))
	{
		// 初始化 
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		// 简化：dp[j] = max(dp[j-1], pre[j-1]) + arr[j]; 
		for(int i=1; i<=m; i++)
		{
			mx = -INF;
			for(int j=i; j<=n; j++)// 分成i组,要从j=i开始 
			{
				dp[j] = max(dp[j-1], pre[j-1]) + arr[j];
				pre[j-1] = mx;
				mx = max(mx, dp[j]);
			}
		}
		
		cout << mx << endl;
	}
	return 0;
}

/*
1 3 1 2 3
2 6 -1 4 -2 3 -2 3

6
8
*/
