// 最小独立集 = n个点 - 最大匹配数
// 这题就n个点，二分图划分是左边n个点，右边n个点
// 求得的最大匹配数要除以2，因为边重复了 
#include<iostream>
#include<cstring>
#define MAX 1005
using namespace std;

int n;
int vis[MAX];
int match[MAX];
int map[MAX][MAX];

// 匈牙利算法
bool dfs(int u)
{
    for(int j=0; j<n; j++)
    {
        if(map[u][j] == 1 && vis[j] == 0) // 边(u,j)存在且点j未被标记
        {
            vis[j] = 1;
            if(match[j] == 0 || dfs(match[j])) // 点j没有男朋友或者可以找其他人作为男朋友
            {
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int k,m,u,v,res;
    while(~scanf("%d", &n) && n)
    {
        // 初始化
        res = 0;
        memset(vis, 0, sizeof(vis));
        memset(map, 0, sizeof(map));
        memset(match, 0, sizeof(match));

        for(int i=0; i<n; i++)
        {
            scanf("%d: (%d)", &u, &m);
            while(m--)
            {
                scanf("%d", &v);
                map[u][v] = map[v][u] = 1;
            }
        }

        for(int i=0; i<n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if(dfs(i))
            {
                res ++;
            }
        }

        printf("%d\n", n - res/2);
    }
    return 0;
}

/*
7
0: (3) 4 5 6
1: (2) 4 6
2: (0)
3: (0)
4: (2) 0 1
5: (1) 0
6: (2) 0 1
3
0: (2) 1 2
1: (1) 0
2: (1) 0

5
2
*/