#include<iostream>
#include<cstring>
#include<cstdio>
#define N 100005
using namespace std;

char str[N];

//next[i],表示第i+1个字符传串的最大相同前后缀最后一个字符下标
void cal_next(char *str, int len, int *next)
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
            k ++;
        }
        next[i] = k;
    }
}

int main()
{
    int n,len;
    int next[N];
    int num,l;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",str);
        len = strlen(str);
        cal_next(str, len, next);
        l = len - (next[len-1]+1);
        num = l - len%l;
        if(l!=len && len%l==0)
        {
            num = 0;
        }
        printf("%d\n",num);

    }
    return 0;
}

