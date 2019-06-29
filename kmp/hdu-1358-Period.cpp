// 循环节： cycle = (i+1) - (next[i]+1)
// 注意循环节特殊情况：len%cycle=0，可能aabaab这样，也可能是abcde这样
// 题意：找到由两个及以上循环节构成的子串
#include<iostream>
#include<cstring>
#define N 1000005
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
    int n,cycle;
    int _case = 0;
    while(~scanf("%d", &n) && n!=0)
    {
        scanf("%s", str);
        get_next(str, n, nt);
        printf("Test case #%d\n", _case++);

        for(int i=0; i<n; i++)
        {
            cycle = (i+1) - (nt[i]+1);// 循环节
            if((i+1)%cycle==0 && (i+1)!=cycle)// 循环节要是当前(i+1)串的子串
            {
                printf("%d %d\n", (i+1), (i+1)/cycle);
            }    
        }
        printf("\n");
    }
    return 0;
}

/*
3
aaa
12
aabaabaabaab
0
Test case #1
2 2
3 3
Test case #2
2 2
6 2
9 3
12 4
*/