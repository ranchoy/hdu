#include<iostream>
#include<cstdio>
#define MAX 105
using namespace std;

int  main()
{
	int n,pot,result;
	int arr[MAX];
	while( scanf("%d", &n) && n!=0)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		pot = result = 0;
		for(int i=0; i<n; i++)
		{
			if( arr[i] > pot)
			{
				result += (arr[i] - pot) * 6;
			}
			else
			{
				result += (pot - arr[i]) * 4;
			}
			pot = arr[i];
			result += 5;
		}	
		cout<<result<<endl;
	} 
	return 0;
}