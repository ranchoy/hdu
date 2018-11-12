// 最大独立集(任意两点没有边相连) = n个点 - 最大匹配(边的集合) 
// 这题就n个点，二分图划分是左边n个点，右边n个点
// 求得的最大匹配数要除以2，因为边重复了 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 501
using namespace std;

int n;
int map[MAX][MAX];
int vis[MAX],match[MAX];

bool dfs(int u)
{
	for(int j=0; j<n; j++)
	{
		if(map[u][j]==1 && vis[j] == 0)
		{
			vis[j] = 1;
			if(match[j]==0 || dfs(match[j]))
			{
				match[j] = u;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int u,v,num,res;
	while(~scanf("%d", &n))
	{
		// 初始化
		res = 0;
		memset(map, 0, sizeof(map));
		memset(match, 0, sizeof(match));
		 
		for(int i=0; i<n; i++)
		{
			scanf("%d: (%d)", &u, &num);
			while(num--)
			{
				scanf("%d", &v);
				map[u][v] = map[v][u] = 1;
			}
		}
		
		// 匈牙利算法
		for(int i=0; i<n; i++)
		{
			memset(vis, 0, sizeof(vis));
			if(dfs(i))	
			{
				res ++;
			}
		} 
		
		printf("%d\n", n - res/2);
	}
	return 0;
} 

/*
7
0: (3) 4 5 6
1: (2) 4 6
2: (0)
3: (0)
4: (2) 0 1
5: (1) 0
6: (2) 0 1
3
0: (2) 1 2
1: (1) 0
2: (1) 0

5
2
*/