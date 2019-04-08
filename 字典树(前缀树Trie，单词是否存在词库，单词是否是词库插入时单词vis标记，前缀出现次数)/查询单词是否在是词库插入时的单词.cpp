// 查询单词是否在是词库插入时的单词
// trie[i][j]=k,当前节点i的子节点j的编号为k 
#include<iostream>
#include<cstring>
#define MAX 1005
using namespace std;

int number = 1; // 根节点root,编号number
int vis[MAX];
int trie[MAX][26];

// 插入单词
void insert(char *str)
{
    int root = 0; // 根节点为0
    for(int i=0,j; i<strlen(str); i++)
    {
        j = str[i] - 'a';
        if(trie[root][j] == 0) // 未编号
        {
            trie[root][j] = number++;
        }
        root = trie[root][j]; // 继续往下找
    }
    vis[root] = 1; // 标记单词
}

// 查找
bool search(char *str)
{
    int root = 0;
    for(int i=0,j; i<strlen(str); i++)
    {
        j = str[i] - 'a';
        if(trie[root][j] == 0) // 字符串断了
        {
            return false;
        }
        root = trie[root][j]; // 未断继续往下找
    }
    return vis[root]; // 查询单词是否是在词库插入时的单词
}

int main()
{
    int n,m;
    char str[MAX];
    while(~scanf("%d", &n) && n)
    {
        scanf("%d", &m);
        // 初始化
        memset(vis, 0, sizeof(vis));
        memset(trie, 0, sizeof(trie));
        
        for(int i=0; i<n; i++)
        {
            scanf("%s", str);
            insert(str);
        }

        for(int i=0; i<m; i++)
        {
            scanf("%s", str);
            printf("%d\n", search(str));
        }
    }
    return 0;
}
/*
3 2
cat
dog
pig
cat
1
do
0
*/