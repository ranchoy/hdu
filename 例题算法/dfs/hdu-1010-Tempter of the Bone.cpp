//dfs算法,用到剪枝,奇偶剪枝
#include <cstdio>
#include <cmath>

using namespace std;

int n,m,t,sx,sy,ex,ey,flag;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
char str[10][10];

void dfs( int x, int y, int step)
{

    if( step==t && x==ex && y==ey)
    {
        flag = 1;
        return;
    }

    if(flag) return;

    //奇偶剪枝
    int temp = (t-step) - abs(x-ex) - abs(y-ey);

    if( temp <0 || temp&1 ){
        return;
    }

    for( int i=0; i<4; i++)
    {
        int fx = x + dir[i][0];
        int fy = y + dir[i][1];
        if( fx>=0 && fx<n && fy>=0 && fy<m && str[fx][fy]!='X' )
        {
            str[fx][fy] = 'X';
            dfs( fx, fy, step+1);
            str[fx][fy] = '.';//回溯
            if(flag) return;
        }
    }
}

int main()
{
    int wall;
    while( scanf("%d %d %d",&n,&m,&t)==3&&(n||m||t) )
    {
        getchar();
        wall = 0;
        flag = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%c",&str[i][j]);

                if( str[i][j]=='S' ){
                    sx = i;
                    sy = j;
                }else if( str[i][j]=='D' ){
                    ex = i;
                    ey = j;
                }else if( str[i][j]=='X' ){
                    wall ++;
                }
            }
            getchar();
        }

        //剪枝
        if( n*m - wall <= t){
            printf("NO\n");
        }else{
            str[sx][sy] = 'X';
            dfs( sx, sy, 0);

            if(flag){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
