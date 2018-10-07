#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 105
#define INF 0x7f7f7f7f
using namespace std;

int map[MAX][MAX];
int dist[MAX],vis[MAX];

int prim(int n)
{
	int cnt=n-1,point,res=0;
	dist[1] = 0;
	// n-1条边
	while(cnt--)
	{
		int temp=INF;
		for(int i=1; i<=n; i++)// 找V集合中到最小生成树最近的点 
		{
			if(vis[i]==0 && temp>dist[i])
			{
				temp = dist[i]; 
				point = i;
			}
		}
		
		vis[point] = 1;// 把point加入S集合 
		
		for(int i=1; i<=n; i++)
		{
			if(vis[i]==0 && map[point][i]<dist[i] && map[point][i]!=INF)
			{
				dist[i] = map[point][i];
			}
		}
	} 
	
	for(int i=1; i<=n; i++)
	{
		res += dist[i];
	}
	return res; 
}

int main()
{
	int n,res;
	int a,b,c;
	while(~scanf("%d", &n) && n)
	{
		// 初始化
		memset(vis, 0, sizeof(vis));
		memset(map, 0x7f, sizeof(map));
		memset(dist, 0x7f, sizeof(dist));
		
		for(int i=0; i<n*(n-1)/2; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}	
		
		res = prim(n);
		cout << res << endl;
	}	
	return 0;
}
/**
3
1 2 1
1 3 2
2 3 4
4
1 2 1
1 3 4
1 4 1
2 3 3
2 4 2
3 4 5
0

3
5
*/ 