#include<iostream>
#include<cstdio>
#define N 100

using namespace std;
int m,n;
int str[N][N];
int dir[8][2] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };//八个方向

void dfs( int x, int y)
{
    int nx,ny;
    for( int i=0; i<8; i++)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if( nx>=0 && nx<m && ny>=0 && ny<n && str[nx][ny]=='@' )
        {
            str[nx][ny] = '*';
            dfs( nx, ny);
        }
    }
}

//这里的思路是只要是同一个油井我们就把他变成没有的，然后加1
int main()
{
    int cnt;
    while( scanf("%d %d",&m,&n)!=EOF )
    {
        cnt = 0;
        if( m==0 && n==0 )
        {
            break;
        }
        getchar();
        for( int i=0; i<m; i++)
        {
            for( int j=0; j<n; j++)
            {
                scanf("%c",&str[i][j]);
            }
            getchar();
        }

        for( int i=0; i<m; i++)
        {
            for( int j=0; j<n; j++)
            {
                if( str[i][j]=='@' )
                {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}

