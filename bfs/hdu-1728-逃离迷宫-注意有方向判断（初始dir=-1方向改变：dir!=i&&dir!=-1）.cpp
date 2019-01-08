#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define MAX 105
using namespace std;

int m,n,w;
int turn[MAX][MAX]; // 转弯次数
char map[MAX][MAX];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

struct node {
    int x,y,w,dir;
}s,e;

bool bfs(struct node s)
{
    struct node cur,next;
    queue<struct node> q;
    q.push(s);

    while(!q.empty())
    {
        cur = q.front();
        q.pop();

        if(cur.x==e.x && cur.y==e.y && cur.w<=w)
        {
            return true;
        }

        for(int i=0; i<4; i++)
        {
            next = cur;
            next.x += dir[i][0];
            next.y += dir[i][1];
            next.dir = i;
            
            if(cur.dir!=-1 && cur.dir!=i) // 当前方向改变
            {
                next.w ++;
            }

            if(next.x>=1 && next.x<=m && next.y>=1 && next.y<=n && map[next.x][next.y]!='*')
            {
                if(next.x==e.x && next.y==e.y && next.w<=w)
                {
                    return true;
                }
                // 注意等于符号，详见：http://972169909-qq-com.iteye.com/blog/1244218
                if(next.w <= turn[next.x][next.y])
                {
                    turn[next.x][next.y] = next.w;
                    q.push(next);
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        // 初始化
        memset(map, 0, sizeof(map));
        memset(turn, 1, sizeof(turn));

        scanf("%d %d", &m, &n);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf(" %c", &map[i][j]);
            }
        }

        scanf("%d %d %d %d %d", &w, &s.y, &s.x, &e.y, &e.x);
        s.w = 0;
        s.dir = -1;

        if(bfs(s))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

/*

2
5 5
...**
*.**.
.....
.....
*....
1 1 1 1 3
5 5
...**
*.**.
.....
.....
*....
2 1 1 1 3

no
yes
*/