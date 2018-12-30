#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 105
using namespace std;

int pre[30];

int find(int u)
{
    int r,k,temp;

    r = u;
    while(pre[r] != r)// 查找
    {
        r = pre[r];
    }

    k = u;
    while(pre[k] != r)// 压缩
    {
        temp = pre[k];
        pre[k] = r;
        k = temp;
    }
    return r;
}

void join(int u, int v)
{
    int a,b;
    a = find(u);
    b = find(v);
    if(a != b)
    {
        pre[a] = b;
    }
}

// 初始化
void init()
{
    for(int i=0; i<30; i++)
        pre[i] = i;  
}

int main()
{
    int len, u, v;
    char str[MAX];

    init();
    while(~scanf("%s", str))
    {
        if(str[0] == '0')
        {
            if(pre[2] == pre[13])
                printf("Yes.\n");
            else
                printf("No.\n");

            init();
        }
        else
        {
            len = strlen(str);
            u = str[0] - 'a' + 1;
            v = str[len-1] - 'a' + 1;
            join(u, v);
        }
    }
    return 0;
}

/*
so
soon
river
goes
them
got
moon
begin
big
0

Yes.
*/