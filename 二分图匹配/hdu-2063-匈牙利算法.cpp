#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 505
using namespace std;

int m,n;
int map[MAX][MAX];
int girls[MAX],vis[MAX];

bool dfs(int x)
{
	for(int j=1; j<=n; j++)
	{
		if(map[x][j]!=0 && vis[j]==0)
		{
			vis[j] = 1;
			if(girls[j]==0 || dfs(girls[j]))
			{
				girls[j] = x;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int k,a,b,res;
	while(~scanf("%d", &k) && k)
	{
		// 初始化
		res = 0;
		memset(map, 0, sizeof(map));
		memset(girls, 0, sizeof(girls));
		
		scanf("%d %d", &m, &n);
		while(k--)
		{
			scanf("%d %d", &a, &b);
			map[a][b] = 1;	
		} 
		
		// 匈牙利算法 
		for(int i=1; i<=m; i++)
		{
			memset(vis, 0, sizeof(vis));
			if(dfs(i))
			{
				res ++;
			}
		}
		cout << res << endl;
	}
	return 0;
}

/*
6 3 3
1 1
1 2
1 3
2 1
2 3
3 1
0

3
*/ 