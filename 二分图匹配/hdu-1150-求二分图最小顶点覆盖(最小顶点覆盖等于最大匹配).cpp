// 最小顶点覆盖：用最少的点，让每条边都至少和其中一个点关联
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

int n,m,k; 
int map[MAX][MAX];
int vis[MAX],match[MAX];

bool dfs(int u)
{
	for(int j=1; j<=m; j++)
	{
		if(map[u][j]==1 && vis[j]==0)
		{
			vis[j] = 1;
			if(match[j]==0 || dfs(match[j]))
			{
				match[j] = u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int temp,u,v,res;
	while(~scanf("%d", &n) && n)
	{
		// 初始化
		res = 0;
		memset(map, 0, sizeof(map));
		memset(match, 0, sizeof(match));
		
		scanf("%d %d", &m, &k);
		while(k--)
		{
			scanf("%d %d %d", &temp, &u, &v);
			if(u>0 && v>0)
			{
				map[u][v] = 1;
			}
		}
		
		for(int i=1; i<=n; i++)
		{
			memset(vis, 0, sizeof(vis));
			if(dfs(i))
			{
				res ++;
			} 
		} 
		printf("%d\n", res);
	}
	return 0;
} 

/*
5 5 10
0 1 1
1 1 2
2 1 3
3 1 4
4 2 1
5 2 2
6 2 3
7 2 4
8 3 3
9 4 3
0

3
*/