//高精度问题：例如差为0.0001这样子的时候res不应该减去1
//1.00000001 - 1.00000000 = 0.00000001满足
//1.000000001 - 1.00000001 = -0.000000009就不要减去了 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 5005
#define esp 1e-8
using namespace std;

int main()
{
	int res;
	double n,m,temp,sum;	
	while(~scanf("%lf %lf", &n, &m))
	{
		res = sum = 0;
		for(int i=1; i<MAX; i++)
		{
			sum = i*(i+1)*m;
			if(sum >= n*2)
			{
				res = i*(i+1)/2 + (i-1); 
				while( sum - n*2 >= -esp)//跳出循环 
				{
					sum = sum - 2.0*m;
					res --;
				}
				break;
			} 
		}
		printf("%d\n",res+1); 
	}
	return 0;
}
/*
10 1

13
*/ 