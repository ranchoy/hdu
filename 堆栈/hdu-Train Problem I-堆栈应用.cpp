#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define MAX 1010
using namespace std;

stack<char> stk;
char s1[MAX],s2[MAX];
int flag[MAX];

int main()
{
	int n,k,idx;
	while(~scanf("%d %s %s", &n, s1, s2))
	{
		memset(flag, 0, sizeof(0));
		while(!stk.empty())
		{
			stk.pop();
		}
		
		idx = k = 0;
		for(int i=0; i<n; i++)
		{
			stk.push(s1[i]);
			flag[idx++] = 1;
			while( !stk.empty() && stk.top()==s2[k])
			{
				flag[idx++] = 0;
				stk.pop();
				k ++;
			}
		}
		
		if(k==n)
		{
			printf("Yes.\n");
			for(int i=0; i<idx; i++)
			{
				if(flag[i]==1)
				{
					printf("in\n");
				}
				else
				{
					printf("out\n");
				}
			}
		}
		else
		{
			printf("No.\n");
		}
		printf("FINISH\n");
	}
	return 0;
}
