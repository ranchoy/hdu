#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int a,b,mx,m,cnt;
	while(~scanf("%d %d", &a, &b))
	{
		// 初始化
		mx = 0;
	
		if(a > b)
		{
			swap(a, b);
		}
		for(int i=a; i<=b; i++)
		{
			m = i;
			cnt = 1;
			while(m != 1)
			{
				if(m&1)
				{
					m = 3*m + 1;	
				}
				else
				{
					m /= 2;
				}
				cnt ++;
			}
			mx = max(mx, cnt);
		}
		printf("%d %d %d\n", a, b, mx);
	} 
	return 0;
}

/*
1 10
100 200
201 210
900 1000

1 10 20
100 200 125
201 210 89
900 1000 174
*/