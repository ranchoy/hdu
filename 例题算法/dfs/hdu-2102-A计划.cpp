#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 15

int m,n,t,flag;
char str[2][MAX][MAX];
int visited[2][MAX][MAX];
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void dfs( int k, int x, int y, int step)
{
    int nx,ny;
    if( flag==1 )
    {
        return;
    }

    if( step<t && str[k][x][y]=='P' )
    {
        flag = 1;
        return;
    }

    if( step==t )
    {
        if( str[k][x][y]=='P' )
        {
            flag = 1;
        }
        return;
    }

    for(int i=0; i<4; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];

        if( nx>=0 && nx<n && ny>=0 && ny<m && str[k][nx][ny]!='*' && visited[k][nx][ny]==0 )
        {
            if( str[k][nx][ny]!='#' )
            {
                visited[k][nx][ny] = 1;
                dfs( k, nx, ny, step+1);
                visited[k][nx][ny] = 0;
            }
            else
            {
                if( str[!k][nx][ny]!='#' && str[!k][nx][ny]!='*')
                {
                    if( visited[!k][nx][ny]==0 )
                    {
                        visited[!k][nx][ny] = visited[k][nx][ny] = 1;
                        dfs( !k, nx, ny, step+1);
                        visited[!k][nx][ny] = visited[k][nx][ny] = 0;
                    }
                }
            }
        }
    }
}

int main()
{
    int cnt;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        flag = 0;
        scanf("%d %d %d",&n,&m,&t);
        for( int k=0; k<2; k++)
        {
            for(int i=0; i<n; i++)
            {
                scanf("%s",&str[k][i]);
            }
        }
        memset( visited, 0, sizeof(visited));
        visited[0][0][0] = 1;
        dfs( 0, 0, 0, 0);

        if( flag )
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
