#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#define MAX 30
using namespace std;

int pre[MAX]; 
struct node {
	int u,v,w;
} edge[2000];

bool cmp(struct node a, struct node b)
{
	return a.w < b.w;
} 

// 并查集
int find(int x) 
{
	int r=x,a,b;
	// 查找 
	while(pre[r] != r)
	{
		r = pre[r];
	}
	// 压缩
	a = x;
	while(pre[a] != r)
	{
		b = pre[a];
		pre[a] = r;
		a = b;	
	} 
	return r;
}

int join(int x, int y)
{
	int a,b;
	a = find(x);
	b = find(y);
	if(a != b)
	{
		pre[b] = a;
		return 1;
	}
	return 0;
}
// kruskal算法n个点,m条边 
int kruskal(int n, int m)
{
	int edge_num=0,res=0;
	for(int i=0; i<m; i++)
	{
		if(join(edge[i].u, edge[i].v) == 1)
		{
			res += edge[i].w;
			edge_num ++;
		}	
	}	
	if(edge_num == n-1)// 总共有n-1条边 
	{
		return res;
	}
	return 0;
}

int main()
{
	char a,b;
	int n,m,k,t,res;
	while(~scanf("%d", &n) && n!=0)
	{
		getchar();
		// 初始化
		k = 0;// 边数 
		memset(edge, 0, sizeof(edge));
		for(int i=0; i<n; i++)
		{pre[i] = i;}
		// 结构体 
		for(int i=1; i<n; i++)
		{
			getchar();
			scanf("%c %d", &a, &m);
			while(m--)
			{
				getchar();
				scanf("%c %d", &b, &t);
				edge[k].u = a - 'A';
				edge[k].v = b - 'A';
				edge[k].w = t;
				k ++;
			}
		}
		// 排序
		sort(edge, edge+k, cmp);
		// kruskal算法 
		res = kruskal(n, k);
		cout << res << endl;
	}
	return 0;
}

/*
9
A 2 B 12 I 25
B 3 C 10 H 40 I 8
C 2 D 18 G 55
D 1 E 44
E 2 F 60 G 38
F 0
G 1 H 35
H 1 I 35
3
A 2 B 10 C 40
B 1 C 20
0

216
30
*/ 