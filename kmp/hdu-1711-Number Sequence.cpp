#include<iostream>
#include<cstdio>
#define N 1000005
#define M 10005
using namespace std;

int a[N];
int b[M];

void cal_next(int *m, int len, int *next)
{
    int k = -1;
    next[0] = -1;
    for(int i=1; i<len; i++)
    {
        while(k>-1 && m[i]!=m[k+1])
        {
            k = next[k];
        }
        if(m[i] == m[k+1])
        {
            k++;
        }
        next[i] = k;
    }
}

int kmp(int *a, int alen, int *b, int blen, int *next)
{
    int k = -1;
    cal_next(b, blen, next);
    for(int i=0; i<alen; i++)
    {
        while(k>-1 && a[i]!=b[k+1])
        {
            k = next[k];
        }

        if(a[i] == b[k+1])
        {
            k++;
        }
        if(k == blen-1)
        {
            return i-k+1;//下标加1
        }
    }
    return -1;
}

int main()
{
    int cnt,m,n,res;
    int next[M];
    scanf("%d", &cnt);
    while(cnt--)
    {
        scanf("%d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d", &b[i]);
        }
        res = kmp(a, n, b, m, next);
        printf("%d\n",res);
    }
    return 0;
}

