#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 10000000
using namespace std;

bool arr[N];

//筛法求素数 
void is_prime()
{
	arr[2] = true;	
	for(int i=3; i<N; i++)
	{
		if(i%2&1)
		{
			arr[i] = true;
		}
		else
		{
			arr[i] = false;
		}
	}
	for(int i=3; i<N; i++)
	{
		if(arr[i])
		{
			for(int j=i+i; j<N; j+=i)
			{
				arr[j] = false;
			}
		}
	}
}

bool huiwen(int n)
{
	int a = n,b = 0;
	
	while(n>0)
	{
		b = b*10 + n%10;
		n /= 10;
	}
	
	return a==b;
}

void solve()
{
	for(int i=2; i<N; i++)
	{
		if(arr[i]==1)
		{
			if(huiwen(i))
			{
				arr[i] = true;
			}
			else
			{
				arr[i] = false;
			}
		}	
	}	
} 



int main()
{
	int m,n;
	is_prime();
	solve();
	while(~scanf("%d %d", &m, &n))
	{
		n = min(n, N);
		for(int i=m; i<=n; i++)
		{
			if(arr[i]==true)
			{
				printf("%d\n", i);
			}
		}
	}
	printf("\n");
	return 0;
}

/*
5 500

5
7
11
101
131
151
181
191
313
353
373
383
*/