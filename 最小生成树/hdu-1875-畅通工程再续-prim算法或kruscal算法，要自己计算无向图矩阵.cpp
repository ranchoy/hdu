#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAX 105
#define INF 0x7f7f7f7f
using namespace std;

int vis[MAX];
double map[MAX][MAX],dist[MAX];

struct node {
	int x,y;
} p[MAX];

// prim算法保证连通的前提下求最小生成树 
void prim(int n)
{
	int cnt=n,point;
	double dist_min,res=0;
	dist[0] = 0;
	// n-1条边 
	while(cnt--)
	{
		dist_min = INF;
		for(int i=0; i<n; i++)// 找一个最小dist的点加入s集合 
		{
			if(vis[i]==0 && dist[i]<dist_min)
			{
				dist_min = dist[i];
				point = i;
			}
		}
		
		if(dist_min == INF)
		{
			printf("oh!\n");
			return ;	
		}
		
		vis[point] = 1;
		// 更新点point到各个不在s集合中点的距离 
		for(int i=0; i<n; i++)
		{
			if(vis[i]==0 && map[point][i]<dist[i] && map[point][i]!=INF)
			{
				dist[i] = map[point][i];
			}
		} 
	}
	
	for(int i=0; i<n; i++)
	{
		res += dist[i]*100;
	}
	printf("%.1lf\n", res);
}

int main()
{
	int cnt,n;
	cin >> cnt;
	while(cnt--)
	{
		// 初始化
		memset(vis, 0, sizeof(vis)); 
		memset(dist, 0x7f, sizeof(dist));
		
		cin >> n;
		for(int i=0; i<n; i++)
		{
			scanf("%d %d", &p[i].x, &p[i].y);
		}
		// 构图矩阵 
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				map[i][j] = map[j][i] = sqrt(1.0*(p[i].x - p[j].x)*(p[i].x - p[j].x) + (p[i].y - p[j].y)*(p[i].y - p[j].y));	
				if(map[i][j]>1000 || map[i][j]<10)
				{
					map[i][j] = map[j][i] = INF;
				}
			}	
		} 		

		prim(n);
	}
	return 0;
}
/*
2
2
10 10
20 20
3
1 1
2 2
1000 1000

1414.2
oh!
*/