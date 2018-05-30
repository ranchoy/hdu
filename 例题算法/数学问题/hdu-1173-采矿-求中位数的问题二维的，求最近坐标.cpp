#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000000
using namespace std;

int cmp( double a, double b)
{
    return a<b;
}

double x[MAX],y[MAX];

int  main()
{
    int n;
    while( scanf("%d",&n)!=EOF )
    {
        if(n==0){return 0;}
        for( int i=0; i<n; i++)
        {
            scanf("%lf %lf",&x[i],&y[i]);
        }

        sort( x, x+n, cmp);
        sort( y, y+n, cmp);

        printf("%.2lf %.2lf\n",(x[n / 2] + x[(n-1) / 2])/2,(y[n / 2] + y[(n-1) / 2])/2);
    }
    return 0;
}
