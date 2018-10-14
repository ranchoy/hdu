#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 105
#define INF 0x7f7f7f7f
using namespace std;

int n,m;
int map[MAX][MAX];
int vis[MAX],dist[MAX];

void spfa(int s)
{
	int cur;
	queue<int> q;
	vis[s] = 1;
	dist[s] = 0;
	q.push(s);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		vis[cur] = 0;
		
		for(int i=1; i<=n; i++)
		{
			if(map[cur][i]!=INF && dist[i]>dist[cur]+map[cur][i])
			{
				dist[i] = dist[cur] + map[cur][i];
				if(vis[i] == 0)
				{
					vis[i] = 1;
					q.push(i);
				}	
			}	
		}	
	}	
}

int main()
{
	int u,v,w;
	while(~scanf("%d %d", &n, &m) && n+m)
	{
		// 初始化
		memset(vis, 0, sizeof(vis));	
		memset(map, 0x7f, sizeof(map));
		memset(dist, 0x7f, sizeof(dist));
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);	
			map[u][v] = map[v][u] = w;
		} 
		
		spfa(1);
		printf("%d\n", dist[n]);
	}
	return 0;
} 

/*
2 1
1 2 3
3 3
1 2 5
2 3 5
3 1 2
0 0

3
2
*/