#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;

struct node {
	int row,col;
} s[30];

int main()
{
	int n,flag,a,b,idx,res;
	char str[10010],ch;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf(" %c %d %d", &ch, &a, &b);
		s[ch - 'A'].row = a;
		s[ch - 'A'].col = b;
	}

	while(~scanf("%s", str))
	{
		// 初始化
		res = 0;
		flag = 0; 
		idx = 30;//往后面加 
		stack<char> st;
		for(int i=0; str[i]!='\0'; i++)
		{
			if(str[i] == '(')
			{
				continue;
			}
			else if(str[i] == ')')
			{
				b = st.top();//注意b和a的顺序 
				st.pop();
				a = st.top();
				st.pop();
				
				if(s[a].col != s[b].row)
				{
					flag = 1;
					break;
				}
				else
				{
					res += (s[a].col * s[b].col * s[a].row);
				}
				st.push(idx);
				s[idx].row = s[a].row;
				s[idx].col = s[b].col;
				idx ++;
			}
			else
			{
				st.push(str[i] - 'A');
			}
		}
		if(flag == 1)
		{
			printf("error\n");
		}
		else
		{
			printf("%d\n", res);
		}
	}
	return 0;
}
 
/*
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))

0
0
0
error
10000
error
3500
15000
40500
47500
15125
*/