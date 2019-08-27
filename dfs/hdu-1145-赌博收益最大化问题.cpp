// 题意：每次做最好选择，当前钱为money，下次最好选择钱的期望为e，收益率r=money/e
// r<=t时，(1+t)/e；r>t时，(1-r)*(1-t) * (1+r)/2 * e + (r-t)/(1-t) * money = 下次参加 + 下次不参加
#include<iostream>
using namespace std;

int n;
double t;

double dfs(int k, int money, double t)
{
    double e,r; // 收益率rate:当前钱/下次期望
    if(k == n) { // 最后一题
        r = 0.5;
        e = 2*money;
        if(t > r) {
            return (1+t)/2*e;
        }   
        return (1-r)/(1-t)*(1+r)/2*e + (r-t)/(1-t)*money; // 参加+不参加
    }
    e = dfs(k+1, 2*money, t);
    r = money / e;
    if(t > r) {
        return (1+t)/2*e;
    }
    return (1-r)/(1-t)*(1+r)/2*e + (r-t)/(1-t)*money;
}

int main()
{
    double res;
    while (scanf("%d %lf", &n, &t) && (n+t))
    {
        res = dfs(1, 1, t);
        printf("%.3lf\n", res);
    }
    
    return 0;
}

/*
1 0.5
1 0.3
2 0.6
24 0.25
0 0

1.500
1.357
2.560
230.138
*/