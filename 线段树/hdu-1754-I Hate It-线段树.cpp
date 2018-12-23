#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 200000
using namespace std;

int res;
struct node {
    int l,r,w;
} tree[4 * MAX + 5];

// 建立
void build(int l, int r, int k)
{
    int mid;

    tree[k].l = l;
    tree[k].r = r;
    tree[k].w = 0;

    if(tree[k].l == tree[k].r)
    {
        return ;
    }

    mid = (l + r) / 2;

    build(l, mid, 2*k);
    build(mid+1, r, 2*k+1);
}

// 更新
void update(int idx, int val, int k)
{
    int mid;

    if(tree[k].l == tree[k].r && tree[k].l == idx)
    {
        tree[k].w = val;
        return ;
    }

    mid = (tree[k].l + tree[k].r) / 2;

    if(idx <= mid)
    {
        update(idx, val, 2*k);
    }
    else 
    {
        update(idx, val, 2*k+1);
    }

    tree[k].w = max(tree[2*k].w, tree[2*k+1].w);
}

// 查找
void search(int l, int r, int k)
{
    int mid;

    if(tree[k].l == l && tree[k].r == r)
    {
        res = max(res, tree[k].w);
        return ;
    }

    mid = (tree[k].l + tree[k].r) / 2;
    
    if(mid >= r)
    {
        search(l, r, 2*k);
    }
    else if(mid < l)
    {
        search(l, r, 2*k+1);
    }
    else
    {
        search(l, mid, 2*k);
        search(mid+1, r, 2*k+1);
    }
}

int main()
{
    char ch;
    int n,m,a,b;

    while(~scanf("%d %d", &n, &m))
    {
        // 初始化
        build(1, n, 1);

        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a);
            update(i, a, 1);
        }

        while(m--)
        {
            scanf(" %c %d %d", &ch, &a, &b);

            if(ch == 'Q')
            {   
                res = 0;
                search(a, b, 1);
                printf("%d\n", res);
            }
            else
            {
                update(a, b, 1);
            }
        }
    }
    return 0;
}

/*
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 2 9
Q 1 5

5
6
5
9
*/