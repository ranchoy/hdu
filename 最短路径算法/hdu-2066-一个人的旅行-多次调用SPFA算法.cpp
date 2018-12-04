#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 1005
#define INF 0x7f7f7f7f
using namespace std;

int n,m,t,res;
bool vis[MAX];
int dist[MAX];
int map[MAX][MAX],near[MAX],want[MAX];

// 求单源最短路径
void spfa(int s)
{
    int cur;
    queue<int> q;
    vis[s] = true;
    dist[s] = 0;
    q.push(s);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();
        vis[cur] = false;// 释放s

        for(int j=0; j<MAX; j++)
        {
            if(map[cur][j]!=INF && dist[j]>dist[cur]+map[cur][j])
            {
                dist[j] = dist[cur] + map[cur][j];
                if(vis[j] == false)// 点j不在队列中则现在加入且标记
                {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
    }

    // 去目的地最小的dist
    for(int i=0; i<t; i++)
    {
        res = min(res, dist[ want[i] ]);
    }
}

int main()
{
    int u,v,w,s;
    while(~scanf("%d %d %d", &n, &m, &t))
    {
        // 初始化
        res = INF;
        memset(map, 0x7f, sizeof(map));

        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            if(map[u][v] > w)
            {
                map[u][v] = map[v][u] = w;
            }      
        }

        // 和家临近的起点
        for(int i=0; i<m; i++)
        {
            scanf("%d", &near[i]);
        }

        // 想去的目的地
        for(int i=0; i<t; i++)
        {
            scanf("%d", &want[i]);
        }
        
        for(int i=0; i<m; i++)
        {
            // 初始化
            memset(dist, 0x7f, sizeof(dist));
            memset(vis, false, sizeof(vis));
            spfa(near[i]);
        }

        printf("%d\n", res);
    }
    return 0;
}

/*
6 2 3
1 3 5
1 4 7
2 8 12
3 8 4
4 9 12
9 10 2
1 2
8 9 10

9
*/