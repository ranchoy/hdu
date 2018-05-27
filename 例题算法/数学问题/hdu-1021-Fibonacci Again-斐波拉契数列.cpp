#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 1000000
using namespace std;
//数学问题，斐波拉契数列
int dp[MAX];

int main()
{
    dp[0] = 7;
    dp[1] = 11;
    for( int i=2; i<MAX; i++)
    {
        dp[i] = dp[i-1]%3 + dp[i-2]%3;
    }

    int n;
    while( scanf("%d",&n)==1)
    {
        if( dp[n]%3 == 0 )
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}
