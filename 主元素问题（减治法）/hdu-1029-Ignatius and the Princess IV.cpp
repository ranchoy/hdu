#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000005
using namespace std;

int arr[MAX];

// 主元素问题 
void mian_element(int *arr, int n)
{
	int cnt=0,main=arr[0];
	for(int i=1; i<n; i++)
	{
		if(cnt == 0)
		{
			cnt = 1;
			main = arr[i];
		}
		else 
		{
			main==arr[i] ? cnt++ : cnt--;
		}
	}
	
	printf("%d\n", main); 
}

int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		mian_element(arr, n);
	}
	return 0;
} 

/*
5
1 3 2 3 3
11
1 1 1 1 1 5 5 5 5 5 5
7
1 1 1 1 1 1 1

3
5
1
*/