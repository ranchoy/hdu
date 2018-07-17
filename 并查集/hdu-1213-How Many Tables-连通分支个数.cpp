#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;

int pre[MAX];

int find(int x)
{
	int r = x;
	while(pre[r]!=r)//找根节点r 
	{
		r = pre[r];
	}
	
	int i = x,j;
	while(pre[i]!=r)//路径压缩 
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	
	return r; 
}

void join(int x, int y)
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
	int cnt;
	int n,m,a,b,temp,res;
	cin >> cnt;
	while(cnt--)
	{
		scanf("%d %d", &n, &m);
		//初始化
		res = 0;
		
		for(int i=1; i<=n; i++)
		{
			pre[i] = i;
		}
		 
		while(m--)
		{
			scanf("%d %d", &a, &b);
			join(a, b);
		}
		
		for(int i=1; i<=n; i++)
		{
			if(i==find(i))
			{
				res ++;
			}
		}
		cout << res << endl;
	}
	return 0;
} 
/**
2
5 3
1 2
2 3
4 5

5 1
2 5

2
4
*/