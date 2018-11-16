//https://blog.csdn.net/u013445530/article/details/44301995
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 100005
#define INF 0x7fffffff
using namespace std;

struct node {
	double x,y;
} p[MAX];

bool cmp(node a, node b)
{
	if(a.x != b.x)
	{
		return a.x < b.x;
	}
	return a.y < b.y;
}

bool cmp_y(node a, node b)
{
	return a.y < b.y;
}

double get_dist(node a, node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double solve(int left, int right)
{	
	vector<node> vet;
	double dist_min = INF;
	int mid = (left + right) / 2;
	
	if(left == right)
	{
		return dist_min;
	}
	if(left + 1 == right)
	{
		return get_dist(p[left], p[right]);
	} 
	 
    dist_min = min(solve(left, mid), solve(mid+1, right));// 最小距离 
    // 最近点有可能一个点在左边，一个点在右边，所以要单独
	for(int i=left; i<=right; i++) 
    {
        if(fabs(p[mid].x - p[i].x) <= dist_min)// 在范围内的点
        {
            vet.push_back(p[i]);
        } 
    }

    sort(vet.begin(), vet.end(), cmp_y);
    for(int i=0; i<vet.size(); i++)
    {
        for(int j=i+1; j<vet.size(); j++)
        {
        	if(vet[j].y - vet[i].y >= dist_min)//如果有y坐标差大于dist_min的话，就跳出，因为后面的话都是大于y，不存在更小的 
        	{
        		break;
			}
            dist_min = min(dist_min,get_dist(vet[i],vet[j]));
        }
    }
	return dist_min; 
}

int main()
{
	int n;
	while(~scanf("%d", &n) && n!=0)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		sort(p, p+n, cmp);
		printf("%.2lf\n", solve(0, n-1) / 2);
	}
	return 0;
}

/*
2
0 0
1 1
2
1 1
1 1
3
-1.5 0
0 0
0 1.5
0

0.71
0.00
0.75
*/