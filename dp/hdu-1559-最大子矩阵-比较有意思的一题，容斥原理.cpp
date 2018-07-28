//dp问题：dp[i][j] = current_point + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]; 
//表示从矩阵左上角到当前点(i,j)的矩形的值，求结果就很简单了
//res = max(res,dp[i][j]+dp[i-x][j-y]-dp[i-x][j]-dp[i][j-y]);
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;

int dp[MAX][MAX]; 

int main()
{
	int n,m,x,y,temp,cnt,res;
	cin >> cnt;
	while(cnt--)
	{
		//初始化
		res = 0;
		memset(dp, 0, sizeof(dp)); 
		scanf("%d %d %d %d", &n, &m, &x, &y);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				scanf("%d", &temp);
				dp[i][j] = temp + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			}
		}
		
		for(int i=x; i<=n; i++)
		{
			for(int j=y; j<=m; j++)
			{
				res = max(res, dp[i][j]+dp[i-x][j-y]-dp[i-x][j]-dp[i][j-y]);
			}
		}
		printf("%d\n", res);
	}
	return 0;	
} 

/*
1
4 5 2 2
3 361 649 676 588
992 762 156 993 169
662 34 638 89 543
525 165 254 809 280

2474
*/