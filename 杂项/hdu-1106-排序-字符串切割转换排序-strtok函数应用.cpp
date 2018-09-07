//strtok(str,ptr)函数切割字符串
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1010
using namespace std;

int main()
{
	char str[MAX],*p;
	int arr[MAX],cnt;
	while(gets(str))
	{
		//初始化
		cnt = 0;
		p = strtok(str, "5");
		while(p)
		{
			arr[cnt++] = atoi(p);
			p = strtok(NULL, "5");	
		} 
		
		if(cnt>0)
		{
			sort(arr, arr+cnt);
			
			for(int i=0; i<cnt-1; i++)
			{
				printf("%d ", arr[i]);
			}printf("%d\n", arr[cnt-1]);
		}
	}
	return 0;
}
/**
0051231232050775
0 77 12312320

*/