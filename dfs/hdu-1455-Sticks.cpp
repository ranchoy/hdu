#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 70

using namespace std;

int num[N];
int visited[N];
int n,flag;

bool cmp( int a, int b)
{
    return a>b;
}
//下标，当前长度，目标一根长度，匹配数量
void dfs( int index, int clen, int slen, int cnt)
{
    if( flag )
    {
        return;
    }

    if( cnt==n )
    {
        flag = 1;
        return;
    }

    for( int i=index; i<n; i++)
    {
        if( visited[i]== 0 && clen+num[i]<=slen )
        {
            visited[i] = 1;

            if( clen+num[i]<slen )
            {
                dfs( i+1, clen+num[i], slen, cnt+1);
            }
            else
            {
                dfs( 0, 0, slen, cnt+1);
            }

            visited[i] = 0;

            if( flag )
            {
                return;
            }

            if( clen==0 ) //第一根dfs不满足条件，后面肯定不行
            {
                return;
            }
        }
    }
}

int main()
{
    int sum;
    while( scanf("%d",&n)!=EOF )
    {
        if( n==0 )
        {
            break;
        }
        flag = 0;
        sum = 0;
        memset( visited, 0, sizeof(visited));

        for( int i=0; i<n; i++)
        {
            scanf("%d",&num[i]);
            sum += num[i];
        }
        sort( num, num+n, cmp);//从大到小

        for( int i=num[0]; i<=sum; i++)
        {
            if( i==sum )
            {
                printf("%d\n",sum);
            }
            else if( sum%i==0 )
            {
                dfs( 0, 0, i, 0);
                if( flag )
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }

    }
}
