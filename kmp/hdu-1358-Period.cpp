// 题意：求最小循环节问题，可能这题数据比较特殊,大部分都是循环节由循环节构成的
// 注意循环节求法， cycle = (i+1) - ( next[i]+1 );
// 注意循环节特殊情况：len%cycle=0，可能aabaab这样，也可能是abcde这样
#include<cstdio>
#include<iostream>
#include<cstring>
#define MAX 1000005
using namespace std;

char str[MAX];
int nexti[MAX];

void get_next( char *str, int len, int *next)
{
    int k = next[0] = -1;

    for( int i=1; i<len; i++)
    {
        while( k!=-1 && str[i]!=str[k+1] )
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
    int len,cycle;
    int k = 0;
    while(~scanf("%d",&len))
    {
        if(len==0)
        {
            break;
        }
        scanf("%s",str);
        printf("Test case #%d\n",++k);

        get_next( str, len, nexti);

        for( int i=0; i<len; i++)
        {
            cycle = (i+1) - (nexti[i]+1);// 循环节
            if((i+1)%cycle==0 && (i+1)!=cycle)// 循环节要是其子串
            {
                printf("%d %d\n", i+1, (i+1)/cycle);
            }
        }
        printf("\n");
    }
}
