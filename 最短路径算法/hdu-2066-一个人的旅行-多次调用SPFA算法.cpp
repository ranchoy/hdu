#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 1005
#define INF 0x7f7f7f7f
using namespace std;

int n,m,t,res;
int live[MAX],want[MAX];// live[]住的地方,want[]想去的地方 
int map[MAX][MAX],vis[MAX],dist[MAX];

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x7f, sizeof(dist));
}

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
		
		for(int i=0; i<MAX; i++)
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
	
	for(int i=0; i<t; i++)
	{
		res = min(res, dist[ want[i] ]);
	}
}

int main()
{
	int u,v,w;
	while(~scanf("%d %d %d", &n, &m, &t))
	{
		// 初始化
		init();
		res = INF;
		memset(map, 0x7f, sizeof(map));
		
		while(n--)
		{
			scanf("%d %d %d", &u, &v, &w);
			if(w < map[u][v])// (u,v)有多条路相连 
			{
				map[u][v] = map[v][u] = w;	
			}
		}
					
		for(int i=0; i<m; i++)
		{
			scanf("%d", &live[i]);	
		}	
		for(int i=0; i<t; i++)
		{
			scanf("%d", &want[i]);
		}
		
		for(int i=0; i<m; i++)
		{
			// 初始化 
			init();
			spfa(live[i]); 
		}
			
		cout << res << endl; 
	}
	return 0;
}

/*
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10

9
*/ 