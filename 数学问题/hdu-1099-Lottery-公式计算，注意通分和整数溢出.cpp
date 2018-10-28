// 计算：n/1 + n/2 + n/3 + ... + n/n！= (1/1 + 1/2 + 1/3 + ... + 1/n!)
#include<iostream>
#include<cstdio>
using namespace std;

int gcd(__int64 a, __int64 b)
{
	return (b==0) ? a : gcd(b, a%b);	
}

void init(__int64 *arr)
{
	arr[1] = 1;
	for(int i=2; i<=22; i++)
	{
		arr[i] = i*arr[i-1] / gcd(i, arr[i-1]);
	}
}

int main()
{
	__int64 n,a_size,c_size,x,y;
	__int64 arr[23];
	__int64 a,b,c,num;// 整数,分子,分母 
	init(arr);// 初始化数组 

	while(~scanf("%I64d", &n))
	{
		// 初始化
		a = b = c = 0;
		for(int i=1; i<=n; i++)
		{
			b += arr[n] / i; 
		} 
		b *= n;
		num = gcd(b, arr[n]);// 分子与分母公约数
		
		b /= num;// 约分 
		c = arr[n] / num;
	    a = b / c;
		b = b - a * c;// 分子 
		if(b == 0)
		{
			printf("%I64d\n", a);	
		} 
		else
		{
			a_size = c_size = 0;
			x = a;
			y = c;
			while(x != 0)
			{
				a_size ++;
				x /= 10;
			}
			while(y != 0)
			{
				c_size ++;
				y /= 10;
			}
			
			for(int i=0; i<=a_size; i++)
			{
				printf(" ");
			}
			printf("%I64d\n", b);
			printf("%I64d ", a);
			
			for(int i=0; i<c_size; i++)
			{
				printf("-");
			}printf("\n"); 
			for(int i=0; i<=a_size; i++)
			{
				printf(" ");
			}	
			printf("%I64d\n", c);
		}
	}
	return 0;
}

/*
2
5
17

3 
   5
11 --
   12
   340463
58 ------
   720720
*/