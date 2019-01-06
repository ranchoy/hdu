// 查询单词是否在是词库插入时的单词
// trie[i][j]=k,当前节点i的子节点j的编号为k 
#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 20005
using namespace std;

int number;// 根节点root,编号number 
int trie[MAX][27];
int vis[1005];// vis[i]编号为i的节点是否在词库中,往词库插单词时标记该单词

// 插入字符串 
void insert(char *str)
{
	int root=0;// 根节点为0 
	for(int i=0,j=0; str[i]!='\0'; i++)
	{
		j = str[i] - 'a';
		if(trie[root][j] == 0)// 未编号 
		{
			trie[root][j] = number ++;
		}
		root = trie[root][j];// 继续往下找 
	}
	vis[root] = true;// 标记词库中存在的单词 
}

// 查找
bool search(char *str)
{
	int root = 0;// 根节点
	for(int i=0,j=0; str[i]!='\0'; i++)	
	{
		j = str[i] - 'a';
		if(trie[root][j] == 0)// 断了 
		{
			return false;
		}
		root = trie[root][j];// 未断则往下找 
	}
	return vis[root];// 如果单词在词库中存在vis[root]为true,否则false 
} 

int main()
{
	int n,m;
	char str[1005];
	while(~scanf("%d", &n))
	{
		// 初始化
		number = 1;
		memset(trie, 0, sizeof(trie));
		memset(vis, false, sizeof(vis));
		
		for(int i=0; i<n; i++)
		{
			scanf("%s", str);
			insert(str);	
		}
		
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s", &str);
			if(search(str) == true)
			{
				printf("Yes\n");	
			}	
			else
			{
				printf("No\n");
			}	
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

No
No
Yes
No
Yes
*/