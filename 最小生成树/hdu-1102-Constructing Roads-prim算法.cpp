#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7f7f7f7f
#define MAX 105
using namespace std;

int map[MAX][MAX];
int vis[MAX],dist[MAX];//标记数组vis[],点i到图最短距离dist[i]
 
int prim(int n)
{	
	int cnt=n-1,point,dist_min;
	dist[1] = 0;
	while(cnt--)//n循环 
	{
		dist_min = INF;
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0 && dist_min>dist[i])
			{
				dist_min = dist[i];
				point = i;
			}
		}
		
		vis[point] = 1;
		
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0 && dist[i]>map[point][i] && map[point][i]!=INF)
			{
				dist[i] = map[point][i];
			}
		} 
	}
	
	//计算dist
	int res = 0;
	for(int i=1; i<=n; i++)
	{
		res += dist[i];	
	} 
	return res;
}
 
int main()
{
	int n;
	int q,a,b;
	while(~scanf("%d", &n))
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		
		scanf("%d", &q);
		while(q--)//减去已经有的路径 
		{
			scanf("%d %d", &a, &b);
			map[a][b] = map[b][a] = 0;
		}
		
		//初始化
		memset(vis, 0, sizeof(vis)); 
		memset(dist, 0x7f, sizeof(dist));
		
		int res = prim(n);
		cout << res << endl;
	}
	return 0;	
} 

/**
3
0 990 692
990 0 179
692 179 0
1
1 2

179
*/