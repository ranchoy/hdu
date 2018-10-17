#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 100
using namespace std;

int main()
{
	int n,m;
	int arr[MAX];
	char a[MAX],b[MAX];
	while(gets(a) && a[0]!='#')
	{
		// 初始化
		memset(arr, 0, sizeof(arr)); 
		
		gets(b);
		n = strlen(a);
		m = strlen(b);
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				if(a[i] == b[j])
				{
					arr[i] ++;
				}
			}
		}
		
		for(int i=0; i<n; i++)
		{
			printf("%c %d\n", a[i], arr[i]);
		}
	}
	return 0;
} 

/*
I
THIS IS A TEST
i ng
this is a long test string
#

I 2
i 3
  5
n 2
g 2 
注：第2个测试用例中，空格也是被统计的字符之一
*/