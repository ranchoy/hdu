#include<iostream>
#include<cstdio>
#define MAX 1000010
using namespace std;

int number=1;// 编号 
int arr[MAX]={0};// 前缀出现的次数 
int trie[MAX][26];// trie[i][j]表示节点i的子节点j的编号


// 插入字符串
void insert(char *str) 
{
	int root = 0;// 根节点 
	for(int i=0,j=0; str[i]!='\0'; i++)
	{
		j = str[i] - 'a';
		if(trie[root][j] == 0)// 未编号
		{
			trie[root][j] = number ++; 
		} 
		root = trie[root][j];
		
		arr[root] ++;// 前缀后移一个位置保存,次数加1
	}
}

// 查找前缀出现次数,未出现返回0
int search(char *str) 
{
	int root = 0;
	for(int i=0,j=0; str[i]!='\0'; i++)
	{
		j = str[i] - 'a';
		if(trie[root][j] == 0)// 字符串断了 
		{
			return 0;
		}
		root = trie[root][j]; 
	} 
	return arr[root];
}

int main()
{
	char str[20];

	while(gets(str))
	{
		if(str[0] == NULL)
		{
			break;
		}
		insert(str);	
	}
	
	while(gets(str))
	{
		printf("%d\n", search(str));
	}
	return 0;
}

/*
banana
band
bee
absolute
acm

ba
b
band
abc

2
3
1
0
*/