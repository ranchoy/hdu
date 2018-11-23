#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100005

using namespace std;

char str[N];
int nexti[N];
int len;

//求循环节
void cal_next(char *str, int len, int *next)
{
    int k = -1;
    next[0] = -1;
    for(int i=1; i<len; i++)
    {
        while( k>-1 && str[i]!=str[k+1] )
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
    int cnt,res,circle;
    scanf("%d",&cnt);
    getchar();
    while(cnt--)
    {
        scanf("%s",str);

        len = strlen(str);

        cal_next(str, len, nexti);

        circle = len - ( nexti[len-1] + 1 );//循环节

        if(circle!=len && len%circle==0 )
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",circle-len%circle);
        }
    }
    return 0;
}
