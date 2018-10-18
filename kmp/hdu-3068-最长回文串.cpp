#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 225000

using namespace std;
char str[N];
char s[N];
int p[N];

int get_s()
{
    int len = strlen(str);
    int j = 0;
    s[j] = '$';
    s[++j] = '#';
    for(int i=0; i<len; i++)
        s[++j] = str[i], s[++j] = '#';
    return j;
}

int kmp(int slen)
{
    int res=0,mid=1,mx=0;//注意mid=1,为了保证开始时2*mid - i=-1导致数组越界情况
    for(int i=1; i<slen; i++)
    {
        p[i] = mx>i ? min(p[2*mid - i],mx-i) : 1;
        while( s[i+p[i]] == s[i-p[i]])
        {
            p[i]++;
        }
        if( i+p[i] > mx )
        {
            mx = i + p[i];
            mid = i;
        }
        if(p[i]>res)
        {
            res = p[i];
        }
    }
    return res - 1;
}

int main()
{
    int i,j;
    int res,slen;
    while(scanf("%s",str)!=EOF)
    {
        slen = get_s();
        res = kmp(slen);
        printf("%d\n",res);
    }
    return 0;
}

/*
aaaa
abab

4
3
*/