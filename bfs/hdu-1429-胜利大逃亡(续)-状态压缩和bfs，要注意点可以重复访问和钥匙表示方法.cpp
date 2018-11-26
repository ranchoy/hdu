#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 21
using namespace std;

int n,m,t;
char map[MAX][MAX];
int vis[MAX][MAX][1<<10 + 1];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 

struct node {
    int key;// key表示钥匙数
    int x,y,step;
};
struct node s;// 起点

int bfs(struct node s)
{
    int flag;
    struct node cur,next;
    queue<struct node> q;
    vis[s.x][s.y][0] = 1;
    q.push(s);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        if(map[cur.x][cur.y]=='^' && cur.step<t)// 达到终点且step<t
        {
            return cur.step;
        }

        for(int i=0; i<4; i++)
        {
            next = cur;
            next.x += dir[i][0];
            next.y += dir[i][1];
            next.step ++;

            // 不越界，不是墙，在t时间内
            if(next.x>=0 && next.x<n && next.y>=0 && next.y<m && map[next.x][next.y]!='*' && next.step<t)
            {
                if(map[next.x][next.y]>='A' && map[next.x][next.y]<='J')// 门A-J
                {
                    flag = next.key & 1<<(map[next.x][next.y] - 'A');// 验证钥匙 
                    if(flag && vis[next.x][next.y][next.key]==0)
                    {
                        vis[next.x][next.y][next.key] = 1;
                        q.push(next);
                    }
                }
                else if(map[next.x][next.y]>='a' && map[next.x][next.y]<='j')// 钥匙a-j
                {
                    next.key = next.key | 1<<(map[next.x][next.y] - 'a'); // 捡钥匙
                    if(vis[next.x][next.y][next.key] == 0)
                    {
                        vis[next.x][next.y][next.key] == 1;
                        q.push(next);
                    }
                }
                else if(map[next.x][next.y]=='.' || map[next.x][next.y]=='@')
                {
                    if(vis[next.x][next.y][next.key] == 0)
                    {
                        vis[next.x][next.y][next.key] = 1;
                        q.push(next);
                    }
                }
                else if(map[next.x][next.y]=='^')
                {
                    return next.step;
                }
            }
        }
    }
    return -1;
}

int main()
{
    int res;
    while(~scanf("%d %d %d", &n, &m, &t))
    {
        // 初始化
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf(" %c", &map[i][j]);

                if(map[i][j] == '@')
                {
                    s.x = i;
                    s.y = j;
                    s.key = 0;
                    s.step = 0;
                }
            }
        }
 
        res = bfs(s);
        printf("%d\n", res);
    }
    return 0;
}

/*
4 5 17
@A.B.
a*.*.
*..*^
c..b*
4 5 16
@A.B.
a*.*.
*..*^
c..b*

16
-1
*/