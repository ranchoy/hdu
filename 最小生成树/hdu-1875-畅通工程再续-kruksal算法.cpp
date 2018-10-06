/* kruskal算法步骤：
 * 1.构造结构体数组：u,v,w然后根据权值从小到大排序
 * 2.并查集算法，如果(u,v)不连通则把这条边加进s集合，否则舍弃
 * 3.如果最后加的边数等于(n-1)则构成最小生成树，否则无法构成
 */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAX 201
using namespace std;

int x[MAX],y[MAX],pre[MAX];//pre并查集数组 
double map[MAX][MAX];

struct node {
	int u,v;
	double w;
} edge[20000];

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

int main()
{
	int cnt,n,k,edge_num;
	double temp,sum;
	cin >> cnt;
	
	while(cnt--)
	{
		cin >> n;
	  	
		for(int i=0; i<n; i++)
		{ 
			// 初始化并查集 
			pre[i] = i;
			scanf("%d %d", &x[i], &y[i]);
		}
		// 构造边 
        k = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				temp = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));	
				// 边满足要求
				if(temp>=10 && temp<=1000)
				{
					edge[k].u = i;
					edge[k].v = j;
					edge[k].w = temp;
					k ++;
				} 
				
			}
		} 
		
		// 排序
		sort(edge, edge+k, cmp); 
		
		edge_num = 0;
		sum = 0;
		for(int i=0; i<k; i++)
		{
			if(join(edge[i].u, edge[i].v) == 1)//(u,v)祖先不一样可以合并 
			{
				edge_num ++;
				sum += edge[i].w; 
			}
		}

		// 边数为n-1 
		if(edge_num == n-1)
		{
			printf("%.1lf\n", sum*100);
		}
		else
		{
			printf("oh!\n");
		}
	}
	return 0;
} 