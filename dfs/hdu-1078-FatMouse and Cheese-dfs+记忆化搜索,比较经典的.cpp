//深搜，dp[i][j]表示从（i,j）点出发最多能吃到的豆子
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 105 
using namespace std;


int n,m;
int arr[MAX][MAX];
int dp[MAX][MAX];//表示(x,y)位置最大为dp[x][y] 
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

int dfs(int x, int y)
{
	int nx,ny,mx=0;
	
	if(dp[x][y]==0)//表示 
	{
		for(int i=1; i<=m; i++)
		{
			for(int j=0; j<4; j++)
			{
				nx = x + dir[j][0]*i;
				ny = y + dir[j][1]*i;
				
				if(nx>=0 && nx<n && ny>=0 && ny<n && arr[nx][ny]>arr[x][y])
				{
					mx = max(mx, dfs(nx,ny));
				}
			}
		}
		dp[x][y] = mx + arr[x][y];
	}
	return dp[x][y];
}

int main()
{
	while(~scanf("%d %d", &n, &m) && (n>0&&m>0))
	{
		//初始化
		memset(dp, 0, sizeof(dp)); 
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		
		cout << dfs(0,0) <<endl;
	}
	return 0;
}
/**
3 1
1 2 5
10 11 6
12 12 7
-1 -1

37
*/ 