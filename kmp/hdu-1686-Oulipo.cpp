#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000005
#define M 10005

using namespace std;

char str[N],ptr[M];
int slen,plen;

//求next函数
void cal_next(char *str,int len, int *next)
{
    int k = -1;
    next[0] = -1;
    for(int i=1; i<len; i++)
    {
        if( k>-1 && str[i]!=str[k+1])
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
        if( k>-1 && str[i]!=ptr[k+1])
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
            k = next[k];//重新初始化
        }
    }
    return cnt;
}

int main()
{
    int n,res=0;
    int next[M];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s%s",ptr,str);
        slen = strlen(str);
        plen = strlen(ptr);
        cal_next(ptr,plen,next);
        res = kmp(str, ptr, next);
        printf("%d\n", res);
    }
    return 0;
}

/*
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN

1
3
0
*/
