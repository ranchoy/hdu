#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int cnt,n,a,sum;
	scanf("%d", &cnt);
	while(cnt--)
	{
		scanf("%d", &n);
		sum = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &a);
			sum = abs(sum - a);
		}
		
		if(sum)
		{
			printf("I will never go out T_T\n");
		}
		else
		{
			printf("yeah~ I escaped ^_^\n");
		}
	}
	return 0;
} 
/*
2
2
2 2
2 
1 2

yeah~ I escaped ^_^
I will never go out T_T
*/