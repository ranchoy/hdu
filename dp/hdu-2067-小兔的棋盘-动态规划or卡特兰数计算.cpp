//求(0,0)到(n,n)有多少种走法，注意是关于y=x对称的，只要求一半
//dp[i][j] = dp[i-1][j];(i==j)
//dp[i][j] = dp[i-1][j] + dp[i][j-1];(i!=j)
//这道题可以用卡特兰数求
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 36
using namespace std;

__int64 dp[MAX][MAX];//注意数的大小

void solve()
{
	memset(dp, 0, sizeof(dp));
	for(int j=0; j<=MAX; j++)
	{
		dp[0][j] = 1;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	}
	
	for(int i=1; i<MAX; i++)
	{
		for(int j=1; j<MAX; j++)
		{
			if(i==j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}
}

int main()
{
	int n,cnt=1;
	solve();
	while(~scanf("%d", &n) && n!=-1)
	{
		printf("%d %d %I64d\n", cnt++, n, dp[n][n]*2);	
	} 
	return 0;
} 



/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int arr[105][300];

//h(n) = h(n-1)*(4n-2)/(n+1) 
//这里输出要h(n)*2 
void catelan()
{
	int len,yu,temp;
	memset(arr, 0, sizeof(arr));
	arr[1][0] = arr[1][1] = 1;
	arr[2][0] = 1;
	arr[2][1] = 2;
	len = 1;
	
	for(int i=3; i<40; i++)
	{
		yu = 0;
		for(int j=1; j<=len; j++)
		{
			temp = arr[i-1][j]*(4*i-2) + yu;
			arr[i][j] = temp%10;
			yu = temp/10;
		}
		
		while(yu)
		{
			arr[i][++len] = yu%10;
			yu = yu/10;
		}
		
		for(int j=len; j>=1; j--)
		{
			temp = arr[i][j] + yu*10;
			arr[i][j] = temp/(i+1);
			yu = temp%(i+1);
		}
		
		while(arr[i][len]==0)
		{
			len --;
		}
		arr[i][0] = len;
	}
}

int main()
{
	int n,cases=1;
	catelan();
	while(~scanf("%d",&n) && n!=-1)
	{
		int temp,yu=0,len=arr[n][0];
		for(int j=1; j<=len; j++)
		{
			temp = arr[n][j]*2 + yu;
			arr[n][j] = temp%10;
			yu = temp/10;
		}
		while(yu)
		{
			arr[n][++len] = yu%10;
			yu = yu/10;
		}
		arr[n][0] = len;
		
		printf("%d %d ", cases++, n);
		for(int i=arr[n][0]; i>=1; i--)
		{
			printf("%d",arr[n][i]);
		}printf("\n");
	}
	return 0;
} 
*/