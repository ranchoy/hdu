#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 12
using namespace std;

int n,m;
char map[MAX][MAX],step[MAX][MAX];

void solve(int x, int y)
{
	int cnt=0;
	while(true)
	{
		if(x<0 || x>=n || y<0 || y>=m)
		{
			printf("%d step(s) to exit\n", cnt);
			return;
		}
		
		if(step[x][y] > 0)
		{
			printf("%d step(s) before a loop of %d step(s)\n", step[x][y], cnt - step[x][y]);
			return;
		}
		
		step[x][y] = cnt;
		
		switch (map[x][y]){
			case 'E':
				y ++;
				break;
			case 'W':
				y --;
				break;
			case 'S':
				x ++;
				break;
			case 'N':
				x --;
				break;
		}
		
		cnt ++;// 步数 
	}
}

int main()
{
	int k;
	while(~scanf("%d %d", &n, &m) && (n+m))
	{
		// 初始化
		memset(step, 0, sizeof(step)); 
		scanf("%d", &k);
		for(int i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		solve(0, k-1);
	}
	return 0;
}

/*
3 6 5
NEESWE
WWWESS
SNWWWW
4 5 1
SESWE
EESNW
NWEEN
EWSEN
0 0 

10 step(s) to exit
3 step(s) before a loop of 8 step(s)
*/ 