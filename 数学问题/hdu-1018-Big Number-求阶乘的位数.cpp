#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{

    int cnt,n;
    double s;
    cin>>cnt;
    while( cnt--)
    {
        s = 0;
        cin>>n;
        for( int i=1; i<=n; i++)
        {
            s += log10(i);
        }
        cout<<(int)s+1<<endl;
    }
    return 0;
}
