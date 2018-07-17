#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 11000
using namespace std;

int maxn;
int is_circle,graph;
int pre[MAX],vis[MAX];//pre[i],i的父亲是pre[i] 

int find(int x)
{
	int r = x;
	while(pre[r]!=r)
	{
		r = pre[r];
	}
	
	int i=x,j;
	while(pre[i]!=r)//路径压缩,1->2->3变成1->2,1->3 
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

void join(int u, int v)//合并u->v
{
	int a,b;
	a = find(u);
	b = find(v);
	
	if(b!=v || a==b)//有向图有环的两种情况,1->2、2->1或1->2->4、1->3->4; 
	{
		is_circle = 1;
	}
	if(a!=b)
	{
		pre[b] = a;//注意这里的顺序 
	} 
} 

void init()
{
	//初始化 
	is_circle = 0;
	graph = 0;
	maxn = 0;
	memset(vis, 0, sizeof(vis));
	for(int i=1; i<=MAX; i++)	
	{
		pre[i] = i;
	}	
}

int main()
{
	int a,b,_case=1;
	init();
	while(~scanf("%d %d", &a, &b) && (a!=-1 && b!=-1))
	{
		if(a==0 && b==0)
		{
			for(int i=1; i<=maxn; i++)
			{
				if(vis[i]==1 && pre[i]==i)
				{
					graph ++;//连通子图的数量 
				}
			}
			
			if(is_circle==0 && graph<=1)
			{
				printf("Case %d is a tree.\n", _case++);
			}
			else
			{
				printf("Case %d is not a tree.\n", _case++);
			}		
			init();
		}
		else
		{
			maxn = max(maxn, max(a,b));//最大的数 
			vis[a] = vis[b] = 1;
			join(a, b);
		}
	}
	return 0;
}
/**
6 8 5 3 5 2 6 4
5 6 0 0

8 1 7 3 6 2 8 9 7 5
7 4 7 8 7 6 0 0

3 8 6 8 6 4
5 3 5 6 5 2 0 0

-1 -1

Case 1 is a tree.
Case 2 is a tree.
Case 3 is not a tree.
*/ 