// 题意：女生u愿意和男生v在一排，是单向的map[u][v] = 1；
// 匈牙利算法：当不能再找到增广轨时，就得到了一个最大匹配
// 匈牙利算法：核心是让，就是不停的找增广路（匹配边和未匹配边交替，第一和最后是未匹配边），然后反转
// 下标不能从0开始因为match[k]=0，不知道是没有女朋友还是女朋友是0
#include<iostream>
#include<cstring>
#define N 505
using namespace std;

int m,n; // m女生，n男生
int vis[N]; // vis[i]表示女生
int map[N][N]; // map[i][j]表示女生i愿意和男生j坐一起
int match[N]; // match[j]表示男生j的女朋友是match[j]


// 解释：女生没有男朋友或女生男朋友可以找其她女生
bool dfs(int u)
{
    for(int j=1; j<=n; j++)
    {
        if(vis[j]==0 && map[u][j]==1) // 未匹配点&可以匹配
        {
            vis[j] = 1;
            if(match[j]==0 || dfs(match[j])) // 没有女朋友|女朋友可以找其他男生
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
    while(~scanf("%d", &k) && k)
    {
        // 初始化
        res = 0;
        memset(map, 0, sizeof(map));
        memset(match, 0, sizeof(match));
        
        scanf("%d %d", &m, &n);
        while(k--)
        {
            scanf("%d %d", &u, &v);
            map[u][v] = 1; // 注意是单向的
        }

        // 女生找男朋友
        for(int i=1; i<=m; i++)
        {
            memset(vis, 0, sizeof(vis));
            if(dfs(i))
            {
                res++;
            }
        }
        printf("%d\n", res);
    }
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
*/