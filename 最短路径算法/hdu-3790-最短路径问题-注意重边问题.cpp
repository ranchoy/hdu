#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
#define INF 0x7f7f7f7f
using namespace std;

int n,m;
int map[MAX][MAX],val[MAX][MAX],vis[MAX];
int dist[MAX],cost[MAX];

void Dijkstra(int s)
{
	vis[s] = 1;
	dist[s] = 0;
	cost[s] = 0;
	for(int i=1; i<=n; i++)
	{
		dist[i] = min(dist[i], map[s][i]);
		cost[i] = val[s][i];// 注意val也要更新 
	}
	int cnt=n-1,dist_min;
	while(cnt--)
	{
		dist_min = INF;
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0 && dist_min>dist[i])
			{
				dist_min = dist[i];
				s = i;
			}
		}
		vis[s] = 1;
		for(int i=1; i<=n; i++)
		{
			if(map[s][i]!=INF && dist[i]>dist[s]+map[s][i])// 注意这里>=中等于表示路程相等时取花费最小的 
			{
				dist[i] = dist[s] + map[s][i];
				cost[i] = cost[s] + val[s][i]; 
			}
			else if(map[s][i]!=INF && dist[i]==dist[s]+map[s][i])
			{
				cost[i] = min(cost[i], cost[s]+val[s][i]); 
			}
		}
	}
}

void spfa(int s)
{
	int cur;
	queue<int> q;
	
	vis[s] = 1;
	dist[s] = 0;
	cost[s] = 0;// 初始化 
	
	q.push(s);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		vis[cur] = 0;// 出队列
		
		for(int i=1; i<=n; i++)
		{
			if(map[cur][i]!=INF && dist[i]>dist[cur]+map[cur][i])
			{
				dist[i] = dist[cur] + map[cur][i];
				cost[i] = cost[cur] + val[cur][i];
				if(vis[i] == 0)// 入队列 
				{
					vis[i] = 1;
					q.push(i);
				}
			}
			else if(map[cur][i]!=INF && dist[i]==dist[cur]+map[cur][i])
			{
				cost[i] = min(cost[i], cost[cur]+val[cur][i]);
			}
		}
	}
}

int main()
{
	int u,v,w,value,a,b;
	while(~scanf("%d %d", &n, &m) && (n+m))
	{
		// 初始化
		memset(vis, 0, sizeof(vis));
		memset(val, 0x7f, sizeof(val));
		memset(cost, 0x7f, sizeof(cost));
		memset(dist, 0x7f, sizeof(dist));
		memset(map, 0x7f, sizeof(map));
		while(m--)
		{
			scanf("%d %d %d %d", &u, &v, &w, &value);
			if(w < map[u][v])// 判断重边 
			{
				map[u][v] = map[v][u] = w;
				val[u][v] = val[v][u] = value;
			}
		}
		scanf("%d %d", &a, &b);
		
		Dijkstra(a);
		printf("%d %d\n", dist[b], cost[b]);
	}
	return 0;
} 
/*
3 2
1 2 5 6
2 3 4 5
1 3
0 0

9 11
*/