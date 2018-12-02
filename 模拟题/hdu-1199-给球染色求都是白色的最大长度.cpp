#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 2001
using namespace std;

struct node {
    int start, end;
} p[MAX];// 只存白线段

bool cmp(struct node a, struct node b)
{
    return a.start < b.start;
}

int main()
{
    char ch;
    int n,a,b,len,left,right,s,e,mx,temp;
    while(~scanf("%d", &n) && n)
    {
        // 初始化
        len = 0;
        while(n--)
        {
            scanf("%d %d %c", &a, &b, &ch);
            if(ch == 'w')
            {
                p[len].start = a;
                p[len].end = b;
                len ++;
            }
            else
            {
                // 黑色的有4种情况，内部|左边|右边|全部包含
                temp = len;
                for(int i=0; i<temp; i++)
                {
                    if(a>p[i].start && b<p[i].end)// 内部
                    {
                        p[len].start = b + 1;
                        p[len].end = p[i].end;
                        p[i].end = a - 1;
                        len ++;
                    }
                    else if(a<=p[i].start && b>=p[i].start && b<p[i].end)// 左边
                    {
                        p[i].start = b + 1;
                    }
                    else if(a>p[i].start && a<=p[i].end && b>=p[i].end)// 右边
                    {
                        p[i].end = a - 1;
                    }
                    else if(a<=p[i].start && b>=p[i].end)// 全部包含
                    {
                        p[i].start = p[i].end = -1;
                    }
                }
            }
        }

        sort(p, p+len, cmp);

        mx = 0;
        s = -1;
        e = -2;
        for(int i=0; i<len; i++)
        {
            if(p[i].start != -1)// 除去不存在的p[i]
            {
                if(p[i].start > e+1)
                {
                    temp = e - s + 1;
                    if(temp > mx)
                    {
                        mx = temp;
                        left = s;
                        right = e;
                    }
                    s = p[i].start;
                    e = p[i].end;
                }
                else
                {
                    e = max(e, p[i].end);
                }
            }
        }

        temp = e - s + 1;
        if(temp > mx)
        {
            mx = temp;
            left = s;
            right = e;
        }
        if(mx == 0)
            printf("Oh, my god\n");
        else
            printf("%d %d\n", left, right);
    }
    return 0;
}