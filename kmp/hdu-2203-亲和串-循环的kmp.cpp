#include<cstdio>
#include<iostream>
#include<cstring>
#define MAX 100010

using namespace std;

char str[MAX],ptr[MAX];
int nexti[MAX];

void get_next( char *str, int len, int *next)
{
    int k = next[0] = -1;

    for( int i=1; i<len; i++)
    {
        while( k>-1 && str[k+1]!=str[i] )
        {
            k = next[k];
        }

        if( str[k+1]==str[i] )
        {
            k ++;
        }
        next[i] = k;
    }
}

void kmp( char *str, int len, char *ptr, int plen, int *next)
{
    int k = -1;
    get_next( ptr, plen, next);
    for( int i=0; i<2*len; i++ )
    {
        while( k!=-1 && str[i%len]!=ptr[k+1])
        {
            k = next[k];
        }

        if( str[i%len]==ptr[k+1] )
        {
            k ++;
        }

        if( k==plen-1 )
        {
            printf("yes\n");
            return;
        }
    }
    printf("no\n");
}


int main()
{
    int len,plen;
    while( ~scanf("%s %s",str,ptr) )
    {
        len = strlen(str);
        plen = strlen(ptr);

        if( len < plen )
        {
            printf("no\n");
        }else{
            kmp( str, len, ptr, plen, nexti);
        }
    }
}

/*
AABCD
CDAA
ASD
ASDF

yes
no
*/