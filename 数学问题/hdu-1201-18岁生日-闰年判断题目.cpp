#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int isRun( int y)
{
    if( (y%4 == 0 && y%100 != 0) || (y%400 == 0) )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int cnt;
    int y,m,d,s;
    cin>>cnt;
    while( cnt--)
    {
        s = 0;
        scanf("%d-%d-%d",&y,&m,&d);
        if(m==2 && d==29 && isRun(y+18)==0)
        {
            cout<<-1<<endl;
        }
        else
        {
            s = 365*18;
            for( int i=1; i<18; i++)
            {
                s += isRun(y+i);
            }

            if( m > 2)
            {
                s += isRun(y+18);
            }
            else if( m<2 || d!=29)
            {
                s += isRun(y);
            }
            cout<<s<<endl;
        } 
    }
    return 0;
}
