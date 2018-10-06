#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 201
using namespace std;

int m,n;
int sx,sy,ex,ey;
int step_min[MAX][MAX];
char map[MAX][MAX];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
 
struct node {
	int x,y,step;
	bool operator < (const node &a) const {
		return step > a.step;
	}
};
 
int bfs(struct node s)
{
	struct node cur,next;
	priority_queue<struct node> pq;
	pq.push(s);
	
	while(!pq.empty())
	{
		cur = pq.top();
		pq.pop();
		
		if(cur.x==ex && cur.y==ey)
		{
			return cur.step;
		}
		for(int i=0; i<4; i++)
		{
			next = cur;
			next.x += dir[i][0];
			next.y += dir[i][1];
			next.step ++;
			if(map[next.x][next.y] == 'x')
			{
				next.step ++;
			}
			
			if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && map[next.x][next.y]!='#' && next.step<step_min[next.x][next.y])
			{
				step_min[next.x][next.y] = next.step;
				if(next.x==ex && next.y==ey)
				{
					return next.step;
				}
				pq.push(next);
			}
		}
	}
	return 0; 
}
int main()
{
	int res;
	struct node s;
	while(~scanf("%d %d", &m, &n))
	{
		// 初始化
		memset(step_min, 0x7f, sizeof(step_min));
		 
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf(" %c", &map[i][j]);
				if(map[i][j] == 'r')
				{
					s.x = i;
					s.y = j;
					s.step = 0;
				}
				else if(map[i][j] == 'a')
				{
					ex = i;
					ey = j;
				}
			}
		}
		
		res = bfs(s);
		if(res)
		{
			cout << res << endl;	
		}
		else
		{
			cout << "Poor ANGEL has to stay in the prison all his life." << endl;
		}
	}
	return 0;
} 

/*
7 8
#.#####.
#.a#..r.
#..#x...
..#..#.#
#...##..
.#......
........

13
*/