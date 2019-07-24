#include<iostream>
using namespace std;

int main()
{
    int n,s,d,a,b;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d", &s, &d);
        if((d+s)&1 || s<d)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d %d\n", (s+d)/2, (s-d)/2);
        }   
    }
}

/*
2
40 20
20 40

30 10
impossible
*/