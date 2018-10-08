//source:http://dengdengoj.cc/problem.php?id=1087
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 2005
#define INF 0x7f7f7f7f
using namespace std;

int vis[MAX];
double map[MAX][MAX],dist[MAX];// dist这里表示rate乘积，由于x*rate=100所以dist[i]越大越好 

void Dijkstra(int n, int s)
{
	vis[s] = 1;
	dist[s] = INF;
	for(int i=1; i<=n; i++)
	{
		dist[i] = max(dist[i], map[s][i]);
	}
	int cnt=n-1;
	while(cnt--)
	{
		double dist_max = 0;
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0 && dist_max<dist[i])
			{
				dist_max = dist[i];
				s = i;// 更改源点s到下一个点i 
			}
		}
		// 更新dist 
		for(int i=1; i<=n; i++)
		{
			if(map[s][i] != 0)
			{
				dist[i] = max(dist[i], dist[s]*map[s][i]);
			}
		}
	}
}
int main()
{
	int n,m,a,b;
	int u,v,rate;
	while(~scanf("%d %d", &n, &m))
	{
		// 初始化
		memset(vis, 0, sizeof(vis));
		memset(dist, 0, sizeof(dist));
		memset(map, 0, sizeof(map));
		 
		while(m--)
		{
			cin >> u >> v >> rate;
			map[u][v] = map[v][u] = 1 - 0.01*rate;
		}
		cin >> a >> b;

		Dijkstra(n,a);
		printf("%.8lf\n", 100/dist[b]);
	}
	return 0;
}
/*
3 3
1 2 1
2 3 2
1 3 3
1 3

103.07153164
*/