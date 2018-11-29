// 并查集算法
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;

int pre[27];
char str[MAX];

// 查找|压缩
int find(int x)
{
    int r = x;
    while(pre[r] != r)// 查找
    {
        r = pre[r];
    }
    int k = x;
    while(pre[k] != r)// 压缩
    {
        k = pre[k];
        pre[k] = r;
    }
    return r;
}

// 合并
void join(int x, int y)
{
    int a,b;
    a = find(x);
    b = find(y);
    if(a != b)
    {
        pre[a] = b;// 这里注意顺序
    }
}

int main()
{
    int len,a,b;
    for(int i=1; i<=26; i++) pre[i] = i;// 初始化
    while(~scanf("%s", str))
    {
        if(str[0] == '0')
        {
            if(pre[2] == pre[13])// b...m
            {
                printf("Yes.\n");
            }
            else
            {
                printf("No.\n");
            }
            for(int i=1; i<=26; i++) pre[i] = i;// 初始化
        }
        else
        {
            len = strlen(str);
            a = str[0] - 'a' + 1;
            b = str[len-1] - 'a' + 1;
            join(a, b);
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