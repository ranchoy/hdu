#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 110
using namespace std;

struct node{
	int idx,num;
	int time;
	int res;
} p[MAX];

bool cmp(node a, node b) 
{
	if(a.num != b.num)
	{
		return a.num > b.num;	
	}	
	else
	{
		return a.time < b.time;
	}
}

bool cmp2(node a, node b)
{
	return a.idx < b.idx;
}

int main()
{
	int sum[10],tol[10];
	int n,h,m,s;
	while(~scanf("%d", &n) && (n!=-1))
	{
		// 初始化
		memset(p, 0, sizeof(p));
		memset(sum, 0, sizeof(sum)); 
		memset(tol, 0, sizeof(tol));
		
		for(int i=0; i<n; i++)
		{
			p[i].idx = i;
			scanf("%d %d:%d:%d", &p[i].num, &h, &m, &s);
			p[i].time = 3600*h + 60*m + s;	
			sum[ p[i].num ] ++;//计算数量 
		}
		
		sort(p, p+n, cmp); 
		
		for(int i=4; i>0; i--)
		{
			tol[i] = tol[i+1] + sum[i+1];
		}
		
		for(int i=0; i<n; i++)
		{
			p[i].res = 50 + 10*p[i].num;
			
			if( p[i].num>=1 && p[i].num<=4 && (i+1 - tol[p[i].num] <= sum[p[i].num]/2))
			{
				p[i].res += 5;
			}
		}
		
		sort(p, p+n, cmp2);
		
		for(int i=0; i<n; i++)
		{
			cout << p[i].res << endl;
		}
		printf("\n");
	}
	return 0;
} 
/**
4
5 06:30:17
4 07:31:27
4 08:12:12
4 05:23:13
100
90
90
95

1
5 06:30:17
100

-1
*/