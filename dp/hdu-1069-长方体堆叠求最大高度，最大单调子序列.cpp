// 题意：长方体数量无限个，上面的长方体的长宽大于下面的，求最大高度
// 题型：单调递减子序列 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 35
using namespace std;

int dp[MAX];
struct node {
	int x,y,z;
} p[MAX*6];

bool cmp(node a, node b)
{
	if(a.x != b.x)
	{
		return a.x > b.x;	
	}	
	else
	{
		return a.y > b.y;
	}
}

void push(int a, int b, int c, int k)
{
	p[k].x = a;
	p[k].y = b;
	p[k].z = c;
}

int main()
{
	int n,x,y,z,k;
	int _case=1,mx;
	while(~scanf("%d", &n) && n!=0)
	{
		// 初始化
		mx = k = 0;
		 
		for(int i=0; i<n; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			push(x, y, z, k);
			push(x, z, y, k+1);
			push(y, x, z, k+2);
			push(y, z, x, k+3);
			push(z, x, y, k+4);
			push(z, y, x, k+5);
			k += 6;
		}
		
		sort(p, p+k, cmp);

		// 单调递减子序列
		for(int i=0; i<k; i++)
		{
			dp[i] = p[i].z;
			for(int j=0; j<i; j++)
			{
				if(p[i].x<p[j].x && p[i].y<p[j].y)
				{
					dp[i] = max(dp[i], dp[j]+p[i].z);	
				}		
			}	
			mx = max(mx, dp[i]);
		} 
		printf("Case %d: maximum height = %d\n", _case++, mx);
	}
	return 0;
}

/*
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0

Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342
*/ 