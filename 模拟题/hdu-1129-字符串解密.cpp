// 题解：str[idx*ley%len]对应的字符是(char)((x+idx)%28)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[80];
int key, len;
char map[] = "_abcdefghijklmnopqrstuvwxyz.";

void solve(int idx, char ch)
{
    int x, y;
    if(ch == '_') x = 0; 
    else if(ch == '.') x = 27;
    else x = (int)(ch - 'a' + 1);
    y = (x + idx) % 28;
    arr[key*idx % len] = y;// 下标key*idx%len对应字符是(char)((x+idx)%28)
}

int main()
{
    char str[80];
    while(~scanf("%d", &key) && key)
    {
        scanf("%s", str);
        len = strlen(str);

        for(int i=0; i<len; i++)
        {
            solve(i, str[i]);
        }

        for(int i=0; i<len; i++)
        {
            printf("%c", map[ arr[i] ]);
        }printf("\n");
    }
    return 0;
}

/*
5 cs.
101 thqqxw.lui.qswer
3 b_ylxmhzjsys.virpbkr
0

cat
this_is_a_secret
beware._dogs_barking
*/