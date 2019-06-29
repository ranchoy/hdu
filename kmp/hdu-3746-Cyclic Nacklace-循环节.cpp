// next[i]表示[0,i-1]前缀等于后缀的最长字符串数目
#include<iostream>
#include<cstring>
#define N 100005
using namespace std;

int nt[N];
char str[N];

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
            k++;
        }
        next[i] = k;
    }
}

int main()
{
    int cnt,len,cycle;
    scanf("%d", &cnt);
    while(cnt--)
    {
        
        scanf("%s", str);
        len = strlen(str);
        get_next(str, len, nt);

        cycle = len - (nt[len-1] + 1); // 循环节

        if(len!=cycle && len%cycle==0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", len - len%cycle);
        }       
    }
    return 0;
}

/*
3
aaa
abca
abcde

0
2
5
*/