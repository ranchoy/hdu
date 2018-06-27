#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<fstream>
#define MAX 10000
using namespace std;

int arr[MAX];//输入数据
int dp[MAX]; //一维dp
int maxV;   //贪心最大价值
int road[MAX]; //dp路径
int road_greedy[MAX]; //贪心路径

int dp_next[MAX][MAX];

struct node{
    int w,v;//重量和体积
} s[50];

//动态规划
void bag( int n, int m)
{
    for( int i=0; i<n; i++)
    {
        for( int j=m; j>=s[i].w; j--)
        {
            dp[j] = max( dp[j], dp[ j-s[i].w ]+s[i].v);
        }
    }
}
//贪心算法
int cmp( node a, node b)
{
    return a.w*b.v > b.w*b.v;
}
void bag_greedy( int n, int m)
{
    sort( s, s+n, cmp);//性价比最高
    for( int i=0; i<n; i++)
    {
        if( m-s[i].w>=0 )
        {
            maxV += s[i].v;
            m -= s[i].w;
            road_greedy[ s[i].number ] = 1;
        }
    }
}
//二维dp可以求出路径
void bag_1( int n, int m)
{
    for( int i=0; i<n; i++)
    {
        for( int j=1; j<=m; j++)
        {
            if( j<s[i].w)
            {
                dp_next[i][j] = dp_next[i-1][j];
            }
            else
            {
                dp_next[i][j] = max( dp_next[i-1][j], dp_next[i-1][j-s[i].w]+s[i].v);
            }
        }
    }
    //求路径
    int i = n-1;
    while( i>=0 )
    {
        if( dp_next[i][m]==dp_next[i-1][m])
        {
            i = i - 1;
        }
        else
        {
            m = m - s[i].w;
            road[i] = 1;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    int cnt,n,m,temp=1;
    scanf("%d",&cnt);
    while( cnt-- )
    {
        memset( dp, 0, sizeof(dp));
        memset( dp_next, 0, sizeof(dp_next));
        memset( road, 0, sizeof(road));
        memset( road_greedy, 0, sizeof(road_greedy));
        scanf("%d %d", &n, &m);
        for( int i=0; i<n; i++)
        {
            cin>>s[i].w;
        }
        for( int i=0; i<n; i++)
        {
            cin>>s[i].v;
        }

        cout<<"\n样例"<<temp++<<"：--------------------------------------"<<endl;

        //动态规划一维--------------------------------------------
        bag( n, m);
        cout<<"\n动态规划一维01背包最大价值为："<<dp[m]<<endl;

        //-------------------------------------------------------
        //动态规划二维
        bag_1( n, m);
        cout<<"\n动态规划二维01背包最大价值为："<<dp_next[n-1][m]<<endl;
        cout<<"动态规划二维选的物品标1:";
        for( int i=0; i<n; i++)
        {
            cout<<" "<<road[i];
        }cout<<endl;
        for( int i=0; i<n; i++)
        {
            for( int j=0; j<=m; j++)
            {
                cout<<dp_next[i][j]<<" ";
            }cout<<endl;
        }
        //-------------------------------------------------------
        //贪心算法
        maxV = 0;
        bag_greedy( n, m);
        cout<<"\n贪心算法01背包最大价值为："<<maxV<<endl;
        cout<<"贪心算法选的物品标1:";
        for( int i=0; i<n; i++)
        {
            cout<<" "<<road_greedy[i];
        }cout<<endl;
    }
    return 0;
}


