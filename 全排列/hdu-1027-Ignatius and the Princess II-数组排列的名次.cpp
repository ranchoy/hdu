#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int step[9] = {1,1,2,6,24,120,720,5040,40320};

int main()
{
	int n,m,s,temp;
	int res[9]; 
	while(~scanf("%d %d", &n, &m))
	{
		if(n > 8)
		{
			for(int i=1; i<=n-8; i++)
			{
				printf("%d ", i);
			}
			s = 0;
			for(int i=n-8+1; i<=n; i++)
			{
				res[++s] = i;
			}
		}
		else
		{
			for(int i=1; i<=n; i++)
			{
				res[i] = i;
			}
			s = n;
		}
		
		for(int i=8; i>0&&m!=1; i--)
		{
			if(m > step[i])
			{
				for(int j=s-i+1; m!=1; j++)
				{
					m -= step[i];
					temp = res[j];
					res[j] = res[s-i];
					res[s-i] = temp;
					if(m <= step[i])
					{
						break;
					}
				}
			}
		}
		for(int i=1; i<=s-1; i++)
		{
			printf("%d ", res[i]);
		}printf("%d\n", res[s]);
	}
	return 0;
} 

/*
6 4
11 8

1 2 3 5 6 4
1 2 3 4 5 6 7 9 8 11 10
*/