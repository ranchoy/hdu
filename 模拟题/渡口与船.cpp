#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 105
using namespace std;

char map[MAX][MAX];

int main()
{
    int n,m,res;
    while(~scanf("%d %d", &n, &m))
    {
        // 初始化
        res = 0;
        memset(map, 0, sizeof(map));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf(" %c", &map[i][j]);
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j] == 'o')
                    continue;
                    
                if(i!=n-1 && map[i+1][j]=='+') // 竖直
                {
                    map[i][j] = 'o';
                }

                if(j!=m-1 && map[i][j+1]=='+')// 水平
                {
                    map[i][j] = 'o';
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j] == '+')
                    res ++;
                printf("%c", map[i][j]);
            }printf("\n");
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
3 4
+oo+
ooo+
ooo+

2
*/