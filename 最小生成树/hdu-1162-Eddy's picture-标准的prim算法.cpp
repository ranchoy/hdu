#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX 105
#define INF 0x7f7f7f7f
using namespace std;

double dist[MAX],vis[MAX];
double x[MAX],y[MAX];
double map[MAX][MAX]; 

double prim(int n)
{
	double res=0;
	int cnt=n-1,dist_min,point;
	dist[0] = 0;
	while(cnt--)
	{
		dist_min = INF;
		// 找dist最小的点加入S集合 
		for(int i=0; i<n; i++)
		{
			if(vis[i]==0 && dist_min>dist[i])
			{
				dist_min = dist[i];
				point = i;	
			}	
		}	
		vis[point] = 1;// 标记已访问
		// 更新dist 
		for(int i=0; i<n; i++)
		{
			if(vis[i]==0 && map[point][i]!=INF && dist[i]>map[point][i])
			{
				dist[i] = map[point][i];
			}
		}
	}	
	
	for(int i=0; i<n; i++)
	{
		res += dist[i];
	}
	return res;
}

int main()
{
	int n;
	double temp,res;
	while(~scanf("%d", &n))
	{
		// 初始化
		memset(vis, 0, sizeof(vis));
		memset(map, 0x7f, sizeof(map));
		memset(dist, 0x7f, sizeof(dist));
		
		for(int i=0; i<n; i++)
		{
			scanf("%lf %lf", &x[i], &y[i]);	
		}	
		// 矩阵 
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				temp = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
				map[i][j] = map[j][i] = temp;
			}
		}
		// prim算法
		res = prim(n);
		printf("%.2lf\n", res);
	}	
} 

/*
3
1.0 1.0
2.0 2.0
2.0 4.0

3.41
*/