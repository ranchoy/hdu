// 题意：女生u愿意和男生v在一排，是单向的map[u][v] = 1；
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 505
using namespace std;

int m,n;// m女生，n男生
bool vis[MAX];
int match[MAX];
int map[MAX][MAX];

// 匈牙利算法：核心是让，女生没有男朋友或女生男朋友可以找其她女生
bool dfs(int u)
{
    for(int j=1; j<=n; j++)
    {
        if(vis[j]==false && map[u][j]==1)// 未被访问&男女有好感
        {
            vis[j] = true;
            if(match[j]==0 || dfs(match[j]))// 女生没有男朋友|女生男朋友可以找其他人
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
    int k,u,v,res;
    while(~scanf("%d", &k) && k!=0)
    {
        // 初始化
        res = 0;
        memset(map, 0, sizeof(map));
        memset(match, 0, sizeof(match));

        scanf("%d %d", &m, &n);
        while(k--)
        {
            scanf("%d %d", &u, &v);
            map[u][v] = 1;// 注意是单向的
        }

        // 男生和女生匹配
        for(int i=1; i<=m; i++)
        {
            memset(vis, false, sizeof(vis));
            
            if(dfs(i))
            {
                res ++;
            }
        }   

        cout << res << endl; 
    }
    return 0;
}

/*
6 3 3
1 1
1 2
1 3
2 1
2 3
3 1
0

3
0
*/
