//题意：一个没有回路的联通图，考察并查集
//1.没有回路（环）；2.只有一个连通分支,或者没有连通分支(0 0的特殊情况) 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 100005
using namespace std;

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
	return r;//返回根节点
}

void join(int x, int y)//合并
{
	int a,b;
	a = find(x);
	b = find(y);
	
	if(a!=b)
	{
		pre[a] = b;	
	} 
	else//有环 
	{
		is_circle = 1;
	}
} 

void init()
{
	//初始化 
	is_circle = 0;
	graph = 0;
	memset(vis, 0, sizeof(vis));
	for(int i=1; i<=MAX; i++)	
	{
		pre[i] = i;
	}	
}
int main()
{
	int a,b;
	init();
	while(~scanf("%d %d", &a, &b) && (a!=-1 && b!=-1))
	{
		if(a==0 && b==0)
		{
			for(int i=1; i<=MAX; i++)
			{
				if(vis[i]==1 && pre[i]==i)
				{
					graph ++;//连通子图的数量 
				}
			}
			
			if(is_circle==0 && graph<=1)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			
			init();
		}
		else
		{
			vis[a] = 1;
			vis[b] = 1;
			join(a, b);
		}
	}
	return 0;
}
/**
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0

-1 -1

Yes
Yes
No
*/ 