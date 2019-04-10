// 经典的DFS走迷宫问题，奇偶剪枝
#include<iostream>
#include<cstring>
#define MAX 55
using namespace std;

int vis[MAX][MAX];
char map[MAX][MAX];
int n,m,t,sx,sy,ex,ey,flag;
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(int x, int y, int step)
{
    int temp,nx,ny; 
    
    if(step == t && ex == x && ey == y)
    {
        flag = 1;
        return;
    }

    if(flag) return;
    
    // 奇偶剪枝
    temp = abs(t-step) - abs(ex-x) - abs(ey-y);
    if(temp&1 || temp<0) return;

    for(int i=0; i<4; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];

        if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny]!='X' && vis[nx][ny]==0)
        {
            vis[nx][ny] = 1;
            dfs(nx, ny, step+1);
            vis[nx][ny] = 0;
        }
    }
}

int main()
{
    int wall;
    while(~scanf("%d %d %d", &n, &m, &t) && (n+m+t))
    {
        // 初始化
        wall = 0;
        flag = 0;
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf(" %c", &map[i][j]);
                if(map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                else if(map[i][j] == 'D')
                {
                    ex = i;
                    ey = j;
                }
                else if(map[i][j] == 'X')
                {
                    wall++;
                }    
            }
        }
        
        if(n*m - wall <= t)
        {
            printf("NO\n");
        }
        else
        {
            vis[sx][sy] = 1;
            dfs(sx, sy, 0);
            
            if(flag) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

/*
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D
0 0 0

NO
YES
*/