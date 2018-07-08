//快速幂 
#include<iostream>
#include<cstdio>
using namespace std;

int mod(int a, int b, int k)
{
	int res = 1;
	a = a%k;
	while(b>0)
	{
		if(b%2==1)
		{
			res = res*a%k;
		}
		b = b / 2;
		a = a*a%k;
	}
	return res%k;
}

int main()
{
	int a,b;
	while(scanf("%d %d", &a, &b)==2)
	{
		printf("%d\n", mod(a, b, 10));
	}
	return 0;
}
/**
7 66
8 800

9
6
*/ 