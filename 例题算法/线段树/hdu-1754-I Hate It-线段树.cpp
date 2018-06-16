#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200000
#define M 5000
#define INF 0x7ffffff
using namespace std;

int res;
struct Tree{
	int low,high,w;
}tree[4*N+1];

void build(int low, int high, int k)
{
	tree[k].low = low;
	tree[k].high = high;
	tree[k].w = 0;
	if(low == high)
	{
		return;
	}
	int mid = (low + high) / 2;
	build(low, mid, 2*k);//左孩子 
	build( mid+1, high, 2*k + 1);//右孩子 
}

void update(int idx, int val, int k)
{
	if(tree[k].low==tree[k].high && tree[k].low==idx) //叶子节点 
	{
		tree[k].w = val;
		return;
	}
	
	int mid = (tree[k].low + tree[k].high) / 2;
	
	if( idx <= mid)
	{
		update(idx, val, 2*k);
	}
	else
	{
		update(idx, val, 2*k+1);
	} 
	
	tree[k].w = max(tree[2*k].w, tree[2*k+1].w); //最大值 
}

void search(int low, int high, int k)
{
	if(tree[k].low==low && tree[k].high==high)
	{
		res = max(res, tree[k].w);
		return;
	}
	int mid = (tree[k].low + tree[k].high) / 2;
	if( low >= mid+1) 
	{
		search(low, high, 2*k+1);
	}
	else if(high <= mid)
	{
		search(low, high, 2*k);
	}
	else
	{
		search(low, mid, 2*k);
		search(mid+1, high, 2*k+1);
	}
}

int main()
{
	int n,m,a,b,mx;
	char ch;
	while(scanf("%d %d", &n, &m)==2)
	{	
		getchar();
		build(1, n, 1);//建立线段树 

		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a);
			update(i, a, 1);
		}
		
		while(m--)
		{
			getchar();
			scanf("%c %d %d", &ch, &a, &b);			
	
			if(ch=='Q')
			{
				res = -INF;
				search(a, b, 1);
				cout<< res << endl;
			}
			else if(ch=='U')
			{
				update(a, b, 1);
			}
		}
	}
	return 0;
}