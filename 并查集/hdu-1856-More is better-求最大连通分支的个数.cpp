#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 100005
#define INF 0x7fffffff
using namespace std;
 
int pre[MAX],num[MAX],vis[MAX];


int find(int x)
{
	int r = x;
	while(pre[r]!=r)//找根节点 
	{
		r = pre[r];
	}
	
	int i=x,j;
	while(pre[i]!=r)//路径压缩 
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

void join(int u, int v)
{
	int a,b;
	a = find(u);
	b = find(v);
	if(a!=b)
	{
		pre[b] = a;
		num[a] += num[b];
	}	
} 

int main()
{
	int mn,mx,res;
	int n,a,b;
	while(~scanf("%d", &n))
	{
		//初始化
		mn = INF;mx = 0;res = 1;
		memset(vis, 0 ,sizeof(vis));
		for(int i=0; i<MAX; i++)
		{
			pre[i] = i;	
			num[i] = 1;
		} 
		for(int i=0; i<n; i++)
		{
			scanf("%d %d", &a, &b);
			join(a,b);
			mn = min(mn, min(a,b));
			mx = max(mx, max(a,b));
		}
		
		for(int i=mn; i<=mx; i++)
		{
			res = max(res, num[i]);
		}
		cout << res << endl;
	}
	return 0;	
} 