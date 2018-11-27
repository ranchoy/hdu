#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 19
#define LL long long
using namespace std;

LL cate[MAX];

void get_catelan()
{
    cate[0] = 1;
    for(int i=1; i<MAX; i++)
    {
        cate[i] = cate[i-1] * (4*i-2) / (i+1);
    }
}

void dfs(int s, int n, int idx)
{
    idx --;
    if(idx < 0) return;

    for(int i=idx, k=n; i>=0; i--)
    {
        if(k <= cate[i] * cate[idx-i])
        {
            if(s) printf("(");

            dfs(1, (k-1)/cate[i] + 1, idx-i);
            printf("X");
            dfs(1, (k-1)%cate[i] + 1, i);

            if(s) printf(")");
            break;
        }
        k -= cate[i]*cate[idx-i];
    }
}

int main()
{
    int n,i;
    get_catelan();
    
    while(~scanf("%d", &n) && n!=0)
    {
        i = 0;
        for(i=1; n>cate[i] && i<MAX; i++)
        {
            n = n - cate[i];
        }

        dfs(0, n, i);
        printf("\n");
    }
    return 0;
}