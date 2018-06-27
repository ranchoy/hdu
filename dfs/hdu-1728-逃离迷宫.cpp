//这道题比较坑，首先是y1,x1,y2,x2输入,表示是行列不是下标
//这里用dfs,用转弯数记录，不是一般的dfs的step步骤
//这里用dfs,用转弯数记录，不是一般的dfs的step步骤数问题
#include<cstdio>
#include<iostream>
#include<cstring>
#define N 105
#define MAX 999999
using namespace std;

int m,n,k,x2,y2,flag;
int dir[4][2] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
char str[N][N];
int turn[N][N];

void dfs( int x, int y, int t)
{
    int nx,ny;
    if( x==x2 && y==y2 && turn[x][y]<=k )
    {
        flag = 1;
        return;
    }

    if( turn[x][y]>k )
    {
        return;
    }

    if( x!=x2 && y!=y2 && turn[x][y]==k )
    {
        return;
    }

    for( int i=0; i<4; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];

        if( nx>0 && nx<=m && ny>0 && ny<=n && str[nx][ny]=='.' )
        {
            if( turn[nx][ny] <  turn[x][y] )
            {
                continue;
            }
            //已经要转弯了，但是加上1还是大了，所以不能要
            if( t!=-1 && i!=t && turn[nx][ny]<turn[x][y]+1 )
            {
                continue;
            }

            if( t!=-1 && i!=t )
            {
                turn[nx][ny] = turn[x][y]+1;
            }
            else
            {
                turn[nx][ny] = turn[x][y];
            }

            str[nx][ny] = '*';
            dfs( nx, ny, i);
            str[nx][ny] = '.';
            if( flag )
            {
                return;
            }
        }
    }
}

int main()
{
    int cnt,x1,y1;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        scanf("%d %d",&m,&n);

        for( int i=1; i<=m; i++)
        {
            for( int j=1; j<=n; j++)
            {
                scanf(" %c",&str[i][j]);
                turn[i][j] = MAX;
            }
        }

        scanf("%d %d %d %d %d",&k,&y1,&x1,&y2,&x2);
        memset(turn,MAX,sizeof(turn));
        flag = 0;
        turn[x1][y1] = 0;
        dfs( x1, y1, -1);//初始方向为-1

        if( flag )
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
