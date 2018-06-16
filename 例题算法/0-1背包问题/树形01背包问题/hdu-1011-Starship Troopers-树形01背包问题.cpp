#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 105
using namespace std;

int n,m;//n个洞,m个士兵
int dp[MAX][MAX];//dp[i][j],以i为根节点,j为容量，值为最大价值
int vis[MAX];//标记数组
vector<int> dv[MAX];//dv[i]表示与i相连接的节点有哪些 

struct Node{
	int bugs_num,val;
}room[MAX];

void dfs(int root)
{
	vis[root] = 1;//root被访问 
	int cost = (room[root].bugs_num + 19) / 20;
	
	for(int j=cost; j<=m; j++)
	{
		dp[root][j] = room[root].val;//当前的root点赋值 
	}
	
	for(int i=0; i<dv[root].size(); i++)
	{
		int son = dv[root][i];//root的儿子son 
		if(vis[son] == 0)
		{
			dfs(son);
			
			for(int j=m; j>=cost; j--) //root点有士兵个数j
			{
				for(int k=1; k<=j-cost; k++) //给儿子的士兵个数k 
				{
					dp[root][j] = max(dp[root][j], dp[root][j-k] + dp[son][k]);
				}
			} 
		}
	} 
	
}

int main()
{
	int a,b;
	while( scanf("%d %d", &n, &m)!=EOF )
	{
		if(n==-1 || m==-1)
		{
			break;
		}
		
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<=n; i++)
		{
			dv[i].clear();
		} 
		for(int i=1; i<=n; i++)
		{
			cin >> room[i].bugs_num >> room[i].val;
		} 
		
		for(int i=1; i<n; i++) //连通块,n个点n-1条边 
		{
			cin >> a >> b;
			dv[a].push_back(b);
			dv[b].push_back(a);
		}
		
		if( m==0 )
		{
			printf("0\n");
		}
		else
		{
			dfs(1);
			printf("%d\n", dp[1][m]);
		}
	} 
	return 0;	
} 