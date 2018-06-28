//dfs解题，题意是给你一个数target,一个字符串str，求使得字符串中5个不同字符满足公式
//v - w^2 + x^3 - y^4 + z^5 = target 
//多个结果输出大的strcmp() 
#include<iostream>
#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<map>
#define MAX 1010 
using namespace std;

map<char,int> mp;
void init()
{
	char ch = 'A';
	for(int i=1; i<=26; i++)
	{
		mp[ch++] = i;
	}
}

char ch[10],m_ch[10];
char str[MAX];
int target,len,vis[MAX];

int is(int v, int w, int x, int y, int z)
{
	v = v - 'A' + 1;
	w = w - 'A' + 1;
	x = x - 'A' + 1;
	y = y - 'A' + 1;
	z = z - 'A' + 1;
	if( (v - w*w + x*x*x - y*y*y*y + z*z*z*z*z) == target )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void dfs(int idx)
{
	if(idx==5)
	{
		if(is(ch[0], ch[1], ch[2], ch[3], ch[4])&& strcmp(ch,m_ch)>0)
		{
			strcpy(m_ch, ch);
		}
	}
	else
	{
		for(int i=0; i<len; i++)
		{
			if(vis[ mp[str[i]] ]==0)
			{
				ch[idx] = str[i];
				vis[ mp[str[i]] ] = 1;
				
				dfs(idx+1);
				
				vis[ mp[str[i]] ] = 0;
			}
		}
	}
}

int main()
{
	init();
	while(scanf("%d %s", &target, str)!=EOF)
	{
		if(target==0 || (strcmp(str,"END")==0) )
		{
			break;
		}
		memset(vis, 0, sizeof(vis));
		memset(ch, '\0', sizeof(ch));
		memset(m_ch, '\0', sizeof(m_ch));
		
		len = strlen(str);
		dfs(0);
		
		if(strlen(m_ch)==0)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%s\n", m_ch);
		}
	}
	return 0;
}