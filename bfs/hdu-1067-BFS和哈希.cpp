/*
11 26 0 13 44 0 24 42
21 17 45 23 25 0 36 0
31 46 34 14 12 37 32 47
41 16 43 27 35 22 33 15
开始把27放到26后面,原27位置变0,step+1,push(next) 
然后把45放到44后面,原45位置变0,step+1,push(next) 
然后把26放到25后面,原26位置变0,step+1,push(next)
执行下去,直到达到goal_hash;
这里的get_hash我还不会= = !
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue> 
#include<algorithm>
#define mod 1000007
using namespace std;

struct node {
	int step;
	int map[4][8];
};

bool vis[mod]; 
int goal_hash; // 最终hash 
int goal[4][8] = {
	{11,12,13,14,15,16,17,0},
	{21,22,23,24,25,26,27,0},
	{31,32,33,34,35,36,37,0},
	{41,42,43,44,45,46,47,0}
};

// 类似于康拓展开，这个哈希不会爆int
int get_hash(int map[4][8])
{
	__int64 res = 0;
	for(int i=0; i<4; i++)
	{
		for(int j=1; j<8; j++)
		{
			res <<= 1;
			res += map[i][j];
		}
	}
	return res % mod;
}

struct node get_next(struct node cur, int n)
{
	for(int i=0; i<4; i++)
	{
		for(int j=1; j<8; j++)
		{
			if(cur.map[i][j] == n)
			{
				cur.map[i][j] = 0;
				break;
			}
		}
	}
	return cur;
}

int bfs(node s) 
{
	queue<node> q;
	struct node cur,next;	
	int hash = get_hash(s.map);
	vis[hash] = true;
	s.step = 0;
	q.push(s);
	
	while(!q.empty())
	{
		cur = q.front();
		q.pop();

		if(get_hash(cur.map) == goal_hash)
		{
			return cur.step;
		}
		
		for(int i=0; i<4; i++)
		{
			for(int j=1; j<8; j++)
			{
				// 当前为0,左边不是0且不是17|27|37|47 
				if(cur.map[i][j]==0 && cur.map[i][j-1]!=0 && (cur.map[i][j-1]%10!=7))
				{
					next = get_next(cur, cur.map[i][j-1]+1);
					next.map[i][j] = cur.map[i][j-1] + 1;// 题目要求做法 
					next.step ++;
					hash = get_hash(next.map);
					if(vis[hash] == false)
					{
						vis[hash] = true;
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
	node s;
	int cnt,res;
	scanf("%d", &cnt);
	goal_hash = get_hash(goal);
	while(cnt--)
	{
		// 初始化
		memset(vis, false, sizeof(vis));
		memset(s.map, 0, sizeof(s.map));

		for(int i=0; i<4; i++)
		{
			for(int j=1; j<8; j++)
			{
				scanf("%d", &s.map[i][j]);
				if(s.map[i][j]%10 == 1)
				{
					s.map[i][j] = 0;
				} 
			}
		}
		s.map[0][0] = 11; s.map[1][0] = 21;
		s.map[2][0] = 31; s.map[3][0] = 41;
		
		res = bfs(s);
		printf("%d\n", res);
	}
	return 0;	
} 