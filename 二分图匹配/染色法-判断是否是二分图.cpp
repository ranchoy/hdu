// 染色法，判断是否是二分图
#include<iostream>
#include<cstring>
#include<queue>
#define N 1005
using namespace std;

int n,m;
int vis[N];
int map[N][N];

bool bfs()
{
    int cur;
    queue<int> q;
    memset(vis, 0, sizeof(vis)); // 初始化
    vis[1] = 1;
    q.push(1);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        for(int j=1; j<=n; j++)
        {
            if(map[cur][j] == 1)
            {
                if(vis[j] == 0) // 未染色
                {
                    vis[j] = (vis[cur] == 1) ? 2 : 1; // 邻边异色
                    q.push(j);
                }
                else if(vis[cur] == vis[j]) // 邻边同色
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int u,v;
    while(~scanf("%d %d", &n, &m))
    {
        // 初始化
        memset(map, 0, sizeof(map));

        while(m--)
        {
            scanf("%d %d", &u, &v);
            map[u][v] = map[v][u] = 1;
        }

        if(bfs())
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        
    }
    return 0;
}

/*
4 4
1 2
1 3
1 4
2 3
6 5
1 2
1 3
1 4
2 5
3 6

no
yes
*/