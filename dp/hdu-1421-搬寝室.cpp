/*dp问题： 
* dp[i][j] = min(dp[i-1][j], dp[i-2][j-1]+(arr[i]-arr[i-1])^2) 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 2010
#define INF 0x7f7f7f7f
using namespace std;

int arr[MAX],dp[MAX][MAX/2];

int cmp(int a, int b)  
{  
    return a < b;  
}  

int main()
{
	int n,m,k;
	while(~scanf("%d %d", &n, &k))
	{
		//初始化
		dp[0][0] = 0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &arr[i]);
		}

		sort(arr+1, arr+1+n, cmp);
		
		for(int i=0; i<=n; i++)
		{
			for(int j=1; j<=k; j++)
			{
				dp[i][j] = INF;
			}
		}
		
		for(int i=2; i<=n; i++)
		{
			for(int j=1; 2*j<=i; j++)
			{
				dp[i][j] = min(dp[i-1][j], (arr[i]-arr[i-1])*(arr[i]-arr[i-1]) + dp[i-2][j-1]);
			}
		}
		printf("%d\n", dp[n][k]);
	}
	return 0;
}
/*
2 1
1 3
4
*/ 