//这题的关键是vis数组，注意点是可以重复访问的，主要是要获得钥匙开门，vis[i][j][k]表示在点（x,y）获得钥匙数为k（eg:1010表示获得2把钥匙b和d，用的二进制）
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 21
using namespace std;

int n,m,t;
char map[MAX][MAX];
int vis[MAX][MAX][1<<10 + 1];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 

struct node {
	int x,y;
	int key;//钥匙的二进制
	int step;// 步数 
};

struct node s,e;//人开始和结束位置 

int bfs(struct node s)
{
	int temp,key; 
	struct node cur,next;
	queue<struct node> q;
	
	// 初始化
	memset(vis, 0, sizeof(vis));
	vis[s.x][s.y][0] = 1; 
	q.push(s);
	
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		
		if(cur.x==e.x && cur.y==e.y && cur.step<t)
		{
			return cur.step;
		}
		
		for(int i=0; i<4; i++)
		{
			next = cur;
			next.x += dir[i][0];
			next.y += dir[i][1];
			next.step ++;
			// 注意不能在下面IF语句加vis[next.x][next.y][next.key]=0,因为next.key还不知道 
			if(next.x>=0 && next.x<n && next.y>=0 && next.y<m && map[next.x][next.y]!='*' && next.step<t)
			{	
				// 开门 
				if(map[next.x][next.y]>='A' && map[next.x][next.y]<='J')
				{
					temp = map[next.x][next.y] - 'A';
					key = next.key&1<<temp;// 验证钥匙 
					if(key && vis[next.x][next.y][next.key]==0)
					{
						vis[next.x][next.y][next.key] = 1;
						q.push(next);
					}
				}
				// 捡到钥匙	
				else if(map[next.x][next.y]>='a' && map[next.x][next.y]<='j')
				{
					temp = map[next.x][next.y] - 'a';
					next.key = next.key|1<<temp;// 捡到钥匙 
					if(vis[next.x][next.y][next.key]==0)
					{
						vis[next.x][next.y][next.key] = 1;
						q.push(next);
					}
				}
				else
				{
					if(vis[next.x][next.y][next.key]==0)
					{
						vis[next.x][next.y][next.key] = 1;
						q.push(next);
					}
				}
			} 
		}
	}
	return -1;
}

int main()
{
	int res;
	while(~scanf("%d %d %d", &n, &m, &t))
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				scanf(" %c", &map[i][j]);
				if(map[i][j] == '@')
				{
					s.x = i;
					s.y = j;
					s.key = 0;
					s.step = 0;
				} 
				else if(map[i][j] == '^')
				{
					e.x = i;
					e.y = j;
				}
			}
		}
		
		res = bfs(s);
		cout << res << endl;
	}
	return 0;
}

/*
4 5 17
@A.B.
a*.*.
*..*^
c..b*

4 5 16
@A.B.
a*.*.
*..*^
c..b*

16
-1
*/