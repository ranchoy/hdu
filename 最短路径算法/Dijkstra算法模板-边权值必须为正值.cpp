#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005 
#define INF 0x7f7f7f7f
using namespace std;

int n,m;//点数n,边数m
int map[MAX][MAX];
int vis[MAX],dist[MAX]; 

// Dijkstra算法是求单源最短路径,边权值不能为负数,因为(dist[s]+负数)可能小于dist[i](这个i是vis[i]已经确定最小了)
void Dijkstra(int s)// n个点,源点s
{
	vis[s] = 1;
	dist[s] = 0;
	for(int i=1; i<=n; i++)// 开始就更新 
	{
		dist[i] = min(dist[i], map[s][i]);
	}	
	int cnt = n-1,dist_min;//剩下n-1个点 
	while(cnt--)
	{
		dist_min = INF;
		// 查找最小dist[i]对应的下标i 
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0 && dist_min>dist[i])
			{
				dist_min = dist[i];
				s = i;
			}	
		} 
		vis[s] = 1;
		// 更新dist
		for(int i=1; i<=n; i++)
		{
			if(map[s][i]!=INF && dist[i]>dist[s]+map[s][i])
			{
				dist[i] = dist[s] + map[s][i];	
			}	
		} 
	} 
} 

int main()
{
	int u,v,w; 
	while(~scanf("%d %d", &n, &m)) 
	{
		// 初始化
		memset(vis, 0, sizeof(vis));
		memset(dist, 0x7f, sizeof(dist));
		memset(map, 0x7f, sizeof(map));

		while(m--)
		{
			cin >> u >> v >> w;
			map[u][v] = map[v][u] = w;
		}

		Dijkstra(1);
		for(int i=1; i<=n; i++)
		{
			printf("%d ", dist[i]);
		}printf("\n");
	}
	return 0;
} 
/*
5 6
1 2 5
1 3 8
2 3 1
2 4 3
4 5 7
2 5 2

0 5 6 8 7
*/ 