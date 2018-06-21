//最少钱币数，动态规划问题，dp[i] = min(dp[i], dp[ i-conis[j] ] + 1)
//http://dengdengoj.cc/problem.php?id=1031 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
#define MAX 5000
#define INF 0x7fffffff
using namespace std;

int coins[] = { 1, 2, 5, 10, 50, 100};
int dp[MAX];
int arr[N];

int main()
{
	int m,n,sum;
	for(int i=1; i<=MAX; i++)
	{
		dp[i] = INF;
	}
	for(int i=1; i<=MAX; i++)
	{
		for(int j=0; j<6; j++)
		{
			if(i-coins[j]>=0)
			{
				dp[i] = min(dp[i], dp[ i-coins[j] ] + 1 );
			}
		}
	}
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		sum = 0;
		for(int i=0; i<n; i++)
		{
			sum += dp[ arr[i] ];
		}
		
		if(sum>0)
		{
			printf("%d\n", sum);
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;	
} 
/**
3
1 2 3
2
1 2

4
2
*/