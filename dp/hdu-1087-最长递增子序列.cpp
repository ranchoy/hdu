// dp最长递增子序列,dp[i]表示包含当前数arr[i]的最长值dp[i]=max(dp[i], dp[j]+arr[i]);
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005 
using namespace std;

int main()
{
	int n,mx;
	int arr[MAX],dp[MAX];
	while(~scanf("%d", &n) && n)
	{
		// 初始化
		mx = 0;
		memset(dp, 0, sizeof(dp));
		 
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		dp[0] = arr[0];
		for(int i=1; i<n; i++)
		{
			dp[i] = arr[i];
			for(int j=0; j<i; j++)
			{
				if(dp[j] < dp[i])
				{
					dp[i] = max(dp[i], dp[j]+arr[i]);
				}
			}
			mx = max(mx, dp[i]);
		}
		cout << mx << endl;
	}
	return 0;	
} 

/*
3 1 3 2
4 1 2 3 4
4 3 3 2 1
0

4
10
3
*/ 