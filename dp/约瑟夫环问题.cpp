// 问题描述：编号为1~N的N个士兵围坐在一起形成一个圆圈，从编号为1的士兵开始依次报数（1，2，3...这样依次报），数到m的士兵会被杀死出列，之后的士兵再从1开始报数。直到最后剩下一士兵，求这个士兵的编号。
// 设old为删除之前的节点编号，new为删除了一个节点之后的编号，则关系为old = (new + m - 1) % n + 1。
#include<iostream>
using namespace std;

int dp(int n, int m)
{
    if(n == 1)
    {
        return 1;
    }
    return (dp(n-1, m) + m-1)%n + 1;
}

int main()
{
    int n,m,res;
    while(~scanf("%d %d", &n, &m))
    {
        res = dp(n, m);
        printf("%d\n", res);
    }
}

/*
1 1
6 3
6 2

1
1
5
*/