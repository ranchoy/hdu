//素数环问题，每次以1开始，描述的是相邻的两个元素和为素数，首尾之和也为素数的一个一维数组
//做法dfs去找,条件是(vis[i]==0 && prime[ arr[num] + i ]==1) 
//注意n为奇数是不会有素数环的,1不算 
#include<iostream>
#include<cstdio>
#include<cstring>
#define N 20
using namespace std; 

int prime[40] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
int arr[N];
int vis[N]; 
int n;

void dfs(int num)
{
	if( num==n )
	{
		if(prime[ arr[num] + 1 ]==1)
		{
			for(int i=1; i<=n-1; i++)
			{
				printf("%d ", arr[i]);
			}printf("%d\n", arr[n]);
		}
		return; 
	}
	
	for(int i=1; i<=n; i++)
	{
		if(vis[i]==0 && prime[ arr[num] + i ]==1)
		{
			vis[i] = 1;
			arr[num+1] = i;
			
			dfs(num+1);
			
			vis[i] = 0;
		}
	}
}

int main()
{
	int cnt;
	cnt = 1;
	while( ~scanf("%d", &n))
	{
		printf("Case %d:\n", cnt++);
		
		memset(vis, 0, sizeof(vis));
		memset(arr, 0, sizeof(arr));
		
		vis[1] = 1;
		arr[1] = 1;
		
		dfs(1);
		printf("\n"); 
	}
	return 0;
}
