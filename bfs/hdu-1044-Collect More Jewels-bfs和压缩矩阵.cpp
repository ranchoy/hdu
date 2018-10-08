#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 51
using namespace std;

int n,m,t,num;
int val[11];// 珍珠价值 
char map[MAX][MAX];
int vis[MAX][MAX][1<<10+1];// 珠宝有十种 
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

struct node {
	int x,y,w,step;// w表示得到珠宝的二进制(状态压缩) ,step表示步数 
};
struct node s,e;//起点和终点

int cal_val(int x)
{
	int res = 0;
	for(int i=0; i<10; i++)
	{
		if(x&(1<<i))
		{
			res += val[i];
		}
	}
	return res;
} 

void bfs(struct node s) 
{
	int temp,res=-1;
	struct node cur,next;
	queue<struct node> q;
	q.push(s);
	vis[s.x][s.y][s.w] = 1;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		if(cur.x==e.x && cur.y==e.y)
		{
			res = max(res, cal_val(cur.w));
		}
		
		for(int i=0; i<4; i++)
		{
			next = cur;
			next.x += dir[i][0];
			next.y += dir[i][1];
			next.step ++;

			if(next.x>=0 && next.x<n && next.y>=0 && next.y<m && map[next.x][next.y]!='*')
			{
				if(map[next.x][next.y]>='A' && map[next.x][next.y]<='J')// 珠宝 
				{
					temp = map[next.x][next.y] - 'A';
					next.w = next.w|(1<<temp);
				}

				if(vis[next.x][next.y][next.w] == 0) 
				{
					vis[next.x][next.y][next.w] = 1;				
					if(next.x==e.x && next.y==e.y)
					{
						res = max(res, cal_val(next.w));
					}
					if(next.step == t)
					{
						continue;
					}	
					q.push(next);
				}
			}
		}
	}

	if(res == -1)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("The best score is %d.\n", res);
	}
}
int main()
{
	int cnt,_case=1; 
	cin >> cnt;
	
	while(cnt--)
	{
		// 初始化
	    memset(vis, 0, sizeof(vis));
	    
		cin >> m >> n >> t >> num;// 注意题目是先列再行 
		for(int i=0; i<num; i++)
		{
			cin >> val[i];	
		} 
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				scanf(" %c", &map[i][j]);
				if(map[i][j] == '@')
				{
					s.x = i;
					s.y = j;
					s.w = 0;
					s.step = 0;
				}
				else if(map[i][j] == '<')
				{
					e.x = i;
					e.y = j;
				}
			}	
		} 
		
		printf("Case %d:\n", _case++);
		bfs(s);
		if(cnt)
		{
			printf("\n"); 
		} 
	}
} 

/*
3
4 4 2 2
100 200
****
*@A*
*B<*
****
4 4 1 2
100 200
****
*@A*
*B<*
****
12 5 13 2
100 200
************
*B.........*
*.********.*
*@...A....<*
************

Case 1:
The best score is 200.

Case 2:
Impossible

Case 3:
The best score is 300.
*/