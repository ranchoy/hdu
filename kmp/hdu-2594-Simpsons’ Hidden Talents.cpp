//题意：给定两个字符串s1,s2,求最长的s1前缀ss使得ss为s2的最长后缀,输出该字符串和其长度。
#include<cstdio>
#include<iostream>
#include<cstring>
#define MAX 50010

char str[2*MAX],ptr[MAX];
int nexti[2*MAX];

void get_next( char *str, int len, int *next)
{
    int k = next[0] = -1;
    for( int i=1; i<len; i++)
    {
        while( k>-1 && str[i]!=str[k+1])
        {
            k = next[k];
        }

        if( str[i]==str[k+1] )
        {
            k ++;
        }
        next[i] = k;
    }
}

int main()
{
    int len,plen,slen;
    while( ~scanf("%s %s",str,ptr) )
    {
        len = strlen(str);
        plen = strlen(ptr);
        slen = len + plen;

        strcat( str, ptr);
        
        get_next( str, slen, nexti);

        slen = slen - 1;//注意是下标
        while(slen>len-1 || slen>plen-1)
        {
            slen = nexti[slen];
        }

        if( slen >= 0)
        {
            for( int i=0; i<=slen; i++)
            {
                printf("%c",str[i]);
            }

            printf(" %d\n",slen+1);
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
