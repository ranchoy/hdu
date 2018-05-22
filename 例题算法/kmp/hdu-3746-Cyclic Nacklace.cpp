#include<iostream>
#include<cstring>
#include<cstdio>
#define MAX 100010

using namespace std;
char str[MAX];
int nexti[MAX];
int len;
//nexti[i],表示第i+1个字符传串的最大相同前后缀最后一个字符下标
void get_next(char *str, int len, int *next)
{
    int k = -1;
    nexti[0] = -1;
    for( int i=1; i<len; i++)
    {
        while( k>-1 && str[i]!=str[k+1])
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

int main()
{
    int cnt;
    int cycle;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        num = 0;
        scanf("%s",str);
        len = strlen(str);
        get_next( str, len, nexti);
        cycle = len - ( nexti[len-1] + 1 );

        if(cycle!=len && len%cycle==0)
        {
            printf("0\n");//已经循环
        }else
        {
            printf("%d\n",cycle-len%cycle);
        }
    }
    return 0;
}
