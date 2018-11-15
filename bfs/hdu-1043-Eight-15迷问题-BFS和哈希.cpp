#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 400000 //最大hash 
using namespace std;

bool vis[MAX];// 最大hash=362879
int goal_hash = 46233;// 目标hash=46233
char dir_str[5] = "udlr";
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
int dp[9]={1,1,2,6,24,120,720,5040,40320}; 

struct node {	
	int x,y;// 空格 
	int hash; 
	int step,hope;// 步数 
	int map[3][3];
	
	bool operator < (const struct node &a) const {
		return step + hope > a.step + a.hope; 
	}
};

// 路径 
struct Path {
	char ch;
	int pre;	
} path[MAX];

// 逆序数k*(n-1)!的和 
int get_hash(int map[3][3])
{
	int arr[9];
	int k=0,res=0;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			arr[k++] = map[i][j];
		}
	}
	// 获取逆序数
	for(int i=0; i<9; i++)
	{
		k = 0;
		for(int j=i+1; j<9; j++)
		{
			if(arr[i] > arr[j])
			{
				k ++;	
			}	
		}
		res += k * dp[9-i-1];	
	} 
	return res;
}

// 期望hope 
int get_hope(int map[3][3])
{
    int res=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(map[i][j]!=0)
            {
                res += abs(i - (map[i][j] - 1)/3) + abs(j - (map[i][j] - 1)%3);
            }
        }
    }
    return res;
}

void print(int n)
{
	if(path[n].pre == -1)
	{
		return;
	}
	print(path[n].pre);
	printf("%c", path[n].ch);	
} 

void bfs(struct node s)
{
	struct node cur,next;
	priority_queue<struct node> q;
	q.push(s);
	
	while(!q.empty())
	{
		cur = q.top();
		q.pop();
		
//		if(cur.hash == goal_hash)// 达到目标 
//		{
//			print(cur.hash);
//			printf("\n");
//			return;	
//		} 
		
		for(int i=0; i<4; i++)
		{
			next = cur;
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.step ++;
	
			if(next.x>=0 && next.x<3 && next.y>=0 && next.y<3)
			{
				swap(next.map[next.x][next.y], next.map[cur.x][cur.y]);
				next.hash = get_hash(next.map);
				next.hope = get_hope(next.map);// 期望 
				
				if(vis[next.hash] == false) 
				{
					vis[next.hash] = true;
					
					path[next.hash].pre = cur.hash;
					path[next.hash].ch = dir_str[i];
					
					if(next.hash == goal_hash)// 达到目标 
					{
						print(next.hash);
						printf("\n");
						return;	
					} 
					q.push(next);
				}
			}
		}
	}
}

int main()
{
	int k;
	char str[30];
	struct node s;

	while(gets(str))
	{
		// 初始化
		k = 0;
		memset(vis, false, sizeof(vis)); 
	
		for(int i=0; i<strlen(str); i++)
		{
			if(str[i] == ' ')
			{continue;}
			if(str[i] == 'x')
			{
				s.map[k/3][k%3] = 0;
				s.x = k/3;// 空格 
				s.y = k%3;
			}
			else
			{
				s.map[k/3][k%3] = str[i] - '0';
			}
			k ++;
		}
		
		s.step = 0;
		s.hope = get_hope(s.map);
		s.hash = get_hash(s.map);		
		vis[s.hash] = true;
		path[s.hash].pre = -1;// 重要 

		// 剪枝,去除逆序数奇数次的情况
		k = 0;
		for(int i=0; i<9; i++)
		{
			if(s.map[i/3][i%3] == 0)
			{continue;}
			for(int j=0; j<i; j++)
			{
				if(s.map[j/3][j%3] == 0)
				{continue;}
				if(s.map[j/3][j%3] > s.map[i/3][i%3])
				{ 
					k ++;
				}
			}
		} 
		
		if(k&1)
		{
			printf("unsolvable\n");
		}
        else if(s.hash == goal_hash)// 已经是目标则换行
        {
            printf("\n");
        }
		else
		{
			bfs(s);
		} 
	}
	return 0;
}

/*
2 3 4 1 5 x 7 6 8
1 2 3 4 5 6 7 8 x
1 2 3 4 5 6 8 7 x

ullddrurdllurdruldr

unsolvable
*/