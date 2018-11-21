// dp最长递增子序列,dp[i]表示包含当前数arr[i]的最长值dp[i]=max(dp[i], dp[j]+arr[i]);
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
#define INF 0x7fffffff
using namespace std;

int n;
int arr[MAX],dp[MAX];

int main()
{
	int mx;
	while(~scanf("%d", &n) && n!=0)
	{
		// 初始化
		mx = -INF; 
		
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		for(int i=1; i<n; i++)
		{
			dp[i] = arr[i];// 注意赋值 
			for(int j=0; j<i; j++)
			{
				if(arr[j] < arr[i])
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