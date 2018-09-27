#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define MAX 1001
using namespace std;

int n,m,k;
int sx,sy,ex,ey,flag;
int map[MAX][MAX],turn[MAX][MAX];
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

struct node{
	int x,y,turn,dir;
};

void bfs(struct node s)
{
	struct node cur,next;
	queue<struct node> q;
	q.push(s);

	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		
		if(cur.turn<=2 && cur.x==ex && cur.y==ey)
		{
			flag = 1;
			return;
		}
		
		for(int i=0; i<4; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			
			if(next.x>=1 && next.x<=n && next.y>=1 && next.y<=m && (map[next.x][next.y]==0 || (next.x==ex && next.y==ey)))
			{
				next.dir = i;//当前方向
				if(cur.dir!=-1 && cur.dir!=i)//当前方向改变 
				{
					next.turn = cur.turn + 1;
				}
				else
				{
					next.turn = cur.turn;
				}
				
				if(next.turn > 2)
				{
					continue;
				}	
				
				if(next.turn<=2 && turn[next.x][next.y]>=next.turn)
				{
					turn[next.x][next.y] = next.turn;
					q.push(next);
				}
			}
		}
	}
}

int main()
{
	struct node s;	
	while(~scanf("%d %d", &n, &m) && (n!=0||m!=0))
	{
		// 初始化
		memset(map, 0, sizeof(map));
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		
		scanf("%d", &k);
		while(k--)
		{
			// 初始化
			flag = 0;
			memset(turn, 1, sizeof(turn));
			
			scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
			s.x = sx;
			s.y = sy;
			s.turn = 0;
			s.dir = -1;
			//注意测试集有map[sx][sy]=0情况 
			if(map[sx][sy]!=map[ex][ey] || map[sx][sy]==0 || map[ex][ey]==0)
			{
				printf("NO\n");
			}
			else
			{
				bfs(s);
				
				if(flag)
				{
					printf("YES\n");	
				}	
				else
				{
					printf("NO\n");
				}
			}
		}
	}
	return 0;
}

/*
3 4
1 2 3 4
0 0 0 0
4 3 2 1
4
1 1 3 4
1 1 2 4
1 1 3 3
2 1 2 4
3 4
0 1 4 3
0 2 4 1
0 0 0 0
2
1 1 2 4
1 3 2 3
0 0

YES
NO
NO
NO
NO
YES
*/