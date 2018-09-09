//二分查找时间复杂度为：O(log(n))  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10010
using namespace std;

int half(int *arr, int n, int m)
{
	int low=0,high=n;
	int mid = (low + high) / 2;
	while(low <= high)
	{
		if(arr[mid] > m)
		{
			high = mid - 1;
		}
		else if(arr[mid] < m)
		{
			low = mid + 1;
		}
		else
		{
			return arr[mid];
		}
	}
	return -1;
}

int main()
{
	int n,m;
	int arr[MAX];
	while(~scanf("%d %d", &n, &m))
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		sort(arr, arr+n);
		
		int res = half(arr, n, m);
		
		if(res == -1)
		{
			printf("No\n");
		}
		else
		{
			printf("%d\n", res);
		}
	}
	return 0;
}