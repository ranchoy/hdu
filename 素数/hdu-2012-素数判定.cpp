#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 3000
using namespace std;

int is_prime[MAX];

void init()
{
	is_prime[1] = 0;
	is_prime[2] = 1;
	for(int i=3; i<MAX; i++)
	{
		if(i%2==1)
		{
			is_prime[i] = 1;
		}
		else
		{
			is_prime[i] = 0;
		}
	}
	
	for(int i=3; i<MAX; i++)
	{
		if(is_prime[i]==1)
		{
			for(int j=i+i; j<MAX; j=j+i)
			{
				is_prime[j] = 0;
			}
		}
	}
}

int main()
{
	init();
	int x,y,flag;
	while(~scanf("%d %d", &x, &y) && (x+y))
	{
		flag = 0;
		for(int i=x; i<=y; i++)
		{
			if(is_prime[i*i+i+41]==0)
			{
				flag = 1;
				break;
			} 
		}
		
		if(flag==0)
		{
			printf("OK\n");
		}
		else
		{
			printf("Sorry\n");
		}
	}
	return 0;
} 