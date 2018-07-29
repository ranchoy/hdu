//鸽巢原理：找一种最大数量的糖果个数mx做挡板，mx-1为间隙，只要剩下糖果数量sum-mx大于等于mx-1就可以了 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	__int64 sum;
	int cnt,n,temp,mx;
	scanf("%d", &cnt);
	while(cnt--)
	{
		scanf("%d", &n);
		mx = 0;
		sum = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &temp);
			sum += temp;
			mx = max(mx, temp);
		}

		if(mx-1<=sum-mx)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
} 
/*
2
3
4 1 1
5
5 4 3 2 1

No
Yes
*/