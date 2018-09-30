#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 10
using namespace std;

int m,n;
int map[MAX][MAX],vis[MAX][MAX][4];
int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

struct node {
	int x,y,step;
	int arr[MAX][MAX];

	bool check() {
		if(x>=0 && x<m && y>=0 && y<n) {
			return 1;
		}
		return 0;
	}
};

struct node p_s,p_e;//人开始和目标位置

// 只要判断人能不能到，所以只要二维标识数组
int bfs_people(struct node s) {
	int flag[MAX][MAX];
	struct node cur,next;
	queue<struct node> q;
	memset(flag, 0, sizeof(flag));
	// 寻找人开始位置
	p_s = s;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(s.arr[i][j] == 4) {
				p_s.x = i;
				p_s.y = j;
				break;
			}
		}
	}
	flag[p_s.x][p_s.y] = 1;
	q.push(p_s);
	//if(p_s.x==p_e.x && p_s.y==p_e.y)//人能到目标位置，一开始就是目标位置，不能删除！！！
	//{
	//	return 1;
	//}
	while(!q.empty()) {
		cur = q.front();
		q.pop();

		// 这种写法是最稳的，判断当前节点是否满足
		if(cur.x==p_e.x && cur.y==p_e.y) {
			return 1;
		}

		for(int i=0; i<4; i++) {
			next = cur;
			next.x += dir[i][0];
			next.y += dir[i][1];

			if(next.check() && flag[next.x][next.y]==0 && (next.arr[next.x][next.y]!=1 && next.arr[next.x][next.y]!=2)) {
				flag[next.x][next.y] = 1;
				// 人能到目标位置
				if(next.x==p_e.x && next.y==p_e.y) {
					return 1;
				}
				q.push(next);
			}
		}
	}
	return 0;
}

// 要计算最小耗费，所以三维标识数组
int bfs_box(struct node s) {
	struct node cur,next;
	queue<struct node> q;
	// 初始化
	memset(vis, 0, sizeof(vis));
	q.push(s);

	while(!q.empty()) {
		cur = q.front();
		q.pop();

		if(map[cur.x][cur.y] == 3) {
			return cur.step;
		}

		for(int i=0; i<4; i++) {
			next = cur;
			next.x += dir[i][0];
			next.y += dir[i][1];
			next.step ++;

			if(next.check() && vis[next.x][next.y][i]==0 && map[next.x][next.y]!=1) {
				// 人到目标位置
				p_e.x = cur.x - dir[i][0];
				p_e.y = cur.y - dir[i][1];

				// 检查人目标位置是否合法
				if(p_e.check()==false) {
					continue;
				}

				if(bfs_people(next)) {
					// 更新人和箱子位置
					swap(next.arr[p_e.x][p_e.y], next.arr[p_s.x][p_s.y]);
					swap(next.arr[next.x][next.y], next.arr[cur.x][cur.y]);

					if(map[next.x][next.y] == 3) {
						return next.step;
					}
					// 标识数组置1
					vis[next.x][next.y][i] = 1;
					q.push(next);
				}
			}
		}
	}
	return -1;
}

int main() {
	int cnt,res;
	struct node s;
	cin >> cnt;
	while(cnt--) {
		cin >> m >> n;
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d", &map[i][j]);
				if(map[i][j] == 2) {
					s.x = i;
					s.y = j;
					s.step = 0;
				}
				// 赋值
				s.arr[i][j] = map[i][j];
			}
		}

		res = bfs_box(s);
		cout << res << endl;
	}
}

/*
1
5 5
0 3 0 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0

4
*/