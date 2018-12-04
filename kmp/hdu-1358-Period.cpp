// 注意循环节求法， cycle = (i+1) - ( next[i]+1 );
// 注意循环节特殊情况：len%cycle=0，可能aabaab这样，也可能是abcde这样
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000005
using namespace std;

int nt[MAX];// next[]数组
char str[MAX];

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

int main()
{
    int cse=1;
    int n,cycle;
    while(~scanf("%d", &n) && n)
    {
        scanf("%s", str);
        get_next(str, n, nt);

        printf("Test case #%d\n", cse++);
        for(int i=1; i<n; i++)
        {
            cycle = i - nt[i];// 循环节
            if((i+1)%cycle==0 && (i+1)!=cycle)// 循环节要是当前(i+1)串的子串
            {
                printf("%d %d\n", i+1, (i+1)/cycle);
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