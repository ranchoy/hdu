//注意一定要：next.step < step_min[next.x][next.y]，当前步数小于记录的最小数，不然会超时 
//这题主要是考：1.bfs出去重复路径的条件step_min[i][j]，2.过桥时如果直接走则加1，如果堵住则等待1分钟后直接走（+1+1） 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 21
using namespace std;

int m,n;
int sx,sy;
char map[MAX][MAX];
int step_min[MAX][MAX];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}}; 

struct node {
	int x,y,step=0;
	bool operator < (const struct node &a) const {
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
    	
    	for(int i=0; i<4; i++)
    	{
    		next = cur;
    		next.x += dir[i][0];
    		next.y += dir[i][1];
    		next.step ++;// 如果方向一致已经走过了桥，不一致再加1 
    		if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && map[next.x][next.y]!='*' && next.step<step_min[next.x][next.y])
    		{
    			// 下面情况是遇到桥不通过时等待一分钟 
    			if(map[next.x][next.y] == '|')
    			{
					if(next.x==cur.x && (cur.step&1)==0)// 横着方向且桥改变方向
					{
						next.step ++;	
					} 
					if(next.y==cur.y && (cur.step&1)==1)// 竖着方向且桥改变方向
					{
						next.step ++;	
					} 
					// 赶紧过桥 
					next.x += dir[i][0];
					next.y += dir[i][1];
				}
				else if(map[next.x][next.y] == '-')
				{
					if(next.y==cur.y && (cur.step&1)==0)// 横着方向且桥没有改变方向
					{
						next.step ++;	
					} 
					if(next.x==cur.x && (cur.step&1)==1)// 横着方向且桥改变方向
					{
						next.step ++;	
					} 
					// 赶紧过桥 
					next.x += dir[i][0];
					next.y += dir[i][1];
				} 
				
				if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && map[next.x][next.y]!='*' && next.step<step_min[next.x][next.y]) 
				{
					if(map[next.x][next.y] == 'T')// 终点
					{
						return next.step;	
					}
					step_min[next.x][next.y] = next.step;// 记录最小值
					pq.push(next); 
				}
			}
		}
	}
}
int main()
{
	int res;
	struct node s;
	while(~scanf("%d %d", &m, &n))
	{
		// 初始化
		memset(step_min, 0x3f, sizeof(step_min)); 

		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				scanf(" %c", &map[i][j]);
				if(map[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
			}
		}
		
		s.x = sx;
		s.y = sy;
		
		res = bfs(s);
		cout << res << endl;
	}
	return 0;
}

/*
5 5
**..T
**.*.
..|..
.*.*.
S....

7
*/ 