#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

void solve(int n)
{
	int a[10000];
	int temp,idx,carry;
	idx = 0;
	a[0] = 1;
	for(int i=1; i<=n; i++)
	{
		carry = 0;
		
		for(int j=0; j<=idx; j++)
		{
			a[j] = a[j] * i + carry;
			carry = a[j] / 10000;
			a[j] = a[j] % 10000;
		}
		
		if( carry > 0)
		{
			idx ++;
			a[idx] = carry;
		}
	}
	
	cout<<a[idx];
	for(int i=idx-1; i>=0; i--)
	{
		printf("%04d",a[i]);
	}printf("\n");
}

int main()
{
	int n;
	while( scanf("%d",&n)!=EOF)
	{
		solve(n);
	}
	return 0;
}