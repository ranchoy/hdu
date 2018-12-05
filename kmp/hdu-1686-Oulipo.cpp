#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000005
using namespace std;

int nt[MAX];
char ptr[MAX],str[MAX];

void get_next(char *str, int len, int *next)
{
    int k = -1;
    next[0] = -1;
    for(int i=1; i<len; i++)
    {
        while(k>-1 && str[i]!=str[k+1])
        {
            k = next[k];
        }
        if(str[i] == str[k+1])
        {
            k ++;
        }
        next[i] = k;
    }
}

int kmp(char *ptr, int plen, char *str, int slen, int *next)
{
    int k=-1,cnt=0;
    get_next(str, slen, next);

    for(int i=0; i<plen; i++)
    {
        while(k>-1 && ptr[i]!=str[k+1])
        {
            k = next[k];
        }

        if(ptr[i] == str[k+1])
        {
            k ++;
        }

        if(k == slen - 1)// 找到一个str加一
        {
            cnt ++;
            k = next[k];
        }
    }
    return cnt;
}

int main()
{
    int n,plen,slen,res;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s %s", str, ptr);
        plen = strlen(ptr);
        slen = strlen(str);

        res = kmp(ptr, plen, str, slen, nt);
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