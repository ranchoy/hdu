#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 100010
using namespace std;

int arr[MAX],arr_half[MAX];

bool cmp(int a, int b)
{
	return a > b;
}

bool is_equal(int arr[], int n)
{
	for(int i=1; i<n; i++)
	{
		if(arr[i] != arr[i-1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n,times;
	while(~scanf("%d", &n) && n)
	{
		// 初始化
		times = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		while(1)
		{
			// 结束条件 
			if(is_equal(arr, n))
			{
				break;
			}
			for(int i=0; i<n; i++)
			{
				arr_half[i] = arr[i] / 2;
			}

			for(int i=1; i<n; i++)
			{
				arr[i] = arr_half[i] + arr_half[i-1];
				if(arr[i]&1)// 变成偶数 
				{
					arr[i] ++;
				}
			} 
			arr[0] = arr_half[0] + arr_half[n-1];
			if(arr[0]&1)
			{
				arr[0] ++; 	
			} 
			
			// 记录次数 
			times ++;
		}
		printf("%d %d\n", times, arr[0]);
	}
	return 0;	
} 
/*
6
36 2 2 2 2 2
11
22 20 18 16 14 12 10 8 6 4 2
4
2 4 6 8
0

15 14
17 22
4 8
*/ 