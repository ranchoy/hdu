#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 200000
using namespace std;

int n,m,res;
struct node {
	int left,right,val;
} tree[4*MAX + 5];

// 线段树建立,build(左边界,右边界,节点k);
void build(int left, int right, int k)
{
	tree[k].left = left;
	tree[k].right = right;
	tree[k].val = 0;
	if(left == right)
	{
		return;
	}
	int mid = (left + right) / 2;
	build(left, mid, 2*k);// 左孩子 
	build(mid+1, right, 2*k+1);// 右孩子
}

// 线段树更新,update(下标idx,值val,节点k) 
void update(int idx, int val, int k)
{
	int mid;
	if(tree[k].left==idx && tree[k].left==tree[k].right)
	{
		tree[k].val = val;
		return;
	}
	
	mid = (tree[k].left + tree[k].right) / 2;
	
	if(idx <= mid)
	{
		update(idx, val, 2*k);
	}
	else
	{
		update(idx, val, 2*k+1);
	}
	
	tree[k].val = max(tree[2*k].val, tree[2*k+1].val);// 最大值 
}

// 线段树查找,search(左边界left,右边界right,节点k) 
void search(int left, int right, int k)
{
	int mid;
	if(tree[k].left==left && tree[k].right==right)
	{
		res = max(res, tree[k].val);
		return;
	}
	
	mid = (tree[k].left + tree[k].right) / 2;
	
	if(left > mid)
	{
		search(left, right, 2*k+1);
	}
	else if(right <= mid)
	{
		search(left, right, 2*k);
	}
	else
	{
		search(left, mid, 2*k);
		search(mid+1, right, 2*k+1);
	}
} 

int main()
{
	int a,b;
	char ch;
	while(~scanf("%d %d", &n, &m))
	{
		// 初始化 
		getchar();
		build(1, n, 1);
		 
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &a);
			update(i, a, 1);
		}
		
		while(m--)
		{
			getchar();
			scanf("%c %d %d", &ch, &a, &b);
			if(ch == 'U')
			{
				update(a, b, 1);
			}
			else if(ch == 'Q')
			{	
				res = 0;
				search(a, b, 1);
				printf("%d\n", res);
			} 
		}
	}
	return 0;
} 

/*
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5

5
6
5
9
*/