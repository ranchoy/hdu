#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 105
#define INF 0x7f7f7f7f
using namespace std;

int p_times[MAX];// 点i入队列次数,用于判断负权图,p_times[i]<=n,因为只要n-1次就能求出所有单源最短路径 
int map[MAX][MAX],vis[MAX],dist[MAX];

// spfa求单源最短路径,边的权值可以为负数
// spfa算法很好理解:不断把与队列中点相通且dist更小的点加入到队列中
// 负环的图判断：我们要知道带有负环的图是没有最短路径的,如果某个点进入队列的次数超过n次则存在负环(n为图的顶点数)
void spfa(int s)
{
	int cur;
	queue<int> q;
	q.push(s);
	
	vis[s] = 1;
	dist[s] = 0;
	p_times[s] ++;
	
	while(!q.empty()) 
	{
		cur = q.front();
		q.pop();
		vis[cur] = 0;// 出队列释放标记 

		for(int i=1; i<=n; i++)
		{
			if(map[cur][i]!=INF && dist[i]>dist[cur]+map[cur][i])
			{
				dist[i] = dist[cur] + map[cur][i];
				if(vis[i] == 0)// 点i不在队列中 
				{
					vis[i] = 1;
					q.push(i);
					
					if(p_times[i] > n)
					{
						printf("存在负环\n");
						return;
					}
				}
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
		memset(p_times, 0, sizeof(p_times));
		
		while(m--)
		{
			cin >> u >> v >> w;
			map[u][v] = map[v][u] = w;	
		} 
		
		spfa(1);
		for(int i=1; i<=n; i++)
		{
			printf("%d ", dist[i]);
		}printf("\n");
	}
	return 0;
}