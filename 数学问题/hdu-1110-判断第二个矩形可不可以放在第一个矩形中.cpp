#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

bool check(double a, double b, double x, double y)
{
    if(a*b <= x*y) return false;
    if(a>x && b>y) return true;
    if(a <= x) return false;

    double dist_xy = sqrt(x*x + y*y);
    double angle = asin(a / dist_xy) - asin(x / dist_xy);
    double dist = y * cos(angle) + x * sin(angle);

    if(dist > b) return false;
    else return true;
}

int main()
{
    int cnt;
    double a,b,x,y;
    scanf("%d", &cnt);
    while(cnt--)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &x, &y);
        if(a > b) swap(a, b);
        if(x > y) swap(x, y);

        if(check(a, b, x, y))
        {
            printf("Escape is possible.\n");
        }
        else
        {
            printf("Box cannot be dropped.\n");
        }
    }
    return 0;
}

/*
2
10 10 8 8
8 8 10 10

Escape is possible.
Box cannot be dropped.
*/