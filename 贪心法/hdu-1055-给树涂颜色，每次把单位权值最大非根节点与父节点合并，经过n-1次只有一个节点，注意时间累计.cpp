// 题解： 每次找一个单位时间权值最大(cost/cur_time）非根节点，与父节点合并，经过(n-1)次合并后只有一个节点
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;

struct node {
    double w;// 权值
    int parent,time,cost;
} p[MAX];

// 查找权值最大点
int get_point(int n, int root)
{
    int point;
    double max_w = 0;
    for(int i=1; i<=n; i++)
    {
        if(i!=root && p[i].w>max_w)
        {
            max_w = p[i].w;
            point = i;
        }
    }
    return point;
}

int main()
{
    int n,root,u,v,res;
    while(~scanf("%d %d", &n, &root) && (n+root))
    {
        // 初始化
        res = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &p[i].cost);
            p[i].time = 1;
            p[i].w = p[i].cost;
            res += p[i].cost;
        }

        for(int i=1; i<n; i++)
        {
            scanf("%d %d", &u, &v);
            p[v].parent = u;
        }

        for(int i=1; i<n; i++)
        {
            v = get_point(n, root);
            p[v].w = 0;
            u = p[v].parent;// v的父节点u
            res += p[v].cost * p[u].time;
            // 合并父和子节点，把m子节点的父亲指向p节点
            for(int j=1; j<=n; j++)
            {
                if(p[j].parent == v)
                {
                    p[j].parent = u;
                }
            }

            p[u].cost += p[v].cost;
            p[u].time += p[v].time;
            p[u].w = 1.0 * p[u].cost / p[u].time;
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
5 1
1 2 1 2 4
1 2
1 3
2 4
3 5
0 0

33
0
*/