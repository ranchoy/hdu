// 题解：首先并查集判断所有出现的点是否连通，然后判断这个图有没有欧拉回路或者欧拉通路
// 欧拉回路：所有点的入度等于出度
// 欧拉通路：起点（入度-出度=1），终点（出度-入度=1），其他点（入度=出度）
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int pre[27];// i的父节点是ptre[i]

struct node {
    bool vis;// 是否出现过
    int in, out;// 入度in,出度out
} p[27];

// 查找根节点
int find(int x)
{
    int r,m,temp;
    r = x;
    while(pre[r] != r)// 查找
    {
        r = pre[r];
    }

    m = x;
    while(pre[m] != r)// 压缩
    {
        temp = pre[m];
        pre[m] = r;
        m = temp;
    }
    return r;
}

// 合并节点
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

int main()
{
    int n,m,u,v;
    char str[1005];
    scanf("%d", &n);
    while(n--)
    {
        // 初始化
        for(int i=0; i<27; i++)
        {
            pre[i]   = i;
            p[i].vis = false;
            p[i].in  = p[i].out = 0;
        }

        scanf("%d", &m);
        for(int i=0; i<m; i++)
        {
            scanf("%s", str);
            u = str[0] - 'a' + 1;
            v = str[strlen(str) - 1] - 'a' + 1;
            join(u, v);
            
            p[u].vis = p[v].vis = true;// (u,v)出现过
            p[u].out ++;// 记录v入度和u出度
            p[v].in ++;
        }

        int cnt = 0;
        for(int i=1; i<27; i++)
        {
            if(p[i].vis==true && pre[i]==i)
            {
                cnt ++;
            }
        }
        
        if(cnt > 1)// 连通图有多个
        {
            printf("The door cannot be opened.\n");
            continue;
        }

        int k = 0;
        struct node mark[27];
        for(int i=1; i<27; i++)
        {
            if(p[i].vis==true && p[i].in!=p[i].out) // 出入度不等
            {
                mark[k++] = p[i];
            }
        }

        if(k == 0)
        {
            printf("Ordering is possible.\n");// 欧拉回路
        }
        else if(k==2 && (mark[0].out-mark[0].in==1 && mark[1].in-mark[1].out==1 || mark[0].in-mark[0].out==1 && mark[1].out-mark[1].in==1))
        {
            printf("Ordering is possible.\n");// 欧拉通路
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