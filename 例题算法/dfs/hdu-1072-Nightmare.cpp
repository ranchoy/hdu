#include<iostream>
#include<cstdio>
#include<cstring>
#define N 10
#define MAX 100000

using namespace std;

//a记录走到(x,y)要多步，最小的，初始最大数
//b表示走到(x,y)要多少时间
int map[N][N],step[N][N],time[N][N];
int m,n,min_step,sx,sy,ex,ey;
int dir[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };


//步数，剩余时间
void dfs( int x, int y, int step_xy, int time_xy)
{
    int nx,ny;
    //下标越界
    if( x<0 || x>=m || y<0 || y>=n)
    {
        return;
    }

    if( time_xy <=0 || step_xy > min_step )
    {
        return;
    }

    if( map[x][y]==0 )
    {
        return;
    }

    if( map[x][y]==3 )
    {
        if( step_xy < min_step )
        {
            min_step = step_xy;
        }
        return;
    }

    if( map[x][y]==4 )
    {
        time_xy = 6;
    }

    //剪枝
    if( step_xy>= step[x][y] && time[x][y]>=time_xy )
    {
        return;
    }
    step[x][y] = step_xy;
    time[x][y] = time_xy;
    for( int i=0; i<4; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];

        dfs( nx, ny, step_xy+1, time_xy-1);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while( t-- )
    {
        scanf("%d %d",&m,&n);

        for( int i=0; i<m; i++)
        {
            for( int j=0; j<n; j++)
            {
                scanf("%d",&map[i][j]);
                //初始化
                step[i][j] = MAX;
                time[i][j] = 0;

                if( map[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }

                if( map[i][j] == 3)
                {
                    ex = i;
                    ey = j;
                }
            }
        }

        min_step = MAX;//初始最大
        dfs( sx, sy, 0, 6);

        if(min_step == MAX)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",min_step);
        }
    }
    return 0;
}
