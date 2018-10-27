//卡特兰数：h(n) = h(n-1)*(4*n-2)/(n+1)
//h(n) = h(0)*h(n-1) + h(1)*h(n-2) + h(2)*h(n-3) + ... + h(n-1)*h(0)
//参考：https://blog.csdn.net/blogs_of_slicer/article/details/20479279
#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX 36
using namespace std;

__int64 arr[MAX];

void catelan()
{
	arr[0] = 1;
	for(int i=1; i<MAX; i++)
	{
		for(int j=0; j<i; j++)
		{
			arr[i] += arr[j]*arr[i-j-1]; 	
		} 
	}
}

int main()
{
	int cnt=1,n;
	catelan(); 
	while(~scanf("%d", &n) && n!=-1)
	{
		printf("%d %d %I64d\n", cnt++, n, arr[n]*2);	
	} 
	return 0;
} 
/**
1
3
12
-1

1 1 2
2 3 10
3 12 416024
*/