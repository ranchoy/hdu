#include<iostream>
#include<cstring>
#include<sstream>
#define MAX 105
using namespace std;

int number, res;
int vis[MAX];
char str[MAX];
int trie[MAX][26];

void insert(string str)
{
    int root = 0; // 根节点
    int len = str.length();
    for(int i=0,j; i<len; i++)
    {
        j = str[i] - 'a';
        if(trie[root][j] == 0) // 未编号
        {
            trie[root][j] = number ++;
        }
        root = trie[root][j]; // 继续往下找
    }
    vis[root] = 1;
}

void init()
{
    res = 0;
    number = 1;
    memset(vis, 0, sizeof(vis));
    memset(trie, 0, sizeof(trie));
}

int main()
{
    int len;
    string str, temp;
    while(getline(cin, str) && str[0]!='#')
    {
        // 初始化
        init();

        len = str.length();
        stringstream ss(str);

        while(ss >> temp)
        {
           insert(temp);
        }

        for(int i=0; i<=number; i++)
        {
            if(vis[i] == 1)
                res ++;
        }
        cout << res << endl;
    }
    return 0;
}

/*
you are my friend
#

4
*/