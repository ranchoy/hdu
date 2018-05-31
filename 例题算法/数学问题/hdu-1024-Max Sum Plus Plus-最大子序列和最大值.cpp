//dp[i][j] = max(dp[i][j-1], max(dp[i-1][k])) + arr[j]; (i-1 <= k <= j-1)
//i表示多少段,j表示第几个数;就是以j结尾的,以j作为开头的最大值。 
#include<iostream>
#include<cstring>
#include<cstdio>
#define INF 0x7fffffff
#define MAX 1000005
using namespace std;

int dp[MAX];
int ans[MAX];
int arr[MAX];

int main()
{
	int m,n,maxn;
	while( scanf("%d %d", &m, &n)==2 )
	{
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &arr[i]);
		}

		for(int i=1; i<=m; i++)
		{
			maxn = -INF;
			for(int j=i; j<=n; j++)
			{
				dp[j] = max(dp[j-1], ans[j-1]) + arr[j];
				ans[j-1] = maxn;
				maxn = max(maxn, dp[j]);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}