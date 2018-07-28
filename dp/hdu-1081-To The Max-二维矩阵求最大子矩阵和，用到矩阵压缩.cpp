//二维最大子序列和，要压缩矩阵：sum[i][j]表示a[i][1]~a[i][j]前j个元素的和
//结果可以参照一维的最大序列和来写
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 105
#define INF 0x7fffffff
using namespace std;

int sum[MAX][MAX];

int main()
{
	int  n,temp,res;
	while(~scanf("%d",&n))
	{
		memset(sum, 0, sizeof(sum)); 
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				scanf("%d", &temp);
				sum[i][j] = sum[i][j-1] + temp;
			}
		}

		res = -INF;
		for(int i=1; i<n; i++)//i,j表示某一行的第i列到第j列，求的是第i列到第j列的和
		{                     //所以每一行应该是(sum[k][j] - sum[k][i-1])
			for(int j=i+1; j<=n; j++)
			{
				temp = 0;
				for(int k=1; k<=n; k++)
				{
					if(temp<0)
					{
						temp = 0;
					}
					temp += sum[k][j] - sum[k][i-1];
					res = max(res, temp);//存最大值 
				}
			}
		}
		
		cout << res << endl; 
	}
	return 0;
}
/*
4
0 -2 -7 0 9 2 -6 2
-4 1 -4 1 -1
8 0 -2

15
*/