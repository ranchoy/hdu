// 题意：给一系列按照字典序排列的单词，输出由两个单词组合的单词
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 100005
using namespace std;

int number,res;
bool vis[MAX];
int trie[MAX][26];
char map[MAX][90];

void insert(char *str)
{
    int root = 0;
    int len = strlen(str);
    for(int i=0,j; i<len; i++)
    {
        j = str[i] - 'a';
        if(trie[root][j] == 0)// 为空
        {
            trie[root][j] = number ++;// 编号
        }
        root = trie[root][j];
    }
    vis[root] = true;// 单词标记
}

// 查找单词是否在词库中
bool search(char *str)
{
    int root = 0;
    int len = strlen(str);
    for(int i=0,j; i<len; i++)
    {
        j = str[i] - 'a';
        if(trie[root][j] == 0)// 断了
        {
            return false;
        }
        root = trie[root][j];
    }
    return vis[root];
}

int main()
{
    int idx,len;
    char a[MAX],b[MAX];
    // 初始化
    idx = 0;
    number = 1;
    memset(map, 0, sizeof(map));
    memset(vis, false, sizeof(vis));
    memset(trie, '\0', sizeof(trie));

    while(~scanf("%s", map[idx]))
    {
        insert(map[idx]);
        idx ++;
    }

    // for(int i=0; i<6; i++)
    // {
    //     scanf("%s", map[idx]);
    //     insert(map[idx]);
    //     idx ++;
    // }
    
    for(int i=0; i<idx; i++)
    {
        len = strlen(map[i]);

        for(int j=0; j<len; j++)
        {
            strncpy(a, map[i], j+1); a[j+1] = '\0';
            strncpy(b, map[i]+j+1, len-j); b[len-j] = '\0'; 

            if(search(a) && search(b))
            {
                printf("%s\n", map[i]);
                break;
            }
        }
    }
    return 0;
}

/*
a
ahat
hat
hatword
hziee
word

ahat
hatword
*/