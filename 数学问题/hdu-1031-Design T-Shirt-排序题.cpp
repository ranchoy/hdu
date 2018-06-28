//
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10010
using namespace std;

struct node{
	int idx;
	double sum;
}p[MAX];

int cmp(node a, node b)
{
	return a.sum > b.sum;
}

int cop(node a, node b)
{
	return a.idx > b.idx;
}

int main()
{
	int n,m,k;
	double num;
	while(scanf("%d %d %d", &n, &m, &k)==3)
	{
		for(int i=0; i<m; i++)
		{
			p[i].idx = i+1;
			p[i].sum = 0;
		}
		for(int i=0; i<n; i++)
		{	
			for(int j=0; j<m; j++)
			{
				scanf("%lf", &num);
				p[j].sum += num;
			}
		}
		
		sort(p, p+m, cmp);
		sort(p, p+k, cop);
		for(int i=0; i<k-1; i++)
		{
			printf("%d ", p[i].idx);
		}
		printf("%d\n",p[k-1].idx);
	}
	return 0;
}
/**
3 6 4
2 2.5 5 1 3 4
5 1 3.5 2 2 2
1 1 1 1 1 10

3 3 2
1 2 3
2 3 1
3 1 2

6 5 3 1
2 1
*/