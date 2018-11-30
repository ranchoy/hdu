// 题意：D代表破坏村庄，R代表修复最后被破坏的那个村庄，Q代表询问包括x在内的最大连续区间是多少
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#define MAX 50000
using namespace std;

struct node {
    int left, right;// 左右区间 
    int a, b, c;// a左端最大,b右端最大,c区间最大
} tree[4*MAX + 1];

// 建立线段树
void build(int left, int right, int k)
{
    tree[k].left = left;
    tree[k].right = right;
    tree[k].a = tree[k].b = tree[k].c = right - left + 1;

    if(left == right)
    {
        return;
    }

    int mid = (left + right) / 2;
    build(left, mid, 2*k);
    build(mid+1, right, 2*k+1);
}

// 更新线段树,D摧毁节点val=0，R恢复节点val=1
void update(int idx, int val, int k)
{
    if(tree[k].left == tree[k].right)// 叶节点,idx==tree[k].left==tree[k].right因为是向idx靠近的
    {
        tree[k].a = tree[k].b = tree[k].c = val;// 删除val=0,恢复val=1
        return;
    }
    
    int mid = (tree[k].left + tree[k].right) / 2;
    
    if(idx <= mid)// 左半区
    {
        update(idx, val, 2*k);
    }
    else// 右半区
    {
        update(idx, val, 2*k+1);
    }
    // 更新a,b,c
    tree[k].a = tree[2*k].a;
    tree[k].b = tree[2*k+1].b;
    tree[k].c = max(max(tree[2*k].c, tree[2*k+1].c), tree[2*k].b + tree[2*k+1].a);// c最大值是tree[2*k].c或tree[2*k+1].c或tree[2*k].b + tree[2*k+1].a
    // 特殊情况
    if(tree[2*k].a == tree[2*k].right - tree[2*k].left + 1)// tree[2*k].a已经包括整个tree[2*k]区间则还要加tree[2*k+1].a;
    {
        tree[k].a += tree[2*k+1].a;
    }
    if(tree[2*k+1].b == tree[2*k+1].right - tree[2*k+1].left + 1)// 同上
    {
        tree[k].b += tree[2*k].b;
    }
}

// 查找某个点
int search(int idx, int k)
{
    if(tree[k].left==tree[k].right || tree[k].c==0 || tree[k].c==tree[k].right-tree[k].left+1)// 叶节点|c等于0|c等于区间最大没有必要再找
    {
        return tree[k].c;// 1或0或整个区间
    }
    
    int mid = (tree[k].left + tree[k].right) / 2;
    
    if(idx <= mid)// 左半区
    {
        if(idx >= tree[2*k].right - tree[2*k].b + 1)// 如果idx在左子树的右区间内，则要看右子树的左区间有多长并返回
        {
            return search(idx, 2*k) + search(mid+1, 2*k+1);
        }
        else
        {
            return search(idx, 2*k);
        }
    }
    else// 右半区 
    {
        if(idx <= tree[2*k+1].left + tree[2*k+1].a - 1)// 如果idx在右子树的左区间内，则要看左子树的右区间有多长并返回
        {
            return search(mid, 2*k) + search(idx, 2*k+1);
        }
        return search(idx, 2*k+1);
    }
}

int main()
{
    char str[5];
    int n, m, idx;
    while(~scanf("%d %d", &n, &m))
    {
        // 初始化
        build(1, n, 1);
        stack<int> st;// 栈

        while(m--)
        {
            scanf("%s", str);
            if(str[0] == 'D')
            {
                scanf("%d", &idx);
                st.push(idx);// 入栈
                update(idx, 0, 1);
            }
            else if(str[0] == 'R')
            {
                if(!st.empty())
                {
                    idx = st.top();
                    st.pop();// 出栈
                    update(idx, 1, 1);
                }
            }
            else
            {
                scanf("%d", &idx);
                printf("%d\n", search(idx, 1));// 询问
            }
        }
    }
    return 0;
}

/*
7 9
D 3
D 6
D 5
Q 4
Q 5
R
Q 4
R
Q 4

1
0
2
4
*/