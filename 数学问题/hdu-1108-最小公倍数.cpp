#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int gcd( int a, int b)
{
    return (b == 0) ? a : gcd(b, a%b);
}

int main()
{

    int m,n,mx,mn;
    while( ~scanf("%d %d",&m,&n))
    {
        mx = max( m, n);
        mn = min( m, n);
        cout<<m*n/gcd(mx,mn)<<endl;
    }
    return 0;
}
