#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAX 1010
#define INF 0x7f7f7f7f
using namespace std;

int n,m,end_station,w;
int map[MAX][MAX];
int vis[MAX],dist[MAX];

void spfa(int s)
{
	int cur;
	queue<int> q;
	// 初始化
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x7f, sizeof(dist));
	vis[s] = 1;
	dist[s] = 0;
	q.push(s);
	
	while(!q.empty()) 
	{
		cur = q.front();
		q.pop();
		vis[cur] = 0;// 释放cur 
		
		for(int i=0; i<=n; i++)
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
	int a,b,c;
	while(~scanf("%d %d %d", &n, &m, &end_station))
	{
		// 初始化
		memset(map, 0x7f, sizeof(map)); 
		
		while(m--)
		{
			scanf("%d %d %d", &a, &b, &c);
			if(map[a][b] > c)// 单向边且有多个取最短 
			{
				map[a][b] = c;
			}
		}
		
		scanf("%d", &w);
		for(int i=0; i<w; i++)
		{
			scanf("%d", &a);
			map[0][a] = 0;
		}
	
		spfa(0);// 起点从0开始 
		if(dist[end_station] == INF)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", dist[end_station]);
		}
	}
	return 0;
}

/*
5 8 5
1 2 2
1 5 3
1 3 4
2 4 7
2 5 6
2 3 5
3 5 1
4 5 1
2
2 3
4 3 4
1 2 3
1 3 4
2 3 2
1
1

1
-1
*/ 