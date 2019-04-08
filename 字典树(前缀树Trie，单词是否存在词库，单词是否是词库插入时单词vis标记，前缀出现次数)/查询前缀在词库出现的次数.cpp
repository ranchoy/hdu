// 查询前缀在词库中出现次数
#include<iostream>
#include<cstring>
#define MAX 1005
using namespace std;

int number = 1; // 根节点root,编号number
int arr[MAX]; // 出现次数
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
        root = trie[root][j]; // 继续往下
        arr[root]++; // 前缀后一个位置，次数加1(放下面就是单个单词出现次数)
    }
}

// 查找
int search(char *str)
{
    int root = 0;
    for(int i=0,j; i<strlen(str); i++)
    {
        j = str[i] - 'a';
        if(trie[root][j] == 0) // 字符串断了
        {
            return 0;
        }
        root = trie[root][j]; // 未断继续往下找
    }
    return arr[root]; // 前缀存在，返回次数 
}

int main()
{
    int n,m;
    char str[MAX];
    while(~scanf("%d", &n) && n)
    {
        
        // 初始化
        memset(arr, 0, sizeof(arr));
        memset(trie, 0, sizeof(trie));
        
        for(int i=0; i<n; i++)
        {
            scanf("%s", str);
            insert(str);
        }
        
        scanf("%d", &m);
        while(m--)
        {
            scanf("%s", str);
            printf("%d\n", search(str));
        }
    }
    return 0;
}

/*
6
cat
cash
app
apple
aply
ok
5
c
ca
cat
aps
app

2
2
1
0
2
*/