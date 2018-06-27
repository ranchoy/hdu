//一组数的最小公倍数，只要会求gcd(a,b)即可，注意先除再乘避免溢出 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int cmp(int a, int b)
{
	return a>b;
}

int arr[100000];

int gcd(int a, int b)
{
	return (b==0) ? a : gcd(b,a%b);	
}

int main()
{
	int cnt,n,temp;
	cin >> cnt;
	while( cnt--)
	{
		cin >> n;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		sort(arr, arr+n, cmp);

		temp = arr[0];
		for(int i=1; i<n; i++)
		{
			temp = temp / gcd(temp, arr[i]) * arr[i];
		}
		
		printf("%d\n", temp);
	}
}