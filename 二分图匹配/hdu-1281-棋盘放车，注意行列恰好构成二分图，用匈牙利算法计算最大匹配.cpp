// 题意：任意两个棋子不能在同一行或同一列，把行列看成二分图，相当于求二分图的最大匹配数
// 题目还要求重要的点，枚举k个点，先map[a][b]=0如果匹配数少了就是重要的点，然后map[a][b]=1还原 
#include<iostream>
#include<cstring>
#define N 105
using namespace std;

int n,m,k;
int vis[N];
int match[N]; // 列j对应的行未match[j]
int map[N][N];

struct node{
    int x,y;
} p[N*N];

// 匈牙利算法
bool dfs(int u)
{
    for(int j=1; j<=m; j++)
    {
        if(vis[j]==0 && map[u][j]==1) // 列未匹配&有关联边
        {
            vis[j] = 1;
            if(match[j]==0 || dfs(match[j])) // 没有行|行可以找其他列
            {
                match[j] = u;
                return true;
            }
        }
    }
    return false;
}

int get_max_match()
{
    int res = 0;
    memset(match, 0, sizeof(match)); // 初始化 
    for(int i=1; i<=n; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i))
        {
            res++;
        }
    }
    return res;
}

int main()
{
    int cnt = 1;
    int u,v,res,point,temp;
    while(~scanf("%d %d %d", &n, &m, &k))
    {
        // 初始化
        point = 0;
        memset(map, 0, sizeof(map));

        for(int i=0; i<k; i++)
        {
            scanf("%d %d", &u, &v);
            map[u][v] = 1;
            p[i].x = u;
            p[i].y = v;
        }

        // 最大匹配数
        res = get_max_match();

        // 不断去点，找重要点
        for(int i=0; i<k; i++)
        {
            u = p[i].x;
            v = p[i].y;
            map[u][v] = 0; // 去点
            temp = get_max_match();
            map[u][v] = 1; // 还原
            
            if(temp < res)
            {
                point++;
            }
        }

        printf("Board %d have %d important blanks for %d chessmen.\n", cnt++, point, res);
    }
    return 0;
}

/*
3 3 4
1 2
1 3
2 1
2 2
3 3 4
1 2
1 3
2 1
3 2

Board 1 have 0 important blanks for 2 chessmen.
Board 2 have 3 important blanks for 3 chessmen.
*/