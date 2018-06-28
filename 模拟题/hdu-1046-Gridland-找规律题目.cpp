#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int cnt,m,n,temp=1;
	cin >> cnt;
	while(cnt--)
	{
		
		cin >> m >> n;
		printf("Scenario #%d:\n",temp++);
		if(m%2==0 || n%2==0)
		{
			printf("%.2lf\n\n",(double)(m*n));
		}
		else
		{
			printf("%.2lf\n\n", (double)(m*n-1+1.41));
		}
	}
	return 0;
}