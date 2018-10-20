#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1005

using namespace std;

char str[N],ptr[N];
int slen,plen;

//求next函数
void cal_next(char *str,int len, int *next)
{
    int k = -1;
    next[0] = -1;
    for(int i=1; i<len; i++)
    {
        if(k>-1 && str[i]!=str[k+1])
        {
            k = next[k];
        }
        if(str[i]==str[k+1])
        {
            k++;
        }
        next[i] = k;
    }
}

int kmp(char str[],char ptr[], int next[])
{
    int k = -1;
    int cnt = 0;//统计含多少个子串

    for(int i=0; i<slen; i++)
    {
        if(k>-1 && str[i]!=ptr[k+1])
        {
            k = next[k];
        }

        if(str[i]==ptr[k+1])
        {
            k++;
        }
        if(k==plen-1)
        {
            cnt ++;
            k = -1;
        }
    }
    return cnt;
}

int main()
{
    int res,next[N];
    while(~scanf("%s %s",str,ptr))
    {
        if(str[0]=='#') return 0;
        slen = strlen(str);
        plen = strlen(ptr);
        cal_next(ptr,plen,next);
        res = kmp(str, ptr, next);
        printf("%d\n", res);
    }
    return 0;
}


