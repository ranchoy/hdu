#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1010

using namespace std;

int num[N][N];
int visited[N][N];
int dir[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
int n,m,flag;
int sx,sy,ex,ey;

void dfs(int x, int y, int dir_xy, int turn)
{
    int nx,ny;
    if(flag || turn>2)
    {
        return;
    }

    if(turn<=2 && x==ex && y==ey)
    {
        flag = 1;
        return;
    }

    //剪枝,不在一条线结束
    if(turn==2 && x!=ex && y!=ey)
    {
        return;
    }

    for(int i=0; i<4; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];

        if(nx>0 && nx<=n && ny>0 && ny<=m && visited[nx][ny]==0 && turn<=2)
        {
            if( num[nx][ny]==0 || (nx==ex&&ny==ey) )
            {
                visited[nx][ny] = 1;
                //转弯了
                if(dir_xy!=-1 && i!=dir_xy)
                {
                    dfs(nx, ny, i, turn+1);
                }
                else
                {
                    dfs(nx, ny, i, turn);
                }
                visited[nx][ny] = 0;

                if( flag )
                {
                    return;
                }
            }
        }
    }
}

int main()
{
    int q;
    while(~scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
        {
            break;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&num[i][j]);
            }
        }

        scanf("%d",&q);

        while(q--)
        {
            scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
            flag = 0;
            memset(visited, 0, sizeof(visited));
            if(num[sx][sy] == num[ex][ey] && num[sx][sy]!=0)
            {
                visited[sx][sy] = 1;
                dfs( sx, sy, -1, 0);
            }

            if(flag)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }

    }
    return 0;
}
