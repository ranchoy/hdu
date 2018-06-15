//dp[i] = max(dp[i-1]+arr[i], arr[i]);
//start = end = 0;初始化
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 100010
using namespace std;

int dp[MAX];
int arr[MAX];

int main()
{
	int cnt,n,t=0;
	int temp,start,end,maxn;
	scanf("%d", &cnt);
	while( cnt-- )
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		temp = start = end = 0;
		maxn = dp[0] = arr[0];
		for(int i=1; i<n; i++)
		{
			if(dp[i-1] >= 0)
			{
				dp[i] = dp[i-1] + arr[i];
			}
			else
			{
				dp[i] = arr[i];
				temp = i;
			}
			
			if(maxn < dp[i])
			{
				maxn = dp[i];
				start = temp;
				end = i;
			}	
		}
		
		printf("Case %d:\n%d %d %d\n", ++t, maxn, start+1, end+1);
		if(cnt>0)
		{
			printf("\n");
		}
	}
	return 0;
} 