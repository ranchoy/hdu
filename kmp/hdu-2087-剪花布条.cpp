#include<iostream>
#include<cstring>
#define MAX 1010
using namespace std;

int len, plen;
int _next[MAX];
char str[MAX], ptr[MAX];

void get_next(char *str, int len, int *next)
{
    int k;
    k = next[0] = -1;
    for(int i=1; i<len; i++)
    {
        while(k>-1 && str[i]!=str[k+1])
        {
            k = next[k];
        }
        if(str[i] == str[k+1])
        {
            k++;
        }
        next[i] = k;
    }
}

int kmp(char *str, char *ptr, int *next)
{
    int k = -1, cnt = 0; 
    get_next(ptr, plen, next);
    for(int i=0; i<len; i++)
    {
        while(k > -1 && str[i] != ptr[k+1])
        {
            k = next[k];
        }
        if(str[i] == ptr[k+1])
        {
            k++;
        }
        if(k == plen - 1)
        {
            k = -1;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int cnt;
    while(~scanf("%s", str))
    {
        if(str[0] == '#')
            return 0;
        scanf("%s", ptr);
        len = strlen(str);
        plen = strlen(ptr);
        cnt = kmp(str, ptr, _next);
        printf("%d\n", cnt);
    }
}