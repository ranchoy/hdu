#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n,x,t;
	while(~scanf("%d", &n))
	{
		if(n==1 || n%2==0)
		{
			printf("2^? mod %d = 1\n", n);
		}
		else
		{
			x = 1;
			t = 2;
			while(t%n!=1)
			{
				x ++;
				t = t * 2 % n;
			}
			printf("2^%d mod %d = 1\n", x, n);
		}
	}
	return 0;
}
/*
2
5

2^? mod 2 = 1
2^4 mod 5 = 1
*/