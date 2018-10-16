#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX 105
#define INF 0x7f7f7f7f
using namespace std;

int pre[MAX];// 并查集 
double x[MAX],y[MAX];

struct node {
	int u,v;
	double w;
} edge[10000];

bool cmp(struct node a, struct node b)
{
	return a.w < b.w;	
}
// 并查集 
int find(int x)
{
	int r=x,a=x,b;
	while(pre[r] != r)// 搜索 
	{
		r = pre[r];
	}
	// 压缩
	while(pre[a] != r) 
	{
		b = pre[a];
		pre[a] = r;
		a = b;
	}
	return r;// 根节点 
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

double kruskal(int n, int edge_total)
{
	double res = 0;
	int edge_num = 0;	 
	for(int i=0; i<edge_total; i++)
	{
		if(join(edge[i].u, edge[i].v) == 1)// (u,v)不在一个集合 
		{
			res += edge[i].w;
			edge_num ++;
		}
	}
	if(edge_num == n-1)// 总共用n-1条边则有最小生成树 
	{
		return res;
	}
	return 0;
}

int main()
{
	int n,k;
	double temp,res;
	while(~scanf("%d", &n))
	{
		// 初始化
		memset(edge, 0, sizeof(edge));
		
		for(int i=0; i<n; i++)
		{
			pre[i] = i;// 初始化并查集数组pre[] 
			scanf("%lf %lf", &x[i], &y[i]);	
		}	
		// 结构体
		k = 0; 
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				temp = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
				edge[k].u = i;
				edge[k].v = j;
				edge[k].w = temp;
				k ++;
			}
		}
		// 排序
		sort(edge, edge+k, cmp);
		// kruskal算法
		res = kruskal(n, k);
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