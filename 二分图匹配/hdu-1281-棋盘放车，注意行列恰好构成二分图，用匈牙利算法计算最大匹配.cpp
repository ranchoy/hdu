// 棋盘放置车，同一行或者列只能放置一个棋子，例如(1,2)，(1,3)只能放一个棋子，相当于二分图求最大匹配用匈牙利算法即可
// 题目还要求重要的点，枚举k个点，先map[a][b]=0如果匹配数少了就是重要的点，然后map[a][b]=1还原 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;

int n,m,k;
int vis[MAX],match[MAX];
int map[MAX][MAX];// map[i][j]行i列j二分匹配 

struct node {
	int x,y;
} p[MAX*MAX];

// 匈牙利算法
bool dfs(int x) 
{
	for(int j=0; j<=m; j++)
	{
		if(map[x][j]==1 && vis[j]==0)
		{
			vis[j] = 1;
			if(match[j]==0 || dfs(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}

int get_max_match()
{
	int res=0; 
	memset(match, 0, sizeof(match));// 初始化 
	for(int i=1; i<=n; i++)
	{
		memset(vis, 0, sizeof(vis));
		if(dfs(i))
		{
			res ++;
		}
	}
	return res;
}

int main()
{
	int cnt = 1,temp;
	int a,b,res,point;
	while(~scanf("%d %d %d", &n, &m, &k))
	{
		// 初始化
		res = point = 0;
		memset(map, 0, sizeof(map));
		
		for(int i=0; i<k; i++)
		{
			scanf("%d %d", &a, &b);
			map[a][b] = 1;
			p[i].x = a;
			p[i].y = b; 
		}
		
		// 求最大匹配 
		res = get_max_match();

		// 不断去点，求不重要点
		for(int i=0; i<k; i++)
		{
			a = p[i].x;
			b = p[i].y;
			map[a][b] = 0;
			temp = get_max_match();
			map[a][b] = 1;// 还原 
			if(temp < res)	
			{
				point ++; // 重要的点 
			}
		} 	
		printf("Board %d have %d important blanks for %d chessmen.\n", cnt++, point, res);
	}
	return 0;
} 

/*
3 3 4
1 2
1 3
2 1
2 2
3 3 4
1 2
1 3
2 1
3 2

Board 1 have 0 important blanks for 2 chessmen.
Board 2 have 3 important blanks for 3 chessmen.
*/