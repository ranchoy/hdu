//[LeetCode]739. Daily Temperatures
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#define MAX 30010 
using namespace std;

int arr[MAX],res[MAX];
stack<int> st;

int main()
{
	int n,temp;
	while(~scanf("%d", &n) && n!=0)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
		}
		
		for(int i=0; i<n; i++)
		{
			while(!st.empty() && arr[i] > arr[st.top()])
			{	
				res[st.top()] = i - st.top();
				st.pop();	
			}
			st.push(i);
		}
		
		for(int i=0; i<n-1; i++)
		{
			printf("%d ", res[i]);
		}
		printf("%d\n",res[n-1]);
	}
	return 0;
}
/**
8
73 74 75 71 69 72 76 73

1 1 4 2 1 1 0 0
*/