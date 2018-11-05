// 硬币125不能表示的最小值，类似于筛法求素数 
// 注意如果a+2b+5c内都能凑成，则最小是a+2b+5c+1 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10050
using namespace std;

int main()
{
	int a,b,c;
	int x[MAX],y[MAX];
	while(~scanf("%d %d %d", &a, &b, &c) && (a+b+c))
	{
		// 初始化
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		// 处理硬币1 
		for(int i=0; i<=a; i++)
		{
			x[i] = 1;// 可以用硬币1凑成	
		} 
		// 处理硬币2 
		for(int i=0; i<=a; i++)
		{
			for(int j=0; j<=b; j++)
			{
				y[i+2*j] = 1;// 可以用硬币12凑成 
			}
		}

		// 把计算结果转移到x[]中 
		for(int i=0; i<=a+2*b; i++)
		{
			x[i] = y[i];
			y[i] = 0;
		}
		// 处理硬币5 
		for(int i=0; i<=a+2*b; i++)
		{
			for(int j=0; j<=c; j++)
			{
				y[i+5*j] = x[i];// 如果x[i]凑不成，则这个也凑不成	
			}	
		}
		// 求不能用硬币表示的最小值，如果到a+2b+5c都能表示，则a+2b+5c+1不能表示的最小值 
		for(int i=0; i<=a+2*b+5*c+1; i++)
		{
			if(y[i] == 0)
			{
				printf("%d\n", i);
				break;
			}
		} 
	}
	return 0;
} 

/*
1 1 3
0 0 0

4
*/