#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define INF 0x3f3f3f3f
#define MAX 500000
#define M 3
using namespace std;
int ha[9]={1,1,2,6,24,120,720,5040,40320};
int dir[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
char d[5]="udlr";
struct Node{
    int arr[3][3];
    int hash_num;//唯一确定一个排列顺序
    int x,y;//表示空白的坐标
    int g,h;//耗费g,期望h
    bool operator <(const Node &a) const{
        return h + g > a.h + a.g;
    }
};
int vis[MAX],end_hash;


//路径
struct Path{
    int pre;
    char ch;
}path[MAX];

//唯一标识矩阵,康托展开
int get_hash(Node a)
{
    int num[9],k=0,ans=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            num[k++] = a.arr[i][j];
        }
    }

    for(int i=0; i<9; i++)
    {
        k = 0;
        for(int j=i+1; j<9; j++)
        {
            if(num[i]>num[j])
            {
                ++k;
            }
        }
        ans += k * ha[9-i-1];
    }
    return ans;
}

int get_h(Node a)
{
    int ans=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(a.arr[i][j]!=0)
            {
                ans += abs(i - (a.arr[i][j] - 1)/3) + abs(j - (a.arr[i][j] - 1)%3);
            }
        }
    }
    return ans;
}

void print(int x)
{
    if(path[x].pre == -1)
    {
        return;
    }
    print(path[x].pre);
    printf("%c",path[x].ch);
}

void bfs(Node e)
{
    int x,y,nx,ny;
    memset( vis, 0, sizeof(vis));
    e.hash_num = get_hash(e);
    e.g = 0;
    e.h = get_h(e);
    vis[e.hash_num] = 1;
    path[e.hash_num].pre = -1;

    if(e.hash_num == end_hash)
    {
        printf("\n");
        return;
    }

    priority_queue<Node> pq;//优先队列
    pq.push(e);
    while( !pq.empty())
    {
        Node temp = pq.top();
        pq.pop();

        for(int i=0; i<4; i++)
        {
            x = temp.x;
            y = temp.y;
            nx = x + dir[i][0];
            ny = y + dir[i][1];

            if( nx>=0 && nx<3 && ny>=0 && ny<3)
            {
                Node next = temp;
                swap( next.arr[nx][ny], next.arr[x][y]);
                next.hash_num = get_hash(next);
                if(vis[next.hash_num])
                {
                    continue;
                }

                vis[next.hash_num] = 1;
                next.x = nx;
                next.y = ny;
                next.g ++;
                next.h = get_h(next);
                path[next.hash_num].pre = temp.hash_num;
                path[next.hash_num].ch = d[i];

                if( next.hash_num == end_hash )
                {
                    print(next.hash_num);
                    printf("\n");
                    return;
                }
                pq.push(next);
            }
        }
    }
}

int main()
{
    int n,j,k;
    char a[30];
    Node temp;
    for(int i=0; i<9; i++)
    {
        temp.arr[i/3][i%3] = (i+1)%9;
    }
    end_hash = get_hash(temp);

    while( gets(a) )
    {
        k = 0;
        Node e;

        for(int i=0,j=0; i<strlen(a); i++)
        {
            if(a[i]==' '){continue;}
            if(a[i]=='x')
            {
                e.arr[j/3][j%3] = 0;
                e.x = j/3;
                e.y = j%3;
            }
            else
            {
                e.arr[j/3][j%3] = a[i] - '0';
            }
            j ++;
        }

        //判断逆序数,12345678x变换不改变奇偶性,k应该为0
        int k = 0;
        for(int i=0; i<9; i++)
        {
            if(e.arr[i/3][i%3]==0){continue;}
            for(int j=0; j<i; j++)
            {
                if(e.arr[j/3][j%3]==0){continue;}
                if(e.arr[j/3][j%3] > e.arr[i/3][i%3])
                {
                    k ++;
                }
            }
        }

        if(k&1)
        {
            cout<<"unsolvable"<<endl;
        }
        else
        {
            bfs(e);
        }

    }
    return 0;
}
