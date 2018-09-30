#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 105
using namespace std;

char map[MAX][MAX];
int m,n,k,flag;
int turn[MAX][MAX];//转弯次数
int sx,sy,ex,ey;
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

struct node {
	int x,y,dir,turn;
};

void bfs(struct node s) {
	struct node cur,next;

	turn[s.x][s.y] = 0;
	queue<struct node> q;
	q.push(s);

	while(!q.empty()) {
		cur = q.front();
		q.pop();

		if(cur.x==ex && cur.y==ey && cur.turn<=k) {
			flag = 1;
			return;
		}

		if(cur.turn > k) {
			continue;
		}

		for(int i=0; i<4; i++) {
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];

			if(next.x>=0 && next.x<m && next.y>=0 && next.y<n && map[next.x][next.y]!='*') {
				// 注意是对当前方向的判断cur.dir
				if(cur.dir!=i && cur.dir!=-1) {
					next.turn = cur.turn + 1;
				}else {
					next.turn = cur.turn;
				}
				next.dir = i;
                // 注意等于符号，详见：http://972169909-qq-com.iteye.com/blog/1244218
				if(next.turn <= turn[next.x][next.y]) {
					turn[next.x][next.y] = next.turn;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	int t;
	struct node s;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &m, &n);
		// 初始化
		flag = 0;
		memset(turn, 1, sizeof(turn));
		memset(map, 0, sizeof(map));

		for(int i=0; i<m; i++) {
			scanf("%s", map[i]);
		}

		scanf("%d %d %d %d %d", &k, &sy, &sx, &ey, &ex);
		sx = sx - 1;
		sy = sy - 1;
		ex = ex - 1;
		ey = ey - 1;
		
		s.x = sx;
		s.y = sy;
		s.dir = -1;
		s.turn = 0;

		bfs(s);

		if(flag) {
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
}

/*
2
5 5
...**
*.**.
.....
.....
*....
1 1 1 1 3
5 5
...**
*.**.
.....
.....
*....
2 1 1 1 3

no
yes
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAX 105
using namespace std;

int n,m,k,flag;
int sx,sy,ex,ey;
char map[MAX][MAX],turn[MAX][MAX];
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };

struct node{
    int x,y,turn,dir;

    bool operator < (const node &a) const {
        return turn > a.turn;
    }
};

void bfs(struct node s)
{
    struct node cur,next;

    priority_queue<struct node> pq;
    pq.push(s);

    while(!pq.empty())
    {
        cur = pq.top();
        pq.pop();

        if(cur.turn<=k && cur.x==ex && cur.y==ey)
        {
            flag = 1;
            return;
        }

        if(cur.turn > k)
        {
            continue;
        }

        for(int i=0; i<4; i++)
        {
            next.x = cur.x + dir[i][0];
            next.y = cur.y + dir[i][1];

            if(next.x>=1 && cur.x<=n && cur.y>=1 && cur.y<=m && map[next.x][next.y]!='*')
            {
                if(cur.dir!=-1 && cur.dir!=i)
                {
                    next.turn = cur.turn + 1;
                }
                else
                {
                    next.turn = cur.turn;
                }

                next.dir = i;
                if(next.turn <= k && next.turn<=turn[next.x][next.y])
                {
                    turn[next.x][next.y] = next.turn;
                    pq.push(next);
                }
            }
        }
    }
}


int main()
{
    int cnt;
    struct node s;

    cin >> cnt;
    while(cnt--)
    {
        // 初始化
        flag = 0;
        memset(turn, 0x3f, sizeof(turn));
        cin >> n >> m;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf(" %c", &map[i][j]);
            }
        }

        cin >> k >> sy >> sx >> ey >> ex;

        s.x = sx;
        s.y = sy;
        s.dir = -1;
        s.turn = 0;

        bfs(s);
        if(flag)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
*/