/*
 * 注意这题其实就是象棋的马走日字，有八个方向，从起点到终点要走多少步，
 * 为了不走重复的路引入vis[x][y][dir]，除去重复走的方案
 * 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int sx,sy,ex,ey;
int vis[10][10][10];
int dir[8][2] = { {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2} };

struct node{
	int x,y,step;
};

int bfs(node s)
{
	struct node cur,next;
	
	queue<struct node> q;
	q.push(s);
	
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		
		if(cur.x==ex && cur.y==ey)
		{
			return cur.step;
		}
		
		for(int i=0; i<8; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			
			if(next.x>=0 && next.x<8 && next.y>=0 && next.y<8 && vis[next.x][next.y][i]==0)
			{
				vis[next.x][next.y][i] = 1;
				next.step = cur.step + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	int res; 
	struct node s;
	char s1[5],s2[5];
	while(~scanf("%s %s", s1, s2))
	{
		// 初始化
		memset(vis, 0, sizeof(vis));
		 
		sx = s1[1] - '0' - 1;
		sy = s1[0] - 'a';
		ex = s2[1] - '0' - 1;
		ey = s2[0] - 'a';
		
		s.x = sx;
		s.y = sy;
		s.step = 0;

		res = bfs(s);
		
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, res);
	}
	return 0;
}
/*
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/