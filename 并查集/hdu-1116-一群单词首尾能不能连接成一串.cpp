// 题解：首先并查集判断所有出现的点是否连通，然后判断这个图有没有欧拉回路或者欧拉通路
// 欧拉回路：所有点的入度等于出度
// 欧拉通路：起点(出度-入度=1)，终点(入度-出度=1)，其他点(入度=出度)
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;

int pre[27]; // i的父节点是pre[i]
struct node {
    int vis,in,out; // 是否访问，入度，出度 
} p[27],mark[27];

int find(int x) // 查找根节点
{
    int r,k,temp;
    r = x;
    while(pre[r] != r) // 查找
    {
        r = pre[r];
    }

    k = x;
    while(pre[k] != r) // 压缩
    {
        temp = pre[k];
        pre[k] = r;
        k = temp;
    }

    return r;
}

void join(int u, int v) // 合并
{
    int a,b;
    a = find(u);
    b = find(v);
    if(a != b)
    {
        pre[a] = pre[b];
    }
}

int main()
{
    int n,m,u,v,k;
    char str[MAX];
    scanf("%d", &n);
    while(n--)
    {
        // 初始化
        for(int i=1; i<27; i++)
        {
            pre[i] = i;
            p[i].vis = p[i].in = p[i].out = 0;   
        }

        scanf("%d", &m);
        while(m--)
        {
            scanf("%s", str);
            u = str[0] - 'a' + 1;
            v = str[strlen(str)-1] - 'a' + 1;
            join(u, v);

            p[u].vis = p[v].vis = 1; // u,v出现
            p[u].out ++; // 出度
            p[v].in ++; // 入度
        }

        k = 0; // 联通图个数
        for(int i=1; i<27; i++)
        {
            if(p[i].vis == 1 && pre[i]==i) // 根节点个数
            {
                k ++;
            }
        }

        if(k > 1) // 多个联通图
        {
            printf("The door cannot be opened.\n");
            continue;
        }

        k = 0; // 出入度不相等节点个数 
        for(int i=1; i<27; i++)
        {
            if(p[i].vis == 1 && p[i].in != p[i].out) // 出入度不相等
            {
                mark[k++] = p[i];
            }
        }

        if(k == 0) // 欧拉回路
        {
            printf("Ordering is possible.\n");
        }
        else if(k==2 && abs(mark[0].in-mark[0].out)==1 && abs(mark[1].in-mark[1].out)==1) // 欧拉通路
        {
            printf("Ordering is possible.\n");
        }
        else
        {
            printf("The door cannot be opened.\n");
        }
    }
    return 0;
}

/*
3
2
acm
ibm
3
acm
malform
mouse
2
ok
ok

The door cannot be opened.
Ordering is possible.
The door cannot be opened.
*/