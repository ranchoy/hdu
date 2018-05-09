#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define N 21
using namespace std;

int a[N],visited[N];
int avg,n;

bool cmp(int a,int b)
{
    return a>b;
}

//cnt第几条边,index下标,len的前边长度
int dfs( int cnt, int index, int len)
{
    if( cnt==3 )
    {
        return 1;
    }

    for( int i=index; i<n; i++)
    {
        if( visited[i]==0 )
        {

            visited[i] = 1;
            if( a[i]+len < avg )
            {
                if( dfs( cnt, i+1, len+a[i]) )
                {
                    return 1;
                }
            }
            else if( a[i]+len==avg )
            {
                if( dfs( cnt+1, 0, 0) )
                {
                    return 1;
                }
            }

            visited[i] = 0;//回溯
        }
    }
    return 0;
}

int main()
{
    int cnt,sum,flag;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        sum = flag =0;
        scanf("%d",&n); //数量
        for( int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }

        if( sum%4!=0 )
        {
            printf("no\n");
        }
        else
        {
            avg = sum/4;
            memset(visited, 0, sizeof(visited));
            sort( a, a+n, cmp);

            flag = dfs( 0, 0, 0);

            if( flag )
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }

    }
    return 0;
}