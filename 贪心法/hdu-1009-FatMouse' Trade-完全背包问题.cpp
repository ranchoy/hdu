//完全背包问题 ，属于贪心法，先排序优先选择单位价值最大的物品 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;

struct Node{
	double w,v;
} room[MAX];

int cmp(Node a, Node b)
{
	return a.w*b.v > a.v*b.w;
}

int main()
{
	int m,n;
	double rate,sum;
	while( scanf("%d %d", &m, &n) == 2)
	{
		if(m==-1 || n==-1)
		{
			break;
		}
		
		for(int i=0; i<n; i++)
		{
			scanf("%lf %lf", &room[i].w, &room[i].v);
		}
		
		sort( room, room+n, cmp);
		sum = 0;
		
		for(int i=0; i<n; i++)
		{
			if( m - room[i].v > 0)
			{
				m -= room[i].v;
				sum += room[i].w;
			}
			else
			{
				rate = room[i].w / room[i].v; 
				sum += rate * m;
				break;
			} 
		}
		
		printf("%.3f\n", sum);
	}
	return 0;
}