#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define M 105
#define N 305
using namespace std;

int m,n;
int vis[N];// 表示已经访问的点 
int map[M][N];
int boys[M],girls[N];// 男生i的女朋友boys[i]，女生j的男朋友girls[j] 

bool dfs(int x)
{
	// 课程x找一个对应的学生i，比喻成男生x找女生j 
	for(int j=1; j<=n; j++)
	{
		if(map[x][j]==1 && vis[j]==0)// 学生j在学课程且学生未被搜索，女生j没有被搜索过 
		{
			vis[j] = 1;
			if(girls[j]==0 || dfs(girls[j]))// 单身或者她现在对象可以找到新的，女生j没有男朋友或者她男朋友可以找其他女生代替，把女生j让给男生x（增广路径的反转） 
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
	int cnt,temp,k,res;
	cin >> cnt;
	while(cnt--)
	{
		// 初始化
		res = 0;
		memset(girls, 0, sizeof(girls));
		memset(map, 0, sizeof(map));
		 
		scanf("%d %d", &m, &n);
		for(int i=1; i<=m; i++)
		{
			scanf("%d", &temp);
			while(temp--)
			{
				scanf("%d", &k);
				map[i][k] = 1;
			}
		}
		
		for(int i=1; i<=m; i++)
		{
			memset(vis, 0, sizeof(vis));
			if(dfs(i))// 匹配好一个男生 
			{
				res ++;
			}
		}
		
		if(res == m)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
} 

/*
2
3 3
3 1 2 3
2 1 2
1 1
3 3
2 1 3
2 1 3
1 1

YES
NO
*/ 