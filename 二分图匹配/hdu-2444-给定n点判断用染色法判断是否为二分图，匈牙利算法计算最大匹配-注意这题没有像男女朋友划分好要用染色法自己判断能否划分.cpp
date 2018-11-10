#include<iostream> 
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 201
using namespace std;

int n,m;
int vis[MAX],match[MAX];
int map[MAX][MAX];

// 染色法判断是不是二分图 
bool bfs()
{
	int cur;
	queue<int> q;
	// 初始化
	memset(vis, 0, sizeof(vis)); 
	q.push(1);
	vis[1] = 1;
	
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		
		for(int j=1; j<=n; j++)
		{
			if(map[cur][j] == 1)// 边存在 
			{
				if(vis[j] == 0)// 未染色 
				{
					vis[j] = (vis[cur] == 1) ? 2 : 1;// 染异色 
					q.push(j);
				}
				else if(vis[cur] == vis[j])// 邻边同色 
				{
					return false;
				}
			}
		}
	}
	return true;
}

// 匈牙利算法 
bool dfs(int x)
{
	for(int j=1; j<=n; j++)
	{
		if(map[x][j]==1 && vis[j]==0)// 有关系&&没有被访问过 
		{
			vis[j] = 1;
			if(match[j]==0 || dfs(match[j]))// 没有男朋友||男朋友不要你了 
			{
				match[j] = x;// 换男朋友 
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int a,b,res;
	while(~scanf("%d %d", &n, &m))
	{
		// 初始化
		memset(map, 0, sizeof(map));
		memset(match, 0, sizeof(match));
		
		while(m--)
		{
			scanf("%d %d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}
		
		if(n==1 || bfs()==false)
		{
			printf("No\n");
		} 
		else
		{
			res = 0;
			for(int i=1; i<=n; i++)
			{
				memset(vis, 0, sizeof(vis));
				if(dfs(i))
				{
					res ++; 
				}
			} 
			printf("%d\n", res/2);
		}
	}
	return 0;
}

/*
4 4
1 2
1 3
1 4
2 3
6 5
1 2
1 3
1 4
2 5
3 6

No
3
*/ 