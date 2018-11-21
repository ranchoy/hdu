// 求前缀在词库中出现次数,不存在返回0 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1005
using namespace std;

struct node {
	int count;// 前缀出现次数 
	struct node *son[26];
} *root;

// 插入字符串 
void insert(char *str)
{
	struct node *p = root;
	for(int i=0,j=0; str[i]!='\0'; i++)
	{
		j = str[i] - 'a';
		if(p->son[j] == NULL)// 词库中未出现则添加 
		{
			p->son[j] = (struct node *)malloc(sizeof(struct node)); 
			(p->son[j])->count = 0;// 初始化 
		}
		p = p->son[j];
		p->count ++;// 当前节点的下一个子节点count++ 
	}
}

// 查询前缀出现次数,未出现返回0 
int search(char *str) 
{
	struct node *p = root;
	for(int i=0,j=0; str[i]!='\0'; i++)
	{
		j = str[i] - 'a';
		if(p->son[j] == NULL)// 字符串断了 
		{
			return 0;
		}
		p = p->son[j];
	}
	return p->count;	
}

int main()
{
	int n,m;
	char str[1005];
	while(~scanf("%d", &n))
	{
		// 初始化
		root = (struct node *)malloc(sizeof(struct node));
		root->count = 0; 
		
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