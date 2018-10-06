#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005 
using namespace std;

int pre[MAX];

int find(int x)//查找根节点 
{
	int root = x;
	while(pre[root]!=root)
	{
		root = pre[root];
	}
	
	int i=x,j;
	while(pre[i]!=root)//路径压缩算法 
	{
		j = pre[i];
		pre[i] = root;//1->2->3变成1->2,1->3 
		i = j;
	}
	return root;
}

void join(int x, int y)//联通x和y 
{
	int a,b;
	a = find(x);
	b = find(y);
	if(a!=b)
	{
		pre[a] = b;
	}
}

int main()
{
	int n,m,res;
	int  a,b,temp;
	while(~scanf("%d", &n) && n)
	{
		//初始化,自己就是根节点
		res = 0;
		for(int i=1; i<=n; i++)
		{
			pre[i] = i;	
		} 
		
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d %d", &a, &b);
			join(a, b);
		}
		
		for(int i=1; i<=n; i++)//根节点个数就表示连通分支个数
		{
			if(pre[i] == i)
			{
				res ++;
			}
		}
		cout << res - 1 << endl;
	}
	return 0;
}
/**
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0

1
0
2
998
*/